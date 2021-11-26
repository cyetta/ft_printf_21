/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 00:59:30 by cyetta            #+#    #+#             */
/*   Updated: 2021/11/26 19:29:31 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "ft_printf.h"
#include "libft/libft.h"

int	main(void)
{
	int		len;
	char	*s = "test";
	char	*t;

	t = malloc(1);
	len = printf("%p %p hello %% %c %s world %d %i %u\n", s, t, 'A', s, 42, -21, -1);
	printf("%d\n---ftprintf---\n", len);
	len = ft_printf("%p %p hello %% %c %s world %d %i %u\n", s, t, 'A', s, 42, -21, -1);
	printf("%d\n", len);
	free(t);
	return (0);
}
