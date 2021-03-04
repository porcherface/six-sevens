#ifndef FT_REPL_H
# define FT_REPL_H

int	replace_char(char *fmt, char val);
int	replace_string(char *fmt, char *val);
int	replace_digit(char *fmt, int val);
int	replace_pointer(char *fmt, void *val);
int	replace_unsigned(char *fmt, unsigned val);
int	replace_float(char *fmt, float val);
int replace_percent(char *fmt);

#endif

