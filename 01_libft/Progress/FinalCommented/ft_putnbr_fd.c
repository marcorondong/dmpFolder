/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marondon <marondon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:14:45 by marondon          #+#    #+#             */
/*   Updated: 2023/09/12 13:25:51 by marondon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	// Check for lowest int, and 'disassemble' it
	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		ft_putnbr_fd(147483648, fd);
	}
	// Check if 'nb' negative, store '-' sign, change sing, run with +nb
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
		ft_putnbr_fd(n, fd);
	}
	// '/' for nb 1st digit. '% = modulo' for rest. then recursion to
	// 'disassembly' it
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	// Print singe-digit number. +48 to change to ascii numbers
	else
	{
		ft_putchar_fd(n + 48, fd);
	}
}
/*
int	main(void)
{
	ft_putnbr_fd(-2147483648, 1);
	return (0);
}
==============================================================================
- ASCII numbers go from value 48 to 57 and since im working with integers,
then im working with values, and +48 is to go to ASCII number range
*/
