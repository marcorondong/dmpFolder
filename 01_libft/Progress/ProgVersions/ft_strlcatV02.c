/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat (Pend).c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marondon <marondon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 09:29:47 by marondon          #+#    #+#             */
/*   Updated: 2023/09/08 10:12:01 by marondon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dstlen;
	size_t	srclen;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
//	if (size <= dstlen)
//		return (size + ft_strlen(src));
//	i = dstlen; // Or i = dstlen -1?
	i = 0;
	while(src[i] != '\0' && i < size)
	{
		dst[dstlen - 1 + i] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	if (src[i] != '\0')
		//return(dstlen + srclen);
		return(dstlen + srclen);
	else
		return (ft_strlen(dst));

	//return (dstlen + ft_strlen(src));
}
*/
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	// I check the lenght of dst
	i = 0;
	while (dst[i])
		i++;
	// I append src to dst, checking size to not surpass it (i+j)(+1 is for \0)
	j = 0;
	while (src[j] && i + j < size) // src[j] = src[j] != '\0' ??
	// before it was while (src[j] && i + j + 1 < size)
	{
		dst[i + j] = src[j]; // And i++ ?? // before was only i
		j++;
	}
	// I add \0 to the end of dst to close it
	if (i < size) // before was only i
	{
		dst[i + j] = '\0';
	// I check if there's more src to append, only if I havent surpassed size
		while (src[j]) // src[j] = src[j] != '\0' ??
		j++;
		// I return the initial lenght of dst + leght of src
		return (i + j);
	}
	// If i > size, then (according to man), lenght of dst = size and I return
	// lenght of dst (= size) + leght of src
	else
		return (i + size);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	size_t	size = 100; // This is destination buffer = dst SIZE (not lenght)
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
*/

