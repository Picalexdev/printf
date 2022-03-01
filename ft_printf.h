/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apico-su <apico-su@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 17:23:01 by apico-su          #+#    #+#             */
/*   Updated: 2022/03/01 18:23:45 by apico-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"

typedef struct s_print
{
	va_list		args;
	int			width;
	int			precision;
	int			padd;
	int			point;
	int			dash;
	int			lenght;
	int			minus;
	int			zero;
	int			percent;
	int			sp;
}	t_print;
#endif