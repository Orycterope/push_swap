/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 17:40:12 by tvermeil          #+#    #+#             */
/*   Updated: 2016/03/15 19:53:49 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"
#include <stdio.h>

static int	should_rotate_swap(t_pile *pile)
{
	t_pile	*top;
	int		rank;

	top = pile->previous;
	rank = 1;
	while (get_rank_of(top) == rank)
	{
		rank++;
		top = top->previous;
	}
	return (get_rank_of(top) == get_pile_size(top)
			&& get_rank_of(top->previous) == get_pile_size(top) - 1);
}

t_pile	**rotate_swap(t_pile *pile_tab[], char	**op_lst, char *flags)
{
	pile_tab = do_operation("rra", pile_tab, op_lst, flags);
	pile_tab = do_operation("rra", pile_tab, op_lst, flags);
	pile_tab = do_operation("sa", pile_tab, op_lst, flags);
	pile_tab = do_operation("ra", pile_tab, op_lst, flags);
	pile_tab = do_operation("ra", pile_tab, op_lst, flags);
	return (pile_tab);
}

t_pile	**push_all_a(t_pile *pile_tab[], char **op_lst, char *flags)
{
	while (pile_tab[1] != NULL)
		pile_tab = do_operation("pa", pile_tab, op_lst, flags);
	return (pile_tab);
}

t_pile	**push_all_b(t_pile *pile_tab[], char **op_lst, char *flags)
{
	if (is_sorted(pile_tab[0]))
		return (push_all_a(pile_tab, op_lst, flags));
	else if (should_rotate_swap(pile_tab[0]))
		return (rotate_swap(pile_tab, op_lst, flags));
	else if (get_rank_of(pile_tab[0]->previous) == 1)
		return (do_operation("pb", pile_tab, op_lst, flags));
	else if (get_rank_of(pile_tab[0]->previous) > get_rank_of(pile_tab[0]->previous->previous))
		return (do_operation("sa", pile_tab, op_lst, flags));
	else if (0)
		return (do_operation("rra", pile_tab, op_lst, flags));
	else
		return (do_operation("ra", pile_tab, op_lst, flags));
}

char	*solve(t_pile *pile_tab[], char *flags)
{
	char	*op_lst;

	op_lst = NULL;
	while (pile_tab[1] != NULL || is_sorted(pile_tab[0]) == 0)
		pile_tab = push_all_b(pile_tab, &op_lst, flags);
	return (op_lst);
}
