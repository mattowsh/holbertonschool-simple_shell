# Simple Shell
The **simple shell project** is the final project of the Foundations: first trimester, of the career Software Engineering at Holberton School.

To create it we apply the knowledge learnt about *C programming language*. The objetive was **generate a simplify version of the original Unix system shell**.

The authors are Mateo Gallo and Belén Matto.  
Holberton School, 2022.  
Montevideo, Uruguay.

## The shell: what is?
Shell is a programm that provides a interface to the Unix system, operating like a command interpetre.

Takes the user input entered through the keyboard (in form of *standard input*), and
displays the output in the screen (like *standard output* or *standard error*, if is the case).

## Simple shell functionalities
>>>LUEGO CUANDO TENGAMOS CHECKER OK<<

## Functions and system calls used
- `close` (man 2 close)  
- `execve` (man 2 execve)  
- `exit` (man 3 exit)  
- `fork` (man 2 fork)  
- `free` (man 3 free)  
- `getline` (man 3 getline)   
- `isatty` (man 3 isatty)  
- `malloc` (man 3 malloc)  
- `open` (man 2 open)  
- `perror` (man 3 perror)  
- `stat` (__xstat) (man 2 stat)  
- `strtok` (man 3 strtok)  
- `wait` (man 2 wait)  

## Files
- **`AUTHORS`** : List of contributors  
- **`man_1_simple_shell`** : Manual page of the simple shell  
- **`main.c`** : Function that contains the main code; coordinates the execution of programs and alternate between interactive and non-interactive shell modes  
- **`main.h`** : Header File  
- **`error.c`** : Function that creates the message error to be printed when interactive shell mode will fail  
- **`free.c`** : Function that frees memory allocated  
- **`separators.c`** : Function that checks if a char is a separator like: space, newline, tab or NULL character at the end of the string  
- **`set_strtok.c`** : Function that tokenizes a string based in separators (mentioned previously)  
- **`shellmodes.c`** : File that contains the functions  
    - *exit* : Get the status of a file, checking if a filename exists or not
    - *non_interactive* : Executes the non-interactive shell mode from child process
    - *interactive* : Executes the interactive shell mode from child process

## Usage example
Clone this repository and compile the files in the following way:

    gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

>>>ADD IMAGE<<

## Flowchart
>>>AÑADIR LUEGO<<
## Authors
[Mateo Gallo](link de linkedin)  
[Belén Matto](https://www.linkedin.com/in/mattobelen/)

Flowdchart
==========

```mermaid
graph TD;
  Start0(Shell starts)
  Start0-->While0{Continue if it's interactive mode}
  While0-->If0{Is it interactive<br>mode?}
  While0-->Exit1(End non<br>interactive<br>mode)
  If0-->Getline[Read input]
  Getline-->Fork0[Create a<br>child process]
  Fork0-->|Input is equal to exit|Exit0(Exit shell)
  Fork0-->Fork1{Check if it's<br>parent or<br>child}
  Fork1-->|Child|Execve[Execute<br>requested<br>command]
  Fork1-->|Parent|Wait[Wait for<br>child to<br>finish]
  Execve-->|Finish process|Wait
  Wait-->While0
  ```
