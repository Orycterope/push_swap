/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 21:25:15 by tvermeil          #+#    #+#             */
/*   Updated: 2016/01/13 23:17:14 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_utils.h"

void	put_oplist_colors(char *op_list, char *last_op)
{
	ft_putstr(op_list);
	ft_putchar(' ');
	ft_putendl(last_op);
}
