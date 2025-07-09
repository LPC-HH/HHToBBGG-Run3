#!/usr/bin/env bash
set -uo pipefail

INPUT_BASE=/eos/uscms/store/group/lpcdihiggsboost/nparekh/analyzer/ZeeAnalyzer/option1/nano/run3
OUTPUT_DIR=/eos/uscms/store/group/lpcdihiggsboost/nparekh/combined

mkdir -p "$OUTPUT_DIR"
ERROR_LOG=merge_errors.log
: > "$ERROR_LOG"

for year in 2022; do
  for src in "$INPUT_BASE/$year"/*; do
    [[ -d "$src" ]] || continue
    sample=$(basename "$src")
    out="$OUTPUT_DIR/${sample}.root"

    # collect all .root inputs
    inputs=( "$src"/*.root )
    if [[ ! -e "${inputs[0]}" ]]; then
      echo "No input files for $sample (in $src)" >> "$ERROR_LOG"
      continue
    fi

    echo "Merging $sample from $year..."
    if hadd -fk "$out" "${inputs[@]}"; then
      ls -lh "$out"
    else
      echo "FAIL: $sample (exit code $?)" >> "$ERROR_LOG"
    fi
  done
done
echo "Done.  See $ERROR_LOG for any failures."