/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marondon <marondon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:10:36 by marondon          #+#    #+#             */
/*   Updated: 2023/09/13 17:38:02 by marondon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	ft_storechar(char a, int *i, char *numstr)
{
	numstr[*i] = a;
	(*i)++;
}

static void	ft_putnbr(int nb, int *i, char *numstr)
{
	if (nb == -2147483648)
	{
		ft_storechar('-', i, numstr);
		ft_storechar('2', i, numstr);
		ft_putnbr(147483648, i, numstr);
	}
	else if (nb < 0)
	{
		ft_storechar('-', i, numstr);
		nb = -nb;
		ft_putnbr(nb, i, numstr);
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10, i, numstr);
		ft_putnbr(nb % 10, i, numstr);
	}
	else
	{
		ft_storechar(nb + 48, i, numstr);
	}
}

char	*ft_itoa(int n)
{
	int		i;
	int		acum;
	char	*numstr;

	i = 1;
	acum = n;
	while (acum / 10 > 0)
	{
		acum = (acum / 10);
		i++;
	}
	numstr = (char *)malloc((i + 1) * sizeof(char));
	if (!numstr)
		return (NULL);
	i = 0;
	ft_putnbr(n, &i, numstr);
	numstr[i] = '\0';
	return (numstr);
}
/*
#include <stdio.h>
int	 main(void)
{
	int	n = -9;
	char	*c;

	c = ft_itoa(n);
	//printf("%s", ft_itoa(n));
	//printf("\n%i", n);
	printf("%s", c);
	free(c);
	return (0);
}
*/