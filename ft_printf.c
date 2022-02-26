/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apico-su <apico-su@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 17:20:35 by apico-su          #+#    #+#             */
/*   Updated: 2022/02/26 18:40:51 by apico-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static ssize_t	cfunct(char c)
{
	ssize_t	check;

	check = write(1, &c, sizeof(char));
	return (check);
}

/*int	ft_printf(const char *format, ...)
{
}*/

int	main(int argc, char *argv[])
{
	char	n;

	n = '\n';
	cfunct(argv[1][0]);
	write(1, &n, sizeof(char));
	return (0);
}
