# monty
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.
### Compilation
* Your code will be compiled this way:
```
$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty
```
* Any output will be printed on `stdout`.
* Any error message will be printed on `stderr`.
### Monty Byte Code Files
Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:
```
Timmy@ubuntu:~/0x18-stacks_queues_lifo_fifo$ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
Timmy@ubuntu:~/0x18-stacks_queues_lifo_fifo$
```
Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:
```
Timmy@ubuntu:~/0x18-stacks_queues_lifo_fifo$ cat -e bytecodes/001.m
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
pall This is the end of our program. Monty is awesome!$
Timmy@ubuntu:~/0x18-stacks_queues_lifo_fifo$
```
### The monty program
* Usage: `monty file`
  * where `file` is the path to the file containing Monty byte code.
* If the user does not give any file or more than one argument to your program, print the error message `USAGE: monty file`, followed by a new line, and exit with the status `EXIT_FAILURE`.
* If, for any reason, it’s not possible to open the file, print the error message `Error: Can't open file <file>`, followed by a new line, and exit with the status `EXIT_FAILURE`.
  * where `<file>` is the name of the file.
* If the file contains an invalid instruction, print the error message `L<line_number>: unknown instruction <opcode>`, followed by a new line, and exit with the status `EXIT_FAILURE`.
  * where `<line_number>` the line number where the instruction appears.
  * Line numbers always start at 1.
* The monty program runs the bytecodes line by line and stop if either:
  * it executed properly every line of the file.
  * it finds an error in the file.
  * an error occured.
* If you can’t malloc anymore, print the error message `Error: malloc failed`, followed by a new line, and exit with status `EXIT_FAILURE`.
### Output
Here are some examples of the output for th opcodes used.

**The push opcode**
The opcode `push` pushes an element to the stack.
* Usage: `push <int>`.
  * where `<int>` is an integer.

**The pall opcode**
The opcode `pall` prints all the values on the stack, starting from the top of the stack.
* Usage `pall`.
* Format: see example.
* If the stack is empty, don’t print anything.

```
Timmy@ubuntu:~/0x18-stacks_queues_lifo_fifo$ cat -e bytecodes/00.m
push 1$
push 2$
push 3$
pall$
Timmy@ubuntu:~/0x18-stacks_queues_lifo_fifo$ ./monty bytecodes/00.m
3
2
1
Timmy@ubuntu:~/0x18-stacks_queues_lifo_fifo$
```

**The add opcode**
The opcode `add` adds the top two elements of the stack.
* Usage: `add`
* The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
  * The top element of the stack contains the result.
  * The stack is one element shorter.
```
Timmy@ubuntu:~/0x18-stacks_queues_lifo_fifo$ cat bytecodes/12.m
push 1
push 2
push 3
pall
add
pall

Timmy@ubuntu:~/0x18-stacks_queues_lifo_fifo$ ./monty bytecodes/12.m
3
2
1
5
1
Timmy@ubuntu:~/0x18-stacks_queues_lifo_fifo$
```

### About
All files were created and compiled on `Ubuntu 14.04.4 LTS` using `GCC 4.8.4`

### Authors
- **Jun Zhu** - [VieetBubbles](https://github.com/VieetBubbles)
- **Marc Cavigli** - [MCavigli](https://github.com/MCavigli)