/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 16:33:45 by tvermeil          #+#    #+#             */
/*   Updated: 2016/01/14 17:58:42 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

void	display_pile(t_pile *pile, int height)
{
	char	*value;

	ft_putchar('\t');
	if (height < get_pile_size(pile))
	{
		while (height--)
			pile = pile->next;
		value = ft_itoa(pile->value);
		ft_putstr(value);
		if (ft_strlen(value) < 8)
			ft_putchar('\t');
		free(value);
	}
	else
		ft_putstr("|\t");
}

void	print_piles(t_pile *pile_tab[])
{
	int	height;

	ft_putchar('\n');
	height = get_pile_size(pile_tab[0]);
	if (get_pile_size(pile_tab[1]) > height)
		height = get_pile_size(pile_tab[1]);
	while (height--)
	{
		display_pile(pile_tab[0], height);
		display_pile(pile_tab[1], height);
		ft_putchar('\n');
	}
	ft_putstr("\t___\t\t___\n");
	ft_putstr("\tA\t\tB\n");
}

void	add_operation(t_pile *pile_tab[], char *flags, char **op_lst, char *op)
{
	if (ft_strchr(flags, 'c'))
		put_oplist_colors(*op_lst, op);
	if (*op_lst != NULL)
		*op_lst = ft_strjoin_free(*op_lst, ft_strdup(" "));
	*op_lst = ft_strjoin_free(*op_lst, ft_strdup(op));
	if (ft_strchr(flags, 'c') == NULL)
		ft_putendl(*op_lst);
	if (ft_strchr(flags, 'v'))
		print_piles(pile_tab);
}
