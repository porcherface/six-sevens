/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                           :+:      :+:    :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 14:17:19 by amazzei           #+#    #+#             */
/*   Updated: 2020/12/11 13:20:40 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

/* typedef */
/* simple */
typedef unsigned char		t_byte;


/* structured */
typedef struct     s_list
{
    void           *content;
    struct s_list  *next;
}                  			t_list;
typedef struct     s_tree
{
    void			*content;
    struct s_tree	*parent;
    struct s_tree	**children;
}							t_tree;

/* asserts */
int			ft_isdigit(int c);
int			ft_isalpha(int c);
int			ft_isprint(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isupper(int c);
int			ft_islower(int c);
 
/* string */
size_t		ft_strcount(const char *s, int c);
size_t		ft_strlen(const char *str);
size_t		ft_strlenchr(const char *str, int c);
char		*ft_strdup(const char *src);
char		*ft_strdupchr(const char *src, int c);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
int			ft_strcmp(char *s1, char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnjoin(int size, char **strs, char *sep);
char 		*ft_strnstr(const char *s1, const char *s2, size_t n);
char 		*ft_substr(char const *s, unsigned int start, size_t len);
char 		*ft_strjoin(char const *s1, char const *s2);
char 		*ft_strtrim(char const *s1, char const *set);
char 		**ft_split(char const *s, char c);
char 		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		**ft_splitall(char const *s, char c);
char        *ft_strnew(size_t size);
void        ft_strdel(char **as);
void        ft_strappend(char *s, char *buf); 
char		*ft_strreplone(char *str, char *old, char *new);
char		*ft_strrepl(char *str, char *old, char *new);

/* mem */
void 		*ft_memset(void *b, int c, size_t len);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memccpy(void *dst, const void *src, int c, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t n);
int 		ft_memcmp(const void *s1, const void *s2, size_t n);
void		ft_initialize(size_t *a, size_t *b, size_t *c, size_t *d);

/* put */
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

/* alloc */
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);
int			*ft_range(int min, int max);

/* translators */
int			ft_tolower(int c);
int			ft_toupper(int c);
int			ft_atoi(const char *str);
int			ft_atoi_base(const char *str, char *base);
char		*ft_itoa(int n);
char		*ft_itoa_anybase(int nb, char *base);
char		*ft_itoa_base(int nb, int base_num);

/* algorithms */
void		ft_rev_ints(int *tab, int size);
void		ft_bubblesort_ints(int *tab, int size);
int			ft_find_next_prime(int nb);
int			ft_isprime(int nb);

/* lists */
t_list		*ft_lstnew(void *content);
int			ft_lstsize(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_front(t_list **lst, t_list *new);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void*));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *),void (*del)(void *));


#endif