/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marondon <marondon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:47:29 by marondon          #+#    #+#             */
/*   Updated: 2023/09/05 17:42:31 by marondon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == c)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	*str = "_-+*!$%&0123456789ThisisAprettylongString";
	int valtolook;
	int	i;

	i = 0;
	valtolook = 'i';
	printf("Source strg: ");
	while (str[i] != '\0')
	{
		printf("%c", str[i]);
		i++;
	}
	printf("\nMy Function: ");
	char	*myResult = ft_strrchr(str, valtolook);
	if (myResult == NULL)
		printf("%c is not in the string", valtolook);
	else
	{
		while (myResult != NULL && *myResult != '\0')
		{
			printf("%c", *myResult);
			myResult++;
		}
	}
	printf("\nOriginal Fn: ");
	char	*origResult = strrchr(str, valtolook);
	if (origResult == NULL)
		printf("%c is not in the string", valtolook);
	else
	{
		while (origResult != NULL && *origResult != '\0')
		{
			printf("%c", *origResult);
			origResult++;
		}
		return (0);
	}
}
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