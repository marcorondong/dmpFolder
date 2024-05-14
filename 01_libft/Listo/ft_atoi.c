/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marondon <marondon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:05:54 by marondon          #+#    #+#             */
/*   Updated: 2023/09/13 15:50:53 by marondon         ###   ########.fr       */
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
	while (nptr[i] != '\0' && (nptr[i] == 32
			|| (nptr[i] >= 9 && nptr[i] <= 13)))
	{
		i++;
	}
	if (nptr[i] == '+' || nptr[i] == '-')
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
/*
==============================================================================
Other approaches to do it:
=========== Approach 1:
int	ft_atoi(conts char *str)
{
	int result = 0;
	int sign = 1;

	while (*str == ' ' || (*str >= 9 && *str <= 13))
        	str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (sign * result);
}
==============================================================================
int main(void)
{
	printf("%d\n", ft_atoi("42")); // Output: 42
	printf("%d\n", ft_atoi("   -42")); // Output: -42
	printf("%d\n", ft_atoi("4193 with words")); // Output: 4193
	printf("%d\n", ft_atoi("words and 987")); // Output: 0
	printf("%d\n", ft_atoi("-+42")); // Output: 0
	printf("%d\n", ft_atoi("-91283472332")); // Output: -2147483648 (INT_MIN)
	printf("----------------\n");
	printf("%d\n", atoi("42")); // Output: 42
	printf("%d\n", atoi("   -42")); // Output: -42
	printf("%d\n", atoi("4193 with words")); // Output: 4193
	printf("%d\n", atoi("words and 987")); // Output: 0
	printf("%d\n", ft_atoi("-+42")); // Output: 0
	printf("%d\n", atoi("-91283472332")); // Output: -2147483648 (INT_MIN)
	return (0);
}
==============================================================================
- I only have to handle ONE sign (+/-) before the number
so more that one sign is considered to return '0'
- Im not handling overflows in integer (INT_MAX nor INT_MIN)
To do so; I have to check before multiplying *10 if result is >INT_MAX/10
or <__INt_MIN/10
*/
