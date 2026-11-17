#include "ft_printf.h"

int	len(char *base)
{
	if (*base)
		return (len(++base) + 1);
	return (0);
}

int	ft_putnbr_base(unsigned long nb, char *base)
{ 
	int     bs;
	int     size;
	int     n;

	bs = len(base);
	size = 1;
	if ((unsigned long)bs <= nb)
	{
		size = 1 + ft_putnbr_base(nb / bs, base);
		if (size <= 0)
			return (-1);
	}

	n = ft_putchar(base[nb % bs]);
			if (n < 0)
				return (-1);
	return (size);
}

int	ft_putptr(void *ptr)
{
	int size;
	size = 0;
	if (!ptr)
		return (ft_putstr("(nil)"));
	size += ft_putstr("0x");
	if (size <= 0)
		return (-1);
	size += ft_putnbr_base((unsigned long)ptr, "0123456789abcdef");
	if (size <= 2)
		return (-1);
	return (size);
}
