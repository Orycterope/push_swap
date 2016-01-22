/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 20:06:17 by tvermeil          #+#    #+#             */
/*   Updated: 2016/01/22 20:27:47 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATION_H
# define OPERATION_H
# include "pile.h"
# include "display.h"

t_pile	*operation_swap(t_pile *pile);
t_pile	*operation_rotate(t_pile *pile, int sens);
t_pile	**operation_push(t_pile *pile_tab[], int to);
t_pile	**do_rot_op(char *op, t_pile *pile_tab[], char **op_lst, char *flags);
t_pile	**do_swap_op(char *op, t_pile *pile_tab[], char **op_lst, char *flags);

#endif
