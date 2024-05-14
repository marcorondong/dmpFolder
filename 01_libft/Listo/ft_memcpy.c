/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marondon <marondon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:41:49 by marondon          #+#    #+#             */
/*   Updated: 2023/09/13 21:21:38 by marondon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;	

	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((const unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
    char	*Myresult;
    char	*Orresult;
    char	Myoriginal[] = "This is testing str MyFn";
    char	Mynewcopy[50];
	char	Ororiginal[50] = "This is testing str OrFn";
	char	Ornewcopy[50];

    Myresult = ft_memcpy(Mynewcopy, Myoriginal, 24);
	Orresult = memcpy(Ornewcopy, Ororiginal, 24);
    Mynewcopy[24] = 0;
    Ornewcopy[24] = 0;
    printf("%s\n", Mynewcopy);
	printf("%s\n", Ornewcopy);

    return 0;
}
==============================================================================
- It have to crash when dst OR src are NULL. I shouldn't handle
'if(dst == NULL || src == NULL)'. ONLY handle 'if(dst == NULL && src == NULL)'
- I can cast the pointers outside the while loop, like this:
unsigned char		*tempdest;
const unsigned char	*tempsrc;
tempdest = (unsigned char *)dest;
tempsrc = (const unsigned char *)src;
And then work with the new variables; but this way means more code lines
- I can fill the original arrays with strcpy, like this:
strcpy(original, "This is testing str") instead of filling it when
declaring them (char original[] = "This is testing str")
- I have to cast 's' and 'c' to unsigned char because I'm receiving any value
(void) and I'm setting the maximum byte value wich is 255
(binary: 11111111)(hexadecimal: 0xFF)
*/
