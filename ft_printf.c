/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 17:37:51 by cyetta            #+#    #+#             */
/*   Updated: 2021/11/15 22:55:55 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft/libft.h"
#include "ft_printf.h"

/*
function manage the following conversions: cspdiuxX%
*/
int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		str_bgn;
	int		str_idx;
	int		str_cnt;

	if (!str)
		return (-1);
	va_start(arg, str);
	str_bgn = 0;
	str_idx = 0;
	str_cnt = ft_strlen(str);
	while (str[str_idx] != '\0')
	{
		str_bgn += str_idx;
		++str_idx;
	}
	va_end(arg);
	return (str_cnt);
}
