/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marondon <marondon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:46:09 by marondon          #+#    #+#             */
/*   Updated: 2023/09/06 18:26:46 by marondon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = '\0';
		i++;
	}
	return ;
}
/*
int	main(void)
{
	char str1[] = "1234567890";
	char str2[] = "1234567890";
	int	i;

	printf("Before ft_bzero:\n%s\n", str1);
	printf("After ft_bzero:\n");
	ft_bzero(str1, 5);
	i = 0;
	while (i < 10)
	{
		write(1, &str1[i], 1);
		i++;
	}
	printf("\nBefore bzero:\n%s\n", str2);
	printf("After bzero:\n");
	bzero(str2, 5);
	i = 0;
	while (i < 10)
	{
		write(1, &str2[i], 1);
		i++;
	}
    return 0;
}
==============================================================================
- I use write function and specify how many characters it should print because
if not, as printf function, it'll find the '\0' and wont print correctly
*/
