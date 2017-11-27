# push_swap

The goal of the push_swap project is to write an algorithm to sort a stack of integers, using a list of operations and a second stack for temporary storage.

Since a stack is a FIFO (First-in, first-out) data structure, random access is limited, making it difficult to use most conventional sorting algorithms.

We are allowed to use these operations:

sa - swap the first two elements of the stack a  
sb - swap the first two elements of the stack b  
ss - swap the first two elements of both stacks  
pa - push an element from stack b onto stack a  
pb - push an element from stack a onto stack b  
ra - remove the top element from stack a and move it to the bottom  
rb - remove the top element from stack b and move it to the bottom   
rr - carry out both ra and rb in a single operation  
rra - remove the bottom element from stack a and push it to the top.  
rrb - remove the bottom element from stack b and push it to the top.  
rrr - carry out both rra and rrb in a single operation  

I had to write two programs for this project - a generator and a checker.

The checker takes a list of integers as command-line arguments and waits for instructions on standard input.
If the stack is fully sorted and stack b is empty when "^D" is entered, the checker outputs "OK".
If the stack is not fully sorted, the checker outputs "KO".
If the checker runs into an error of any kind - invalid input or invalid operations, for instance - the checker outputs "Error" and exits.

The generator creates a list of instructions by implementing the algorithm and printing the operations
on standard output. I use three different algorithms to sort, depending on the size of the stack.

* If the stack is 3 numbers or less, I can sort it in two moves or less - at most one swap, and at most one rotate/reverse rotate. This kind of hardcoding tends to be less useful for large stacks.
* If the stack is between 3 and 8 numbers long, I look for the minimum value in stack a and push it to stack b, until stack a has a size of 3. I then carry out the previously-mentioned sort, and pop everything from stack b back to stack a. This algorithm loses effectiveness when the stack in question has over 8 members.
* If the stack has more than 8 numbers, I look for the easiest-to-move value in stack a, based on its current position and position of the greatest value less than it in stack b. I carry out the necessary operations to get that number into place in stack b, and then pop everything from stack b when stack a is empty.
