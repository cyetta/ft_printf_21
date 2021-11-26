/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 17:02:14 by cyetta            #+#    #+#             */
/*   Updated: 2021/11/26 19:27:37 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_printf(const char *str, ...);
int	ft_prn_char(int c);
int	ft_prn_str(char *s);
int	ft_prn_dec(int a);
int	ft_prn_udec(unsigned int a);
int	ft_prn_uhex(unsigned int a);
int	ft_prn_uuhex(unsigned int a);
int	ft_prn_ptr(unsigned long long a);
#endif
