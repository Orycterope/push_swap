/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advenced_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 21:58:29 by tvermeil          #+#    #+#             */
/*   Updated: 2016/01/15 00:19:33 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "advenced_operations.h"
#include <stdio.h>

t_pile	**check_for_swaps(t_pile *pile_tab[], char **op_lst, char *flags)
{
	t_pile	*top;
	char	op[5];

	op[0] = '\0';
	if (pile_tab[0] != NULL && (top = pile_tab[0]->previous)
			&& top->previous->value < top->value)
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
				&& get_rank_of(pile_tab[0]) < get_rank_of(top))
			ft_strcpy(op, "a");
		/*else if (pile_tab[0] != NULL && (top = pile_tab[0]->previous)
				&& pile_tab[0]->value > top->value)
			ft_strcpy(op, "ra");*/
		if (pile_tab[1] != NULL && (top = pile_tab[1]->previous)
				&& get_rank_of(pile_tab[1]) > get_rank_of(top))
			ft_strcat(op, "b");
		/*else if (pile_tab[1] != NULL && (top = pile_tab[1]->previous)
				&& pile_tab[1]->value < top->value)
			ft_strcat(op, "rb");*/
		format_rot_str(op);
		pile_tab = do_rot_op(op, pile_tab, op_lst, flags);
	}
	return (pile_tab);
}

t_pile	**push_swap_n(t_pile *pile_tab[], char **op, char *flags, int n, int t)
{
	//t_pile	*top;
	ft_putendl("in push_swap_n");
	n -= 1; //
	//while (n-- && pile_tab[0] != NULL)
	//{
		//top = pile_tab[0]->previous;
		pile_tab = check_for_rotate(pile_tab, op, flags);
		pile_tab = check_for_swaps(pile_tab, op, flags);
		pile_tab = check_for_rotate(pile_tab, op, flags);
		if (t == 0)
		{
			pile_tab = operation_push(pile_tab, 0);
			add_operation(pile_tab, flags, op, "pa");
		}
		else if (get_next_unsorted(pile_tab[0]) != NULL) // still needed ?
		{
			pile_tab = operation_push(pile_tab, 1);
			add_operation(pile_tab, flags, op, "pb");
		}
		pile_tab = check_for_rotate(pile_tab, op, flags);
		pile_tab = check_for_swaps(pile_tab, op, flags);
	//}
	return (pile_tab);
}

t_pile	**rotate_swap_n(t_pile *pile_tab[], char **op, char *flags, int n)
{
	int		p;
	t_pile	*top;

	p = n;
	printf("rotate_swap %d blocks\n", n);
	top = pile_tab[0]->previous;
	while (n-- && get_next_unsorted(pile_tab[0]))
	{
		pile_tab = do_rot_op("rra", pile_tab, op, flags);
		if (n != p - 1 && (pile_tab[0]->previous->value < top->value
			|| pile_tab[0]->previous->previous->value < pile_tab[0]->previous->value))
		{
			pile_tab[0] = operation_swap(pile_tab[0]);
			add_operation(pile_tab, flags, op, "sa");
		}
	}
	while (p-- && get_next_unsorted(pile_tab[0]))
	{
		pile_tab = do_rot_op("ra", pile_tab, op, flags);
		if (p != 1 && (pile_tab[0]->previous->value < top->value
			|| pile_tab[0]->previous->previous->value < pile_tab[0]->previous->value))
		{
			pile_tab[0] = operation_swap(pile_tab[0]);
			add_operation(pile_tab, flags, op, "sa");
		}
	}
	return (pile_tab);
}
