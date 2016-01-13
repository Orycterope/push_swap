/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_util.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 19:08:36 by tvermeil          #+#    #+#             */
/*   Updated: 2016/01/13 19:30:15 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_UTIL_H
# define LIST_UTIL_H
# include "pile.h"

int		get_pile_size(t_pile *pile);
int		get_dist(t_pile *block1, t_pile *block2);
int		get_shortest_dist(t_pile *block1, t_pile *block2);
t_pile	*get_next_unsorted(t_pile *pile);

#endif
