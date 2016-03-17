/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 18:49:57 by tvermeil          #+#    #+#             */
/*   Updated: 2016/03/17 14:14:14 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_util.h"
#include "operation.h"

int		get_pile_size(t_pile *pile)
{
	int		size;
	t_pile	*start;

	if (pile == NULL)
		return (0);
	start = pile;
	size = 1;
	while (pile->next != start)
	{
		pile = pile->next;
		size++;
	}
	return (size);
}

int		get_dist(t_pile *block1, t_pile *block2)
{
	int	dist;

	if (block1 == NULL || block2 == NULL)
		return (0);
	dist = 0;
	while (block1 != block2)
	{
		block1 = block1->next;
		dist++;
	}
	if (dist > get_pile_size(block1) / 2)
		return (-(dist - get_pile_size(block1) / 2));
	return (dist);
}

int		is_sorted(t_pile *pile)
{
	t_pile	*end;

	if (pile == NULL)
		return (1);
	end = pile->previous;
	while (pile != end)
	{
		if (pile->value < pile->next->value)
			return (0);
		pile = pile->next;
	}
	return (1);
}

int		get_rank_of(t_pile *pile)
{
	t_pile	*start;
	int		rank;

	start = pile;
	rank = 0;
	pile = pile->next;
	while (pile != start)
	{
		if (pile->value < start->value)
			rank++;
		pile = pile->next;
	}
	return (rank + 1);
}

t_pile	**do_operation(char *op, t_pile *pile_tab[], char **op_lst, char *flags)
{
	if (op[0] == 's')
		pile_tab = do_swap_op(op, pile_tab, op_lst, flags);
	else if (op[0] == 'p')
	{
		pile_tab = operation_push(pile_tab, (op[1] == 'a') ? 0 : 1);
		if (op_lst != NULL)
			add_operation(pile_tab, flags, op_lst, op);
	}
	else
		pile_tab = do_rot_op(op, pile_tab, op_lst, flags);
	return (pile_tab);
}
