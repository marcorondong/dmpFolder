/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marondon <marondon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 09:29:47 by marondon          #+#    #+#             */
/*   Updated: 2023/09/12 18:47:40 by marondon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (dst[i])
		i++;
	j = 0;
	while (src[j] && i + j < size)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i < size)
	{
		dst[i + j] = '\0';
		while (src[j])
			j++;
		return (i + j);
	}
	else
		return (i + size);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	size_t	size = 6; // This is dest buffer = dst SIZE (not lenght)
	char	src1[] = "56789";
	char	dst1[] = "01234";
	char	src2[] = "56789";
	char	dst2[] = "01234";
	
	printf("Size: %zu\n", size);
	printf("Src1 str: %s\n", src1);
	printf("Dst1 str: %s\n", dst1);
	printf("My function result: %zu\n", ft_strlcat(dst1, src1, size));
	printf("Resulting string: %s\n", dst1);
	printf("Src2 str: %s\n", src2);
	printf("Dst2 str: %s\n", dst2);
	printf("Orgin funct result: %zu\n", strlcat(dst2, src2, size));
	printf("Resulting string: %s\n", dst2);
    return (0);
}

- Buffer or size: is the leght of my dst string
- The line " while (src[j] != '\0' && i < size - 1) " is
i = leght of my dst string. So dstlen
- (src[j] && i + j < size) is equal to: src[j] = src[j] != '\0'
1. I check the lenght of dst
2. I append src to dst, checking size to not surpass it (i+j)
3. I check if dst leght < size to add \0 to the end of new dst to close it
3.1. I check if there's more src to append, but ONLY if I havent surpassed size
3.2 I return the initial lenght of dst + leght of src
4. If i > size, then (according to man), lenght of dst = size and I return
lenght of dst (= size) + leght of src. and I return i + size
*/
