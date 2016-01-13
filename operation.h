/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 20:06:17 by tvermeil          #+#    #+#             */
/*   Updated: 2016/01/13 16:17:41 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATION_H
# define OPERATION_H
# include "pile.h"

t_pile	*operation_swap(t_pile *pile);
t_pile	*operation_rotate(t_pile *pile, int sens);
void	operation_push(t_pile *pile_tab[], int to);

#endif
