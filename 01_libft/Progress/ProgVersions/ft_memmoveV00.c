/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marondon <marondon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 19:27:07 by marondon          #+#    #+#             */
/*   Updated: 2023/09/06 20:35:10 by marondon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*tempcpy;

	tempcpy = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = tempcpy[i];
		i++;
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

- I can cast the pointers inside the while loop, like this:
((unsigned char *)dest)[i] = ((const unsigned char *)src)[i];
In this way, I dont have to declare new variables and initialize them
like I did in this excercise
- I can fill the original arrays with strcpy, like this:
strcpy(original, "This is testing str") instead of filling it when
declaring them (char original[] = "This is testing str")
*/
