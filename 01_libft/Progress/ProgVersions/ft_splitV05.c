/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marondon <marondon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 17:44:21 by marondon          #+#    #+#             */
/*   Updated: 2023/09/12 13:38:56 by marondon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	**ft_create_arr(char const *s, char c, char **arr)
{
	size_t			i;
	unsigned int	word;

	i = 0;
	word = 1;
	while (s[i] != '\0')
	{
		if ((s[i] == c && (s[i - 1] != c && i != 0)) || (s[i + 1] == '\0'))
			word++;
		i++;
	}
	arr = (char **)malloc(word * sizeof(char *));
	return (arr);
}

static char	**ft_fillarr(char const *s, char c, char **arr)
{
	size_t			i;
	unsigned int	charcount;
	unsigned int	word;

	i = 0;
	charcount = 0;
	word = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			charcount++;
			if (s[i + 1] == c || s[i + 1] == '\0')
			{
				arr[word] = ft_substr(s, (i - charcount + 1), charcount);
				word++;
				charcount = 0;
			}
		}
		i++;
	}
	arr[word] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char			**arr;

	if (!s)
		return (NULL);
	arr = NULL;
	arr = ft_create_arr(s, c, arr);
	arr = ft_fillarr(s, c, arr);
	return (arr);
}
/*
#include <stdio.h>
int main(void)
{
    // Test cases
    const char *test_str = "This,,,,is,a,test,string";
    char **result;

    // Test 1: Splitting a string with a comma as a delimiter
	printf("Test 1: Splitting a string with a comma as a delimiter\n");
    result = ft_split(test_str, ',');
    if (result)
    {
        int i = 0;
        while (result[i] != NULL)
        {
            printf("Result[%d]: %s\n", i, result[i]);
            free(result[i]); // Free each string
            i++;
        }
        free(result); // Free the array of strings
    }
    else
    {
        printf("ft_split returned NULL for Test 1.\n");
    }

    // Test 2: Splitting an empty string
    printf("Test 2: Splitting an empty string\n");
	const char *empty_str = "";
    result = ft_split(empty_str, ',');
    if (result)
    {
        printf("Result[0]: %s (Expected: NULL)\n", result[0]);
        free(result); // Free the array (it should contain only NULL)
    }
    else
    {
        printf("ft_split returned NULL for Test 2.\n");
    }

    // Test 3: Splitting a string without the delimiter
    printf("Test 3: Splitting a string without the delimiter\n");
	const char *no_delimiter_str = "NoDelimiterHere";
    result = ft_split(no_delimiter_str, ',');
    if (result)
    {
        printf("Result[0]: %s (Expected: 'NoDelimiterHere')\n", result[0]);
        printf("Result[1]: %s (Expected: NULL)\n", result[1]);
        free(result[0]); // Free the string
        free(result);    // Free the array
    }
    else
    {
        printf("ft_split returned NULL for Test 3.\n");
    }
    return 0;
}*/