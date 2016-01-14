/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 15:22:25 by tvermeil          #+#    #+#             */
/*   Updated: 2016/01/14 17:07:17 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> //

void		display_usage(char *command)
{
	ft_putstr("usage: ");
	ft_putstr(command);
	ft_putstr(" [-v] [-c] nbr [...]\n");
	exit(0);
}

static int	contains_invalid_flag(char *str)
{
	while (*++str)
	{
		if (*str != 'c' && *str != 'v')
			return (1);
	}
	return (0);
}

static char	*get_flags(int *ac, char **av[])
{
	char	*flags;
	char	*old;
	char	*command;

	flags = NULL;
	command = **av;
	*ac -= 1;
	*av += 1;
	while ((**av)[0] == '-' && ((**av)[1] == 'c' || (**av)[1] == 'v'))
	{
		if (contains_invalid_flag(**av))
		{
			free(flags);
			display_usage(command);
		}
		old = flags;
		flags = ft_strjoin(flags, **av + 1);
		free(old);
		*av += 1;
		*ac -= 1;
	}
	return (flags);
}

int			main(int ac, char *av[])
{
	char	*flags;
	char	*command;
	t_pile	*pile_tab[2];

	command = av[0];
	if (ac < 2)
		display_usage(command);
	flags = get_flags(&ac, &av);
	if (ac < 1)
		display_usage(command);
	printf("flags : %s, first arg: %s, ac: %d\n", flags, av[0], ac);
	pile_tab[0] = save_param_to_pile(ac, av, command);
	pile_tab[1] = NULL;
	if (ft_strchr(flags, 'v'))
		print_piles(pile_tab);
	ft_putstr(solve(pile_tab, flags));
	//free_pile(pile_tab[0]);
	return (0);
}
