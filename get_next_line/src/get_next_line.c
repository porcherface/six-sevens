

/*
Function name get_next_line

Prototype int get_next_line(int fd, char **line);

Turn in files get_next_line.c, get_next_line_utils.c,
get_next_line.h

Parameters #1. file descriptor for reading
#2. The value of what has been read

Return value 
1 : A line has been read
0 : EOF has been reached
-1 : An error happened

External functs. read, malloc, free
Description Write a function which returns a line read from a
file descriptor, without the newline.


Calling your function get_next_line in a loop will then allow you to read the text
available on a file descriptor one line at a time until the EOF.
• Make sure that your function behaves well when it reads from a file and when it
reads from the standard input.
• libft is not allowed for this project. You must add a get_next_line_utils.c file
which will contain the functions that are needed for your get_next_line to work.
• Your program must compile with the flag -D BUFFER_SIZE=xx. which will be used
as the buffer size for the read calls in your get_next_line. This value will be
modified by your evaluators and by moulinette.
• Compilation will be done this way : gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32
get_next_line.c get_next_line_utils.c
• Your read must use the BUFFER_SIZE defined during compilation to read from
a file or from stdin.
• In the header file get_next_line.h you must have at least the prototype of the
function get_next_line


ssize_t read(int fd, void *buf, size_t count);
DESCRIZIONE
La funzione read() legge da fd numero count bytes immagazzinandoli nel buffer puntato da buf.
buf deve essere di dimensioni adeguate, cioe' almeno di count bytes.
VALORE DI RITORNO
La funzione read() ritorna il numero di elementi letti. In caso di raggiungimento della fine file viene restituito un numero minore di count. In caso di errore viene restituito -1.
CONFORME A
SVr4, SVID, AT&T, POSIX, X/OPEN, BSD 4.3
*/


#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*out;
	size_t	len;
	size_t	it;
	size_t	jt;

	len = ft_strlen(s1) + ft_strlen(s2);
	out = (char *)malloc(sizeof(*s1) * (len + 1));
	if (!out)
		return (0x0);
	jt = 0;
	it = 0;
	while (s1[it])
	{
		out[it] = s1[it];
		it++;
	}
	while (s2[jt])
	{
		out[it + jt] = s2[jt];
		jt++;
	}
	out[it + jt] = 0;
	return (out);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*out;
	size_t	slen;
	size_t	it;

	it = 0;
	slen = ft_strlen(s);
	if (!s)
		return (0x0);
	if (slen < start)
		len = 0;
	out = (char *)malloc(sizeof(*out) * (len + 1));
	if (!out)
		return (0x0);
	while (it < len && s[it + start])
	{
		out[it] = s[it + start];
		++it;
	}
	out[it] = 0;
	return (out);
}


static int	appendline(char **s, char **line)
{
	int		len;
	char	*tmp;

	len = 0;
	while ((*s)[len] != '\n' && (*s)[len] != '\0')
		len++;
	if ((*s)[len] == '\n')
	{
		*line = ft_substr(*s, 0, len);
		tmp = ft_strdup(&((*s)[len + 1]));
		free(*s);
		*s = tmp;
		if ((*s)[0] == '\0')
			ft_strdel(s);
	}
	else
	{
		*line = ft_strdup(*s);
		ft_strdel(s);
	}
	return (1);
}

static int	output(char **s, char **line, int ret, int fd)
{
	if (ret < 0)
		return (-1);
	else if (ret == 0 && s[fd] == NULL)
		return (0);
	else
		return (appendline(&s[fd], line));
}

int			get_next_line(const int fd, char **line)
{
	int			token;
	static char	*s[MAX_FD];
	char		buff[BUFFER_SIZE + 1];
	char		*tmp;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((token = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[token] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(s[fd], buff);
			free(s[fd]);
			s[fd] = tmp;
		}
		if (ft_strchr(s[fd], '\n'))
			break ;
	}
	return (output(s, line, token, fd));
}