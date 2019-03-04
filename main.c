/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbearded <sbearded@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:26:29 by sbearded          #+#    #+#             */
/*   Updated: 2019/03/04 15:26:30 by sbearded         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int main()
{
	t_dir *dir;
	size_t c;
	dir = read_dir(".", 1, &c);

	while (c)
	{
		printf("%s, %s\n", chmod_print(((dir->buffer)->st_mode)), (char *)((dir->file)->d_name));
		dir++;
		c--;
	}
	return 0;
}