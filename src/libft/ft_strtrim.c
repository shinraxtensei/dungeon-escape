/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouari <ahouari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:32:39 by ahouari           #+#    #+#             */
/*   Updated: 2021/11/12 13:16:01 by ahouari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<stdio.h>
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	front;
	size_t	rear;
	char	*str;
	int		i;

	i = 0;
	str = 0;
	if (!s1)
		return (0);
	if (s1 != 0 && set != 0)
	{
		front = 0;
		rear = ft_strlen((char *) s1);
		while (s1[front] && ft_strchr(set, s1[front]))
			front++;
		while (s1[rear - 1] && ft_strchr(set, s1[rear - 1]) && rear > front)
			rear--;
		str = (char *) malloc (sizeof (*s1) * (rear - front + 1));
		if (!str)
			return (NULL);
		while (front < rear)
			str[i++] = s1[front++];
		str[i] = 0;
	}
	return (str);
}