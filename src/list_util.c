/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 18:49:57 by tvermeil          #+#    #+#             */
/*   Updated: 2016/03/15 19:20:11 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_util.h"

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

int		next_unsorted(t_pile *pile)
{
	int		i;
	t_pile	*top;
	t_pile	*bottom;

	if (pile == NULL)
		return (0);
	i = 0;
	bottom = pile;
	/*while (get_rank_of(bottom) != get_pile_size(pile))
	{
		i++;
		bottom = bottom->next;
	}*/
	top = bottom->previous;
	while (bottom != top && bottom->next != top)
	{
		if (get_rank_of(bottom) != get_rank_of(bottom->next) + 1
			|| get_rank_of(top) != get_rank_of(top->previous) + 1)
			return (i);
		bottom = bottom->next;
		top = top->previous;
		i++;
	}
	return (0);
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
