/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advenced_operations.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 21:59:02 by tvermeil          #+#    #+#             */
/*   Updated: 2016/01/14 18:37:15 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADVENCED_OPERATIONS_H
# define ADVENCED_OPERATIONS_H
# include "operation.h"
# include "libft.h"
# include "display.h"

t_pile	**check_for_swaps(t_pile *pile_tab[], char **op_lst, char *flags);
t_pile	**push_swap_n(t_pile *pile_tab[], char **op, char *flags, int n, int t);

#endif
