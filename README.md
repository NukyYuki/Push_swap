# push_swap (42) — Turk algorithm solution

This repository contains my implementation of the 42 School Common Core project push_swap. The goal is to sort a list of integers using two stacks (A and B) and a constrained set of operations, outputting a minimal or near-minimal sequence of moves. This solution is based on the Turk algorithm strategy.

Languages: C (~98.1%), Makefile (~1.9%)

Repository layout:
- Makefile — build rules
- [push_swap.h](https://github.com/NukyYuki/Push_swap/blob/af4e304cf33d0e36f4651b8c4879d35ffeee9ca1/push_swap.h) — project header and public API
- srcs/ — C sources (parsing, operations, algorithm, utils)

## Project overview

You must sort numbers in stack A in ascending order using only the following allowed operations on stacks A and B:

- Swaps: `sa`, `sb`, `ss`
- Pushes: `pa`, `pb`
- Rotations: `ra`, `rb`, `rr`
- Reverse rotations: `rra`, `rrb`, `rrr`

Program requirements:
- Validate input (32-bit signed integers, no duplicates, properly formatted arguments)
- Print the sequence of operations, one per line, to sort stack A
- Efficient strategies for small N (≤ 3, ≤ 5) and large N
- On invalid input, print `Error` to stderr and exit non-zero

## Algorithm: Turk strategy

This implementation uses the Turk algorithm, focusing on minimizing the total rotation cost to place elements from B into their target positions in A:

High-level flow:
1. Preprocessing:
   - Build stacks and normalize/index values when useful.
   - Keep a backbone in A and push the rest to B (heuristics may vary).
2. For each iteration while B is not empty:
   - For every node in B, compute:
     - Its target position in A
     - Rotation costs for A and for B to place it correctly
     - Combined rotation cost using shared rotations (`rr` / `rrr`) when both stacks rotate in the same direction
   - Select the cheapest node (minimal combined cost)
   - Apply the optimal rotation plan (simultaneous rotations when advantageous), then `pa`
3. Finalize:
   - Rotate A so that the smallest element ends up at the top

Data carried per node (see struct in header):
- `index`, `op_cost`, `top_stack`, `cheapest`, `target`, and links
These fields support cost modeling, choosing the “cheapest” candidate, and aligning stacks with minimal moves.

Relevant functions (from [push_swap.h](https://github.com/NukyYuki/Push_swap/blob/af4e304cf33d0e36f4651b8c4879d35ffeee9ca1/push_swap.h)):
- Turk core and preparation:
  - `ft_turk`, `prep_rot_a`, `prep_rot_b`, `prep_push_to_b`
  - `ft_rushb`, `ft_rusha` (helpers to drive rotations/pushes)
- Sorting and prep:
  - `ft_sort_checker`, `ft_sort_three`, `ft_sort_stacks`
  - `node_min`, `node_max`, `find_cheapest`, `ft_cheapest_node`

Small inputs (≤ 3, ≤ 5) are handled with dedicated optimal or near-optimal routines, while larger inputs leverage the full Turk cost model.

## Build

Typical 42 Makefile targets:
- `make` — build the program (produces `push_swap`)
- `make clean` — remove object files
- `make fclean` — remove objects and binaries
- `make re` — full rebuild

Example:
```bash
make
./push_swap 2 1 3 6 5 8
```

## Usage

Run the program with a list of integers as arguments:
```bash
./push_swap <list_of_integers>
```

Examples:
```bash
./push_swap 3 2 1
./push_swap 2 1 3 6 5 8
./push_swap "3 2 1 5 4"
```

Output:
- A sequence of operations, one per line (e.g., `pb`, `ra`, `rr`, `pa`, …)

Error handling:
- On invalid input, print `Error` to stderr and exit with a non-zero status.

## Performance notes

- The Turk method reduces total moves by combining rotations and choosing globally cheapest insertions from B to A.
- Typical evaluation thresholds set move-count targets for:
  - 100 numbers (multiple scoring tiers)
  - 500 numbers (multiple scoring tiers)
- This strategy aims for competitive counts on both sets while staying readable and maintainable.

## Code overview

Key modules (names may differ inside srcs/):
- Parsing and validation:
  - `ft_valid_numbers`, `ft_valid_list`, argument splitting, overflow/duplicate checks
- Stack and utils:
  - `t_stack` nodes, `ft_stack_init`, `add_node`, `ft_list_size`, `ft_list_last`, `ft_free_list`
  - Minimal libft helpers (`ft_split`, `ft_calloc`, `ft_substr`, `ft_memset`, `ft_strlen`, `ft_strdup`, `ft_atol`)
- Operations (all print their mnemonic when executed with the proper flag):
  - `ft_sa`, `ft_sb`, `ft_ss`, `ft_pa`, `ft_pb`
  - `ft_ra`, `ft_rb`, `ft_rr`, `ft_rra`, `ft_rrb`, `ft_rrr`
- Sorting:
  - `ft_sort_three`, `ft_sort_stacks`, `ft_sort_checker`
- Turk algorithm:
  - `ft_turk` and helpers (`prep_rot_a`, `prep_rot_b`, `prep_push_to_b`)
  - Cost-based selection: `find_cheapest`, `ft_cheapest_node`, target selection via node links

## Testing

- Edge cases:
  - Already sorted input, single element, two elements
  - Duplicates (should error), negatives, mixed ranges, extreme int values
- Random tests:
  - Generate arrays of 100–500 numbers; measure move counts
- Validation:
  - Use the 42 checker where available to verify correctness and counts

## Norminette and constraints

- Respect 42 coding style and forbidden/allowed functions
- Robust error handling and resource management (no leaks)
- Deterministic, reproducible output for a given input