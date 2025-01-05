#!/bin/bash

# Colors
GREEN="\033[0;32m"
RED="\033[0;31m"
RESET="\033[0m"

# Test cases

limits_Error=(
				"2147483648 0" 
			)
valid_OK=(
				"11 10 9 8 7 6 5 4 3 2 1" 
		)
duplicates_KO=(
				"11 10 9 8 7 6 5 4 3 2 11" 
		)

cases=("limits_Error" "valid_OK" "duplicates_KO")
for case in "${cases[@]}"; do
    eval "inputs=(\"\${${case}[@]}\")"
    echo "============$case============="

    
    for ARG in "${inputs[@]}"; do
        result=$(./push_swap $ARG 2>/dev/null | ./checker $ARG 2>/dev/null)
        ops=$(./push_swap $ARG 2>/dev/null | wc -l)
        
        if [ "$result" == "OK" ]; then
			echo -e "${GREEN}$result${RESET} $ops [$ARG]"
        elif [ "$result" == "KO" ]; then
            echo -e "${RED}KO${RESET} $ops [$ARG]"
		else 
			echo -e "${GREEN}Error${RESET} $ops [$ARG]"
        fi
    done
done



