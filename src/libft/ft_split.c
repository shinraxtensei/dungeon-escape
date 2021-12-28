/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouari <ahouari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 08:10:21 by ahouari           #+#    #+#             */
/*   Updated: 2021/12/28 11:33:46 by ahouari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<stdio.h>
static size_t	count_strs(char  *str, char c)
{
	size_t	count;

	count = 0;
	while (*str != '\0')
	{
		if (*str != c)
		{
			count++;
			while (*str != '\0' && *str != c)
				str++;
		}
		else
			str++;
	}
	return (count);
}

char	**ft_split(char  *s, char c)
{
	size_t		len;
	size_t		i;
	const char	*start;
	char		**arr_strs;

	if (!s)
		return (NULL);
	arr_strs = (char **) malloc(((count_strs(s, c)) + 1) * sizeof(*arr_strs));
	if (!arr_strs)
		return (NULL);
	i = 0;
	while (*s != '\0')
	{
		while (*s && *s == c)
			s++;
		start = s;
		len = 0;
		s--;
		while (*(++s) && *(s) != c)
			len++;
		//if (*(s - 1) != c)
		arr_strs[i++] = ft_substr(start, 0, len);
	}

	arr_strs[i] = 0;
	return (arr_strs);
}