*This project has been created as part of the 42 curriculum by didias-d.*

# ft_printf

## Description

ft_printf is a project from the 42 curriculum whose goal is to create a personal 
reimplementation of the famous standard C library printf function.

The function handles string parsing and formats output data using variadic arguments, 
mimicking the behavior of the original printf.

The purpose of this project is to better understand variadic functions in C, explore 
numerical base conversions, and create a reusable printing tool for future 42 projects.

## Technical Choices: Algorithm & Data Structure

### Data Structure
The project relies entirely on the `va_list` structure from the `<stdarg.h>` header.
- **Justification:** The C language stores variadic parameters sequentially on the execution stack. The `va_list` acts as a type-safe context pointer that allows the program to safely extract variables of the correct type during parsing, avoiding unstable manual pointer arithmetic.

### Algorithm and Architecture
The logic of this project implements a single-token linear parsing approach combined with a recursive strategy for numerical conversions:
- **Linear Parsing (`ft_printf`):** The format string is read character by character. As long as no `%` symbol is found, the current character is written directly to the standard output.
- **Centralized Routing (`ft_checker`):** When a `%` symbol is detected, the algorithm examines the immediate next character. A conditional routing structure acts as a lookup table to extract the argument from the `va_list` with the appropriate type and delegates the display logic.
- **Recursive Base Conversion (`ft_putnbr_fd`, `ft_hex`, `ft_hex_ptr`):** Number conversions (decimal and hexadecimal) use recursive algorithms by successive division. This processes digits from the most significant to the least significant by leveraging the system execution stack, eliminating the need to allocate a temporary string buffer.
- **Return Tracking:** Every sub-function calculates and returns the exact number of bytes it successfully wrote using the `write` system call, ensuring a correct total return value.

## Instructions

To compile the library, run:

make

This creates the static library:

libftprintf.a

Other available commands:

make clean
make fclean
make re

To use the library in another C program, include the header:

#include "ft_printf.h"

and compile your program with libftprintf.a.

Example:

cc main.c libftprintf.a -o program

### Supported conversions

Format specifiers managed by the function and their behavior:

- %c : Prints a single character
- %s : Prints a string of characters
- %p : Prints a pointer address in hexadecimal format
- %d : Prints a signed decimal integer
- %i : Prints a signed integer in base 10
- %u : Prints an unsigned decimal integer
- %x : Prints a hexadecimal number in lowercase
- %X : Prints a hexadecimal number in uppercase
- %% : Prints a literal percent sign

## Resources

Resources used to understand the C standard library functions and their
behavior:

- C manual pages (`man`)
- 42 ft_printf subject
- C documentation
- AI tools: used for markdown structuring, formatting requirements, and writing technical explanations based on the student's implementation.
