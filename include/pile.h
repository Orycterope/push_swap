/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 17:21:28 by tvermeil          #+#    #+#             */
/*   Updated: 2016/01/22 21:01:29 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PILE_H
# define PILE_H
# include "libft.h"

typedef struct		s_pile
{
	struct s_pile	*previous;
	struct s_pile	*next;
	int				value;
}					t_pile;

t_pile				*create_block(int nbr);
t_pile				*save_param_to_pile(int ac, char *av[], char *command);
t_pile				*append_to_pile(int nbr, t_pile *pile);
t_pile				*remove_from_pile(t_pile *maillon);
int					has_duplicate(t_pile *pile);
void				display_usage(char *command);

#endif
