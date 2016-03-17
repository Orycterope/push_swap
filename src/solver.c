/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 17:40:12 by tvermeil          #+#    #+#             */
/*   Updated: 2016/03/17 14:17:02 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"
#include "string_utils.h"

static int	should_rotate_swap(t_pile *pile)
{
	t_pile	*top;
	int		rank;

	if (get_pile_size(pile) < 4)
		return (0);
	top = pile->previous;
	rank = 1;
	while (get_rank_of(top) == rank)
	{
		rank++;
		top = top->previous;
	}
	return (rank == get_pile_size(top) - 1
			&& get_rank_of(top) == get_pile_size(top)
			&& get_rank_of(top->previous) == get_pile_size(top) - 1);
}

static int	should_reverse_rotate(t_pile *pile)
{
	t_pile	*block1;
	t_pile	*block2;
	int		dist;

	dist = 0;
	block1 = pile->previous;
	block2 = pile->previous;
	while (get_rank_of(block1) != 1)
		block1 = block1->next;
	while (block1 != block2)
	{
		block1 = block1->next;
		dist++;
	}
	if (dist > get_pile_size(block1) / 2)
		return (1);
	return (0);
}

t_pile		**push_all_a(t_pile *pile_tab[], char **op_lst, char *flags)
{
	while (pile_tab[1] != NULL)
		pile_tab = do_operation("pa", pile_tab, op_lst, flags);
	return (pile_tab);
}

t_pile		**push_all_b(t_pile *pile_tab[], char **op_lst, char *flags)
{
	t_pile	*top;

	top = pile_tab[0]->previous;
	if (is_sorted(pile_tab[0]))
		return (push_all_a(pile_tab, op_lst, flags));
	else if (should_rotate_swap(pile_tab[0]))
		return (rotate_swap(pile_tab, op_lst, flags));
	else if (get_rank_of(top) == 1)
		return (do_operation("pb", pile_tab, op_lst, flags));
	else if (get_rank_of(top) > get_rank_of(top->previous))
		return (do_operation("sa", pile_tab, op_lst, flags));
	else if (should_reverse_rotate(pile_tab[0]))
		return (do_operation("rra", pile_tab, op_lst, flags));
	else
		return (do_operation("ra", pile_tab, op_lst, flags));
}

char		*solve(t_pile *pile_tab[], char *flags)
{
	char	*op_lst;

	op_lst = NULL;
	while (pile_tab[1] != NULL || is_sorted(pile_tab[0]) == 0)
		pile_tab = push_all_b(pile_tab, &op_lst, flags);
	return (op_lst);
}
