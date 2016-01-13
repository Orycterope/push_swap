/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 18:05:07 by tvermeil          #+#    #+#             */
/*   Updated: 2016/01/13 21:30:55 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVER_H
# define SOLVER_H
# include "libft.h"
# include "operation.h"
# include "pile.h"
# include "display.h"
# include "string_utils.h"

char	*solve(t_pile *pile_tab[], char *flags);

#endif
