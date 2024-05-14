/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove(Pend).c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marondon <marondon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 19:27:07 by marondon          #+#    #+#             */
/*   Updated: 2023/09/07 14:21:40 by marondon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;

	// Check if moving same memory
	if (dest == src)
		return (dest);
	// Check if memory overlaps. If so, then I move backwards to not
	// overwrite: Copy in front, move back, copy in front, move back
	// 123_ -> 12_3 -> 1_23 -> _123. and not: 123_ -> 1_13 -> 11_3 -> 111_
	if (src < dest && (char *)src + n > (char *)dest)
	{
		i = n - 1;
		while (i > 0)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i--;
		}
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
	}
	// If not overlap, copy fwd. 123 ___ -> 123 1__ -> 123 12_ -> 123 123
	else
	{
		i = 0;
		while (i < n)
		{
			// Cast to 'unsigned char *' to treat memory as array
			// of bytes (unsigned chars). (char = 1 byte)
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*Myresult;
	char	*Orresult;
	char	Myoriginal[] = "abcdefghijklmnopqrstuvwxyz";
	char	Ororiginal[50] = "abcdefghijklmnopqrstuvwxyz";

    Myresult = ft_memmove(Myoriginal + 4, Myoriginal + 6, 3);
	Orresult = memmove(Ororiginal + 4, Ororiginal + 6, 3);
    printf("%s\n", Myresult);
	printf("%s\n", Orresult);
    return 0;
}
==============================================================================
- Have in mind that 'size_t' is equivalent to 'UNSIGNED long int', so it never
will be negative, therefore I cannot use it in 'while (i >= 0)'. So I have to
use 'while (i > 0)' and then add the case 'i = 0'
- I can cast the pointers outside the while loop, like this:
unsigned char		*tempdest;
const unsigned char	*tempsrc;
tempdest = (unsigned char *)dest;
tempsrc = (const unsigned char *)src;
And then work with the new variables; but this way means more code lines
- When checking overlaping, I cast to char (char *) to use pointer arithmetic
- I can fill the original arrays with strcpy, like this:
strcpy(original, "This is testing str") instead of filling it when
declaring them (char original[] = "This is testing str")
- I have to cast 's' and 'c' to unsigned char because I'm receiving any value
(void) and I'm setting the maximum byte value wich is 255
(binary: 11111111)(hexadecimal: 0xFF)
*/
