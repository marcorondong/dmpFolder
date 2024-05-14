/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marondon <marondon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 17:44:21 by marondon          #+#    #+#             */
/*   Updated: 2023/09/14 14:44:06 by marondon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	ft_free_arr(char **arr, unsigned int word)
{
	// Check all the words and free them backwards
	while (word > 0)
	{
		free(arr[word]);
		word--;
	}
	// Free 1st word (since my while loop doesn't take '0')
	free(arr[word]);
	// Free the array of strings
	free(arr);
}

static char	**ft_create_arr(char const *s, char c, char **arr)
{
	size_t			i;
	unsigned int	word;

	i = 0;
	word = 1; // I will always have 1 word, or '\0'
	while (s[i] != '\0') // Check the whole string (sentence)
	{
		// Check if 'separator', and skill them all
		while (s[i] == c)
			i++;
		// Check if 'NOT separator', skip it, but not reach string end
		while (s[i] != c && s[i] != '\0')
		{
			// Check if next is 'separator' or end of string
			// and count word if true
			if ((s[i + 1] == c || s[i + 1] == '\0'))
				word++;
			i++;
		}
	}
	// Allocate memory for each word. Note that I start with word = 1
	// to include '\0'
	arr = (char **)malloc(word * sizeof(char *));
	// Malloc protection
	if (!arr)
		return (NULL);
	return (arr);
}

static char	**ft_fillarr(char const *s, char c, char **arr, unsigned int *word)
{
	size_t			i;
	unsigned int	charcount;

	i = 0;
	charcount = 0;
	// Check if 'arr' exist and traverse it
	while (s[i] != '\0' && arr)
	{
		if (s[i] != c) // Count each character and skip 'separator'
		{
			charcount++;
			// Check if I have whole word and allocate memory for it
			if (s[i + 1] == c || s[i + 1] == '\0')
			{
				// Use *word for REAL value of word (fnc receives pointer)
				// Use Fn substr wich needs: string, starting index for
				// copying, and amount of char. (Use +1 because when i=0, charcount=1)
				arr[*word] = ft_substr(s, (i - charcount + 1), charcount);
				// If substring/allocation fails, then I free each word
				// and then array of array
				if (!arr[*word])
				{
					ft_free_arr(arr, *word);
					return (NULL);
				}
				(*word)++; // Add +1 to move to next index of arrray of strings
				charcount = 0;
			}
		}
		i++;
	}
	// Dont need to check here 'if !arr' because I already return it if substr fails
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char			**arr; // array of strings (arrray of arrays)
	unsigned int	word;

	word = 0;
	if (!s)
		return (NULL);
	arr = NULL; // Initialize arr
	arr = ft_create_arr(s, c, arr); // Create array of strings
	if (!arr)
		return (NULL);
	arr = ft_fillarr(s, c, arr, &word); // Fill array. Send REAL value of 'word'
	if (arr)
		arr[word] = NULL;
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
}
*/
