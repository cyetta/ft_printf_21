/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 00:59:30 by cyetta            #+#    #+#             */
/*   Updated: 2021/11/25 23:47:32 by cyetta           ###   ########.fr       */
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

	len = printf("hello %% %c %s world %d %i %u\n", 'A', s, 42, 21, 100);
	printf("%d\n---ftprintf---\n", len);
	len = ft_printf("hello %% %c %s world %d %i %u\n", 'A', s, 42, 21, 100);
	printf("%d\n", len);
	return (0);
}
