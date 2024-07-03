/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 19:55:13 by dkolida           #+#    #+#             */
/*   Updated: 2024/07/03 23:05:12 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# define RED  "\x1B[31m"
# define GREEN  "\x1B[32m"
# define NORMAL  "\x1B[0m"


// libft
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_atoi(const char *nptr);
char	*ft_strdup(const char *s);
int		ft_isdigit(int c);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
int		ft_isprint(int c);
int		ft_isascii(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *s1, const char *s2, size_t len);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_itoa(int n);
//ft_split.c
char	**ft_split(char const *s, char c);
void	ft_free_split(char **split);

void	ft_free_2d(char **split, int len);
int		is_arr_uniq(int *array, int len);
int		is_int_str(char *str);
void	ft_arr_atoi(char **array, int *stack, int len);

// helpers.c
char	*ft_itoa_wrapper(long long n);
char	*ft_utoa_wrapper(long long n);
char	*ft_ctoa_wrapper(long long n);
char	*ft_utob16_wrapper(long long n);
char	*ft_utob16u_wrapper(long long n);

//compare.c
int		ft_is_smaller(int a, int b);
int		ft_is_larger(int a, int b);
int		ft_smallest(int a, int b);
int		ft_largest(int a, int b);

// push_swap
typedef struct int_arr
{
	int	*array ;
	int	size ;
}	t_int_arr;

int		ft_sorted(int *arr, int size);
int		ft_sorted_desc(int *arr, int size);

/*
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstiter(t_list *lst, void (*f) (void *));

int		ft_lstsize(t_list *lst);

t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(void *content);
t_list	*ft_lstmap(t_list *lst, void *(*f) (void *), void (*del) (void *));


typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
*/

#endif
