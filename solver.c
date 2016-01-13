/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 17:40:12 by tvermeil          #+#    #+#             */
/*   Updated: 2016/01/13 23:06:57 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"
#include <stdio.h> //

t_pile	**choose_op(t_pile *pile_tab[], char **op_lst, char *flags)
{
	t_pile	*next;

	next = get_next_unsorted(pile_tab[0]);
	flags = ft_strdup("flags here");
	*op_lst = ft_strjoin(*op_lst, NULL); //
	return (operation_push(pile_tab, 1));
}

char	*solve(t_pile *pile_tab[], char *flags)
{
	char	*op_lst;

	while (pile_tab[1] != NULL || get_next_unsorted(pile_tab[0]) != NULL)
	{
		pile_tab = choose_op(pile_tab, &op_lst, flags);
	}
	return (op_lst);
}
