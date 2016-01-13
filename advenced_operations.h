/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advenced_operations.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 21:59:02 by tvermeil          #+#    #+#             */
/*   Updated: 2016/01/13 22:35:07 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADVENCED_OPERATIONS_H
# define ADVENCED_OPERATIONS_H
# include "operation.h"
# include "libft.h"

t_pile	**push_swap_until_sorted(t_pile *pile_tab[], char **op_lst, char *flag);
t_pile	**check_for_swaps(t_pile *pile_tab[], char **op_lst, char *flags);

#endif
