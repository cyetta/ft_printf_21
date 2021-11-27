/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:39:01 by cyetta            #+#    #+#             */
/*   Updated: 2021/11/26 20:22:57 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft/libft.h"
#include "ft_printf.h"

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

int	ft_prn_dec(int a)
{
	char	*s;
	int		len;

	s = ft_itoa(a);
	if (!s)
		return (0);
	len = ft_prn_str(s);
	free(s);
	return (len);
}

int	ft_prn_udec(unsigned int a)
{
	char	*s;
	int		len;

	s = ft_utoa(a);
	if (!s)
		return (0);
	len = ft_prn_str(s);
	free(s);
	return (len);
}
