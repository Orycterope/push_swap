/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 18:49:57 by tvermeil          #+#    #+#             */
/*   Updated: 2016/01/15 00:14:11 by tvermeil         ###   ########.fr       */
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
	return (dist);
}

int		get_shortest_dist(t_pile *block1, t_pile *block2)
{
	int		dist;
	int		size;

	size = get_pile_size(block1);
	dist = get_dist(block1, block2);
	if (dist > size / 2)
		dist = -(size - dist);
	return (dist);
}

t_pile	*get_next_unsorted(t_pile *pile)
{
	t_pile	*start;

	if (pile == NULL)
		return (NULL);
	pile = pile->previous;
	start = pile;
	while (pile->previous != start)
	{
		if (pile->value > pile->previous->value)
			return (pile);
		pile = pile->previous;
	}
	return (NULL);
}

int		get_rank_of(t_pile *pile) //used ?
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
	return (rank);
}
