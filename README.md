*This project has been created as part of the 42 curriculum by bfathi.*

# Push_swap

## Description
Push_swap is a 42 school algorithm project. The goal is to sort a stack of integers using two stacks (Stack A and Stack B) and a specific set of instructions, with the absolute minimum number of operations.

The project involves complex algorithm design and complexity analysis. The challenge is not just to sort, but to sort efficiently, as the grade depends on the number of moves generated for a given set of numbers.

### The Rules
You have two stacks named A and B.
*   Stack A contains a random amount of non-duplicated negative and/or positive numbers.
*   Stack B is empty.
*   The goal is to sort in ascending order numbers into stack A.

Available operations:
*   `sa`, `sb`, `ss`: Swap the first 2 elements at the top of stack.
*   `pa`, `pb`: Push the top element from one stack to the other.
*   `ra`, `rb`, `rr`: Rotate all numbers up by 1.
*   `rra`, `rrb`, `rrr`: Reverse rotate all numbers down by 1.

## Instructions

### Compilation
Use the provided `Makefile` to compile the project:
```bash
make        # Compiles push_swap
make bonus  # Compiles the checker program
```

Allowed `Makefile` commands:
*   `make`: Compiles the push_swap executable.
*   `make bonus`: Compiles the checker executable.
*   `make clean`: Removes object files.
*   `make fclean`: Removes object files and executables.
*   `make re`: Recompiles everything from scratch.

### Execution
Run the program with a list of integers as arguments:
```bash
./push_swap 4 67 3 87 23
```

### Checker (Bonus)
The checker program reads instructions from standard input and verifies if they correctly sort the stack:
```bash
./push_swap 4 67 3 87 23 | ./checker 4 67 3 87 23
```

Or use the provided `checker_linux` for reference:
```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG
```

The checker outputs:
- `OK` if the stack is sorted after executing all instructions
- `KO` if the stack is not sorted
- `Error` if invalid arguments or instructions are provided

### Tester
A comprehensive test script is included:
```bash
./tester.sh <num_elements> <num_tests>
./tester.sh 100 50   # Run 50 tests with 100 elements each
./tester.sh 500 100  # Run 100 tests with 500 elements each
```

## Performance

| Elements | Moves (Avg) | Moves (Max) | Grade |
|----------|-------------|-------------|-------|
| 3        | ≤ 3         | 3           | 3/3   |
| 5        | ≤ 12        | 12          | 3/3   |
| 100      | ~570        | < 700       | 5/5   |
| 500      | ~5100       | < 5500      | 5/5   |

## Algorithm & Technical Choices

This project implements an optimized sorting strategy based on chunking and efficient element retrieval, heavily inspired by the "Butterfly" algorithm approach.

### 1. Pre-Processing (Indexing)
The input values are first compressed into indices (ranks) ranging from `0` to `N-1`. This allows the algorithm to work with relative positions rather than raw values, simplifying range calculations.

### 2. Phase One: Partitioning (A to B)
The algorithm moves elements from Stack A to Stack B in a "butterfly" distribution pattern.
*   **Dynamic Range:** A variable range (window) is defined around the middle of the sorted sequence.
*   **Independent Expansion:** Elements are pushed to B if they fall within this window. To avoid bottlenecks, the window's lower and upper bounds expand independently as soon as corresponding elements are found.
*   **Base Preservation:** The 3 largest elements are identified and kept in Stack A. They are rotated to the bottom and sorted locally, forming a stable foundation for the final stack. This saves ~6 moves per execution.
*   **Early Exit Optimization:** If Stack A becomes sorted with only the top-3 indices remaining, phase one exits early.

### 3. Phase Two: Greedy Sort (B to A)
Elements are moved back to Stack A attempting to maintain descending order (which becomes ascending in A).
*   **Max Selection:** The algorithm targets the maximum available index in Stack B.
*   **Look-Ahead Optimization:** If the second-largest element (`max-1`) is found at the top of B, it is pushed immediately and rotated to the bottom of A (placing it "down"). A `down` counter tracks these hidden elements. When the true `max` is invariably pushed, the stack is reverse-rotated to bring the `max-1` element back to its correct position.

### 4. Output Optimization
A buffering system captures generated instructions before printing. This allows for post-processing optimizations where redundant or combinable operations are merged (e.g., `ra` followed by `rb` becomes `rr`), significantly reducing the final instruction count.

## Project Structure

```
.
├── Makefile
├── push_swap.h          # Main header file
├── main.c               # Entry point
├── parsing.c            # Argument parsing
├── parse_checks.c       # Input validation
├── indexing.c           # Value to index conversion
├── sorting.c            # Main sorting algorithm
├── simple_sort.c        # Sort for 3-5 elements
├── utils_sorting.c      # Sorting helper functions
├── move_swap.c          # sa, sb, ss operations
├── move_push.c          # pa, pb operations
├── move_rotate.c        # ra, rb, rr operations
├── move_rev_rotate.c    # rra, rrb, rrr operations
├── lists.c              # Linked list utilities
├── error.c              # Error handling
├── ft_*.c               # Utility functions
├── __bonus_checker.c    # Checker main (bonus)
├── __checker_utils.c    # Checker helpers (bonus)
├── gnl/                 # Get Next Line library
│   ├── get_next_line.c
│   ├── get_next_line_utils.c
│   └── get_next_line.h
├── tester.sh            # Testing script
├── checker_linux        # Reference checker
└── README.md
```

## Resources

*   [Push Swap — A journey to find the optimal sorting algorithm](https://medium.com/@msouiyeh/not-your-typical-42network-push-swap-cc583f863a90) by msouiyeh.
