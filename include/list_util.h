/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_util.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 19:08:36 by tvermeil          #+#    #+#             */
/*   Updated: 2016/03/02 16:22:28 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_UTIL_H
# define LIST_UTIL_H
# include "pile.h"

int		get_pile_size(t_pile *pile);
int		get_dist(t_pile *block1, t_pile *block2);
int		next_unsorted(t_pile *pile);
int		get_rank_of(t_pile *pile);
int		is_sorted(t_pile *pile);

#endif
