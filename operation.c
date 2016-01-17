/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 20:03:19 by tvermeil          #+#    #+#             */
/*   Updated: 2016/01/14 22:33:23 by tvermeil         ###   ########.fr       */
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
	return (pile_tab);
}

t_pile	**do_rot_op(char *op, t_pile *pile_tab[], char **op_lst, char *flags)
{
	if (op[0] == '\0')
		return (pile_tab);
	op++;
	if (op[2] == 'r')
	{
		pile_tab[0] = operation_rotate(pile_tab[0], -1);
		pile_tab[1] = operation_rotate(pile_tab[1], -1);
	}
	else if (op[1] == 'r' && op[2] == '\0')
	{
		pile_tab[0] = operation_rotate(pile_tab[0], 1);
		pile_tab[1] = operation_rotate(pile_tab[1], 1);
	}
	else if (op[0] == 'a')
		pile_tab[0] = operation_rotate(pile_tab[0], 1);
	else if (op[0] == 'r' && op[1] == 'a')
		pile_tab[0] = operation_rotate(pile_tab[0], -1);
	else if (op[0] == 'b')
		pile_tab[1] = operation_rotate(pile_tab[1], 1);
	else if (op[0] == 'r' && op[1] == 'b')
		pile_tab[1] = operation_rotate(pile_tab[1], -1);
	add_operation(pile_tab, flags, op_lst, --op);
	return (pile_tab);
}
