/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marondon <marondon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:50:15 by marondon          #+#    #+#             */
/*   Updated: 2023/09/13 16:38:35 by marondon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
int	main(void)
{
	ft_putchar_fd('0', 1);
	return (0);
}
==============================================================================
- I should NOT check 'if c!' because NULL (or 0) is also a ASCII char,
but c! will exclude it.
- I don't have to cast to usigned char because I'm receiving char
- Write function prototipe is: int write(int fd , void *buf, size_t n). So:
1. File descriptor: fd (of type int)
2. What I want to write: *buf (of type void)
3. How many things I want to write: n (of type size_t)
*/
