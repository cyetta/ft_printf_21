/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 17:37:51 by cyetta            #+#    #+#             */
/*   Updated: 2021/12/03 00:27:33 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "libft/libft.h"
#include "ft_printf.h"

/*
str - pointer to
*/
static int	parse_percent(const char *str, va_list arg)
{
	int	ret_prn;

	ret_prn = 1;
	if (*str == '%')
		return (ft_prn_char('%'));
	else if (*str == 'c')
		return (ft_prn_char(va_arg(arg, int)));
	else if (*str == 's')
		return (ft_prn_str(va_arg(arg, char *)));
	else if (*str == 'd' || *str == 'i')
		return (ft_prn_dec(va_arg(arg, int)));
	else if (*str == 'u')
		return (ft_prn_udec(va_arg(arg, unsigned int)));
	else if (*str == 'x')
		return (ft_prn_uhex(va_arg(arg, unsigned int)));
	else if (*str == 'X')
		return (ft_prn_uuhex(va_arg(arg, unsigned int)));
	else if (*str == 'p')
		return (ft_prn_ptr(va_arg(arg, unsigned long long)));
	else
		return (write(1, str, 1));
}

static void	flag_init(t_flag *fl)
{
	fl->f_minus = 0;
	fl->f_null = 0;
	fl->f_point = 0;
	fl->f_prec = 0;
	fl->f_width = 0;
}

static void	parse_fldig(char *str, int *str_idx, t_flag *str_flag)
{

}

static int	parse_flag(char *str, int *str_idx, t_flag *str_flag, va_list arg)
{
	++(*str_idx);
	if (str[*str_idx] == '\0')
		return (0);
	else if (str[*str_idx] == '0')
		str_flag->f_null = 1;
	else if (str[*str_idx] == '-')
		str_flag->f_minus = 1;
	else if (str[*str_idx] == '.')
		str_flag->f_point = 1;
	else if (ft_isdigit(str[*str_idx]))
		parse_fldig(&str[*str_idx], &str_idx, &str_flag);
	else
		return (parse_percent(&str[*str_idx], arg));
	return (parse_flag(&str[*str_idx], str_idx, str_flag, arg));
}

/*
function manage the following conversions: cspdiuxX%
and parse flag '-0.' and mininal field
*/
int	ft_printf(const char *str, ...)
{
	int		str_cnt;
	int		str_idx;
	t_flag	str_flag;
	va_list	arg;

	if (!str)
		return (-1);
	va_start(arg, str);
	str_cnt = 0;
	str_idx = -1;
	while (str[++str_idx] != '\0')
	{
		if (str[str_idx] == '%')
		{
			flag_init(&str_flag);
			str_cnt += parse_flag(&str[str_idx], &str_idx, &str_flag, arg);
			continue ;
		}
		write(1, str + str_idx, 1);
		str_cnt++;
	}
	va_end(arg);
	return (str_cnt);
}
