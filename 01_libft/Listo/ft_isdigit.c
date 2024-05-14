/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marondon <marondon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 21:18:17 by marondon          #+#    #+#             */
/*   Updated: 2023/09/12 11:28:06 by marondon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	int	answer;

	answer = 2048;
	if (c < '0' || c > '9')
		return (0);
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
		printf("%d", ft_isdigit(str[i]));
		i++;
	}
	printf("\nOriginal Fn: ");
	i = 0;
	while (str[i] != '\0')
	{
		printf("%d", isdigit(str[i]));
		i++;
	}
	return (0);
}
==============================================================================
- MAN: isdigit() checks for a digit (0 through 9)
- The original funtion (isdigit) outputs 0 to "0" and 2048 to "1" so that's
why I'm hardcoding the "2048" instead of "1"
*/
