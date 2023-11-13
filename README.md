# BrainFuckPlusPlus
A C++ BrainFuck compiler and some additional function to form BrainFuck++
## Introduction

## About Brain Fuck

**Brainfuck** is an **esoteric programming language** created in 1993 by Urban Müller¹. It is notable for its extreme minimalism, consisting of only eight simple commands, a data pointer, and an instruction pointer¹. The language is fully Turing complete, but it is not intended for practical use. Instead, it is designed to challenge and amuse programmers¹. 

The language's name is a reference to the slang term "brain fuck," which refers to things so complicated or unusual that they exceed the limits of one's understanding¹. Brainfuck requires one to break commands into microscopic steps¹. 

The language consists of eight commands. A brainfuck program is a sequence of these commands, possibly interspersed with other characters (which are ignored)¹. The commands are executed sequentially, with some exceptions: an instruction pointer begins at the first command, and each command it points to is executed, after which it normally moves forward to the next command¹. The program terminates when the instruction pointer moves past the last command¹.

Here are the eight commands in Brainfuck:

| **Command** | **Description** |
|-------------|-----------------|
| `>`         | Move the data pointer to the right |
| `<`         | Move the data pointer to the left |
| `+`         | Increment the value at the data pointer |
| `-`         | Decrement the value at the data pointer |
| `.`         | Output the value at the data pointer |
| `,`         | Input a value and store it at the data pointer |
| `[`         | Jump past the matching `]` if the value at the data pointer is zero |
| `]`         | Jump back to the matching `[` if the value at the data pointer is nonzero |

Brainfuck is not a commonly used programming language, but it is an interesting example of a Turing-complete language that can be used to explore the fundamentals of computer programming¹.

(1) Brainfuck - Wikipedia. https://en.wikipedia.org/wiki/Brainfuck.
(2) brainfuck – Wikipédia, a enciclopédia livre. https://pt.wikipedia.org/wiki/Brainfuck.
(3) brainfuck - Esolang. https://esolangs.org/wiki/Brainfuck.
(4) Welcome - Getting started with BrainFuck - CodinGame. https://www.codingame.com/playgrounds/50426/getting-started-with-brainfuck/welcome.

## About This Brain Fuck Plus Plus

