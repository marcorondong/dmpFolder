/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marondon <marondon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:02:00 by marondon          #+#    #+#             */
/*   Updated: 2023/09/12 10:01:17 by marondon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*newstr;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	newstr = (char *)malloc((i + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		newstr[i] = (*f)(i, s[i]);
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
/*
// Example mapping function that adds 1 to the character ASCII value
char add_one(unsigned int amount, char c) {
    //amount = 1; // This to convert a to b, etc
	return (c + amount);
}

int	main(void)
{
	char	teststring[] = "abcdefg";

	printf("Origin:%s\n", teststring);
	printf("Mapped:%s\n", ft_strmapi(teststring, add_one));

    // Test cases
    const char *test_strings[] = {"Hello, World!", "", NULL};
    
    int i = 0;
    while (i < 3)
	{
        printf("Test Case %d:\n", i + 1);
        const char *input = test_strings[i];
        printf("Origin String: %s\n", input);

        char *result = ft_strmapi(input, add_one);

        if (result) {
            printf("Mapped String: %s\n", result);
            free(result); // Remember to free the allocated memory
        } else {
            printf("Mapped String is NULL (allocation failed)\n");
        }
        printf("\n");

        i++;
    }
    return 0;
}
==============================================================================
- (*f) is equal to f
*/
