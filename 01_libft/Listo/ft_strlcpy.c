/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marondon <marondon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:56:11 by marondon          #+#    #+#             */
/*   Updated: 2023/09/12 19:25:52 by marondon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}
/*
int	main(void)
{
	size_t	size = 3;
	char	srcMyFn[] = "Hell";
	char	dstMyFn[] = "Hella Wella0123456789";
	char	srcOrFn[] = "Hell";
	char	dstOrFn[] = "Hella Wella0123456789";
	
	printf("Source str: %s ---> Dest str: %s\n", srcMyFn, dstMyFn);
	printf("My function result: %zu\n", ft_strlcpy(dstMyFn, srcMyFn, size));
	printf("Resulting strings: src: %s ---> dest: %s\n", srcMyFn, dstMyFn);
	printf("Source str: %s ---> Dest str: %s\n", srcOrFn, dstOrFn);
	printf("Original function result: %zu\n", strlcpy(dstOrFn, srcOrFn, size));
	printf("Resulting strings: src: %s ---> dest: %s\n", srcOrFn, dstOrFn);
    return (0);
}
==============================================================================
- MAN: strlcpy return the size of the string it tried to create. So it always
will return the lenght of src. So:
1. If size=0, I return length of src.
2. If size < length of src, Then I return length of src.
- I need to check size "0" because otherwise my program will crash
- Its "size - 1" because I need to reserve one byte for "\0"
- I must include the header <bsd/string.h> to use the string.h functions
and when compiling, I have to write -lbsd
*/
