/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 17:20:35 by apico-su          #+#    #+#             */
/*   Updated: 2022/03/01 21:03:28 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print	initialise(t_print *src)
{
	src->width = 0;
	src->precision = 0;
	src->padd = 0;
	src->point = 0;
	src->minus_sign = 0;
	src->length = 0;
	src->minus = 0;
	src->zero = 0;
	src->percent = 0;
	src->space = 0;
}

void	dectohex(size_t nbr, int count)
{
	if (nbr / 16 > 16)
		count = nbr_hexa(nbr / 16, count);
	else if (nbr / 16 < 10)
	{
		ft_putchar_fd('0' + (nbr / 16), 1);
		count++;
	}
	else if (nbr / 6 > 0)
	{
		ft_putchar_fd('a' - 10 + (nbr / 16), 1);
		count++;
	}
	if (nbr % 16 < 10)
	{
		ft_putchar_fd('0' + (nbr % 16), 1);
		count++;
	}
	else if (nbr % 6 < 16)
	{
		ft_putchar_fd('a' - 10 + (nbr % 16), 1);
		count++;
	}
	return (count);
}

static void	stringfunct(t_print *save)
{}

static void decifunct(t_print *save)
{}

static void	pointfunct(t_print *save)
{
	int	address;

	nbr_hexa(address, 0);
}

static void	numhex(t_print *save, char caps)
{}

int format_conversion(t_print *save, char *format, int x)
{
	if (format[x] == 'c' || format[x] == 's')
		stringfunct(save);
	else if (format[x] == 'p')
		pointfunct(save);
	else if (format[x] == 'd' || format[x] == 'u')
		decifunct(save);
	else if (format[x] == 'x' || format[x] == 'X')
		numhex(save, format[x]);
	return (x);
}

int	get_format(t_print *save, char *format, int x)
{
	while (format[x] != 'u' && format[x] != 'd' && format[x] != 'c' &&
			format[x] != 's' && format[x] != 'u' && format[x] != 'p' &&
			format[x] != 'x' && format[x] != 'X')
	{
		if (format[x] == '.')
		{
			save->point = 1;
			x++;
		}
		else if (format[x] == '-')
		{
			save->minus_sign = 1;
			x++;
		}
		else if (format[x] == ' ')
		{
			save->space = 1;
			x++;
		}
		else if (format[x] == '%')
			x += percent(save);
	}
	return (format_conversion(save, format, x));
}

int	ft_printf(const char *format, ...)
{
	t_print	*save;
	int		x;
	int		count;

	save = (t_print *)malloc(sizeof(t_print));
	if (!save)
		return (0);
	initialise(save);
	va_start(save->arg, format);
	x = -1;
	count = 0;
	while (format[++x])
	{
		if (format[x] == '%')
			x = get_format(save, format, x + 1);
		else
			count += write(1, format[x], sizeof(char));
	}
	va_end(save->arg);
	count += save->length;
	free(save);
	return (count);
}

int	main(int argc, char *argv[])
{
	char	*n;
	size_t	count;
	int		str;

	n = (char *) 'a';
	str = printf("%p\n", &n);
	printf("%u\n", str);
	count = (size_t) & n;
	ft_putstr_fd("0x", 1);
	str = nbr_hexa(count, 3);
	printf("\n");
	printf("%u\n", str);
	/*
	if (argc < 2)
	{
		printf("0\n");
		return (0);
	}
	pointfunct(argv[1]);
	count = stringfunct(argv[1]);
	printf("\n%u\n", (unsigned int)count);*/
	return (0);
}
