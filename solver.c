/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 17:40:12 by tvermeil          #+#    #+#             */
/*   Updated: 2016/01/14 17:56:00 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"
#include <stdio.h> //

t_pile	**choose_op(t_pile *pile_tab[], char **op_lst, char *flags)
{
	t_pile	*next;
	int		dist;

	ft_putendl("in chooser"); //
	next = get_next_unsorted(pile_tab[0]);
	dist = get_dist(pile_tab[0], next);
	printf("next : %p, dist : %d\n", next, dist); //
	if (next != NULL)
	{
		dist = get_pile_size(pile_tab[0]) - dist;
		printf("push_swapping %d blocks\n", dist); //
		pile_tab = push_swap_n(pile_tab, op_lst, flags, dist); // should be dist from top
	}
	else if (pile_tab[1] != NULL)
		pile_tab = push_all_a(pile_tab, op_lst, flags);
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
