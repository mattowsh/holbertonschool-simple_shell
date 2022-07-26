# <a> <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/1/18/C_Programming_Language.svg/1200px-C_Programming_Language.svg.png" width=3% heigth=3% ></img></a> Simple Shell
The **simple shell project** is the final project of the Foundations: first trimester, of the career Software Engineering at Holberton School.

To create it we apply the knowledge learnt about *C programming language*. The objetive was **generate a simplify version of the original Unix system shell**.

The authors are Mateo Gallo and Belén Matto.  
Holberton School, 2022.  

## The shell: what is?
Shell is a programm that provides a interface to the Unix system, operating like a command interpetre.

Takes the user input entered through the keyboard (in form of *standard input*), and
displays the output in the screen (like *standard output* or *standard error*, if is the case).

## Simple shell functionalities
- [x] Display a prompt and wait for the user to type a command. A command line always ends with a new line  
- [x] The prompt is displayed again each time a command has been executed  
- [x] If an executable cannot be found, print an error message and display the prompt again  
- [x] Handle errors  
- [x] Handle the “end of file” condition (Ctrl+D)  
- [x] Handle command lines with arguments  
- [x] Handle the PATH  
- [x] Handle the exit and env built-in  

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
- `strcat` (man 3 strcat)  
- `strchr` (man 3 strchr) 
- `strcmp` (man 3 strcmp)
- `strcpy` (man 3 strcpy)  
- `strdup` (man 3 strdup)  
- `strtok` (man 3 strtok)  
- `va_arg` (man 2 va_arg)  
- `va_end` (man 2 va_end)  
- `va_start` (man 2 va_start)
- `wait` (man 2 wait)  

## Files
- **`AUTHORS`** : List of contributors  
- **`man_1_simple_shell`** : Manual page of the simple shell  
- **`main.c`** : Function that contains the main code; coordinates the execution of programs and alternate between interactive and non-interactive shell modes  
- **`main_aux.c`** : File that supports the main execution. Contains the functions:
	- *main_aux_1* : Checks if we receive or not arguments
	- *main_aux0* : Checks main getline return. Case: EOF input
	- *main_aux_exit* : Handles the "exit" built it
	- *main_aux_env* : Handles the "env" built it
	- *main_aux_fork* : Creates a child process
- **`main.h`** : Header File  
- **`error.c`** : Function that creates the message error to be printed when interactive shell mode will fail  
- **`free.c`** : Function that frees memory allocated  
- **`free_grid.c`** : Frees a 2 dimensional grid, like return of set_strtok function
- **`separators.c`** : Function that checks if a char is a separator like: space, newline, tab or NULL character at the end of the string  
- **`set_strtok.c`** : Function that tokenizes a string based in separators (mentioned previously)  
- **`shellmodes.c`** : File that contains the functions  
    - *exist* : Get the status of a file, checking if a filename exists or not
- **`_which.c`** : Checks if the input is a path. If not, tokenizes PATH variable and generate differentes paths


## Usage example
Clone this repository and compile the files in the following way:

    gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

<img width="416" alt="simpleshellexample" src="https://user-images.githubusercontent.com/103126719/182978245-0edcef34-05e9-4408-be94-01edff2c7270.png">

## Flowchart
![simpleshellflowchart png](https://user-images.githubusercontent.com/103126719/183076997-63175c7e-a122-4e98-bfc1-3ac16b5288e2.png)

## Authors
[Mateo Gallo](https://www.linkedin.com/in/mateo-gallo-b46a90241/)  
[Belén Matto](https://www.linkedin.com/in/mattobelen/) 

Montevideo, Uruguay.
