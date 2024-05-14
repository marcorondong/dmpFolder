/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marondon <marondon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:55:49 by marondon          #+#    #+#             */
/*   Updated: 2023/09/04 20:07:42 by marondon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	int	answer;

	// The original funtion (isascii) outputs 0 to "0" and 1 to "1"
	answer = 1;
	if (c < 0 || c > 127)
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
		printf("%d", ft_isascii(str[i]));
		i++;
	}
	printf("\nOriginal Fn: ");
	i = 0;
	while (str[i] != '\0')
	{
		printf("%d", isascii(str[i]));
		i++;
	}
	return (0);
}
==============================================================================
MAN: isascii() checks whether c is a 7-bit unsigned char value that fits into
the ASCII character set.
- When I include my own library, I must use "" instead of <>
- Since I'm including my own library, I can call my previous functions
- When compiling, I must compile all the functions (the .c files)
- The original funtion (isascii) outputs 0 to "0" and 1 to "1"
*/
