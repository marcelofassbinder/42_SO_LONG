# 42_SO_LONG 🕹️
A 2D game developed in C and Minilibx (a minimal X-Window library) to handle graphics and inputs.
# About ✍
So_long consists in creating a 2 dimensional game, where the player must collect every collectible present on the map and reach the exit. To achieve that, the player is able to move in 4 directions, up, down, right and left, by pressing W, S, D and A, respectively. To develop this project, I utilized the Minilibx, which is the official graphics library of 42 School. The Minilibx provides essential tools for opening windows, creating images, and handling keyboard and mouse events.

- `sa` (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
- `sb` (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
- `ss` : sa and sb at the same time.
- `pa` (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
- `pb` (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
- `ra` (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
- `rb` (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
- `rr` : ra and rb at the same time.
- `rra` (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
- `rrb` (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
- `rrr` : rra and rrb at the same time.
#  Walkthrough 🧩
- Error Management: The program should only accept parameters within the range of integers from the minimum to the maximum. Anything different from that it will prompt the message ``Error``, followed by a new line, and then finish the program. If no parameters are specified or the numbers provided are already sorted, the program must not display anything and give the prompt back.
- Creating the stacks: I implemented the stacks using singly linked lists, where each node incorporates the following: the value itself, index, and cost (all integers); previous, next, and target nodes (pointers); and a boolean indicating whether the index was above the median element.
- Developing the operations: Each operation is meticulously designed to perform specific tasks such as swapping elements, pushing elements between stacks, and rotating elements within a stack. This phase was pivotal to the project serving as a valuable learning experience in effectively managing linked lists and contributing to my understanding of data structure manipulation.
- Sorting two elements: When only two integers are passed as arguments, the program will apply ``sa``(swap a) operation to rectify the order.
- Sorting three elements: When only three integers are provided, a three-step process is followed. First, if the largest number is at the top, the program executes ``ra`` (rotate a) operation. Alternatively, if the largest number is in the second position, ``rra`` (reverse rotate a) operation is applied. Following these rotations, if the first element remains greater than the second, ``sa`` (swap a) operation is executed to achieve the sorting.
- Sorting more than three elements: When dealing with more than three integers, the program applies the Turk Algorithm, as described below.
# Turk Algorithm ⚙️
The Turk Algorithm was developed by another 42 student called [Ali Ogun](https://github.com/ayogun) and it is detailed in his article ["Push Swap — A journey to find most efficient sorting algorithm"](https://medium.com/@ayogun/push-swap-c1f5d2d41e97). Essentially, the algorithm functions when we have more than 3 numbers as arguments. We begin by pushing the numbers from ``stack_a`` a to ``stack_b`` until only 3 elements remain in ``stack_a``. However, we do this in descending order because later we will need to push the numbers back to ``stack_a``, and they will be automatically organized.

To achieve this efficiently, we define a target node in ``stack_b`` for every node in ``stack_a``, which will be the smallest and closest number to the node in ``stack_a`` present in ``stack_b``. If a smaller number does not exist, the target will become the highest element in ``stack_b``. After that, we calculate the "cost" of each node to be pushed to the right index in ``stack_b``. Finally, we choose the cheapest node, rotate the stack to bring the node to the top (if needed), and then push it.

When only three elements are left in ``stack_a``, we begin pushing the numbers back from ``stack_b`` in a similar manner. However, the target node now becomes the highest and closest number in ``stack_a``. In case a higher number does not exist, the smallest element in ``stack_b`` will then become the target.

Finally, after pushing all the elements from ``stack_b``, if necessary, we organize ``stack_a`` by rotating it until the smallest number is at the top. This ensures that all elements are sorted in ascending order, concluding the program.

# Bonus ⭐
For the bonus section, we were required to develop a program called "checker". Similar to the push_swap program, checker takes a list of integers as arguments and forms a stack with those numbers. Afterward, the program awaits instructions that will be provided on the standard input. Once all the operations are inputted, the program read line by line, employing the [get_next_line](https://github.com/marcelofassbinder/42_GET_NEXT_LINE) function, and proceeds to execute the operations on the stack.

After performing the provided instructions, if ``stack a`` is sorted, and ``stack b`` is empty, the program displays ``OK`` followed by a new line. In any other scenario, the checker outputs ``KO`` followed by a new line. If an error occurs, the program follows the same behavior as push_swap, printing ``Error`` and a new line.

# Usage 🖥️
To install and use push_swap, follow these steps:
- Clone the repository:
```bash
git clone git@github.com:marcelofassbinder/42_PUSH_SWAP.git
```
- Navigate to the project directory and run ``make`` to compile the program:
```bash
cd 42_PUSH_SWAP
make
```
- Run the program providing a list of integers, for example:
```bash
./push_swap 42 24 -6 8 -50
```
- The program will output the operations applied to sort the given numbers, for example:
```bash
pb
pb
rra
pa
ra
pa
ra
```
- To use the checker, do:
```bash
make bonus
```
- Run the program, passing a list of integers as arguments, for example:
```bash
./checker 7 -12 35 42
```
- Now, give the instructions you think will sort the numbers, and press Ctrl + D to finish. For example:
 ```bash
 pb
rra
rra
pa
ra
ra
ra
```
If the operations sorted the stack, checker will print ``OK``. Otherwise ``KO``, and in case of error, ``Error``.

# Grade  <p><img height="30px" src="https://img.shields.io/badge/-125%20%2F%20100-success" /></p>

# Norminette 💂🏻
At 42 School, we need to follow some strict rules when writing our code. These rules are described in the Norm and checked by the formidable `norminette`. Here are some of them:
```
- No for, do...while, switch, case, goto, ternary operators and variable-length arrays are allowed
- Each function must be maximum 25 lines
- One single variable declaration per line
- You can’t declare more than 5 variables per function
- You can't write more than 5 functions per file
...
```
[Click here](https://github.com/42School/norminette/blob/master/pdf/en.norm.pdf) to review the complete Norm document.
