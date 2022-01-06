/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouari <ahouari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 14:22:39 by ahouari           #+#    #+#             */
/*   Updated: 2022/01/03 10:01:41 by ahouari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t		idx;

	if (dest == src || !len)
		return (dest);
	idx = 0;
	{
		while (len > 0)
		{
			*((char *)dest + len - 1) = *((char *)src + len - 1);
			len--;
		}
	}
	return (dest);
}
