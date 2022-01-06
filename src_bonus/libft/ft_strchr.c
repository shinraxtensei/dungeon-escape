/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 13:16:30 by ahouari           #+#    #+#             */
/*   Updated: 2021/11/06 10:00:18 by ahouari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strchr(const char *str, int c)
{
	while (*(char *)str)
	{
		if (*(char *)str == (char)c)
			return ((char *) str);
		str++;
	}
	if (c == 0)
	{
		return ((char *)str);
	}
	return (NULL);
}
