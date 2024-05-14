/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marondon <marondon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:10:36 by marondon          #+#    #+#             */
/*   Updated: 2023/09/13 21:14:57 by marondon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	ft_storechar(char a, int *i, char *numstr)
{
	// Use '*i' to use value of 'i'. If i don't use '*'
	// then is i address, since I receive pointer
	numstr[*i] = a;
	(*i)++;
}

static void	ft_putnbr(int nb, int *i, char *numstr)
{
	// Check for lowest int, and 'disassemble' it
	if (nb == -2147483648)
	{
		ft_storechar('-', i, numstr);
		ft_storechar('2', i, numstr);
		ft_putnbr(147483648, i, numstr);
	}
	// Check if 'nb' negative, store '-' sign, change sing, run with +nb
	else if (nb < 0)
	{
		ft_storechar('-', i, numstr);
		nb = -nb;
		ft_putnbr(nb, i, numstr);
	}
	// '/' for nb 1st digit. '% = modulo' for rest. then recursion to
	// 'disassembly' it
	else if (nb > 9)
	{
		ft_putnbr(nb / 10, i, numstr);
		ft_putnbr(nb % 10, i, numstr);
	}
	// Print singe-digit number. +48 to change to ascii numbers
	else
	{
		ft_storechar(nb + 48, i, numstr);
	}
}

char	*ft_itoa(int n)
{
	int		i;
	long	acum; // Type long to convert -2147483648 to 2147483648
	char	*numstr;

	i = 1; // Will always have at least one number
	acum = n;
	//Check if negative and convert to positive. i +1 for '-' sign
	if (acum < 0)
	{
		acum = -acum;
		i++;
	}
	// Check for how many digits
	while (acum / 10 > 0)
	{
		acum = (acum / 10);
		i++;
	}
	// +1 fir the '\0'
	numstr = (char *)malloc((i + 1) * sizeof(char));
	// Malloc protecion
	if (!numstr)
		return (NULL);
	i = 0;
	// Send REAL 'i' with &i (address of i) so it get updated
	ft_putnbr(n, &i, numstr);
	numstr[i] = '\0'; // End string with '\0'
	return (numstr);
}
/*
#include <stdio.h>
#include <unistd.h>
int	 main(void)
{
	//int	n = -2147483648;
	char	*c;
	int	i = 0;

	c = ft_itoa(-2147483648);
	//printf("%s", ft_itoa(-2147483648LL));
	//printf("\n%i", n);
	//printf("%s", c);
	while (c[i] != '\0')
	{
		write(1,&c[i],1);
		i++;
	}
	free(c);
	return (0);
}
==============================================================================
- I use type 'long' in 'acum' because when I convert -2147483648 (INT_MIN)
to positive 2147483648, that number is NOT an integer anymore.  The biggest
int is 2147483647 (INT_MAX).
- When counting the digits with: while (acum / 10 > 0)
if I have a negative number, this won't work. So I have to change it
to positive and add 1byte for the '-' sign.
- I start with i = 1 because I'll always have 1 number and the whay
I'm couting digits doesn't count one-digit numbers
*/
