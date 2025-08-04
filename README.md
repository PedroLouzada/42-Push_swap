# push_swap

<img src="https://miro.medium.com/v2/resize:fit:744/1*HnhUPGIafYrShJav9tkVug.png" width="600" alt="push_swap Banner" />

## About the Project

push_swap is a core project at 42 where the challenge is to sort a stack of integers using a limited set of operations — and to do it with the **least number of moves possible**. You are only allowed to use two stacks (`A` and `B`) and a handful of operations like `sa`, `pb`, `ra`, etc.

This was my **first large-scale algorithmic project**, and it turned out to be the one I had the most fun building! 🎉  
To solve it efficiently, I implemented a **Radix Sort** algorithm using **bitwise operations**, built on top of a custom **doubly linked list** structure for fast and clean manipulation of stack elements.

---

## What I Learned

- Building and managing **doubly linked lists** from scratch.
- Applying **sorting algorithms** in constrained environments.
- Designing **memory-safe data structures** with dynamic allocation in C.
- Writing **modular code** to handle parsing, validating, and simulating stack operations.
- Debugging and optimizing for **performance and move count**.
- Visualizing data structures and transformations step by step.

---

## Features Implemented

- Full implementation of the mandatory part of the project.
- Uses **Radix Sort** (base-2) for optimal sorting in minimal moves.
- Custom **double-linked list** structure for both stacks.
- Input validation and error handling.
- Efficient parsing and indexing of numbers.
- Clean and readable code organized by responsibility.

---
## Compatibility

This project was developed and tested on Linux systems. It uses only allowed C standard libraries and low-level system calls.

---

## How to Use

Clone the repository and compile using:

```bash
git clone https://github.com/YourUsername/push_swap.git
cd push_swap
make
```
Then, run the program with a list of numbers as arguments:
```bash
./push_swap 3 2 1 6 5 8
```
It will output the sequence of operations to sort the stack.
Example
```bash
$ ./push_swap 4 67 3 87 23
pb
pb
sa
ra
pa
pa
```
## Future Improvements

- Implement a visualizer for the sorting process.
- Explore other sorting strategies for small inputs (e.g. insertion sort, hardcoded for <=5).
- Add full unit tests and performance benchmarks.
- Clean handling of duplicate numbers and invalid input edge cases.

## Final Thoughts

push_swap was the turning point where things started getting really exciting at 42. It was my first big algorithmic challenge and made me fall in love with optimizing logic, memory handling, and low-level coding.

If you're starting push_swap — enjoy it! It's one of the most fun and rewarding projects you'll do. 💡💻

## Contact
Feel free to reach out:

[Github](https://github.com/PedroLouzada)
