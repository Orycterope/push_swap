/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 18:49:57 by tvermeil          #+#    #+#             */
/*   Updated: 2016/01/13 19:30:04 by tvermeil         ###   ########.fr       */
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

	dist = get_dist(block1, block2);
	if (dist > get_pile_size(block1) / 2)
		dist = -dist;
	return (dist);
}

t_pile	*get_next_unsorted(t_pile *pile)
{
	t_pile	*start;

	start = pile;
	while (pile->next != start)
	{
		if (pile->value < pile->next->value)
			return (pile);
	}
	return (NULL);
}
