/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 18:05:07 by tvermeil          #+#    #+#             */
/*   Updated: 2016/01/14 23:47:41 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVER_H
# define SOLVER_H
# include "libft.h"
# include "operation.h"
# include "advenced_operations.h"
# include "pile.h"
# include "display.h"
# include "string_utils.h"
# include "list_util.h"

char	*solve(t_pile *pile_tab[], char *flags);

#endif
