/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 17:23:01 by apico-su          #+#    #+#             */
/*   Updated: 2022/03/01 19:52:47 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>

typedef struct s_print
{
	va_list		arg;
	int			width;
	int			precision;
	int			padd;
	int			point;
	int			minus_sign;
	int			length;
	int			minus;
	int			zero;
	int			percent;
	int			space;
}	t_print;
#endif