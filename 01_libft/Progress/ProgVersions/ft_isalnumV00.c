/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marondon <marondon@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:55:06 by marondon          #+#    #+#             */
/*   Updated: 2023/09/04 17:31:12 by marondon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(char *str)
{
	int	i;
	int	answer;

	answer = 1;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
		{
			if ((str[i] < 'A' || str[i] > 'z') || (str[i] > 'Z' && str[i] < 'a'))
			{
				answer = 0;
			}
		}
		i++;
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
