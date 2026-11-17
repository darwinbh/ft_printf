#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
   va_list  args;
    int     size;
    int     n;

    size = 0;
   va_start(args, format);
  while(*format)
  {
    if (*format == '%')
    {
        format++;
        if (*format == 'd' || *format == 'i')
        {
            size += ft_putnbr(va_arg(args, int));
            format++;
        }
         else if (*format == 's')
        {
            size += ft_putstr(va_arg(args, char *));
            format++;
        }
         else if (*format == 'c')
        {
            size += ft_putchar(va_arg(args, int));
            format++;
        }
         else if (*format == 'u')
        {
            size += ft_putunbr(va_arg(args, unsigned long));
            format++;
        }
         else if (*format == 'x')
        {
            size += ft_putnbr_base(va_arg(args, long),"0123456789abcdef");
            format++;
        }
         else if (*format == 'X')
        {
            size += ft_putnbr_base(va_arg(args, long),"0123456789ABCDEF");
            format++;
        }
         else if (*format == 'p')
        {
            size += ft_putptr(va_arg(args, void *));
            format++;
        }
         else if (*format == '%')
        {
            size += write(1, format, 1);
            format++;
        }
    }
    else
    {
        n = write(1, format, 1);
        if (n < 0)
            return(-1);
        size -= n;
        format++;
    }
  }

   va_end(args);
   return (size);
}
