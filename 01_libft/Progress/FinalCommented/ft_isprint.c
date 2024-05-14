/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marondon <marondon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 20:08:49 by marondon          #+#    #+#             */
/*   Updated: 2023/09/04 20:16:08 by marondon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	int	answer;

	// The original funtion (isprint) outputs 0 to "0" and 8 to "16384" so
	// that's why I'm hardcoding the "16384" instead of "1"
	answer = 16384;
	if (c < ' ' || c > '~')
		return (0);
	return (answer);
}
/*
#include <stdio.h>
#include <ctype.h>
int	main(void)
{
	char	str[] = "_-+*!$%&0123456789ThisisAprettylongString§ßÜÄ";
	int		i;

	i = 0;
	printf("Source strg: ");
	while (str[i] != '\0')
	{
		printf("%c", str[i]);
		i++;
	}
	printf("\nMy Function: ");
	i = 0;
	while (str[i] != '\0')
	{
		printf("%d", ft_isprint(str[i]));
		i++;
	}
	printf("\nOriginal Fn: ");
	i = 0;
	while (str[i] != '\0')
	{
		printf("%d", isprint(str[i]));
		i++;
	}
	return (0);
}
==============================================================================
- MAN: isprint() checks for any printable character including space.
- When I include my own library, I must use "" instead of <>
- Since I'm including my own library, I can call my previous functions
- When compiling, I must compile all the functions (the .c files)
- The original funtion (isascii) outputs 0 to "0" and 1 to "16384" so that's
why I'm hardcoding the "16384" instead of "1"
*/
