/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbearded <sbearded@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:26:24 by sbearded          #+#    #+#             */
/*   Updated: 2019/03/11 02:11:53 by sbearded         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_colomns(t_dir *dir, size_t c)
{
	const struct winsize	win;
	ioctl(1, TIOCGWINSZ, &win);
	printf("%d\n", win.ws_col);

}

void	print_names(t_flags *flags, t_dir *dir, size_t c)
{
	if (flags->flags == 0)
	{
		while (c--)
		{
			if (dir->file->d_name[0] != '.')
			{
				ft_putstr(dir->file->d_name);
				ft_putchar('\t');
			}
			dir++;
		}
	}
}

void	print_err_illegal_flag(char *arr)
{
	ft_putstr("ls: illegal option -- ");
	ft_putchar(*arr);
	ft_putstr("\nusage: ls [-Radfglrtu] [file ...]\n");
}
