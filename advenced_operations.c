/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advenced_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 21:58:29 by tvermeil          #+#    #+#             */
/*   Updated: 2016/01/13 22:58:02 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "advenced_operations.h"

t_pile	**check_for_swaps(t_pile *pile_tab[], char **op_lst, char *flags)
{
	t_pile	*top;
	char	*op;

	op = NULL;
	if (pile_tab[0] != NULL && (top = pile_tab[0]->previous)
			&& top->previous->value < top->value)
	{
		op = ft_strdup("sa");
		pile_tab[0] = operation_swap(pile_tab[0]);
	}
	if (pile_tab[1] != NULL && (top = pile_tab[1]->previous)
			&& top->previous->value > top->value)
	{
		op = ft_strfree_join("sb");
		pile_tab[1] = operation_swap(pile_tab[1]);
	}
	if (ft_strcomp(op, "sasb") == 0)
	{
		free(op);
		op = ft_strdup("ss");
	}
	if (op != NULL)
		add_operation(pile_tab, flags, op_lst, op);
	return (pile_tab);
}

t_pile	**push_swap_until_sorted(t_pile *pile_tab[], char **op_lst, char *flag)
{
	return (check_for_swaps(pile_tab, op_lst, flag));
}
