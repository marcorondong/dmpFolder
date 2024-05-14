/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat (Pend).c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marondon <marondon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 09:29:47 by marondon          #+#    #+#             */
/*   Updated: 2023/09/07 19:47:08 by marondon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dstlen;

	dstlen = ft_strlen(dst);
	i = dstlen;
	while(src[i - dstlen] != '\0' && i - dstlen < size)
	{
		dst[i] = src[i - dstlen];
		i++;
	}
	dst[i] = '\0';
	if (src[i - dstlen] != '\0')
		return(ft_strlen(dst) + 1);
	else
		return (ft_strlen(dst));
}

#include <stdio.h>
#include <string.h>
int	main(void)
{
	size_t	size = 4; // This is the destination buffer
	char	src1[] = " World";
	char	dst1[] = "Hello";
	char	src2[] = " World";
	char	dst2[] = "Hello";
	
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
/*
- Buffer or size: is the leght of my dst string
- The line " while (src[j] != '\0' && i < size - 1) " is
i = leght of my dst string. So dstlen
*/
