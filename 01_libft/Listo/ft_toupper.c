/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marondon <marondon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:17:01 by marondon          #+#    #+#             */
/*   Updated: 2023/09/05 11:56:36 by marondon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		c = c - 32;
	}
	return (c);
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
		printf("%c", ft_toupper(str[i]));
		i++;
	}
	printf("\nOriginal Fn: ");
	i = 0;
	while (str[i] != '\0')
	{
		printf("%c", toupper(str[i]));
		i++;
	}
	return (0);
}
==============================================================================
- In the main, I changed d to c in printf becuase I want to print a character
not a number. If I use d it will print ascii value of the character (a=97)
*/
