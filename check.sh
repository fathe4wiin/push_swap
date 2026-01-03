#!/bin/zsh

# Colors
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'

echo -e "${GREEN}=== PUSH_SWAP CHECKLIST TESTER ===${NC}\n"

run_test() {
    CMD="./push_swap $1"
    EXPECTED=$2
    
    # Run command and capture stderr and stdout
    OUTPUT=$($CMD 2>&1)
    
    if [ "$EXPECTED" == "Error" ]; then
        if [ "$OUTPUT" == "Error" ]; then
            echo -e "${GREEN}[OK]${NC} '$1' -> Returned Error"
        else
            echo -e "${RED}[FAIL]${NC} '$1' -> Expected 'Error', got '$OUTPUT'"
        fi
    elif [ "$EXPECTED" == "Valid" ]; then
        if [ "$OUTPUT" == "Error" ]; then
            echo -e "${RED}[FAIL]${NC} '$1' -> Expected Valid, got 'Error'"
        else
            echo -e "${GREEN}[OK]${NC} '$1' -> Run successful"
        fi
    fi
}

echo "--- 1. Multiple Numerical Arguments ---"
run_test "1 3 5 +9 20 -4 50 60 04 08" "Valid"

echo -e "\n--- 2. Single String Argument ---"
run_test "\"3 4 6 8 9 74 -56 +495\"" "Valid"

echo -e "\n--- 3. Invalid Characters (Should be Error) ---"
run_test "1 3 dog 35 80 -3" "Error"
run_test "a" "Error"
run_test "1 2 3 5 67b778 947" "Error"
run_test "\" 12 4 6 8 54fhd 4354\"" "Error"
run_test "1 -- 45 32" "Error"

echo -e "\n--- 4. Duplicates (Should be Error) ---"
run_test "1 3 58 9 3" "Error"
run_test "3 03" "Error"
run_test "\" 49 128     50 38   49\"" "Error"

echo -e "\n--- 5. Valid Negatives (Should be Valid) ---"
run_test "\"95 99 -9 10 9\"" "Valid"

echo -e "\n--- 6. INT MAX / MIN Limits (Should be Valid) ---"
run_test "2147483647 2 4 7" "Valid"
run_test "99 -2147483648 23 545" "Valid"
run_test "\"2147483647 843 56544 24394\"" "Valid"

echo -e "\n--- 7. Overflow / Underflow (Should be Error) ---"
run_test "54867543867438 3" "Error"
run_test "-2147483647765 4 5" "Error"
run_test "\"214748364748385 28 47 29\"" "Error"

echo -e "\n--- 8. Mixed Inputs (Should be Valid) ---"
run_test "\"1 2 4 3\" 76 90 \"348 05\"" "Valid"