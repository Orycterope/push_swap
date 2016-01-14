/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advenced_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 21:58:29 by tvermeil          #+#    #+#             */
/*   Updated: 2016/01/14 21:59:57 by tvermeil         ###   ########.fr       */
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

	op[0] = '\0';
	if (pile_tab[0] != NULL && (top = pile_tab[0]->previous)
			&& pile_tab[0]->value < top->value)
		ft_strcat(op, "a");
	else if (pile_tab[0] != NULL && (top = pile_tab[0]->previous)
			&& pile_tab[0]->value > top->value)
		ft_strcat(op, "ra");
	if (pile_tab[1] != NULL && (top = pile_tab[1]->previous)
			&& pile_tab[1]->value < top->value)
		ft_strcat(op, "b");
	if (pile_tab[1] != NULL && (top = pile_tab[1]->previous)
			&& pile_tab[1]->value > top->value)
		ft_strcat(op, "rb");
	format_rot_str(op);
	pile_tab = do_rot_op(op, pile_tab, op_lst, flags);
	return (pile_tab);

}

t_pile	**push_swap_n(t_pile *pile_tab[], char **op, char *flags, int n, int t)
{
	t_pile	*top;
	ft_putendl("in push_swap_n");
	while (--n && pile_tab[0] != NULL)
	{
		top = pile_tab[0]->previous;
		if (n > 1 && top->value > top->previous->previous->value)
			pile_tab = check_for_swaps(pile_tab, op, flags);
		if (t == 0)
		{
			pile_tab = operation_push(pile_tab, 0);
			add_operation(pile_tab, flags, op, "pa");
		}
		else
		{
			pile_tab = operation_push(pile_tab, 1);
			add_operation(pile_tab, flags, op, "pb");
		}
		pile_tab = check_for_swaps(pile_tab, op, flags);
	}
	return (pile_tab);
}
