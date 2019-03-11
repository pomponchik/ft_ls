/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbearded <sbearded@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:26:24 by sbearded          #+#    #+#             */
/*   Updated: 2019/03/11 06:05:19 by sbearded         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Возможно сделать быстрее
static size_t	search_longest_word_length(t_dir *dir, size_t c)
{
	size_t	len;
	size_t	tmp;

	len = 0;
	while (c--)
	{
		if ((tmp = ft_strlen(dir->file->d_name)) > len)
			len = tmp;
		dir++;
	}
	return (len);
}

static t_print_col	calc_colomns(size_t max_word, size_t c)
{
	const struct winsize	win;
	t_print_col				col;
	int						tmp;

	tmp = max_word % SIZE_TABS;						//посчитать размер табов
	max_word += SIZE_TABS - tmp;
	col.tab_size = max_word;
	ioctl(1, TIOCGWINSZ, &win);
	col.col = win.ws_col / col.tab_size;			//сколько табов в строке
	if (c > tmp)									//необходимо сделать так, чтобы в каждом столбике было одинаковое количество символов, кроме последнего
	{
		while (1)
		{
			col.rows = c / col.col;											//количество строк
			if ((tmp = c % col.col))										//слов в последней строке. Если остаток не 0, то +1 строка
				col.rows++;
			if (tmp > col.col - col.rows || tmp == 0)						//на сколько слов может отличаться послдений столбец/строка
			{
				col.empty = col.col - tmp;
				break ;
			}
			col.col--;
		}
	}
	return (col);
}

size_t				ft_putstr_fix(char *c)
{
	int	i;

	i = 0;
	while (*c)
	{
		ft_putchar(*c);
		c++;
		i++;
	}
	return (i);
}

static void	print_colomns(t_dir *dir, size_t c)
{
	t_print_col	col;
	int			i;
	int			x;
	int			y;

	col = calc_colomns(search_longest_word_length(dir, c), c);
	y = 0;
	while (y < col.rows)
	{
		x = 0;
		if (y == col.rows - col.empty)
			col.col--;
		while (x < col.col)
		{
			i = ft_putstr_fix((dir + (col.rows * x))->file->d_name);
			while (i++ < col.tab_size)
				write(1, " ", 1);
			x++;
		}
		dir++;
		y++;
		write(1, "\n", 1);
	}
}

void	print_names(t_flags *flags, t_dir *dir, size_t c)
{
	print_colomns(dir, c);
}

void	print_err_illegal_flag(char *arr)
{
	ft_putstr("ls: illegal option -- ");
	ft_putchar(*arr);
	ft_putstr("\nusage: ls [-Radfglrtu] [file ...]\n");
}
