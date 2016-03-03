/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 17:40:12 by tvermeil          #+#    #+#             */
/*   Updated: 2016/03/03 17:21:04 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"
#include <stdio.h> //

int		get_sorted_amount_of_pile(t_pile *pile, int sens)
{
	int		size;
	int		rank;
	int		out;

	if (pile == NULL)
		return (0);
	size = get_pile_size(pile);
	out = 0;
	rank = (sens == 1) ? size : 1;
	if (sens == 1)
		out -= next_unsorted(pile);
	while ((sens == 1 && rank != 0) || (sens == -1 && rank != size)) // one less
	{
		if ((sens == 1 && get_rank_of(pile->next) == get_rank_of(pile) - 1)
			|| (sens == -1 && get_rank_of(pile->next) == get_rank_of(pile) + 1))
			out += get_rank_of(pile) * get_rank_of(pile->next) * 100;
		/*if ((sens == 1 && get_rank_of(pile) == size && get_rank_of(pile->previous) == 1)
			|| (sens == -1 && get_rank_of(pile) == size && get_rank_of(pile->next) == 1))
			out += size; */
		rank -= sens;
		pile = pile->next;
	}
	return (out);
}

int		get_sorted_amount(t_pile *pile_tab[])
{
	int		a_score;
	int		b_score;

	a_score = get_sorted_amount_of_pile(pile_tab[0], 1);
	b_score = get_sorted_amount_of_pile(pile_tab[1], -1);
	if (b_score % 2 != 0)
		b_score++;
	return (a_score + b_score / 2);
}

t_pile	**choose_op(t_pile *pile_tab[], char **op_lst, char *flags)
{
	const char	*best_op;
	char		*operations[] = {"sb", "ss", "rra", "rb", "ra", "rrb", "rr", "rrr", NULL };
	char		*reverse_op[] = {"sb", "ss", "ra", "rrb", "rra", "rb", "rrr", "rr", NULL };
	int			best_value;
	int			current_value; // not so useful
	int			i;

	pile_tab = do_operation("sa", pile_tab, NULL, NULL);
	best_op = "sa";
	best_value = get_sorted_amount(pile_tab);
	pile_tab = do_operation("sa", pile_tab, NULL, NULL);
	printf("[sa] -> %d\n", best_value);

	i = -1;
	while (operations[++i] != NULL)
	{
		pile_tab = do_operation(operations[i], pile_tab, NULL, NULL);
		if (!(pile_tab[1] == NULL && (operations[i][1] == 'b' || operations[i][2] == 'b')))
		{
			current_value = get_sorted_amount(pile_tab);
			best_op = (current_value > best_value) ? operations[i] : best_op;
			best_value = (current_value > best_value) ? current_value : best_value;
		}
		pile_tab = do_operation(reverse_op[i], pile_tab, NULL, NULL);
		printf("[%s] -> %d\n", operations[i], current_value);
	}
	pile_tab = do_operation((char *)best_op, pile_tab, op_lst, flags);
	return (pile_tab);
}

char	*solve(t_pile *pile_tab[], char *flags)
{
	char	*op_lst;
	//char	*operations[9];

	op_lst = NULL;
	while (pile_tab[1] != NULL || is_sorted(pile_tab[0]) == 0)
		pile_tab = choose_op(pile_tab, &op_lst, flags);
	return (op_lst);
}
