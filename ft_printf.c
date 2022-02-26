/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apico-su <apico-su@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 17:20:35 by apico-su          #+#    #+#             */
/*   Updated: 2022/02/26 20:06:12 by apico-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

	address = (size_t) point;
	printf("0x%lx\n%p\n", address, point);
}
/*int	ft_printf(const char *format, ...)
{
}*/

int	main(int argc, char *argv[])
{
	char	n;
	size_t	count;

	n = '\n';
	if (argc < 2)
	{
		printf("0\n");
		return (0);
	}
	pointfunct(argv[1]);
	//count = stringfunct(argv[1]);
	//printf("\n%u\n", (unsigned int)count);
	return (0);
}
