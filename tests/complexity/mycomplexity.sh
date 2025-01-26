#!/bin/bash

declare -A inputs
# [number of items] [how many reruns] [kpi]
inputs["3"]="3 100 3"
inputs["5"]="5 100 12"
inputs["100"]="100 100 700"
inputs["500"]="500 100 5500"

# Loop through cases and execute the command
for case in $(printf "%s\n" "${!inputs[@]}" | sort -n); do
	echo -e '\n'
    echo "============ $case ============"
    ./complexity ${inputs[$case]} ./checker_linux
done
echo -e '\n'
