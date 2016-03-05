/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 17:34:06 by tvermeil          #+#    #+#             */
/*   Updated: 2016/01/22 21:00:58 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pile.h"

t_pile	*create_block(int nbr)
{
	t_pile	*block;

	block = (t_pile*)ft_memalloc(sizeof(t_pile));
	block->value = nbr;
	block->previous = block;
	block->next = block;
	return (block);
}

int		has_duplicate(t_pile *pile)
{
	t_pile	*start;
	t_pile	*end;

	start = pile;
	end = start->previous;
	while (start != end)
	{
		pile = start->next;
		while (pile != start)
		{
			if (start->value == pile->value)
				return (1);
				pile = pile->next;
		}
		start = start->next;
	}
	return (0);
}

t_pile	*append_to_pile(int nbr, t_pile *pile)
{
	t_pile	*new_block;

	new_block = create_block(nbr);
	if (pile == NULL)
		return (new_block);
	new_block->next = pile;
	new_block->previous = pile->previous;
	pile->previous->next = new_block;
	pile->previous = new_block;
	return (pile);
}

t_pile	*remove_from_pile(t_pile *block)
{
	t_pile	*out;

	if (block->next == block)
		out = NULL;
	else
		out = block->next;
	block->previous->next = block->next;
	block->next->previous = block->previous;
	free(block);
	return (out);
}

t_pile	*save_param_to_pile(int ac, char *av[], char *command)
{
	t_pile	*pile;
	int		value;

	pile = NULL;
	while (ac--)
	{
		value = ft_atoi(av[0]);
		if (value == 0 && ((*av)[0] != '0'
				&& !(ft_strchr("+-", (*av)[0]) != NULL && (*av)[1] == '0')))
			display_usage(command);
		pile = append_to_pile(value, pile);
		pile = pile->previous;
		av++;
	}
	return (pile);
}
