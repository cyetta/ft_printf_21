/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dec_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:39:01 by cyetta            #+#    #+#             */
/*   Updated: 2021/12/07 01:17:09 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft/libft.h"
#include "ft_printf_bonus.h"

static int	ft_utoasz(unsigned int n)
{
	int	size;

	size = 0;
	if (n == 0)
		++size;
	while (n)
	{
		++size;
		n = n / 10;
	}
	return (size);
}
/*
static int	ft_utoxsz(unsigned long long n, int base, t_flag *str_flag)
{
	int	size;

	size = 0;
	if (n == 0)
		++size;
	while (n)
	{
		++size;
		n = n / base;
	}


	return (size);
}

static char	*ft_utoabase(unsigned long long n, char *base, t_flag *str_flag)
{
	char	*str;
	int		size;
	int		base_pw;

	base_pw = ft_strlen(base);
	size = ft_utoxsz(n, base_pw, str_flag);
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	str[size] = '\0';
	if (n == 0)
		str[0] = base[0];
	else
	{
		while (n)
		{
			str[--size] = base[(n % base_pw)];
			n = n / base_pw;
		}
	}
	return (str);
}
*/

/*
Allocates (with malloc(3)) and returns a string representing the unsigned
integer received as an argument.
n - the integer to convert.
Return: The string representing the integer. NULL if the allocation fails.
*/
static char	*ft_utoa(unsigned int n)
{
	char	*str;
	int		size;

	size = ft_utoasz(n);
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	str[size] = '\0';
	if (n == 0)
		str[0] = '0';
	else
	{
		while (n)
		{
			str[--size] = n % 10 + '0';
			n = n / 10;
		}
	}
	return (str);
}

int	ft_prn_dec(int a, t_flag *str_flag)
{
	char	*s;
	int		len;

	s = ft_itoa(a);
	if (!s)
		return (0);
	len = ft_prn_str(s, str_flag);
	free(s);
	return (len);
}

int	ft_prn_udec(unsigned int a, t_flag *str_flag)
{
	char	*s;
	int		len;

	s = ft_utoa(a);
	if (!s)
		return (0);
	len = ft_prn_str(s, str_flag);
	free(s);
	return (len);
}
