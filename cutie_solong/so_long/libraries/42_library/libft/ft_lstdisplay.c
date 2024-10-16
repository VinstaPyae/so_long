/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdisplay.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klinn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:29:20 by klinn             #+#    #+#             */
/*   Updated: 2024/04/09 17:32:04 by klinn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdisplay(t_list *lst)
{
	t_list	*t;

	t = lst;
	while (t)
	{
		ft_printf("%d\n", t->data);
		ft_printf("%d\n\n", t->index);
		t = t->next;
	}
}