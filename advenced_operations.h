/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advenced_operations.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 21:59:02 by tvermeil          #+#    #+#             */
/*   Updated: 2016/01/14 16:58:41 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADVENCED_OPERATIONS_H
# define ADVENCED_OPERATIONS_H
# include "operation.h"
# include "libft.h"
# include "display.h"

t_pile	**check_for_swaps(t_pile *pile_tab[], char **op_lst, char *flags);
t_pile	**push_swap_n(t_pile *pile_tab[], char **oplst, char *flags, int n);
t_pile	**push_all_a(t_pile *pile_tab[], char **oplst, char *flags);

#endif
