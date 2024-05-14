/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marondon <marondon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 14:24:31 by marondon          #+#    #+#             */
/*   Updated: 2023/09/09 15:17:02 by marondon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	j;
	char	*dup;

	i = ft_strlen(s);
	dup = (char *)malloc((i + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	j = 0;
	while (j < i)
	{
		dup[j] = s[j];
		j++;
	}
	dup[j] = '\0';
	return (dup);
}
/*
int	main(void)
{
    const char *original = "Hello, World!";
	printf("Orign str: %s\n", original);
    // Test your ft_strdup function
    char *dup_ft = ft_strdup(original);
    if (dup_ft == NULL) {
        fprintf(stderr, "ft_strdup failed to allocate memory\n");
        return 1;
    }
    printf("ft_strdup: %s\n", dup_ft);
    // Test the original strdup function
    char *dup_str = strdup(original);
    if (dup_str == NULL) {
        fprintf(stderr, "strdup failed to allocate memory\n");
        free(dup_ft); // Free memory allocated by ft_strdup
        return 1;
    }
    printf("Or_strdup: %s\n", dup_str);
    // Compare the two strings
    if (strcmp(dup_ft, dup_str) == 0) {
        printf("The strings are identical.\n");
    } else {
        printf("The strings are different.\n");
    }
    // Free memory allocated by ft_strdup and strdup
    free(dup_ft);
    free(dup_str);
    return 0;
}
==============================================================================
- fprintf is for printing error messages. And it's included in string.h
*/
