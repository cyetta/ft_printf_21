/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:39:01 by cyetta            #+#    #+#             */
/*   Updated: 2021/12/08 12:58:13 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft/libft.h"
#include "ft_printf_bonus.h"

int	ft_prn_uhex(unsigned int a, t_flag *str_flag)
{
	char	*s;
	int		len;

	s = ft_utoabase(a, "0123456789abcdef", str_flag);
	if (!s)
		return (0);
	len = ft_prn_str(s, str_flag);
	free(s);
	return (len);
}

int	ft_prn_uuhex(unsigned int a, t_flag *str_flag)
{
	char	*s;
	int		len;

	s = ft_utoabase(a, "0123456789ABCDEF", str_flag);
	if (!s)
		return (0);
	len = ft_prn_str(s, str_flag);
	free(s);
	return (len);
}

int	ft_prn_ptr(unsigned long long a, t_flag *str_flag)
{
	char	*s;
	int		len;

	s = ft_utoabase(a, "0123456789abcdef", str_flag);
	if (!s)
		return (0);
	len = ft_prnwpref("0x", s, str_flag);
	free(s);
	return (len);
}
