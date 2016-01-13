/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 17:40:12 by tvermeil          #+#    #+#             */
/*   Updated: 2016/01/13 19:23:09 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"

pile_tab	**choose_op(t_pile *pile_tab[], char **op_lst, char *flags);
{
	char	*old_oplst;
	t_pile	*next = get_next_unsorted(pile_tab[0]);

	return (operation_push(pile_tab, 1));
}

char		*solve(t_pile *pile_tab[], char *flags)
{
	char	*op_lst;

	op_lst = NULL;
	while (pile_tab[1] != NULL && get_next_unsorted(pile_tab[1]) == NULL)
	{
		pile_tab = choose_op(pile_tab, &op_lst, flags);
		if (ft_strchr('v', flags))
		{
			ft_putstr(op_lst);
			print_tabs(pile_tab);
		}
	}
	return (op_lst);
}
