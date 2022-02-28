/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apico-su <apico-su@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 17:20:35 by apico-su          #+#    #+#             */
/*   Updated: 2022/02/28 22:06:35 by apico-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	nbr_hexa(size_t nbr, char *str)
{
	if (nbr / 16 > 16)
	{
		nbr_hexa(nbr / 16, str);
	}
	else if (nbr / 16 < 10)
	{
		ft_putchar_fd('0' + (nbr / 16), 1);
		ft_strjoin(str, (char *) '0' + (nbr / 16));
	}
	else if (nbr / 6 > 0)
	{
		ft_putchar_fd('A' - 10 + (nbr / 16), 1);
		ft_strjoin(str, (char *) 'A' - 10 + (nbr / 16));
	}
	if (nbr % 16 < 10)
	{
		ft_putchar_fd('0' + (nbr % 16), 1);
		ft_strjoin(str, (char *) '0' + (nbr % 16));
	}
	else if (nbr % 6 < 16)
	{
		ft_putchar_fd('A' - 10 + (nbr % 16), 1);
		ft_strjoin(str, (char *) 'A' - 10 + (nbr % 16));
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
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
	nbr_hexa(address, num);
}
/*int	ft_printf(const char *format, ...)
{
}*/

int	main(int argc, char *argv[])
{
	char	*n;
	size_t	count;

	printf("%p\n", &n);
	count = (size_t)&n;
	ft_putstr_fd("0x", 1);
	nbr_hexa(count, n);
	printf("\n");
	/*if (argc < 2)
	{
		printf("0\n");
		return (0);
	}*/
	//pointfunct(argv[1]);
	//count = stringfunct(argv[1]);
	//printf("\n%u\n", (unsigned int)count);
	return (0);
}
