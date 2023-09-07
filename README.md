# C - Stacks, Queues

> This directory contains all the tasks of the project "C - Stacks, Queues - LIFO, FIFO" at [Holberton School](https://www.holbertonschool.com "Holberton School.")

## Table of Contents

- [Stacks](#stacks)
- [Queues](#Queues)
- [Description](#description)
- [Opcodes](#opcodes)
- [Respository Files Description](#repository-files-description)
- [Usage Examples](#usage-examples)
- [Built With - Compilation](#built-with---compilation)
- [Usage](#Usage)
- [Authors](#authors)
- [License](#license)
- [Acknowledgments](#Acknowledgments)

### Stacks
A stack is one of the simplest data structures. It is just like a pile of playing cards or a stack of plates. When you add something to the pile you put it on top of all the things that are already there. When you take something away you remove it from the top of the stack. Computer Science uses specialized terms for things like this though. So instead of add we say push, and instead of remove we say pop. Another term you may hear with regards to stacks is LIFO which stands for Last In First Out. With a stack the last thing you added in the first thing that is removed.

##### Stack Push
<img src="http://www.thagomizer.com/img/StackPush.gif">

##### Stack Pop
<img src="http://www.thagomizer.com/img/StackPop.gif">

### Queues
A queue is an ordered collection (or group) where we add things to one end (called the tail) and we remove things from the other end (called the head). Adding things to a queue is called enqueueing. Removing items from a queue is called dequeueing. This is also called FIFO for first in, first out.

##### Queue Add
<img src="http://www.thagomizer.com/img/QueueAdd.gif">

##### Queue Remove
<img src="http://www.thagomizer.com/img/QueueRemove.gif">


## Description

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

Our **monty** works as a interpreter for Monty ByteCodes files. Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:
```
julien@ubuntu:~/monty$ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
julien@ubuntu:~/monty$

```
Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:
```
julien@ubuntu:~/monty$ cat -e bytecodes/001.m
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
julien@ubuntu:~/monty$
```

# Opcodes

| **opcode** | **Description** |
|----------|-----------------|
| <ul><li>[x] push</li></ul> | Pushes an element to the stack. |
| <ul><li>[x] pall</li></ul> | Prints all the values on the stack, starting from the top of the stack. |
| <ul><li>[x] pint</li></ul> | Prints the value at the top of the stack, followed by a new line. |
| <ul><li>[x] pop</li></ul> | Removes the top element of the stack. |
| <ul><li>[x] swap</li></ul> | Swaps the top two elements of the stack. |
| <ul><li>[x] add</li></ul> | Adds the top two elements of the stack. |
| <ul><li>[x] nop</li></ul> | Doesn\'t do anything. |
| <ul><li>[x] sub</li></ul> | Subtracts the top element of the stack from the second top element of the stack. |
| <ul><li>[x] div</li></ul> | Divides the second top element of the stack by the top element of the stack. |
| <ul><li>[x] mul</li></ul> | Multiplies the second top element of the stack with the top element of the stack. |
| <ul><li>[x] mod</li></ul> | Computes the rest of the division of the second top element of the stack by the top element of the stack. |
| <ul><li>[x] pchar</li></ul> | Prints the char at the top of the stack, followed by a new line. |
| <ul><li>[x] pstr</li></ul> | Prints the string starting at the top of the stack, followed by a new line. |
| <ul><li>[ ] rotl</li></ul> | Rotates the stack to the top. |
| <ul><li>[ ] rotr</li></ul> | Rotates the stack to the bottom. |
| <ul><li>[ ] stack</li></ul> | Sets the format of the data to a stack (LIFO). This is the default behavior of the program. |
| <ul><li>[ ] queue</li></ul> | Sets the format of the data to a queue (FIFO). |

## Respository Files Description

| **File** | **Description** |
|----------|-----------------|
| monty.h | Header file containing all the functions prototypes, structs and standard C libraries included |
| get_operation.c | Core of the program - Handle all the conections. |
| main.c | Function that reads the standard input and stores the info. |
| stacks.c | All function |
| README.md | Readme file with all the information need to run **monty** interpreter |

## Usage Examples

### push / pall:
```
julien@ubuntu:~/monty$ cat -e bytecodes/00.m
push 1$
push 2$
push 3$
pall$
julien@ubuntu:~/monty$ ./monty bytecodes/00.m
3
2
1
user@ubuntu:~/monty$
```

### pint:
```
julien@ubuntu:~/monty$ cat bytecodes/06.m
push 1
pint
push 2
pint
push 3
pint
julien@ubuntu:~/monty$ ./monty bytecodes/06.m
1
2
3
julien@ubuntu:~/monty$
```

## Built With - Compilation


* gcc 4.8.4 Compiled with the flags: `-Wall -Werror -Wextra -pedantic *.c -o monty`

Any output will be printed on stdout. Any error message will be printed on stderr
## Usage:
```
./monty file
```


Where file is the path to the file containing Monty byte code. If the user does not give any file or more than one argument to your program, print the error message:
```
USAGE: monty file
```
Followed by a new line, and exit with the status EXIT_FAILURE. If, for any reason, it’s not possible to open the file:
```
Error: Can't open file <file>
```
Followed by a new line, and exit with the status EXIT_FAILURE, where <file> is the name of the file. If the file contains an invalid instruction:
```
L<line_number>: unknown instruction <opcode>
```
Followed by a new line, and exit with the status EXIT_FAILURE where is the line number where the instruction appears.
Line numbers always start at 1. The monty program runs the bytecodes line by line and stop if either:
1. it executed properly every line of the file
2. it finds an error in the file
3. an error occured

If you can’t malloc anymore, print the error message:
```
Error: malloc failed
```
Followed by a new line, and exit with status EXIT_FAILURE.
We used malloc and free and are not allowed to use any other function from man malloc (realloc, calloc, …)

<hr>

<h3>

# AUTHORS

* **Ersida Karaj** -https://github.com/Holberton1990
* **Silvia Marku** - https://github.com/SilviMarku


## License

Opensource project.

## Acknowledgments

* Project made at Holberton School.
