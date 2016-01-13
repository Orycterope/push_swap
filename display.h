/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 16:34:31 by tvermeil          #+#    #+#             */
/*   Updated: 2016/01/13 19:24:17 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H
# include "pile.h"
# include "libft.h"
# include "list_util.h"

void	print_piles(t_pile *pile_tab[]);
void	display_pile(t_pile *pile, int height);

#endif
