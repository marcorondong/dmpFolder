/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marondon <marondon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:23:25 by marondon          #+#    #+#             */
/*   Updated: 2023/09/13 16:38:31 by marondon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	// Compare 'n' bytes of each string. I use '||' because if one ends
	// first, then I return the value of the 'last+1' char
	while ((s1[i] != '\0' || s2[i] != '\0') && i != n)
	{
		// Cast both to 'unsigned char' to compare each byte
		// (like comparing memory)
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
/*
#include <string.h>
#include <stdio.h>
int	main(void)
{
	char	s1[] = "Hello";
	char	s2[] = "World";
	size_t	n = 5;
	//int	expected = -0; // Here I write my expected result

	printf("S1: %s\n", s1);
	printf("S2: %s\n", s2);
	printf("n: %zu\n", n);
	//printf("Expected result: %d\n", expected); // Here I see my expected res
	printf("My function result: %d\n", ft_strncmp(s1, s2, n));
	printf("Real strncmp result: %d", strncmp(s1, s2, n));
	return (0);
}
==============================================================================
- I have to cast the comparison and substraction because when casting,
I can use chars from 0 to 255. If not, then i only can use -128 to 127
And I'm receiving a pointer to char, but It doesn't say if unsigned or signed
*/
