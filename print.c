/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbearded <sbearded@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:26:24 by sbearded          #+#    #+#             */
/*   Updated: 2019/03/18 17:07:49 by sbearded         ###   ########.fr       */
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

static void	print_SST(mode_t stat, char *arr)
{
	if (stat & S_ISVTX)
	{
		if (arr[8] == '-')
			arr[8] = 'T';
		else
			arr[8] = 't';
	}
	if (stat & S_ISGID)
	{
		if (arr[5] == '-')
			arr[5] = 'S';
		else
			arr[5] = 's';
	}
	if (stat & S_ISUID)
	{
		if (arr[2] == '-')
			arr[2] = 'S';
		else
			arr[2] = 's';
	}
}

static void	print_permission(mode_t stat)
{
	char		arr[10];
	const char	chars[9];
	size_t		i;
	int			tmp;

	ft_memcpy((void*)chars, "rwxrwxrwx", 9);
	i = 0;
	tmp = 256;
	while (tmp)
	{
		if (stat & tmp)
			arr[i] = chars[i];
		else
			arr[i] = '-';
		i++;
		tmp >>= 1;
	}
	print_SST(stat, arr);
	ft_putstr(arr);
	write(1, "  ", 2);
}

static void	print_ftype(mode_t stat)
{
	if (stat & S_IFREG)
	{
		if ((stat & S_IFREG) == S_IFREG)
			ft_putchar('-');
		else if (stat & S_IFLNK)
			ft_putchar('l');
		else if (stat & S_IFSOCK)
			ft_putchar('s');
	}
	else
	{
		if ((stat & S_IFBLK) == S_IFBLK)
			ft_putchar('b');
		else if (stat & S_IFDIR)
			ft_putchar('d');
		else if (stat & S_IFCHR)
			ft_putchar('c');
		else if (stat & S_IFIFO)
			ft_putchar('p');
	}
}

static void	print_time(t_dir *dir)
{
	char	*str;

	str = ctime(&dir->buffer->st_mtimespec.tv_sec);
	str[16] = '\0';
	ft_putstr(str + 4);
}

static void	print_user(t_dir *dir)
{
	ft_putstr(getpwuid(dir->buffer->st_uid)->pw_name);
	ft_putchar(' ');
	ft_putstr(getgrgid(dir->buffer->st_gid)->gr_name);
}

static void	print_rows(t_dir *dir, size_t c)
{
	while (c--)
	{
		print_ftype(dir->buffer->st_mode);
		print_permission(dir->buffer->st_mode);
		ft_putnbr(dir->buffer->st_nlink);
		ft_putchar(' ');
		print_user(dir);
		ft_putchar(' ');
		ft_putnbr(dir->buffer->st_size);
		ft_putchar(' ');
		print_time(dir);
		ft_putchar(' ');
		ft_putstr(dir->file->d_name);
		ft_putchar('\n');
		dir++;
	}
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
	t_list	**stack;

	if (flags->a == 0)
		while (dir->file->d_name[0] == '.')
		{
			dir++;
			c--;
		}
	if (flags->l == 0)
		print_colomns(dir, c);
	else
		print_rows(dir, c);
}

void	print_err_illegal_flag(char *arr)
{
	ft_putstr("ls: illegal option -- ");
	ft_putchar(*arr);
	ft_putstr("\nusage: ls [-Radfglrtu] [file ...]\n");
}
