/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marondon <marondon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 11:06:23 by marondon          #+#    #+#             */
/*   Updated: 2023/10/24 22:30:21 by marondon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	s1len;
	size_t	s2len;
	char	*nstr;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	nstr = (char *)malloc((s1len + s2len + 1) * sizeof(char));
	if (nstr == NULL)
		return (NULL);
	i = 0;
	while (i < s1len)
	{
		nstr[i] = s1[i];
		i++;
	}
	while (i - s1len < s2len)
	{
		nstr[i] = s2[i - s1len];
		i++;
	}
	nstr[i] = '\0';
	return (nstr);
}
/*
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
