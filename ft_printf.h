#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int     ft_putnbr(long nb);
int 	ft_putunbr(unsigned nb);
int		ft_putnbr_base(unsigned long nb, char *base);
int		ft_putptr(void *ptr);

#endif