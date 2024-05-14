/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marondon <marondon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 11:45:06 by marondon          #+#    #+#             */
/*   Updated: 2023/09/10 19:24:41 by marondon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_to_remove(char const *s1, char const *set, int direction)
{
	size_t	i_s; // index of start (where I'll start trimming s1)
	size_t	i_set; // index of 'set of chars' I want to trimm
	size_t	remove; // For counting chars to remove

	remove = 0;
	// Check if trimming from beginning or from end
	if (direction == 1)
		i_s = 0;
	// If trimming from end, then -1 to check the last index
	// Remember: last index is len - 1
	else
		i_s = ft_strlen(s1) - 1;
	i_set = 0;
	// Check each char of set
	while (set[i_set] != '\0')
	{
		// Check if I find one char of set in the string s
		if (s1[i_s] == set[i_set])
		{
			// If found, then adjust index of start
			// according to the DIRECTION I'll trimm
			i_s = i_s + (1 * direction);
			remove++; // Count how many chars I'll remove
			i_set = 0; // Reset index of set to start looking
				//from its beginning
		}
		//If not found char of set, check next char of set
		else
			i_set++;
	}
	return (remove); // Return how many chars I'll remove
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t			remove; // For counting chars to remove
	unsigned int	start; // Position where I'll trim (Fn substr())
	int				direction; // Trimming direction
	char			*newstr; // resulting trimmed string

	direction = 1; // Set trimming direction from beginning of s1 (L-R)
	// Get number of chars to trimm from beginning of s1
	remove = ft_to_remove(s1, set, direction); // Count chars to remove L-R
	start = remove; // Starting point of trimmed string (Fn substr())
	direction = -1; // Set trimming direction from end of s1 (R-L)
	remove = remove + ft_to_remove(s1, set, direction); // Set newstr lengt
	// substr (string to be trimmed, starting point, length of new string)
	newstr = ft_substr(s1, start, (ft_strlen(s1) - remove));
	return (newstr);
}
/*
#include <stdio.h>
#include <stdlib.h>
int	main(void)
{
    char const *original = "   Hello, World!   "; // "   Hello, World!   "
    char const *set = " ";
    char *trimmed = ft_strtrim(original, set);

    if (trimmed)
	{
        printf("Original: \"%s\"\n", original);
        printf("Trimmed: \"%s\"\n", trimmed);
        free(trimmed); // Must free the allocated memory when done
    }
	else
        printf("Memory allocation failed.\n");
	return (0);
}
*/
