#include "libft.h"

char *chmod_print(mode_t rights)
{
	char *result;
  const char chars[] = "rwxrwxrwx";
		if (!(result = (char *)malloc(10)))
			return (NULL);
  for (size_t i = 0; i < 9; i++) {
    result[i] = (rights & (1 << (8-i))) ? chars[i] : '-';
  }
  result[9] = '\0';
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
	// зафришить current.buffer
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
		current.buffer = (struct stat*)malloc(sizeof(struct stat));
		if (stat_indicate)
		{
			path_and_slash = ft_strjoin(path, "/");
			path_to_stat = ft_strjoin(path_and_slash, current_elem->d_name);
			stat(path_to_stat, current.buffer);
			free(path_and_slash);
			free(path_to_stat);
		}
		ft_lstadd_to_end(&lst, ft_lstnew(&current, sizeof(current)));
		counter++;
	}
	closedir(dir);
	*count = counter;
	return (tdir_lst_to_arr(lst, counter));
}

char change_one_right(mode_t temp, char letter)
{
	if (temp)
		return (letter);
	return ('-');
}

// char *chmod_print(mode_t rights)
// {
// 	char *result;
// 	mode_t temp;
//
	// if (!(result = (char *)malloc(10)))
	// 	return (NULL);
// 	result[9] = '\0';
// 	result[0] = change_one_right((rights << 8), 'r');
// 	result[1] = change_one_right((rights << 7) >> 8, 'w');
// 	result[2] = change_one_right((rights << 6) >> 8, 'x');
// 	result[3] = change_one_right((rights << 5) >> 8, 'r');
// 	result[4] = change_one_right((rights << 4) >> 8, 'w');
// 	result[5] = change_one_right((rights << 3) >> 8, 'x');
// 	result[6] = change_one_right((rights << 2) >> 8, 'r');
// 	result[7] = change_one_right((rights << 1) >> 8, 'w');
// 	result[8] = change_one_right(rights, 'x');
// 	return (result);
// }



//chmod_print(((dir->buffer)->st_mode))
