/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marondon <marondon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 11:06:23 by marondon          #+#    #+#             */
/*   Updated: 2023/09/10 11:38:25 by marondon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i; // size_t to count as long as s1 and s2 go
	size_t	s1len;
	size_t	s2len;
	char	*newstr; // to match return type, and also because I'm
	// a string, wich is an array of char (char *)

	// Validate if both strings exist
	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1); // For traversing the string
	s2len = ft_strlen(s2); // For traversing the string
	newstr = (char *)malloc((s1len + s2len + 1) * sizeof(char));
	// Malloc protection
	if (newstr == NULL)
		return (NULL);
	i = 0;
	// Copy s1 to newstr
	while (i < s1len)
	{
		newstr[i] = s1[i];
		i++;
	}
	// Since 'i' is index of newstr, I need to copy s2 to newstr
	// from when i = s1len to i = s1len + s2len
	// When starting, 'i' is equal to 's1len' so this will be:
	// s1len - s1len < s2len So: 0 < s2len
	while (i - s1len < s2len)
	{
		// When starting, 'i' is equal to 's1len' so this will be:
		// newsrt[s1len] = s2[s1len - s1len]. then i++
		newstr[i] = s2[i - s1len];
		i++;
	}
	newstr[i] = '\0'; // End newstr with '\0'
	return (newstr);
}
/*
#include <stdio.h>
int	main(void)
{
    char *s1 = "01234"; // Hello, 
    char *s2 = "56789"; // world!
    
    char *result = ft_strjoin(s1, s2);
    
    if (result)
	{
        printf("Concatenated string: %s\n", result);
        free(result); // Must free the allocated memory when done
    }
	else
	    printf("Memory allocation failed.\n");
    return 0;
}
*/
