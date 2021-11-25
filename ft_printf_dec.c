/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:39:01 by cyetta            #+#    #+#             */
/*   Updated: 2021/11/25 23:56:18 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft/libft.h"
#include "ft_printf.h"

int	ft_prn_dec(int a)
{
	char	*s;
	int		len;

	s = ft_itoa(a);
	if (!s)
		return (-1);
	len = ft_prn_str(s);
	free(s);
	return (len);
}

/*
Allocates (with malloc(3)) and returns a string representing the unsigned
integer received as an argument.
n - the integer to convert.
Return: The string representing the integer. NULL if the allocation fails.
*/
static char	*ft_utoa(unsigned int n)
{
	char			*str;
	int				size;
	unsigned int	t;

	size = 0;
	t = n;
	if (t == 0)
		++size;
	while (t)
	{
		++size;
		t = t / 10;
	}
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	str[size] = '\0';
	t = n;
	while (t)
	{
		str[--size] = t % 10 + '0';
		t = t / 10;
	}
	if (n == 0)
		str[0] = '0';
	return (str);
}

int	ft_prn_udec(unsigned int a)
{
	char	*s;
	int		len;

	s = ft_utoa(a);
	if (!s)
		return (-1);
	len = ft_prn_str(s);
	free(s);
	return (len);
}
