/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbearded <sbearded@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 21:20:15 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/03/20 18:03:18 by sbearded         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 20

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <dirent.h>
# include <sys/stat.h>
# include <stdio.h>
# include <sys/ioctl.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <sys/xattr.h>
# include <sys/acl.h>
# include <sys/types.h>

# define SIZE_TABS 8

typedef struct			s_flags
{
	short int	flags;
	short int	l;
	short int	R;
	short int	a;
	short int	r;
	short int	t;
	short int	u;
	short int	f;
	short int	g;
	short int	d;
}						t_flags;

typedef struct			s_print_col
{
	int tab_size;
	int	rows;
	int	col;
	int	empty;
}						t_print_col;

typedef struct			s_dir
{
	struct dirent		*file;
	struct stat			*buffer;
	unsigned int		count;
	short int			link;
	short int			major;
}						t_dir;

typedef struct			s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;

typedef struct			s_two_list
{
	void				*content;
	size_t				content_size;
	struct s_two_list	*next;
	struct s_two_list	*back;
}						t_two_list;

typedef struct			s_iterators
{
	int					in;
	char				*str;
	int					work;
	char				*chr;
}						t_iter;

t_flags					*create_flags();
int						check_flags(char **argv, t_flags *flags);

void					print_names(t_flags *flags, t_dir *dir, size_t c, char *path);
void					print_err_illegal_flag(char *arr);

void					ft_lstdelcontent(void *c, size_t c_size);
void					stack_push(t_list **stack, t_list *lst);
t_list					*stack_pop(t_list **stack);

t_dir 					*read_dir(char *path, int stat_indicate, size_t *count);
char 					*chmod_print(mode_t rights);

void					ft_binary_lst_strdel(t_two_list **alst);
void					ft_binary_lstadd(t_two_list **alst, t_two_list *new);
t_two_list				*ft_binary_lstnew(void const *content, \
	size_t content_size);
t_two_list				*ft_binary_lstsea_cs(t_two_list *alst, \
	size_t to_search);
t_two_list				*ft_binary_lstseaconb(t_two_list *alst, \
	void *to_search);
t_two_list				*ft_binary_lstseacon(t_two_list *alst, char *to_search);
float					ft_root(float num, unsigned int root_index);
long int				ft_maxmin(char *type, char *maxmin);
size_t					ft_numch(char *str, char ch);
char					*ft_letter_replacement(char *str, char previous, \
	char new);
void					ft_print_two_dimensional_array(char **str);
void					ft_putnbr(int n);
void					ft_putnbr_fd(int n, int fd);
int						ft_atoi(const char *str);
void					ft_bzero(void *s, size_t n);
int						ft_isalnum(int ch);
int						ft_isalpha(int ch);
int						ft_isascii(int ch);
int						ft_isdigit(int ch);
int						ft_isprint(int ch);
char					*ft_itoa(int n);
void					ft_lstadd(t_list **alst, t_list *new);
void					ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void					ft_lstdelone(t_list **alst, \
	void (*del)(void *, size_t));
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list					*ft_lstnew(void const *content, size_t content_size);
t_list					*ft_lstsearch_cs(t_list *lst, size_t fd);
t_list					*ft_lstsearch_content(t_list *lst, void *to_search);
t_list					*ft_lstsearch_str_content(t_list *lst, char *to_search);
void					ft_lst_free_chain(t_list *chain);
t_list					*ft_lst_turn(t_list *begin);
void					ft_lst_putendl(t_list *lst);
size_t					ft_lst_chain_len(t_list *begin);
t_list					*ft_lst_unit_transfer(t_list *lst);
t_list					*ft_lstsearch_index(t_list *lst, size_t index);
void					ft_lstadd_to_end(t_list **alst, t_list *new);
void					*ft_memalloc(size_t size);
void					*ft_memccpy(void *d, const void *s, int ch, size_t c);
void					*ft_memchr(const void *buffer, int ch, size_t count);
int						ft_memcmp(const void *mem1, const void *mem2, size_t n);
void					*ft_memcpy(void *destptr, const void *srcptr, \
	size_t num);
void					ft_memdel(void **ap);
void					*ft_memmove(void *dest, const void *source, \
	size_t count);
void					*ft_memset(void *destination, int c, size_t n);
void					ft_putchar_fd(char c, int fd);
void					ft_putchar(char c);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putendl(char const *s);
void					ft_putstr_fd(char const *s, int fd);
void					ft_putstr(char const *s);
char					*ft_strcat(char *str1, const char *str2);
char					*ft_strchr(const char *string, int symbol);
void					ft_strclr(char *s);
int						ft_strcmp(const char *str1, const char *str2);
char					*ft_strcpy(char *str1, const char *str2);
void					ft_strdel(char **as);
char					*ft_strdup(const char *src);
int						ft_strequ(char const *s1, char const *s2);
void					ft_striter(char *s, void (*f)(char *));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
char					*ft_strjoin(char const *s1, char const *s2);
size_t					ft_strlcat(char *str1, const char *str2, size_t num);
size_t					ft_strlen(const char *string);
char					*ft_strmap(char const *s, char (*f)(char));
char					*ft_strmapi(char const *s, \
	char (*f)(unsigned int, char));
char					*ft_strncat(char *str1, const char *str2, size_t num);
int						ft_strncmp(const char *str1, const char *str2, \
	size_t num);
char					*ft_strncpy(char *dest, const char *source, \
	size_t count);
int						ft_strnequ(char const *s1, char const *s2, size_t n);
char					*ft_strnew(size_t size);
char					*ft_strnstr(const char *str1, const char *str2, \
	size_t len);
char					*ft_strrchr(const char *string, int symbol);
char					**ft_strsplit(char const *s, char c);
char					*ft_strstr(const char *str1, const char *str2);
char					*ft_strsub(char const *s, unsigned int start, \
	size_t len);
char					*ft_strtrim(char const *s);
int						ft_tolower(int ch);
int						ft_toupper(int ch);
int						get_next_line(const int fd, char **line);

#endif
