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

int		get_sorted_amount_of_pile(t_pile *pile, int sens)
{
	int		size;
	int		rank;
	int		out;

	if (pile == NULL)
		return (0);
	size = get_pile_size(pile);
	out = 0;
	rank = (sens == 1) ? 1 : size;
	while ((sens == 1 && rank != size) || (sens == -1 && rank != 0))
	{
		if (get_rank_of(pile) == rank)
			out += rank;
		if ((sens == 1 && get_rank_of(pile->next) == rank + 1)
				|| (sens == -1 && get_rank_of(pile->next) == rank - 1))
			out *= rank;
		rank += sens;
		pile = pile->next;
	}
	return (out);
}

int		get_sorted_amount(t_pile *pile_tab[])
{
	return (get_sorted_amount_of_pile(pile_tab[0], 1)
		+ get_sorted_amount_of_pile(pile_tab[1], -1) / 2);
}

t_pile	**choose_op(t_pile *pile_tab[], char **op_lst, char *flags)
{
	const char	*best_op;
	char		*operations[] = {"sa", "sb", "ss", "ra", "rb", "rra", "rrb", "rr", "rrr", NULL };
	char		*reverse_op[] = {"sa", "sb", "ss", "rra", "rrb", "ra", "rb", "rrr", "rr", NULL };
	int			best_value;
	int			current_value; // not so useful
	int			i;

	pile_tab = do_operation("sa", pile_tab, NULL, NULL);
	best_op = "sa";
	best_value = get_sorted_amount(pile_tab);
	pile_tab = do_operation("sa", pile_tab, NULL, NULL);

	i = 0;
	while (operations[i] != NULL)
	{
		pile_tab = do_operation(operations[i], pile_tab, NULL, NULL);
		current_value = get_sorted_amount(pile_tab);
		best_op = (current_value > best_value) ? operations[i] : best_op;
		best_value = (current_value > best_value) ? current_value : best_value;
		pile_tab = do_operation(reverse_op[i], pile_tab, NULL, NULL);
		i++;
	}
	pile_tab = do_operation((char *)best_op, pile_tab, op_lst, flags);
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
