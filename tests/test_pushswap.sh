#!/bin/bash

# Colors
GREEN="\033[0;32m"
RED="\033[0;31m"
RESET="\033[0m"

# Test cases
negativeint_OK=(
				"-1" 
				"-3 -58 -9 -7" 
				"-3 -05" 
				"-491 -128     -50 -38  -49"
			)
zero_OK=(
				"0" 
				"3 0 -9 7" 
				"3 0" 
				"491   0  -50 38  -49"
	)
atoi_OK=(
				"0003 001" 
				"-006 -9 7" 
				"+0008 1 9" 
				"+0  50 38  9"
				"-0 0008 1"
				'      0 0008 1'
		)
sorted_OK=(
				"1 2 3" 
				"4 5 6" 
				"-1 0 3 5 6 8 9 10"
		)
single_OK=(
				"1" 
				"4" 
				"-1"
		)
noargs_OK=()
empty_Error=(
				"" 
				" " 
				"    " 
			)
quotes_OK=(
				'"1 2" 6 3 "4"' 
			)
duplicates_Error=(
				"1 3 58 9 3" 
				"3 3" 
				" 49 128     50 38   49" 
			)
limits_Error=(
				"2147483648 0" 
				"4 -2147483649" 
				"54867543867438 3" 
				"-2147483647765 4 5" 
				"214748364748385 28 47 29"
			)

limits_OK=(
				"2147483647 2 4 7" 
				"-2147483648 23 545 0" 
				"2147483646 843 56544 24394" 
				"-2147483647 23 545 0")
nonnumeric_Error=(
				"1 3 dog 35 80 -3" 
				"a b" 
				"0 one 2 3" 
				"1 2 3 5 67bcg778 947" 
				"1 && 45 32"
				)
unspecified_ANY=(
				' "1 2 4 3" 76 90 "348 05'
				)
valid_OK=(
				"11 10 9 8 7 6 5 4 3 2 1" 
				"-7 8 6 5 9 12 34 56 77 -6 0"
				"3 2 1"
		)

cases=("negativeint_OK" "zero_OK" "atoi_OK" "sorted_OK" "single_OK" "noargs_OK" "empty_Error" "quotes_OK" "duplicates_Error" "limits_Error" "limits_OK" "nonnumeric_Error" "unspecified_ANY" "valid_OK")

for case in "${cases[@]}"; do
    eval "inputs=(\"\${${case}[@]}\")"
    echo "============$case============="

    
    for ARG in "${inputs[@]}"; do
        result=$(./push_swap $ARG 2>/dev/null | ./checker_linux $ARG 2>/dev/null)
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



