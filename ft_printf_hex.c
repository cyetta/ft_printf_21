/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:39:01 by cyetta            #+#    #+#             */
/*   Updated: 2021/11/26 20:23:00 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft/libft.h"
#include "ft_printf.h"

static int	ft_utoxsz(unsigned long long n, int base)
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

/*
Allocates (with malloc(3)) and returns a string representing the unsigned
integer received as an argument.
n - the integer to convert.
Return: The string representing the integer. NULL if the allocation fails.
*/
static char	*ft_utoabase(unsigned long long n, char *base)
{
	char	*str;
	int		size;
	int		base_pw;

	base_pw = ft_strlen(base);
	size = ft_utoxsz(n, base_pw);
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

int	ft_prn_uhex(unsigned int a)
{
	char	*s;
	int		len;

	s = ft_utoabase(a, "0123456789abcdef");
	if (!s)
		return (0);
	len = ft_prn_str(s);
	free(s);
	return (len);
}

int	ft_prn_uuhex(unsigned int a)
{
	char	*s;
	int		len;

	s = ft_utoabase(a, "0123456789ABCDEF");
	if (!s)
		return (0);
	len = ft_prn_str(s);
	free(s);
	return (len);
}

int	ft_prn_ptr(unsigned long long a)
{
	char	*s;
	int		len;

	s = ft_utoabase(a, "0123456789abcdef");
	if (!s)
		return (0);
	len = ft_prn_str("0x");
	len += ft_prn_str(s);
	free(s);
	return (len);
}
