/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 21:25:15 by tvermeil          #+#    #+#             */
/*   Updated: 2016/01/14 22:32:09 by tvermeil         ###   ########.fr       */
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

void		format_rot_str(char *op)
{
	char	cpy[4];

	if (op[0] == '\0')
		return ;
	ft_putstr("got rotate str: ");
	ft_putstr(op);
	if (ft_strcmp(op, "rab") == 0)
		ft_strcpy(op, "ra");
	if (ft_strcmp(op, "arb") == 0)
		ft_strcpy(op, "a");
	if (ft_strcmp(op, "ab") == 0)
		ft_strcpy(op, "r");
	if (ft_strcmp(op, "rarb") == 0)
		ft_strcpy(op, "rr");
	ft_strcpy(cpy, "r");
	ft_strcat(cpy, op);
	ft_strcpy(op, cpy);
	ft_putstr(" and returned: ");
	ft_putendl(op);
}
