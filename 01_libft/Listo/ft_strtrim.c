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
	size_t	i_s;
	size_t	i_set;
	size_t	remove;

	remove = 0;
	if (direction == 1)
		i_s = 0;
	else
		i_s = ft_strlen(s1) - 1;
	i_set = 0;
	while (set[i_set] != '\0')
	{
		if (s1[i_s] == set[i_set])
		{
			i_s = i_s + (1 * direction);
			remove++;
			i_set = 0;
		}
		else
			i_set++;
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
