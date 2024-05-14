/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marondon <marondon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 09:29:47 by marondon          #+#    #+#             */
/*   Updated: 2023/09/06 10:47:17 by marondon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t  ft_strlcat(char *dst, const char *src, size_t size)
{
    size_t  i;
	size_t  j;
    size_t  buffer;

    buffer = ft_strlen(dst);
	i = 0;
	while (dst[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0' && j < size - buffer - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (i);
}
#include <stdio.h>
#include <string.h>
int	main(void)
{
	size_t	size = 5;
	char	src1[] = " World";
	char	dst1[] = "Hello";
	char	src2[] = " World";
	char	dst2[] = "Hello";
	
	printf("Source str: %s ---> Dest str: %s\n", src1, dst1);
	printf("My function result: %zu\n", ft_strlcat(dst1, src1, size));
	printf("Resulting string: src: %s ---> dest: %s\n", src1, dst1);
	printf("Source str: %s ---> Dest str: %s\n", src2, dst2);
	printf("Original function result: %zu\n", strlcat(dst2, src2, size));
	printf("Resulting string: src: %s ---> dest: %s\n", src2, dst2);
    return (0);
}
/* - Buffer is the leght of my dst string */