/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 21:29:01 by tvermeil          #+#    #+#             */
/*   Updated: 2016/03/17 14:16:32 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_UTILS_H
# define STRING_UTILS_H
# include "libft.h"

void	put_oplist_colors(char *op_list, char *last_op);
void	format_rot_str(char *op);
t_pile	**rotate_swap(t_pile *pile_tab[], char **op_lst, char *flags);

#endif
