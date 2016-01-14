/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 21:25:15 by tvermeil          #+#    #+#             */
/*   Updated: 2016/01/14 19:41:48 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_utils.h"

static void	print_op_color(char *op)
{
	ft_putstr("\e[");
	if (op[0] == 'r')
		ft_putchar('4');
	else
		ft_putchar('0');
	ft_putstr(";3");
	if (op[0] == 's')
		ft_putchar(op[1] % 8 + '0');
	else if (op[0] == 'p')
		ft_putchar((op[1]) % 8 + '4');
	else
		ft_putchar((op[1] + 1) % 8 + '0');
	ft_putchar('m');
}

void		put_oplist_colors(char *op_list, char *last_op)
{
	if (op_list != NULL)
	{
		ft_putstr(op_list);
		ft_putchar(' ');
	}
	print_op_color(last_op);
	ft_putstr(last_op);
	ft_putstr("\e[0m\n");
}
