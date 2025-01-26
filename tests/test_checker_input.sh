#!/bin/bash

# Colors
GREEN="\033[0;32m"
RED="\033[0;31m"
RESET="\033[0m"
ARGS="3 2 1"

# Create files with commands
echo -e "ra\nsa\n" > ops.txt
echo -e "ra\nsa" > ops_nonl.txt
echo -e "ra\n\nsa\n" > ops_extranl.txt

# Test cases
declare -A cases=(
    [noops]=""
    [wrong_ops]="echo -e 'ra\nsa\npb\n'"
    [extra_delimiters]="echo -e 'ra   \n sa \n'"
    [echo]="echo -e 'ra\nsa\n'"
    [echo_nl]="echo -e 'ra\nsa'"
    [echo_extra_nl]="echo -e 'ra\n\nsa\n'"
)
declare -A files=(
    [cat]="ops.txt"
    [cat_nl]="ops_nonl.txt"
    [cat_extranl]="ops_extranl.txt"
)

# Function to compare checkers
run_checker() {
    local input="$1"
    local file_mode="$2"
    local result result_linux

    if [ "$file_mode" -eq 1 ]; then
        result=$(./checker $ARGS < "$input" 2>/dev/null)
        result_linux=$(./checker_linux $ARGS < "$input" 2>/dev/null)
    else
        result=$(eval "$input" | ./checker $ARGS 2>/dev/null)
        result_linux=$(eval "$input" | ./checker_linux $ARGS 2>/dev/null)
    fi

    if [ "$result" == "$result_linux" ]; then
        echo -e "${GREEN}OK: [$result]${RESET} Input: [$input]"
    else
        echo -e "${RED}Mismatch: Checker [$result] vs Linux_Checker [$result_linux]${RESET} Input: [$input]"
    fi
}

# Test commands
for case in "${!cases[@]}"; do
    echo "============ $case ============"
    input="${cases[$case]}"
    run_checker "$input" 0
done

# Test files
for case in "${!files[@]}"; do
    echo "============ $case ============"
    input="${files[$case]}"
    run_checker "$input" 1
done

# Clean up: Delete test files
rm -f ops.txt ops_nonl.txt ops_extranl.txt
