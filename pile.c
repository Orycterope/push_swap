/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 17:34:06 by tvermeil          #+#    #+#             */
/*   Updated: 2016/01/12 20:02:32 by tvermeil         ###   ########.fr       */
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

int		get_pile_size(t_pile *pile)
{
	int		size;
	t_pile	*start;

	if (pile == NULL)
		return (0);
	start = pile;
	size = 1;
	while (pile->next != start)
	{
		pile = pile->next;
		size++;
	}
	return (size);
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
		av++;
	}
	return (pile);
}
