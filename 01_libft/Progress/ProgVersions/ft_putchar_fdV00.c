/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marondon <marondon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:50:15 by marondon          #+#    #+#             */
/*   Updated: 2023/09/12 12:10:23 by marondon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	if (!c || !fd)
		return ;
	write(fd, &c, 1);
}
/*
int	main(void)
{
	ft_putchar('t');
	return (0);
}
- Write function prototipe is: int	write(int fd , void *buf, size_t n)
So:
1. File descriptor: fd (of type int)
2. What I want to write: *buf (of type void)
3. How many things I want to write: n (of type size_t)
*/