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

	if (dest == src)
		return (dest);
	if (src < dest && (char *)src + n > (char *)dest)
	{
		i = n - 1;
		while (i >= 0)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
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
*/