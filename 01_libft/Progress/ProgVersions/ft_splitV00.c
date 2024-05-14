/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marondon <marondon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 17:44:21 by marondon          #+#    #+#             */
/*   Updated: 2023/09/10 20:57:54 by marondon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_split(char const *s, char c)
{
	size_t	i;
	unsigned int	charcount;
	unsigned int	word;
	char	**arr;
	
	if (!s)
		return (NULL);
	i = 0;
	charcount = 0;
	word = 1;
	while (s[i] != '\0')
	{
		charcount++;
		if ((s[i] == c && (s[i - 1] != c && i != 0)) || (s[i + 1] == '\0')) //DOUBT: i > 0. (s[i] != c && (s[i + 1] = c || s[i + 1] = '\0'))
		{
			//arr = (char **)malloc(word * sizeof(char));
			arr[word] = ft_substr(s, (i - charcount + 1), charcount);
			word++;
			charcount = 0;
		}		
		i++;
	}
	arr[word] = NULL;
	return (arr);
}