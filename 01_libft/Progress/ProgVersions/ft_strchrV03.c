/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marondon <marondon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:57:36 by marondon          #+#    #+#             */
/*   Updated: 2023/09/13 13:07:41 by marondon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	slen;

	slen = ft_strlen(s);
	i = 0;
	while (i <= slen)
	{
		if (s[i] == c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <ctype.h>
int	main(void)
{
	char	str[] = "_-+*!$%&0123456789ThisisAprettylongString";
	int		i;
	int valtolook;
	

	valtolook = 'i';
	i = 0;
	printf("Source strg: ");
	while (str[i] != '\0')
	{
		printf("%c", str[i]);
		i++;
	}
	i = 0;
	printf("\nMy Function: ");
	char	*myResult = ft_strchr(str, valtolook);
	if (myResult == NULL)
		printf("%c is not in the string", valtolook);
	else
	{
		while (myResult != NULL && myResult[i] != '\0')
		{
			printf("%c", myResult[i]);
			i++;
		}
	}
	i = 0;
	printf("\nOriginal Fn: ");
	char	*origResult = strchr(str, valtolook);
	if (origResult == NULL)
		printf("%c is not in the string", valtolook);
	else
	{
		while (origResult != NULL && origResult[i] != '\0')
		{
			printf("%c", origResult[i]);
			i++;
		}
		return (0);
	}
}
- I also have to include the '\0', So I have to check when i=strlen(s)
- This part "return (char *)(s + i)" is for casting (changing) the type of
what I'm returning (from s+i which is a pointer to char in position i) of a
CONSTANT char *; to a normal pointer (char *). This is necessary because the
original function is prototiped like: I receive "const char *", and I return
"char *"
- Note that *myResult is "equal" to myResult[]. So I can change:
i=0
while origResult[i] != '\0'
printf("%c", OrigResult[i])
i++;

To:
while (*origResult != '\0') {
printf("%c", *origResult);
origResult++;
- Here (char *origResult = strchr(str, valtolook);) I'm creating the pointer
and asigning its value.  and here (if (origResult == NULL)) I'm checking if
the pointer is NULL. If I use *origResult == NULL; Iĺl get an error because
I'm comparing a value to a pointer NULL*/
