/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marondon <marondon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 12:02:27 by marondon          #+#    #+#             */
/*   Updated: 2023/09/08 14:00:23 by marondon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	b;
	size_t	l;

	//If little is empty, I return big
	if (little[0] == '\0')
		return (big);
	b = 0;
	l = 0;
	// I start traversing little (more efficient)
	// considering "no more than len"
	while (little[l] != '\0' && l < len)
	{
		if (little[l] == big[b])
		{
			l++;
			b++;
		}
		else
		{
			l = 0;
			b++;
		}
	}
	if (little[l] == '\0')
		return (little - big);
	return (NULL);
}
/*
===========2nd try:
char	*strnstr(const char *big, const char *little, size_t len)
{
	size_t	b;
	site_t	l;

	//If little is empty, I return big
	if (little[0] == '\0')
		return (str);
	b = 0;
	l = 0;
	// I start traversing little (more efficient)
	while (little[l] != '\0') // I have to include "no more than len"
	{
		if (little[l] == big[b])
			l++;
			b++;
		else
			l = 0;
			b++;
	}
	if (little[l] == '\0')
		return (little - big);
	return (NULL);
}
===========1st try:
	size_t	b;
	site_t	l;

	//If little is empty, I return big
	if (little[0] == '\0')
		return (str);
	b = 0;
	l = 0;
	// I start traversing big
	while (big[b] != '\0')
	{
		if (big[b] == little[l])
			b++;
			l++;
		else
			l = 0;
			b++;
	if (litle[l] == '\0')
		return (little - big);
	}

	return (NULL)
}
*/
