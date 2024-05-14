/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marondon <marondon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:17:06 by marondon          #+#    #+#             */
/*   Updated: 2023/09/08 10:31:48 by marondon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	if (n == 0)
		return (NULL);
	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)&((unsigned char *)s)[i]);
		i++;
	}
	return (NULL);
}
/*
int main(void)
{
    const char *str = "Hello, World!";
    int c = 'o';
    size_t n = ft_strlen(str); // For check the whole string

    // Test ft_memchr
    void *result = ft_memchr(str, c, n);
	if (result != NULL)
    {
        printf("ft_memchr: Char '%c' found at index: %ld\n",
        	c, (size_t)((char *)result - str));
    }
    else
    {
        printf("ft_memchr: Char '%c' not found in string.\n", c);
    }
    // Test standard memchr
    void *std_result = memchr(str, c, n);
    if (std_result != NULL)
    {
        printf("Or memchr: Char '%c' found at index: %ld\n",
        	c, (size_t)((char *)std_result - str));
    }
    else
    {
        printf("Or memchr: Char'%c' not found in string.\n", c);
    }

    return 0;
}
==============================================================================
- MAN: The  memchr()  function  scans  the initial n bytes of the memory area
pointed to by s for the first instance of c.  Both c and the bytes of the
memory area pointed to by s are  interpreted as unsigned char.
The memchr() and memrchr() functions return a pointer to the matching byte
or  NULL  if  the character does not occur in the given memory area.
- Explanation of " return ((void *)&((unsigned char *)s)[i]) ":
1.(unsigned char *)s: This part casts the const void *s pointer to an unsigned
char * pointer. This is done because we want to treat the memory as an
array of bytes (unsigned chars) rather than an array of some other data type.
2.((unsigned char *)s)[i]: This part accesses the i-th element of the memory
block pointed to by the casted pointer. In other words, it's accessing
the i-th byte in the memory block.
3.&((unsigned char *)s)[i]: Note the "&". This part takes the address of the
i-th byte within the memory block. It means it returns a pointer to that byte.
4.(void *)&((unsigned char *)s)[i]: This line casts the pointer to (void *).
This casting is done to match the return type of the ft_memchr function,
which is void *. It ensures that the pointer is returned as a void *,
allowing it to be used for any type.
- I can cast the variables outside the loop and that avoid casting each loop:
const unsigned char *sCOPY = (const unsigned char *)s
unsigned char cCOPY = (unsigned char)c
- I have to cast 's' and 'c' to unsigned char because I'm receiving any value
(void) and I'm setting the maximum byte value wich is 255
(binary: 11111111)(hexadecimal: 0xFF)
*/
