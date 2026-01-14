*This project has been created as part of the 42 curriculum by luccribe.*

# Introduction
This project aims to recreate the printf C function. Although it isn't a perfect \
copy, it behaves very similarly to the original. It is an useful addition to my \
libft library. In case you don't know the prinft function, it is used to print messages \
to the terminal. That's an oversimplification, but it is heavily used for debugging code. \
(e.g.: You can use it to print the current value of a variable to check if it's the \
expected value or not)

# Learning curve
The most important knowledge that had to be mastered in order the complete this project \
was the use of Variadic Functions. Which are functions that can take a variable number \
of arguments. Printf is one of them hence why it was necessary to master them. \
Besides that, most of the project is If statements and handling each possible case.

# Resources
https://www.geeksforgeeks.org/c/variadic-functions-in-c/ \
https://www.geeksforgeeks.org/c/format-specifiers-in-c/ \

# How to run it
In case you want to test it yourself, here is a main.c file for compilation.

<details>
<summary>Click to expand main.c</summary>

```c
#include "ft_printf.h"

int  main (void)
{
  ft_printf("message");
}
```
</details>

Instructions for compilation:
1. Git clone the repository and `cd` to it's folder.
2. run `make` command to compile everything.
3. Create a main.c file and paste the code provided above in it.
4. run `gcc main.c libftprintf.a -o my_program`.
5. run `./my_program`.
You'll see the output in the terminal.
Remember, if you want to test it with different messages passed to the \
printf function than the one in the main.c code I provided all you got to do \
is change the `ft_printf("message");` line. \
e.g: `ft_printf("My message is: %s", string_variable)`. \
This will print "My message is" and the value assigned to `string_variable`.

# Chosen algorithm
I followed a simple workflow with this one. In my main function I called an auxiliary \
function called `print_loop` which is responsible for printing the message passed as \
an argument and identifying the *format specifier*. If it finds it, it calls the \
`switch_statement`, a function filled with If statements designed to handle each \
format specifier, in other words, each case.
