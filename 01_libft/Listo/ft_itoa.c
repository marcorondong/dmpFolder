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
	long	acum;
	char	*numstr;

	i = 1;
	acum = n;
	if (acum < 0)
	{
		acum = -acum;
		i++;
	}
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
Other approaches to do it:
=========== Approach 1: only for ft_putnbr
void	ft_putnbr(int nb, int *i, char *numstr)
{
    char base_digits[] = "0123456789";  // This could be used for the
    					// conversion of number to char

    if (nb < 0)
    {
        ft_storechar('-', i, numstr);
        if (nb == -2147483648)  // If it's the smallest integer
        {
            ft_storechar('2', i, numstr);
            nb = 147483648;
        }
        else
            nb = -nb;
    }
    if (nb >= 10)  // If it's bigger than my base
        ft_putnbr(nb / 10, i, numstr);
    ft_storechar(base_digits[nb % 10], i, numstr);  // handle the last digit
    					// without additional recursion
}
===========
- I use type 'long' in 'acum' because when I convert -2147483648 (INT_MIN)
to positive 2147483648, that number is NOT an integer anymore.  The biggest
int is 2147483647 (INT_MAX).
- When counting the digits with: while (acum / 10 > 0)
if I have a negative number, this won't work. So I have to change it
to positive and add 1byte for the '-' sign.
- I start with i = 1 because I'll always have 1 number and the whay
I'm couting digits doesn't count one-digit numbers
*/
