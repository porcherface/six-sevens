

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/* REMEMBER TO REMOVE THIS INCLUSION */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


#define GNL_ERROR			(-1)
#define GNL_SUCCESS			(0x0)
#define GNL_CONTINUE		(000001)

#define BYTE_EOS			(0x0)
#define BYTE_EOF			(0x00004)
#define BYTE_NEWL			('\n')


#ifndef     BUFFER_SIZE
# define    BUFFER_SIZE (4096)
#endif

#ifndef     MAX_FD
# define    MAX_FD (256)
#endif


/* from utils */
unsigned int	ft_strlen(const char *str);
char			*ft_strdup(const char *src);
char            *ft_strchr(const char *s, int c);
void            ft_strdel(char **as);
char            *ft_strjoin(char const *s1, char const *s2);
char            *ft_substr(char const *s, unsigned int start, size_t len);
int              get_next_line(const int fd, char **line);




#endif