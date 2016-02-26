/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advenced_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 21:58:29 by tvermeil          #+#    #+#             */
/*   Updated: 2016/01/22 20:59:45 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "advenced_operations.h"

t_pile	**check_for_swaps(t_pile *pile_tab[], char **op_lst, char *flags)
{
	t_pile	*top;
	char	op[5];

	op[0] = '\0';
	if (pile_tab[0] != NULL && (top = pile_tab[0]->previous)
			&& top->previous->value < top->value
			&& !(pile_tab[1] == NULL
			&& top->value < top->previous->previous->value
			&& get_next_unsorted(top) != pile_tab[0]))
	{
		ft_strcpy(op, "sa");
		pile_tab[0] = operation_swap(pile_tab[0]);
	}
	if (pile_tab[1] != NULL && (top = pile_tab[1]->previous)
			&& top->previous->value > top->value)
	{
		ft_strcat(op, "sb");
		pile_tab[1] = operation_swap(pile_tab[1]);
	}
	if (ft_strcmp(op, "sasb") == 0)
		ft_strcpy(op, "ss");
	if (op[0] != '\0')
		add_operation(pile_tab, flags, op_lst, op);
	return (pile_tab);
}

t_pile	**check_for_rotate(t_pile *pile_tab[], char **op_lst, char *flags)
{
	char	op[5];
	t_pile	*top;

	op[0] = 'c';
	while (op[0])
	{
		op[0] = '\0';
		if (pile_tab[0] != NULL && (top = pile_tab[0]->previous)
				&& get_rank_of(pile_tab[0]) == 0
				&& !(get_rank_of(top) == get_pile_size(pile_tab[0]) - 1))
			ft_strcpy(op, "ra");
		else if (pile_tab[0] != NULL && (top = pile_tab[0]->previous)
				&& get_rank_of(pile_tab[0]) < get_rank_of(top))
			ft_strcpy(op, "a");
		if (pile_tab[1] != NULL && (top = pile_tab[1]->previous)
				&& get_rank_of(pile_tab[1]) + 1 == get_pile_size(pile_tab[1])
				&& !(get_rank_of(top) == 0))
			ft_strcpy(op, "rb");
		else if (pile_tab[1] != NULL && (top = pile_tab[1]->previous)
				&& get_rank_of(pile_tab[1]) > get_rank_of(top))
			ft_strcat(op, "b");
		format_rot_str(op);
		pile_tab = do_rot_op(op, pile_tab, op_lst, flags);
	}
	return (pile_tab);
}

t_pile	**push_swap(t_pile *pile_tab[], char **op, char *flags, int t)
{
	pile_tab = check_for_rotate(pile_tab, op, flags);
	pile_tab = check_for_swaps(pile_tab, op, flags);
	pile_tab = check_for_rotate(pile_tab, op, flags);
	if (t == 0)
	{
		pile_tab = operation_push(pile_tab, 0);
		add_operation(pile_tab, flags, op, "pa");
	}
	else if (get_next_unsorted(pile_tab[0]) != NULL)
	{
		pile_tab = operation_push(pile_tab, 1);
		add_operation(pile_tab, flags, op, "pb");
	}
	pile_tab = check_for_rotate(pile_tab, op, flags);
	pile_tab = check_for_swaps(pile_tab, op, flags);
	return (pile_tab);
}

t_pile	**rotate_swap_n(t_pile *pile_tab[], char **op, char *flags, int n)
{
	int		p;
	t_pile	*top;
	t_pile	*limit;

	p = n;
	limit = pile_tab[0]->previous;
	while (n-- && get_next_unsorted(limit->next))
	{
		top = pile_tab[0]->previous;
		pile_tab = do_rot_op("rra", pile_tab, op, flags);
		if (n != p - 1 && (top->value < limit->value
			|| top->previous->value < top->value))
		{
			pile_tab = do_swap_op("sa", pile_tab, op, flags);
			if (limit->next->value < limit->value)
				limit = limit->next;
		}
	}
	check_for_rotate(pile_tab, op, flags);
	return (pile_tab);
}
