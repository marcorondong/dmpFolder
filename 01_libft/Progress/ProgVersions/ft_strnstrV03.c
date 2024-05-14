/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marondon <marondon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 12:02:27 by marondon          #+#    #+#             */
/*   Updated: 2023/09/10 15:03:02 by marondon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	b;
	size_t	l;

	if (little[0] == '\0')
		return ((char *)big);
	b = 0;
	while (big[b] != '\0')
	{
		l = 0;
		while (big[b + l] == little[l] && l < len)
		{
			l++;
			if (little[l] == '\0')
				return ((char *)big + b);
		}
		b++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
    const char *big = "aaaaabcde";
    const char *little = "aabcde";
    size_t len = strlen(big);

    // My ft_strnstr function
    char *result1 = ft_strnstr(big, little, len);

    // Oiginal strnstr function
    char *result2 = strnstr(big, little, len);

    // Print results
    printf("Your ft_strnstr result: %s\n", result1);
    printf("Original strnstr result: %s\n", result2);

    // Comparation
    if ((result1 == NULL && result2 == NULL) || (strcmp(result1, result2) == 0))
    {
        printf("Results match!\n");
    }
    else
    {
        printf("Results do not match.\n");
    }

    return 0;
}
*/