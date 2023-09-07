# C - Stacks, Queues

> This directory contains all the tasks of the project "C - Stacks, Queues - LIFO, FIFO" at [Holberton School](https://www.holbertonschool.com "Holberton School.")

## Table of Contents

- [Description](#description)
- [Opcodes](#opcodes)
- [Respository Files Description](#repository-files-description)
- [Usage Examples](#usage-examples)
- [Getting Started](#getting-started)
- [Prerequisits](#prerequisits)
- [Built With - Compilation](#built-with---compilation)
- [Authors](#authors)
- [License](#license)
- [Acknowledgments](#Acknowledgments)

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

## Getting Started

Clone this repository to get all the files you need to run this version of "monty" on your machine. Each part needed to make this interpreter works is in a single and a separete file, so you can connect and trace all the steps of the function and you can make your own changes and upgrades.

## Prerequisites

This program was made and tested using Ubuntu 14.04.3 LTS and compiled with gcc 4.8.4. We recommend you to test this interpreter under this conditions.

## Built With - Compilation

* Ubuntu 14.04.3 LTS Running on a Virtual Machine "Vagrant"
* gcc 4.8.4 Compiled with the flags: `-Wall -Werror -Wextra -pedantic *.c -o monty`
* GNU Emacs 24.3.1


# AUTHORS

* **Silvi Marku** - https://github.com/SilviMarku
* **Ersida Karaj** -https://github.com/Holberton1990

## License

Opensource project.

## Acknowledgments

* Project made at Holberton School.
