/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marondon <marondon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 09:45:01 by marondon          #+#    #+#             */
/*   Updated: 2023/09/12 10:52:11 by marondon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	if (!s || !(*f))
		return;
	i = 0;
	while (s[i] != '\0')
	{
		(*f)(i, &s[i]); // I'm passing the value of 's' in position [i]
		i++;
	}
	return;
}
void modify_char(unsigned int i, char *c)
{
    // Increment each character by 1
    (*c)++;
	//When I receive a pointer (the real stuff), I have to use '*' to use
	//its value. If not, Im using its address.
	//Since Im not using 'i' here, I have to compile without the flags
	//If not, then I have to use: c[i]++; which is: address of c[i] then ++
}
#include <stdio.h>
int	main(void)
{
    char str1[] = "Hello, World!";
    char str2[] = "";
    char *str3 = NULL;

    printf("Original string 1: %s\n", str1);
    ft_striteri(str1, modify_char);
    printf("Modified string 1: %s\n\n", str1);

    printf("Original string 2: %s\n", str2);
    ft_striteri(str2, modify_char);
    printf("Modified string 2: %s\n\n", str2);

    printf("Original string 3: %s\n", str3);
    ft_striteri(str3, modify_char);
    printf("Modified string 3: %s\n\n", str3);

    return (0);
}
/*
- (*f) is equal to f
- I shouldn't do this: s[i] = (*f)(i, &s[i]);
Because I'm passing s[i] directly (with &s[i]). So it's not necessary to assign
again s[i]
*/