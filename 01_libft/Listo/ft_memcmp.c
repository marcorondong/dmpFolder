/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marondon <marondon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:39:54 by marondon          #+#    #+#             */
/*   Updated: 2023/09/08 14:29:53 by marondon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*s1byte;
	const unsigned char	*s2byte;

	s1byte = (const unsigned char *)s1;
	s2byte = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s1byte[i] != s2byte[i])
			return (s1byte[i] - s2byte[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
    char str1[] = "0123456789";
    char str2[] = "0123456788";
    size_t n = 13; // Number of bytes to compare (excluding null terminator)

	printf("str1: %s\n",str1);
	printf("str2: %s\n", str2);
    // Using ft_memcmp function
    int result1 = ft_memcmp(str1, str2, n);
	printf("result1: %d\n", result1);
    if (result1 == 0)
        printf("ft_memcmp: str1 and str2 are equal\n");
    else if (result1 < 0)
        printf("ft_memcmp: str1 is less than str2\n");
    else
        printf("ft_memcmp: str1 is greater than str2\n");

    // Using memcmp function
    int result2 = memcmp(str1, str2, n);
	printf("result2: %d\n", result2);
    if (result2 == 0)
        printf("memcmp: str1 and str2 are equal\n");
    else if (result2 < 0)
        printf("memcmp: str1 is less than str2\n");
    else
        printf("memcmp: str1 is greater than str2\n");
    return 0;
}
==============================================================================
- Im casting s1 and s2 outside the loop to make the code shorter, but I can
cast them inside the loop
- 1st I was checking: while (s1byte[i] != '\0' || s2byte[i] != '\0' && i != n)
but this is not correct because Im comparing memory, not strings. So thats why
I have to iterate through each byte. (i < n)
- I have to cast 's' and 'c' to unsigned char because I'm receiving any value
(void) and I'm setting the maximum byte value wich is 255
(binary: 11111111)(hexadecimal: 0xFF)
*/
