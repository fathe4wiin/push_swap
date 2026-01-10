*This project has been created as part of the 42 curriculum by bfathi.*

# Push_swap

## Description
Push_swap is a 42 school algorithm project. The goal is to sort a stack of integers using two stacks (Stack A and Stack B) and a specific set of instructions, with the absolute minimum number of operations.

The project involves complex algorithm design and complexity analysis. The challenge is not just to sort, but to sort efficienty, as the grade depends on the number of moves generated for a given set of numbers.

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
make
```
This will generate the executable `push_swap`.

Allowed `Makefile` commands:
*   `make`: Compiles the project.
*   `make clean`: Removes object files.
*   `make fclean`: Removes object files and the executable.
*   `make re`: Recompiles everything from scratch.

### Execution
Run the program with a list of integers as arguments:
```bash
./push_swap 4 67 3 87 23
```

You can verify the output using the provided checker:
```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG
```

## Algorithm & Technical Choices

This project implements an optimized sorting strategy based on chunking and efficient element retrieval, heavily inspired by the "Butterfly" algorithm approach.

### 1. Pre-Processing (Indexing)
The input values are first compressed into indices (ranks) ranging from `0` to `N-1`. This allows the algorithm to work with relative positions rather than raw values, simplifying range calculations.

### 2. Phase One: Partitioning (A to B)
The algorithm moves elements from Stack A to Stack B in a "butterfly" distribution pattern.
*   **Dynamic Range:** A variable range (window) is defined around the middle of the sorted sequence.
*   **Independent Expansion:** Elements are pushed to B if they fall within this window. To avoid bottlenecks, the window's lower and upper bounds expand independently as soon as corresponding elements are found.
*   **Base Preservation:** The 3 largest elements are identified and kept in Stack A. They are rotated to the bottom and sorted locally, forming a stable foundation for the final stack. This saves ~6 moves per execution.

### 3. Phase Two: Greedy Sort (B to A)
Elements are moved back to Stack A attempting to maintain descending order (which becomes ascending in A).
*   **Max Selection:** The algorithm targets the maximum available index in Stack B.
*   **Look-Ahead Optimization:** If the second-largest element (`max-1`) is found at the top of B, it is pushed immediately and rotated to the bottom of A (placing it "down"). A `down` counter tracks these hidden elements. When the true `max` is invariably pushed, the stack is reverse-rotated to bring the `max-1` element back to its correct position.

### 4. Output Optimization
A buffering system captures generated instructions before printing. This allows for post-processing optimizations where redundant or combinable operations are merged (e.g., `ra` followed by `rb` becomes `rr`), significantly reducing the final instruction count.

## Resources

*   [Push Swap — A journey to find the optimal sorting algorithm](https://medium.com/@msouiyeh/not-your-typical-42network-push-swap-cc583f863a90) by msouiyeh.
