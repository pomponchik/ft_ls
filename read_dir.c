#include <dirent.h>
#include <sys/stat.h>
#include <stdio.h>
#include "libft.h"

typedef struct			s_dir
{
	struct dirent *file;
	struct stat *buffer;
}						t_dir;



t_dir *struct_tdir_copy(t_dir current)
{
	t_dir *result;

	if (!(result = (t_dir *)malloc(sizeof(t_dir))))
		return (NULL);
	result->file = current.file;
	result->buffer = current.buffer;
	return (result);
}
t_dir *tdir_lst_to_arr(t_list *lst, size_t count)
{
	t_dir *arr;
	t_dir *temp_arr;
	size_t index;
	t_list *temp;

	if (!(arr = (t_dir *)malloc(sizeof(t_dir) * (count))))
		return (NULL);
	//arr[count] = NULL;
	index = 0;
	temp = lst;
	while (lst)
	{
		temp_arr = (t_dir *)(lst->content);
		arr[index] = *temp_arr;
		index++;
		lst = lst->next;
	}
	ft_lst_free_chain(temp);
	return (arr);
}

t_dir *read_dir(char *path, int stat_indicate, size_t *count)
{
	DIR *dir;
	t_dir current;
	t_list *lst;
	struct dirent *current_elem;
	char *path_to_stat;
	char *path_and_slash;
	size_t counter;

	dir = opendir(path);
	lst = NULL;
	counter = 0;
	while ((current_elem = readdir(dir)))
	{
		current.file = current_elem;
		if (stat_indicate)
		{
			path_and_slash = ft_strjoin(path, "/");
			path_to_stat = ft_strjoin(path_and_slash, current_elem->d_name);
			stat(path_to_stat, current.buffer);
			free(path_and_slash);
			free(path_to_stat);
		}
		ft_lstadd_to_end(&lst, ft_lstnew(&current, sizeof(current)));
		struct_tdir_copy(current);
		counter++;
	}
	closedir(dir);
	*count = counter;
	return (tdir_lst_to_arr(lst, counter));
}

int main()
{
	t_dir *dir;
	size_t c;
	dir = read_dir(".", 1, &c);

	while (c)
	{
		printf("%s\n", (char *)((dir->file)->d_name));
		dir++;
		c--;
	}
	return 0;
}
