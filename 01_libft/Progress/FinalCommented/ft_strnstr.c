/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marondon <marondon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 12:02:27 by marondon          #+#    #+#             */
/*   Updated: 2023/09/13 18:46:15 by marondon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	b;
	size_t	l;

	// MAN: if little is '\0' then return 'big' (like if I'm looking for
	// whole string)
	if (little[0] == '\0')
		return ((char *)big);
	b = 0;
	// Search until big ends BUT within n' characters of 'big' (or n bytes)
	while (big[b] != '\0' && b <= len)
	{
		l = 0;
		// Check if little is in big, BUT within n' characters of 'big' 
		while (big[b + l] == little[l] && (b + l) <= len)
		{
			l++;
			// Check if whole little is in big,
			// BUT within n' characters of 'big'
			if (little[l] == '\0' && (b + l) <= len)
				return ((char *)big + b);
		}
		b++;
	}
	// If I don't find anything, I return NULL
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	//TESTS: ft_strnstr(aaaaabcde, aabcde, 4);
	//TESTS: ft_strnstr("lorem ipsum dolor sit amet", "dolor", 15);
	//TESTS: ft_strnstr("lorem ipsum dolor sit amet", "dolor", strlen(big));
	//TESTS: ft_strnstr("AAAAAAAAAAA", "AAAAAAAAAAA", strlen(big));
	//TESTS: ft_strnstr("MZIRIBMZIRIBMZE123", "MZIRIBMZE", strlen(little));
    //TESTS: ft_strnstr("A", "A", strlen(big) + 1);
	const char *big = "A";
    const char *little = "A";
    size_t len = strlen(big) + 1;

    // My ft_strnstr function
    char *res1 = ft_strnstr(big, little, len);

    // Oiginal strnstr function
    char *res2 = strnstr(big, little, len);

    // Print results
    printf("Your ft_strnstr result: %s\n", res1);
    printf("Original strnstr result: %s\n", res2);

    // Comparation
    if ((res1 == NULL && res2 == NULL) || (strcmp(res1, res2) == 0))
    {
        printf("Results match!\n");
    }
    else
    {
        printf("Results do not match.\n");
    }
    return 0;
}
==============================================================================
- len belongs to big. Acording to MAN:
The strnstr() function locates the first occurrence of the null-terminated
string little in the string big, where not more than len characters are
searched.  Characters that appear after a ‘\0’ character are not searched.
- So, If I want to search the whole big, then len should be: len=strlen(big)
- If in len i haven't find the whole 'little' then I have to return null.
- In the check: 'if (little[l + 1] == '\0' && (b + l) < len)'
I use little[l+1] to see if its the end of little so I return the position
*/
