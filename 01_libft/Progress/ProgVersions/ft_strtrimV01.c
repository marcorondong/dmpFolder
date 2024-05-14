/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marondon <marondon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 11:45:06 by marondon          #+#    #+#             */
/*   Updated: 2023/09/10 16:47:57 by marondon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_to_remove(char const *s1, char const *set, int direction)
{
	size_t	idxS;
	size_t	idxSET;
	size_t	remove;
	int		setchecked;

	remove = 0;
	if (direction == 1)
		idxS = 0;
	else
			idxS = ft_strlen(s1) - 1;
	setchecked = 0;
	while (setchecked == 0)
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
	size_t			remove;
	unsigned int	start;
	int				direction;
	char			*newstr;

	direction = 1;
	remove = ft_to_remove(s1, set, direction);
	start = remove;
	direction = -1;
	remove = remove + ft_to_remove(s1, set, direction);
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
