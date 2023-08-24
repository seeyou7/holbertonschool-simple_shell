<p align="center">

</p>

<h1> C - Simple Shell</h1></p>

<h2> Context of the project</h2></p>

"simple shell" is an Holberton School project which aims to create a minimalist shell in the C language. It involves several phases, starting with the development of a basic shell that can execute commands and handle input and output.
This program gives to the user a prompt "top_shell>>", accepts and executes the input command.


<h3> Process description</h3></p>

Here's a brief description of how the shell works:

1. **Parent Process Creation:**
   When the user runs the program, the parent process is created.

2. **Terminal Check:**
   The `isatty()` function is used with the `STDIN_FILENO` file descriptor (fd) to test if there is an open file descriptor referring to a terminal. If `isatty()` returns 1, the prompt is shown using `write()` with `STDOUT_FILENO` as fd, and the program waits for user input.

3. **Command Parsing:**
   When the user types a command, the `getline()` function reads the entire line from the stream, and the `strtok()` function breaks the input command into a sequence of non-empty tokens.

4. **Child Process Creation:**
   A separate child process is created using `fork()` to execute the inputted command. Unless specified otherwise, the parent process waits for the child to exit before continuing.

5. **Command Execution:**
   After tokenizing the command, the `execve()` function is used to bring and execute it. Once executed, the program frees all allocated memory using `free()`.

6. **Return to Main Process:**
   Finally, the program returns to the main process. It prints the prompt and waits for another user input.

<h3> Compiling, Debugging and Runing</h3>

Program and all functions will be compiled with:

gcc -Wall -Wextra -Werror -pedantic -Wno-format -g *.c -o hsh

for debugging the shell, we used valgrind:

valgrind --leak-check=full ./hsh

Or just run and try this shell using:
./hsh

<h3> Top Shell Flowchart</h3>


![Shell Flowchart](https://github.com/seeyou7/holbertonschool-simple_shell/blob/master/flowchart%20simple%20shell.drawio.png)
<h3>Authors</h3>

Aicha CHOUIKHI - [@aicha-ch](https://github.com/aicha-ch)

Younes SABER - [@seeyou7](https://github.com/seeyou7) 
