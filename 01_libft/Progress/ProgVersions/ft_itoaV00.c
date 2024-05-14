/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marondon <marondon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:10:36 by marondon          #+#    #+#             */
/*   Updated: 2023/09/11 17:01:52 by marondon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_storechar(char a, int i, char *numstr) // void	ft_putchar(char a)
{
	numstr[i] = a;
	//write(1, &a, 1);
}

char	*ft_putnbr(int nb, char *numstr)
{
	int	i;
	
	if (nb == -2147483648)
	{
		i = 0;
		ft_storechar("-", i, numstr);
		ft_storechar('2', i++, numstr);
		ft_putnbr(147483648, numstr);
	}
	else if (nb < 0)
	{
		i = 0;
		ft_storechar('-', i, numstr);
		nb = -nb;
		i++;
		ft_putnbr(nb, numstr);
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10, numstr);
		ft_putnbr(nb % 10, numstr);
	}
	else
	{
		ft_storechar(nb + 48, i, numstr);
		i++;
	}
}

char	*ft_itoa(int n)
{
	int	i;
	int	acum;
	char	*numstr;
	
	if (n!)
		return (NULL;)
	i = 1; // Because I'll always have at least one number
	acum = n;
	while (acum / 10 > 0) // (acum / (10 * ()))
	{
		acum = (acum / 10);
		i++;
	}
	numstr = (char *)malloc((i + 1) * sizeof(char)); // +1 for '\0'
	if (!numstr) // DOUBT: or it should be: if (numstr == NULL)?
		return (NULL);
	numstr = ft_putnbr(n, numstr);
	numstr[] = '\0';
	return (numstr);
}