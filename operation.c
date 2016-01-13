/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 20:03:19 by tvermeil          #+#    #+#             */
/*   Updated: 2016/01/13 21:57:06 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"

t_pile	*operation_swap(t_pile *pile)
{
	if (pile == NULL)
		return (NULL);
	if (pile->next->next == pile)
		return (pile->next);
	pile = pile->previous;
	pile->previous->previous->next = pile;
	pile->previous->next = pile->next;
	pile->next->previous = pile->previous;
	pile->previous = pile->previous->previous;
	pile->next->previous->previous = pile;
	pile->next = pile->next->previous;
	return (pile->next->next);
}

t_pile	*operation_rotate(t_pile *pile, int sens)
{
	if (pile == NULL)
		return (NULL);
	if (sens > 0)
		return (pile->previous);
	else
		return (pile->next);
}

t_pile	**operation_push(t_pile *pile_tab[], int to)
{
	t_pile	*block;

	if (to == 0)
	{
		if (pile_tab[1] == NULL)
			return (pile_tab);
		block = pile_tab[1]->previous;
		pile_tab[0] = append_to_pile(block->value, pile_tab[0]);
		pile_tab[1] = remove_from_pile(block);
	}
	else
	{
		if (pile_tab[0] == NULL)
			return (pile_tab);
		block = pile_tab[0]->previous;
		pile_tab[1] = append_to_pile(block->value, pile_tab[1]);
		pile_tab[0] = remove_from_pile(block);
	}
	//free(block);
	return (pile_tab);
}
