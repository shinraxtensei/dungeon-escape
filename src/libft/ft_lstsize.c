/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouari <ahouari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 08:45:53 by ahouari           #+#    #+#             */
/*   Updated: 2021/11/12 14:53:04 by ahouari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<stdio.h>
int	ft_lstsize(t_list *lst)
{
	size_t	len;
	t_list	*current;

	len = 0;
	current = lst;
	while (current)
	{
		current = current->next;
		len++;
	}
	return (len);
}
int main ()
{
	t_list *n1,*n2,*n3;
	n1 = (t_list *)malloc(sizeof(t_list));
	n2 = (t_list *)malloc(sizeof(t_list));
	n3 = (t_list *)malloc(sizeof(t_list));
	n1->next = n2;
	n2->next = n3;
	n3->next = NULL;
	printf("%d",ft_lstsize(n1));
}