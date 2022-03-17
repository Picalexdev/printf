/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 17:20:35 by apico-su          #+#    #+#             */
/*   Updated: 2022/03/17 20:36:12 by alex             ###   ########.fr       */
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

/*void	dectohex(size_t nbr, int count)
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
}*/

static int	charfunct(t_print *save)
{
	char	c;

	c = va_arg(save->arg, int);
	ft_putchar_fd(c, 1);
	return (1);
}

static int	stringfunct(t_print *save)
{
	char	*str;

	str = va_arg(save->arg, char *);
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

static int	decifunct(t_print *save)
{
	int		x;
	char	*str;

	x = va_arg(save->arg, int);
	str = ft_itoa(x);
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

static int	pointfunct(t_print *save)
{
	//int	address;

	//nbr_hexa(address, 0);
}

static int	percent(t_print *save)
{
	ft_putchar_fd('%', 1);
	return (1);
}

static int	numhex(t_print *save, char caps)
{
	char	*str;

	str = va_arg(save->arg, char *);
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	format_conversion(t_print *save, const char *format, int x)
{
	if (format[x] == 'c')
		x += charfunct(save);
	else if (format[x] == 's')
		x += stringfunct(save);
	else if (format[x] == 'p')
		x += pointfunct(save);
	else if (format[x] == 'd' || format[x] == 'u')
		x += decifunct(save);
	else if (format[x] == 'x' || format[x] == 'X')
		x += numhex(save, format[x]);
	return (x);
}

int	get_format(t_print *save, char *format, int x)
{
	while (format[x] != 'u' && format[x] != 'd' && format[x] != 'c'
		&& format[x] != 's' && format[x] != 'u' && format[x] != 'p'
		&& format[x] != 'x' && format[x] != 'X')
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
	save->length = x + format_conversion(save, format, x);
	return (x);
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
			x = get_format(save, (char *)format, x + 1);
		else
			count += write(1, &format[x], sizeof(char));
	}
	va_end(save->arg);
	count += save->length;
	free(save);
	return (count);
}

int	main(int argc, char *argv[])
{
	char	a;

	a = 'a';
	ft_printf("Hola %s %d\n", "Holaaaaaaa", 12345);
	return (0);
}
