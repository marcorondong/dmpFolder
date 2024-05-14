/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marondon <marondon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:57:36 by marondon          #+#    #+#             */
/*   Updated: 2023/09/05 15:39:51 by marondon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strchr(const char *s, int c)
{
    int i;
    
    i = 0;
    while (s[i] != '\0' && s[i] != c)
    {
        if (s[i] == c)
            return (s[i]);
        i++;
    }
    return NULL;
}

#include <stdio.h>
#include <ctype.h>
int	main(void)
{
	char	str[] = "_-+*!$%&0123456789ThisisAprettylongString";
	int		i;
	int valtolook;
	

	valtolook = 'i';
	i = 0;
	printf("Source strg: ");
	while (str[i] != '\0')
	{
		printf("%c", str[i]);
		i++;
	}
	printf("\nMy Function: ");
	i = ft_strchr(str, valtolook);
	while (str[i] != '\0')
	{
		printf("%c", str[i]);
		i++;
	}
	printf("\nOriginal Fn: ");
	i = strchr(str, valtolook);
	while (str[i] != '\0')
	{
		printf("%c", str[i]);
		i++;
	}
	return (0);
}
