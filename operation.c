/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 20:03:19 by tvermeil          #+#    #+#             */
/*   Updated: 2016/01/12 20:41:06 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"

void	operation_swap(t_pile *pile)
{
	pile = pile->previous;
	pile->previous->previous->next = pile;
	pile->previous->next = pile->next;
	pile->next->previous = pile->previous;
	pile->previous = pile->previous->previous;
	pile->next->previous->previous = pile;
	pile->next = pile->next->previous;
}
