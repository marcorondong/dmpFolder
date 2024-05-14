/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marondon <marondon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 11:45:06 by marondon          #+#    #+#             */
/*   Updated: 2023/09/10 16:35:47 by marondon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_to_remove(char const *s1, char const *set, int direction)
{
	size_t	idxS;
	size_t	idxSET;
	size_t	remove;
	int	setchecked;

	remove = 0;
	if (direction == 1)
		idxS = 0;
	else
			idxS = ft_strlen(s1) - 1; // Remember last index = len - 1
	setchecked = 0;
	while (setchecked == 0) // BEORE: (setchecked == 0 && s1[idxS] != '\0')
	{
		idxSET = 0;
		while (set[idxSET] != '\0')
		{
			if (s1[idxS] == set[idxSET])
			{
				idxS = idxS + (1 * direction);
				remove++;
				idxSET = 0;
			}
			else
				idxSET++;
		}
		setchecked = 1;
	}
	return (remove);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	remove;
	unsigned int	start;
	int	direction;
	char	*newstr;

	direction = 1;
	remove = ft_to_remove(s1, set, direction);
	start = remove;
	direction = -1;
	remove = remove + ft_to_remove(s1, set, direction);
	newstr = ft_substr(s1, start, (ft_strlen(s1) - remove));
	return (newstr);
}
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
    //return (0);

	//////////////////////////////////////////////////
	    // Test case 1: Empty string, set is empty
    char const *empty = "";
    char const *emptySet = "";
    char *trimmedEmpty = ft_strtrim(empty, emptySet);
    if (trimmedEmpty) {
        printf("Original: \"%s\"\n", empty);
        printf("Trimmed: \"%s\"\n", trimmedEmpty);
        free(trimmedEmpty);
    } else {
        printf("Memory allocation failed.\n");
    }

    // Test case 2: No characters to trim
    char const *noTrim = "Hello, World!";
    char const *noTrimSet = "123";
    char *trimmedNoTrim = ft_strtrim(noTrim, noTrimSet);
    if (trimmedNoTrim) {
        printf("Original: \"%s\"\n", noTrim);
        printf("Trimmed: \"%s\"\n", trimmedNoTrim);
        free(trimmedNoTrim);
    } else {
        printf("Memory allocation failed.\n");
    }

    // Test case 3: All characters are in set
    char const *allTrim = "    ";
    char const *allTrimSet = " ";
    char *trimmedAllTrim = ft_strtrim(allTrim, allTrimSet);
    if (trimmedAllTrim) {
        printf("Original: \"%s\"\n", allTrim);
        printf("Trimmed: \"%s\"\n", trimmedAllTrim);
        free(trimmedAllTrim);
    } else {
        printf("Memory allocation failed.\n");
    }
	return (0);
}
/*
================2 try:
size_t	ft_to_remove(char const *s1, char const *set, int direction)
{
	size_t	idxS;
	size_t	idxSET;
	size_t	remove;
	int	setchecked; // This could be a boolean

	remove = 0;
	if (direction == 1)
		idxS = 0;
	else
			idxS = ft_strlen(s1);
	setchecked = 0;
	while (setchecked == 0 && s1[idxS] != '\0') // || Antes era: (setchecked = 0)
	{
		idxSET = 0;
		while (s1[idxS] != set[idxSET] && set[idxSET] != '\0')
			idxSET++;
		if (s1[idxS] == set[idxSET - 1])
		{
			idxS = idxS + (1 * direction); // Capaz este sobra
			remove++;
		}
		else
			setchecked = 1;
	}
	return (remove);
}
================1 try:
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	slen;
	size_t	idxS;
	size_t	idxSET;
	size_t	remove;
	int	setchecked; // This will be a boolean
	char	*newstr;

	idxS = 0;
	remove = 0;
	setchecked = 0;
	while (setchecked = 0) // || Antes era: (s[idxS] != '\0'&& setchecked = 0)
	{
		idxSET = 0;
		while (s[idxS] != set[idxSET] && set[idxSET] != '\0')
			idxSET++;
		if (s[idxS]) == set[idxSET - 1]
		{
			idxS++; // Capaz este sobra
			remove++;
		}
		else
			setchecked = 1;
	}
	
}
*/