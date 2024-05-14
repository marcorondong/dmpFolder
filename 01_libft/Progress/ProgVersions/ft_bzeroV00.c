/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marondon <marondon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:46:09 by marondon          #+#    #+#             */
/*   Updated: 2023/09/06 15:58:52 by marondon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = '\0';
		i++;
	}
	return;
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char str[] = "bzero teststring";

	printf("Before ft_bzero: %s\n", str);
	ft_bzero(str, 5);
	printf("After ft_bzero: %s\n", str);
    return 0;
}*/
