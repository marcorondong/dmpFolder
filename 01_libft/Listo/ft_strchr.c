/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marondon <marondon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:57:36 by marondon          #+#    #+#             */
/*   Updated: 2023/09/14 13:40:13 by marondon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	char_to_look;

	if (!s)
		return (NULL);
	char_to_look = (char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == char_to_look)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	char	str[] = "tripouille";
	// "_-+*!$%&0123456789ThisisAprettylongString"
	int		i;
	int valtolook = 't' + 256;
	// 'i'
	
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
==============================================================================
I check first if 's' is not null and then I'll access it: if (!s) return NULL
==============================================================================
I had an error before. I had 'invalid read of size 1'
because I was using ft_strlen and when iterating, I was cheching this:
while (i <= slen) And it should be 'i < slen' so I don't go outside boundaries

This was the code with the error:
char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	slen;
	char	char_to_look;

	char_to_look = (char)c;
	slen = ft_strlen(s);
	i = 0;
	while (i <= slen) // Here is the error: '<=' and it shoudl be '<'
	{
		if (s[i] == char_to_look)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}

==============================================================================
- I cast 'c' to type 'char' because char goes from -128 to 127; And int goes
from -2147483648 to 2147483647.
I can also cast it inside 'if statement' inside the while loop:
'if (s[i] == (char)c)' and in this way I don't have to declare a new variable
nor asssign the value
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
the pointer is NULL. If I use *origResult == NULL; I'ĺl get an error because
I'm comparing a value to a pointer NULL
*/
