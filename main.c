/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbearded <sbearded@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:26:29 by sbearded          #+#    #+#             */
/*   Updated: 2019/03/15 22:41:39 by sbearded         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*check_path(char **argv)
{
	return (0);
}

void	print_flags(t_flags *flags)
{
	printf("flag %c: %d\n", 'l', flags->l);
	printf("flag %c: %d\n", 'R', flags->R);
	printf("flag %c: %d\n", 'a', flags->a);
	printf("flag %c: %d\n", 'r', flags->r);
	printf("flag %c: %d\n", 't', flags->t);
	printf("flag %c: %d\n", 'u', flags->u);
	printf("flag %c: %d\n", 'f', flags->f);
	printf("flag %c: %d\n", 'g', flags->g);
	printf("flag %c: %d\n", 'd', flags->d);
}

int		main(int argc, char **argv)
{
	t_dir	*dir;
	t_flags	*flags;
	int		i;
	size_t	c;

	//sort_argv() - надо отсортировать argv
	flags = create_flags();
	if (check_flags(argv, flags) == 0)
		return (0);
	if (argc == 1 || (argc == 2 && flags->flags))
	{
		dir = read_dir(".", 1, &c);
		print_names(flags, dir, c);
	}
	else
	{
		i = 1 + flags->flags;
		while (i < argc)
		{
			dir = read_dir(argv[i++], 1, &c);
			print_names(flags, dir, c);
		}
	}
	free(flags);
	return (0);
}
