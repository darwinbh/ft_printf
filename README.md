*This project has been created as part of the 42 curriculum by bbaha.*

# ft_printf

## Description

ft_printf is a re-implementation of the C library function `printf()`, built as a static library (`libftprintf.a`).

The goal of the project is to learn how variadic functions work in C (`<stdarg.h>`) and how to turn a format string into formatted output using only `write`.

The prototype is:

```c
int ft_printf(const char *format, ...);
```

It returns the number of characters printed, or `-1` if a `write` fails, like the original `printf()`.

### Supported conversions

| Conversion | Output |
|---|---|
| `%c` | a single character |
| `%s` | a string (`(null)` if the pointer is `NULL`) |
| `%p` | a pointer in hexadecimal, prefixed by `0x` (`(nil)` if `NULL`) |
| `%d` | a signed decimal number |
| `%i` | a signed integer in base 10 |
| `%u` | an unsigned decimal number |
| `%x` | a number in lowercase hexadecimal |
| `%X` | a number in uppercase hexadecimal |
| `%%` | a percent sign |

As required by the subject, the buffer management of the original `printf()` is not implemented: output is written directly with `write`.

## Instructions

### Compilation

```
make
```

This builds `libftprintf.a` at the root of the repository, using `cc -Wall -Wextra -Werror` and the `ar` command.

| Rule | Effect |
|---|---|
| `make` / `make all` | builds `libftprintf.a` |
| `make clean` | removes the object files |
| `make fclean` | removes the object files and `libftprintf.a` |
| `make re` | rebuilds everything from scratch |

### Usage

Include the header and link against the library:

```c
#include "ft_printf.h"

int main(void)
{
	ft_printf("Hello %s, you are %d years old\n", "world", 42);
	return (0);
}
```

```
cc main.c libftprintf.a -o app
```

## Algorithm and structure

- `ft_printf` initializes a `va_list` with `va_start`, then walks through the format string one character at a time.
- A normal character is written directly with `write`.
- A `%` means that the next character selects a conversion. A dispatcher reads the matching argument with `va_arg`, once per conversion, using the type that conversion requires, and calls the right helper.
- Every helper returns the number of characters it wrote, or `-1` on error. `ft_printf` adds these values to a running total and stops immediately, after calling `va_end`, if one of them is negative.
- Numbers are printed by a recursive function that takes the value and the base (as a string of digits), so `%u`, `%x`, `%X` and `%p` all share the same code. The recursion prints the higher digits first, which keeps the digits in the correct order without any buffer or `malloc`.
- Signed numbers are handled by printing the sign first and passing the absolute value as an unsigned number, which also covers `INT_MIN`.

### Files

| File | Content |
|---|---|
| `ft_printf.h` | prototypes and includes |
| `ft_printf.c` | the format loop and the dispatcher |
| `ft_print_csi.c` | helpers for `%c`, `%s` and the signed/unsigned integers |
| `ft_print_xp.c` | helpers for `%x`, `%X` and `%p` |
| `Makefile` | build rules |

## Testing

The function was compared against the original `printf()` on both the printed output and the return value, including these edge cases: `NULL` strings and pointers, `'\0'`, `INT_MIN`, `INT_MAX`, `UINT_MAX`, `-1` for `%u` and `%x`, `ULONG_MAX` as a pointer, and several conversions side by side with no separator (`%c%c%c`, `%d%d`).

## Resources

- `man 3 printf`, `man 3 stdarg`, `man 2 write`
- The C standard documentation for `<stdarg.h>`
- 42 peer-to-peer learning and evaluations
