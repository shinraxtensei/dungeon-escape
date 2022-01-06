/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 13:17:44 by ahouari           #+#    #+#             */
/*   Updated: 2021/11/06 14:27:30 by ahouari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*tmp;

	tmp = NULL;
	while (*(char *) str)
	{
		if ((char)*str == (char) c)
			tmp = (char *)str;
		str++;
	}
	if (c == 0)
		return ((char *)str);
	return (tmp);
}
