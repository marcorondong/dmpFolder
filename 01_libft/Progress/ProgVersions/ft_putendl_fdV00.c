/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marondon <marondon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:22:07 by marondon          #+#    #+#             */
/*   Updated: 2023/09/13 16:54:49 by marondon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s || !fd)
		return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
/*
int	main(void)
{
	char	s1[] = "Testing";
	char	s2[] = "-the-";
	char	s3[] = "function";

	ft_putendl_fd(s1, 1);
	ft_putendl_fd(s2, 1);
	ft_putendl_fd(s3, 1);
	return (0);
}
*/