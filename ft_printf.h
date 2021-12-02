/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 17:02:14 by cyetta            #+#    #+#             */
/*   Updated: 2021/12/02 23:07:29 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
typedef struct s_flag
{
	int	f_minus;
	int	f_null;
	int	f_point;
	int	f_width;
	int	f_prec;
}	t_flag;

int	ft_printf(const char *str, ...);
int	ft_prn_char(int c);
int	ft_prn_str(char *s);
int	ft_prn_dec(int a);
int	ft_prn_udec(unsigned int a);
int	ft_prn_uhex(unsigned int a);
int	ft_prn_uuhex(unsigned int a);
int	ft_prn_ptr(unsigned long long a);
#endif
