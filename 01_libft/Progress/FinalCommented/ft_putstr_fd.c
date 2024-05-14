/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marondon <marondon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:07:28 by marondon          #+#    #+#             */
/*   Updated: 2023/09/13 17:03:58 by marondon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i; // To count as long as 's'  could go

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}
/*
int	main(void)
{
	char	s1[] = "Testing";
	char	s2[] = "-the-";
	char	s3[] = "function";
	
	ft_putstr_fd(s1, 1);
	ft_putstr_fd(s2, 1);
	ft_putstr_fd(s3, 1);
	return (0);
}
==============================================================================
- I can use write() and not my ft_putchar_fd so it'll look like this:
while (*s) // While 's' exist (or doesn't reach '\0')
{
	write (fd, s, 1);
	s++;
}
*/
