/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marondon <marondon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:56:11 by marondon          #+#    #+#             */
/*   Updated: 2023/09/06 10:45:30 by marondon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (0);
	i = 0;
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (i);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	size_t	size = 5;
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
- I need to check size "0" because otherwise my program will crash
- I could also use a variable "len" and asign the result of the call
"ft_strlen(src)" and then return "len". But its more lines of code as If I use
"return (ft_strlen(src)"
- Its "size - 1" because I need to reserve one byte for "\0"
- I must include the header <bsd/string.h> to use the string.h functions
and when compiling, I have to write -lbsd*/
