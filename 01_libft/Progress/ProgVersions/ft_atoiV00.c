/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marondon <marondon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:05:54 by marondon          #+#    #+#             */
/*   Updated: 2023/09/08 16:43:56 by marondon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	result;
	int	minus;

	i = 0;
	result = 0;
	minus = 1;
	while (nptr[i] != '\0' && (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13)))
	{
		nptr++;
	}
	while (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			minus = -minus;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - 48);
		i++;
	}
	return (result * minus);
}
#include <stdio.h>
int main(void)
{
	// Step 7: Test the ft_atoi function
	printf("%d\n", ft_atoi("42")); // Output: 42
	printf("%d\n", ft_atoi("   -42")); // Output: -42
	printf("%d\n", ft_atoi("4193 with words")); // Output: 4193
	printf("%d\n", ft_atoi("words and 987")); // Output: 0
	printf("%d\n", ft_atoi("-91283472332")); // Output: -2147483648 (INT_MIN)
	return (0);
}