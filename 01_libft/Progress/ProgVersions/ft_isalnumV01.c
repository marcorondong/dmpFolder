/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marondon <marondon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:55:06 by marondon          #+#    #+#             */
/*   Updated: 2023/09/04 19:26:51 by marondon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if ((c < '0' || c > '9') || (c < 'A' || c > 'z') || (c > 'Z' && c < 'a'))
	{
		answer = 0;
	}
	return (answer);
}

#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	char	str[] = "ThisisAprettylongString0123456";
	int	i;
	int	ans1;
	int	ans2;

	ans1 = ft_isalnum(str);
	ans2 = isalnum(str);
	i = 0;
	printf("Source str: ");
	while (str[i] != '\0')
	{
		printf("%c", str[i]);
		i++;
	}
	printf("\nIs AlphaOrNum?: %d", ans1);
	printf("Original function(isalnum): %d", ans2);
	return (0);
}
