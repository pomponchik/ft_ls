/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbearded <sbearded@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:26:24 by sbearded          #+#    #+#             */
/*   Updated: 2019/03/04 17:40:31 by sbearded         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_names(t_flags *flags, t_dir *dir, size_t c)
{
	/*while (c--)
	{
		printf("%s, %s\n", chmod_print(((dir->buffer)->st_mode)), (char *)((dir->file)->d_name));
		dir++;
	}*/
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
