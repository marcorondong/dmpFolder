/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marondon <marondon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 20:08:15 by marondon          #+#    #+#             */
/*   Updated: 2023/09/04 19:40:27 by marondon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	int	answer;

	// The original funtion (isalpha) outputs 0 to "0" and 8 to "1024" so
	// that's why I'm hardcoding the "1024" instead of "1"
	answer = 1024;
	if (c < 'A' || c > 'z')
		answer = 0;
	else if (c > 'Z' && c < 'a')
		answer = 0;
	return (answer);
}
/*
#include <stdio.h>
#include <ctype.h>
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
		printf("%d", ft_isalpha(str[i]));
		i++;
	}
	printf("\nOriginal Fn: ");
	i = 0;
	while (str[i] != '\0')
	{
		printf("%d", isalpha(str[i]));
		i++;
	}
	return (0);
}
==============================================================================
- MAN: isalpha() checks  for  an  alphabetic  character; in the standard "C"
locale, it is equivalent to (isupper(c) || islower(c)).  In some locales,
there may be  additional  characters  for which isalpha() is true—letters
which are neither uppercase nor lowercase.
- Between the UPPERCASE and lowercase letters there are some symbols, thats
why I have two checks
- The original funtion (isalpha) outputs 0 to "0" and 1024 to "1" so that's
why I'm hardcoding the "1024" instead of "1"
*/
