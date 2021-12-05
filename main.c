/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 00:59:30 by cyetta            #+#    #+#             */
/*   Updated: 2021/12/06 00:52:58 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "ft_printf_bonus.h"
#include "libft/libft.h"

int	main(void)
{
	int		len;
	char	*s = "0strtst8";
	char	*t;

	t = malloc(1);
//	len = printf("%-0p %p hello %% %c %s %s world %d %i %u %x %X\n", s, t, 'A', s, (void *) NULL, 42, -21, -1, -42, 42);
	len = printf("!%-10.5s!%3.25s!%-c!%c!", s, s, 'Q', 'Z');
	printf("\n%d\n---ftprintf---\n", len);
//	len = ft_printf("%-0p %p hello %% %c %s %s world %d %i %u %x %X\n", s, t, 'A', s, (void *) NULL, 42, -21, -1, -42, 42);
	len = ft_printf("!%-10.5s!%3.25s!%-c!%c!", s, s, 'Q', 'Z');
	printf("\n%d\n", len);
	free(t);
	return (0);
}
