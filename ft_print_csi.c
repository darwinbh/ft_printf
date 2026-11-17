#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int ft_putstr(char *str)
{
	int	size;
	int	n;

	if (!str)
		return (write(1, "(null)", 6));
	size = 0;
	while (*str)
	{
		n = 0;
		n += ft_putchar(*str++);
		if (n == -1)
			return (n);
		size += n;
	}
	return (size);
}

int	count_nbr(long nb)
{
	if (nb < 10)
		return (1);
	return (1 + count_nbr(nb / 10));
}

int	ft_putnbr(long nb)
{
	char	c;
	int		size;

	size = 0;
	if (nb < 0)
	{
		nb = -nb;
		if (ft_putchar('-') < 0)
		return (-1);
		size++;
	}
	size += count_nbr(nb);
	if (nb > 9)
		ft_putnbr(nb / 10);
	c = nb % 10 + '0';
	if (ft_putchar(c) < 0)
		return (-1);
	return (size);
}

int	ft_putunbr(unsigned nb)
{
	char	c;
	int		size;

	size = 0;
	size += count_nbr(nb);
	if (nb > 9)
		ft_putunbr(nb / 10);
	c = nb % 10 + '0';
	if (ft_putchar(c) < 0)
		return (-1);
	return (size);
}
