/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marondon <marondon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 20:21:17 by marondon          #+#    #+#             */
/*   Updated: 2023/09/04 20:40:09 by marondon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	idx;

	idx = 0;
	while (s[idx] != '\0')
	{
		idx++;
	}
	return (idx);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	s[] = "0123456789";

	printf("String to check: %s\n", s);
	printf("My Function: %lu\n", ft_strlen(s));
    printf("Original Fn: %lu", strlen(s));
	return (0);
}
- size_t is for subtituing unsigned long int bcuz original function use it
- I don't need to use the "&" to pass s to ft_strlen because s is already
a pointer (an array). I use "&" when the things Im passing (arguments) aren't
pointers.
-I can also use only ft_strlen("Hello world") (and not char s[]=.....)
and it will work since its also a way to send a string
- Also, I can use: while (s[i]) then i++, return (i++) (I don't need to
check for the '\0' character if Im counting)*/
