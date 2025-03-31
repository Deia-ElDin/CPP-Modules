#!/bin/bash

# Colors for output
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' # No Color

# Path to your program
PROGRAM="./btc"

# Original data.csv lines (starting from line 2, as header must remain)
LINES=(
    "date,value"
    ",0.5"
    "2009-01-03,"
    "2008-01-01,0.5"
    "2009/01/03,0.5"
    "01-03-2009,0.5"
    "2009-13-01,0.5"
    "2009-01-32,0.5"
    "2009-02-29,0.5"
    "2009-01-03,-0.5"
    "2009-01-03,abc"
    "2009-01-03,inf"
    "2009-01-03,NaN"
    "2009-01-03,1000001"
    "  2009-01-03  ,  0.5  "
    "2009-01-03 0.5"
    "2009-01-03,0.5,extra"
    "# comment line"
    "2009-01-03,0.5"
    "date exchange_rate"
    "\"date\",\"exchange_rate\""
    "2009-01-03,\"0.5\""
    "'2009-01-03',0.5"
    "\"2009-01-03\",0.00001"
    "2009-01-03,inf"
    "2009-01-04,INF"
    "2009-01-05,infinity"
    "2009-01-06,INFINITY"
    "2009-01-07,1.#INF"
    "2009-01-08,NaN"
    "2009-01-09,nan"
    "2009-01-10,1.#NAN"
    "2009-01-11,1e308"
    "2009-01-12,-1e308"
    "2009-01-13,1.7976931348623157e+308"
    "2009-01-14,-1.7976931348623157e+308"
    "2009-01-15,+INF"
    "2009-01-16,-INF"
    "2009-01-17,\"inf\""
    "2009-01-18,0x1.0p+0"
    "2009-01-19,true"
    "2009-01-20,false"
    "2009-01-03,\"\""
    "2009-01-03,\"abc\""
    "2009-01-03,\"0.5\""
    "2009-01-03,\" 0.5 \""
    "2009-01-03,0,5"
    "2009-01-03,0.5%"
    "2009-01-03,\$0.5"
    "2009-01-03,NULL"
    "2009-01-03,null"
    "2009-01-03,None"
    "2010-01-01,0.5"
    "2009-12-31,1.0"
    "2020-02-29,1.0"
    "2019-02-29,1.0"
    "2019-02-22,2147483647"
    "2009-01-a1,0"
    "2009-01-1a,0"
)

# List of valid test cases that should be accepted
VALID_LINES=(
    "2009-01-03,0.5"
    "2010-01-01,0.5"
    "2009-12-31,1.0"
    "2020-02-29,1.0"  # Valid leap year
    "  2009-01-03  ,  0.5  "  # Extra whitespace should be trimmed
)

# Test file path
TEST_CSV="data/data.csv"

# Test input file
INPUT_TXT="data/input.txt"
echo "date | value" > $INPUT_TXT
echo "2011-01-03 | 3" >> $INPUT_TXT

# Function to check if a line is in the array of valid lines
is_valid_line() {
    local line="$1"
    for valid_line in "${VALID_LINES[@]}"; do
        if [ "$line" = "$valid_line" ]; then
            return 0  # True, line is valid
        fi
    done
    return 1  # False, line is not valid
}

# Variables to track test results
total_tests=0
failed_tests=0
failed_cases=()

# Run tests for each line
for i in "${!LINES[@]}"; do
    total_tests=$((total_tests + 1))
    test_failed=0
    
    # Create test CSV with header and current line
    echo "date,exchange_rate" > $TEST_CSV
    echo "${LINES[$i]}" >> $TEST_CSV
    
    echo -e "\n===== Testing Line $(($i+2)): ${LINES[$i]} ====="
    
    # Run with valgrind
    VALGRIND_OUTPUT=$(valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes $PROGRAM $INPUT_TXT 2>&1)
    
    # Check valgrind result
    if echo "$VALGRIND_OUTPUT" | grep -q "ERROR SUMMARY: 0 errors"; then
        echo -e "${GREEN}PASSED: No memory leaks or errors${NC}"
    else
        echo -e "${RED}FAILED: Valgrind detected memory issues${NC}"
        echo "$VALGRIND_OUTPUT" | grep -E "ERROR SUMMARY|LEAK SUMMARY|definitely lost|indirectly lost"
        test_failed=1
    fi
    
    # Check program result (exit code)
    $PROGRAM $INPUT_TXT > /dev/null 2>&1
    EXIT_CODE=$?
    
    # Determine if this line should be valid or invalid
    if is_valid_line "${LINES[$i]}"; then
        # This should be a valid line
        if [ $EXIT_CODE -eq 0 ]; then
            echo -e "${GREEN}PASSED: Program correctly accepted valid data${NC}"
        else
            echo -e "${RED}FAILED: Program rejected valid data${NC}"
            test_failed=1
        fi
    else
        # This should be an invalid line
        if [ $EXIT_CODE -eq 0 ]; then
            echo -e "${RED}FAILED: Program incorrectly accepted invalid data${NC}"
            test_failed=1
        else
            echo -e "${GREEN}PASSED: Program correctly rejected invalid data${NC}"
        fi
    fi
    
    # Save program output for analysis
    echo "Program Output:"
    $PROGRAM $INPUT_TXT
    
    echo -e "-------------------------"
    
    # Track failures
    if [ $test_failed -eq 1 ]; then
        failed_tests=$((failed_tests + 1))
        failed_cases+=("Line $(($i+2)): ${LINES[$i]}")
    fi
done

# Print summary of results
echo -e "\n===== Test Summary =====\n\n"
if [ $failed_tests -eq 0 ]; then
    echo -e "${GREEN}All $total_tests tests PASSED!${NC}"
else
    echo -e "${RED}$failed_tests out of $total_tests tests FAILED!${NC}"
    echo -e "${RED}Failed test cases:${NC}"
    for case in "${failed_cases[@]}"; do
        echo -e "${RED}- $case${NC}"
    done
fi