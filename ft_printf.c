/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apico-su <apico-su@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 17:20:35 by apico-su          #+#    #+#             */
/*   Updated: 2022/03/01 18:23:54 by apico-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print	initialise(t_print *src)
{
	src->width = 0;
	src->precision = 0;
	src->padd = 0;
	src->point = 0;
	src->dash = 0;
	src->lenght = 0;
	src->minus = 0;
	src->zero = 0;
	src->percent = 0;
	src->sp = 0;
}

int	nbr_hexa(size_t nbr, int count)
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

static size_t	stringfunct(char *c)
{
	static size_t	check;
	static size_t	i;

	check = ft_strlen(c);
	i = 0;
	while (i < check)
	{
		write(1, &c[i], sizeof(char));
		i++;
	}
	return (check);
}

static size_t	pointfunct(void *point)
{
	size_t	address;
	char	*num;

	num = NULL;
	address = (size_t) point;
	nbr_hexa(address, 0);
}
/*int	ft_printf(const char *format, ...)
{
}*/

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
