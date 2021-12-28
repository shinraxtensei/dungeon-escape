/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouari <ahouari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 14:22:39 by ahouari           #+#    #+#             */
/*   Updated: 2021/11/24 09:54:01 by ahouari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t		idx;

	if (dest == src || !len)
		return (dest);
	idx = 0;
	/*if (dest < src)
	{
		while (idx < len)
		{
			*((char *)dest + idx) = *((char *)src + idx);
			idx++;
		}
	}
	else*/
	{
		while (len > 0)
		{
			*((char *)dest + len - 1) = *((char *)src + len - 1);
			len--;
		}
	}
	return (dest);
}