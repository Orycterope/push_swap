/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 17:40:12 by tvermeil          #+#    #+#             */
/*   Updated: 2016/01/22 20:50:20 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"

int		get_rot_nbr(t_pile *pile)
{
	int		size;
	t_pile	*b;
	t_pile	*middle;

	size = get_pile_size(pile) / 2;
	middle = pile;
	while (size--)
		middle = middle->next;
	while (middle != pile)
	{
		b = middle;
		while (b != pile->previous)
		{
			if (b->value < middle->value)
				return (get_dist(pile, middle) + 1);
			b = b->previous;
		}
		middle = middle->previous;
	}
	return (0);
}

t_pile	**reverse_rot_swp(t_pile *tab[], char **oplst, char *flags)
{
	int		n;
	t_pile	*top;

	n = 0;
	top = tab[0]->previous;
	if (get_rank_of(top) >= get_pile_size(tab[0]) / 2
			&& top->value < tab[0]->value)
		n++;
	if (get_rank_of(top->previous) >= get_pile_size(tab[0]) / 2
			&& top->previous->value < tab[0]->value)
		n++;
	if ((n == 1 && top->value < top->previous->value)
			|| (n == 2 && top->value > top->previous->value))
		tab = do_swap_op("sa", tab, oplst, flags);
	if (n > 0)
		tab = do_rot_op("rra", tab, oplst, flags);
	return (tab);
}

t_pile	**choose_op(t_pile *pile_tab[], char **op_lst, char *flags)
{
	t_pile	*next;
	int		dist;
	int		size;

	size = get_pile_size(pile_tab[0]);
	next = get_next_unsorted(pile_tab[0]);
	dist = get_dist(pile_tab[0], next);
	if (next != NULL && dist + 1 < size / 2)
	{
		dist = get_rot_nbr(pile_tab[0]);
		pile_tab = rotate_swap_n(pile_tab, op_lst, flags, dist);
	}
	if (size > 3)
		pile_tab = reverse_rot_swp(pile_tab, op_lst, flags);
	if (next != NULL)
		pile_tab = push_swap(pile_tab, op_lst, flags, 1);
	else if (pile_tab[1] != NULL)
		pile_tab = push_swap(pile_tab, op_lst, flags, 0);
	return (pile_tab);
}

char	*solve(t_pile *pile_tab[], char *flags)
{
	char	*op_lst;

	op_lst = NULL;
	while (pile_tab[1] != NULL || get_next_unsorted(pile_tab[0]) != NULL)
		pile_tab = choose_op(pile_tab, &op_lst, flags);
	return (op_lst);
}
