/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 17:02:14 by cyetta            #+#    #+#             */
/*   Updated: 2021/12/06 00:46:34 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

typedef struct s_flag
{
	int	f_minus;
	int	f_null;
	int	f_point;
	int	f_width;
	int	f_prec;
}	t_flag;

int	ft_printf(const char *str, ...);
int	ft_write_sp(char symb, int n);
int	ft_prn_char(int c, t_flag *str_flag);
int	ft_prn_str(char *s, t_flag *str_flag);
int	ft_prn_dec(int a);
int	ft_prn_udec(unsigned int a);
int	ft_prn_uhex(unsigned int a);
int	ft_prn_uuhex(unsigned int a);
int	ft_prn_ptr(unsigned long long a);
#endif
