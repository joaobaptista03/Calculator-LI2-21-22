# Stack-Based Language Interpreter

## Overview
This university project implements a stack-based language interpreter in C. It's designed to read and execute a series of operations on a stack, handling various data types and operations including mathematical calculations, logical operations, stack manipulations, variable handling, and more.

## Features
- **Custom Stack Implementation**: Handles a stack data structure for storing and manipulating data.
- **Versatile Operations**: Supports a wide range of operations, including arithmetic, logical, stack manipulation, type conversions, and variable assignments.
- **Dynamic Input Handling**: Reads and processes input dynamically, supporting operations defined in an intuitive shorthand notation.

## Getting Started

### Prerequisites
- GCC Compiler
- Standard C Library

### Compilation
Navigate to the project directory and use the following GCC command to compile the project:

```
gcc -Wall -Wextra -pedantic-errors -O2 *.c -lm
```

### Execution
```
./a.out
```

## Project Structure
- **main.c**: The main entry point of the program. It handles input reading, token parsing, and orchestration of operations.
- **stack.c**: Implements the stack data structure and basic stack operations.
- **val_handle.c**: Contains functions for value handling and operation execution based on tokens.
- **math_operations.c**: Defines mathematical operations.
- **logical_operations.c**: Handles logical operations like AND, OR, NOT.
- **stack_manipulation.c**: Includes functions for stack manipulation such as push, pop, and rotate.
- **variables.c**: Manages variable storage and retrieval.
- **arraysstrings.c**: Functions related to array and string operations.
- **conversions.c**: Handles type conversion operations.
- **input_output.c**: Manages input/output related operations.
- **random_funcs.c**: Utility functions used across the project.
