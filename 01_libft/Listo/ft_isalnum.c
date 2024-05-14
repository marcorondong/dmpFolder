/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marondon <marondon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:55:06 by marondon          #+#    #+#             */
/*   Updated: 2023/09/04 20:03:21 by marondon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	int	answer;

	answer = 8;
	if (!(ft_isdigit(c)) && !(ft_isalpha(c)))
	{
		answer = 0;
	}
	return (answer);
}
/*
int	main(void)
{
	char	str[] = "_-+*!$%&0123456789ThisisAprettylongString";
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
		printf("%d", ft_isalnum(str[i]));
		i++;
	}
	printf("\nOriginal Fn: ");
	i = 0;
	while (str[i] != '\0')
	{
		printf("%d", isalnum(str[i]));
		i++;
	}
	return (0);
}
==============================================================================
MAN: isalnum() checks for an alphanumeric character; it is equivalent to
(isalpha(c) || isdigit(c)).
- When I include my own library, I must use "" instead of <>
- Since I'm including my own library, I can call my previous functions
- When compiling, I must compile all the functions (the .c files)
- The original funtion (isalnum) outputs 0 to "0" and 8 to "1" so that's
why I'm hardcoding the "8" instead of "1"
*/
