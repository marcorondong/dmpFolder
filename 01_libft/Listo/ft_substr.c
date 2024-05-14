/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marondon <marondon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 09:51:06 by marondon          #+#    #+#             */
/*   Updated: 2023/09/10 22:27:41 by marondon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	slen;
	char	*subs;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		len = 0;
	if (len > slen - start)
		len = slen - start;
	subs = (char *)malloc((len + 1) * sizeof(char));
	if (subs == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		subs[i] = s[start + i];
		i++;
	}
	subs[i] = '\0';
	return (subs);
}
/*
int	main(void)
{
    char *input = "0123456789"; // Hello, World!
    unsigned int start = 7;
    size_t len = 5;

    char *result = ft_substr(input, start, len);
    if (result)
    {
        printf("Substring: %s\n", result);
        free(result); // Must free the allocated memory when done
    }
    else
    {
        printf("Memory allocation failed.\n");
    }
    return 0;
}
==============================================================================
- Instead of create slen, i can call ft_strlen; but It'll involve more calls
*/
