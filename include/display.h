/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 16:34:31 by tvermeil          #+#    #+#             */
/*   Updated: 2016/01/13 23:02:46 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H
# include "pile.h"
# include "libft.h"
# include "list_util.h"
# include "string_utils.h"

void	print_piles(t_pile *pile_tab[]);
void	display_pile(t_pile *pile, int height);
void	add_operation(t_pile *pile_tab[], char *flags, char **op_lst, char *op);

#endif
