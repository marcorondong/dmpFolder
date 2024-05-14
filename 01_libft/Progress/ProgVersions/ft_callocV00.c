/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marondon <marondon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 11:21:43 by marondon          #+#    #+#             */
/*   Updated: 2023/09/12 12:40:34 by marondon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if ((size * nmemb) / nmemb != size)
		return (NULL);
	if (size == 0 || nmemb == 0)
		return (malloc(0));
	ptr = (void *)malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
/*
#include <stdio.h>
#include <string.h>
int main() {
    size_t nmemb = 5;
    size_t size = sizeof(int); // Change to desired size of each element

    // Test original calloc
    printf("Testing original calloc:\n");
    void *original_calloc_result = calloc(nmemb, size);
    if (original_calloc_result == NULL) {
        perror("Original calloc failed");
        return 1;
    }
    size_t i = 0;
    while (i < nmemb) {
        printf("original_calloc_result[%zu] = %p\n", i,
        	original_calloc_result + i * size);
        i++;
    }
    free(original_calloc_result);

    // Test ft_calloc
    printf("\nTesting ft_calloc:\n");
    void *ft_calloc_result = ft_calloc(nmemb, size);
    if (ft_calloc_result == NULL) {
        perror("ft_calloc failed");
        return 1;
    }
    i = 0;
    while (i < nmemb) {
        printf("ft_calloc_result[%zu] = %p\n", i,
        	ft_calloc_result + i * size);
        i++;
    }
    free(ft_calloc_result);

    return 0;
}

- void allows to use any data type; and 'size_t' is unsigned integer type
- I check integer overflow with (size * nmemb) / nmemb != size
- I cast malloc to void because I don't know the type of data I'll receive
but malloc returns (void *) so not necesary to cast it
- I use 'size' (instead of sizeof) because it's the size of each member
- ft_bzero initializes the nmemb*size bytes of ptr
-Man says: If MULTIPLICATIN of 'nmemb' and 'size' would result in integer
overflow, then calloc() returns an error
- I could use a loop instead of my ft_bzero funtion, like this:
size_t	i; // 'size_t' is unsigned integer type
	i = 0;
	while (i < nmemb)
	{
		ptr[i] = '\0'; // Is the same as ptr[i] = 0;
		i++;
	}
- perror is used to print a descriptive error message to the standard error
stream (usually the console) based on the value of the global errno variable
It is included in <stdio.h> or sometimes in <string.h>
*/
