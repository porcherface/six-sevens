/*


int sum(int num_args, ...) {
   int val = 0;
   va_list ap;
   int i;

   va_start(ap, num_args);
   for(i = 0; i < num_args; i++) {
      val += va_arg(ap, int);
   }
   va_end(ap);
*/

//#include "lib/libft.h"

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list		ap;
   int         token;
   int         it;
   char        *dart;
   char        *copy;

   it = 0;
	token = count_specifiers(format);
   //va_start(ap, token);
   va_start(ap, format);
   copy = ft_strdup(format);
   dart = copy;
   // for each specifier we substitute the specifier with the string
   while(token--)
   {
      // one by one we substitute our specifiers and shift the string pointer
      dart = substitute_shift(dart, copy, ap, it);
      it++;
   }
   //copy is null means we reached the end of the string before exahusting
   //
   if(!dart)
      return (-1);
   ft_putstr_fd(copy, 1);
	free(copy);
   va_end(ap);
	return (0);
}