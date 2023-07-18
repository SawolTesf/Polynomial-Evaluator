# Polynomial Evaluator

This C++ program reads a file containing polynomial expressions, stores them in a linked list, and evaluates them at a given value of x.

## Why Use This Program

This program can be useful for anyone who needs to quickly evaluate multiple polynomial expressions at a specific value of x. It can save time and reduce the risk of errors compared to manual calculations.

## How It Works

The program reads a file containing polynomial expressions in the format `f(x) = expression`. Each expression is stored in a linked list, where each node represents a term in the polynomial. The program then evaluates each expression at the given value of x using the `evaluate` function, which calculates the result by iterating through the linked list and summing the result of each term.

## Getting Started

### Prerequisites

- C++ compiler

### Usage

1. Compile the program using your preferred C++ compiler.
2. Run the program and enter the filename containing the polynomial expressions when prompted.
3. The program will output the evaluated result of each expression.

## License

This project is licensed under the MIT License.
