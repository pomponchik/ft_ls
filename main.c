/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbearded <sbearded@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:26:29 by sbearded          #+#    #+#             */
/*   Updated: 2019/03/20 16:43:36 by sbearded         ###   ########.fr       */
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
	char	*path;
	int		i;
	size_t	c;

	//sort_argv() - надо отсортировать argv
	flags = create_flags();
	if (check_flags(argv, flags) == 0)
		return (0);
	if (argc == 1 || (argc == 2 && flags->flags))
	{
		path = ft_strdup(".");
		dir = read_dir(path, 1, &c);
		print_names(flags, dir, c, path);
	}
	else
	{
		i = 1 + flags->flags;
		while (i < argc)
		{
			path = ft_strdup(argv[i++]);
			dir = read_dir(path, 1, &c);
			print_names(flags, dir, c, path);
		}
	}
	free(flags);
	free(path);
	return (0);
}
