/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 17:40:12 by tvermeil          #+#    #+#             */
/*   Updated: 2016/01/15 00:05:58 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"
#include <stdio.h> //

/*t_pile	*get_inferior_block(t_pile *block)
{
	t_pile	*start;
	int		reference;
	int		best;
	int		init;

	if (block == NULL)
		return (NULL);
	best = reference = block->value;
	start = block;
	init = 0;
	while (block->next != start)
	{
		block = block->next;
		best = (init++ == 0 || (block->value < reference
				&& block->value > best)) ? block->value : best;
	}
	while (block->value != best)
		block = block->next;
	printf("reference : %d, inferior : %d at %p\n", reference, block->value, block);
	return (block);
}*/

t_pile	**choose_op(t_pile *pile_tab[], char **op_lst, char *flags)
{
	t_pile	*next;
	int		dist;
	int		size;

	ft_putendl("in chooser"); //
	size = get_pile_size(pile_tab[0]);
	next = get_next_unsorted(pile_tab[0]);
	dist = get_dist(pile_tab[0], next);
	//printf("next : %d at %p, dist : %d\n", next->value, next, dist); //
	if (dist < size / 2)
	{
		//printf("about to rotate : next : %d at %p, dist : %d\n", next->value, next, dist); //
		pile_tab = rotate_swap_n(pile_tab, op_lst, flags, dist + 1);
	}
	else if (next != NULL)
	{
		dist = get_pile_size(pile_tab[0]) - dist - 1;
		printf("push_swapping %d blocks\n", dist); //
		pile_tab = push_swap_n(pile_tab, op_lst, flags, dist + 1, 1); // should be dist from top
	}
	else if (pile_tab[1] != NULL)
		pile_tab = push_swap_n(pile_tab, op_lst, flags, get_pile_size(pile_tab[1]) + 1, 0);
	return (pile_tab);
}

char	*solve(t_pile *pile_tab[], char *flags)
{
	char	*op_lst;

	op_lst = NULL;
	ft_putendl("start solving");
	while (pile_tab[1] != NULL || get_next_unsorted(pile_tab[0]) != NULL)
	{
		pile_tab = choose_op(pile_tab, &op_lst, flags);
	}
	ft_putendl("stopped solving");
	return (op_lst);
}
