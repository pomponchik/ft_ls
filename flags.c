/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbearded <sbearded@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:51:57 by sbearded          #+#    #+#             */
/*   Updated: 2019/03/04 16:55:33 by sbearded         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	flags_cmp(char *tmp, t_flags *flags)
{
	if (*tmp == 'l')
		flags->l = 1;
	else if (*tmp == 'R')
		flags->R = 1;
	else if (*tmp == 'a')
		flags->a = 1;
	else if (*tmp == 'r')
		flags->r = 1;
	else if (*tmp == 't')
		flags->t = 1;
	else if (*tmp == 'u')
		flags->u = 1;
	else if (*tmp == 'f')
		flags->f = 1;
	else if (*tmp == 'g')
		flags->g = 1;
	else if (*tmp == 'd')
		flags->d = 1;
	else
		return (0);
	return (1);
}

t_flags		*create_flags()
{
	t_flags	*new;

	new = (t_flags*)malloc(sizeof(t_flags));
	new->flags = 0;
	new->l = 0;
	new->R = 0;
	new->a = 0;
	new->r = 0;
	new->t = 0;
	new->u = 0;
	new->f = 0;
	new->g = 0;
	new->d = 0;
	return (new);
}

int		check_flags(char **argv, t_flags *flags)
{
	char	*tmp;

	if (argv[1])
	{
		if (argv[1][0] == '-')
		{
			flags->flags = 1;
			tmp = argv[1];
			while (*(++tmp))
			{
				if (flags_cmp(tmp, flags) == 0)
				{
					print_err_illegal_flag(tmp);
					return (0);
				}
			}
		}
	}
	return (1);
}