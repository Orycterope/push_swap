/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 15:22:25 by tvermeil          #+#    #+#             */
/*   Updated: 2016/01/12 17:12:06 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> //

static void	display_usage(char *command)
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
	//int		*pile_a;
	//int		*pile_b;

	if (ac < 2)
		display_usage(av[0]);
	flags = get_flags(&ac, &av);
	printf("flags : %s, first arg: %s, ac: %d\n", flags, av[0], ac);
	return (0);
}
