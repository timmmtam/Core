_This project has been created as part of the 42 curriculum by timtan._

# push_swap

## Description

**push_swap** is a highly efficient sorting algorithm project that challenges you to sort data on a stack, with a limited set of instructions, using the lowest possible number of actions.

The goal is to sort a set of integers received as arguments into a stack named `a`. To do this, you have access to a second empty stack `b` and a specific set of operations to manipulate these stacks.

**Key Technical Concepts:**
* **Sorting Algorithms:** Implementation of custom sorting logic (e.g., Radix Sort, Quick Sort or Insertion/ Selection Sort) optimized for operation count rather than just time complexity. The algorithm used in this project is a hybrid of the insertion and selection sort where it selects the node with the least amount of moves (rather than smallest number) and inserts it at the correct position.
* **Data Structures:**
    * **Circular Doubly Linked Lists:** Used to implement the stacks, allowing for efficient access to both ends of the stack (head and tail) and easy rotation.
    * **Integer Arrays:** Utilized for encoding and decoding instruction sets.
* **Complexity Analysis:** Focusing on algorithmic efficiency to meet strict operation limits for large datasets (e.g., 100 or 500 numbers).

### The Operations
The project allows only the following moves:
* **sa/sb/ss:** Swap the first 2 elements at the top of stack `a`, `b`, or both.
* **pa/pb:** Push the top element of one stack to the top of the other.
* **ra/rb/rr:** Rotate all elements of stack `a`, `b`, or both up by one.
* **rra/rrb/rrr:** Reverse rotate all elements of stack `a`, `b`, or both down by one.

## Instructions

### Installation
To install the program, `git clone` this git repository in a directory.

### Compilation
To compile the executable, run the following command in the root directory:

```
make
```

To use the checker (bonus), run the following command in the root directory:

```
make bonus
```

### Execution
Run the program by passing a list of integers as arguments. The program will output the list of operations required to sort the numbers.

```
./push_swap 2 1 3 6 5 8
```

Example Output:
```
sa
pb
pb
pb
sa
pa
pa
pa
```

To use the checker, run the checker executable by passing a list of integers as arguments.
```
./checker 2 1 3 6 5 8
```

The program will then wait for instructions from the user. Type each instruction followed by a newline (`ENTER`).

To mark the end of the instructions given, press `Ctrl+D`.

The program will print `KO` if the stack is not sorted and `OK` if the stack is sorted.

### Cleanup
To destroy just the object files, run this command in the root directory:
```
make clean
```

To destroy the object files **and** the executable, run this command in the root directory:
```
make fclean
```

### Error Handling
The program handles various error cases gracefully, returning "Error" followed by a newline if:
* Arguments contain non-numeric characters.
* Arguments exceed integer limits.
* There are duplicate numbers.

## Resources

### References
[**Project Explanation by Jamie Dawson**](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)

### AI Usage
_This project utilized Artificial Intelligence tools for the following tasks:_
* **Conceptual Understanding:** Used AI to explain the mechanics of Circular Doubly Linked Lists and how to handle the "tail" pointer during rotation operations.
* **Debugging:** Used AI to analyze specific segmentation faults related to pointer mismanagement in the linked list implementation.
* **Documentation:** Generated the template and structure for this `README.md` file.
