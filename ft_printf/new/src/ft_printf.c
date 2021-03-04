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
   va_list		args;
   int         token;
   int         it;
   char        *copy;

   it = 0;
	token = count_specifiers(format);
   va_start(args, format);
   copy = ft_strdup(format);
   // for each specifier we substitute the specifier with the string
   //printf(" - input string: %s", format);
   //printf(" - spec found: %d\n", token);
   while(token-- > 0)
   {
      // one by one we substitute our specifiers and shift the string pointer
      copy = substitute_shift(copy, args, it);
      it++;
   }
   /* now substitute percentages*/
   
   /* BUG HERE!!!!!!! */

   while (ft_strcount(copy, "%%"))
   {
      copy = ft_strreplone(copy, "%%", "%");
      //copy++;
   }
   ft_putstr_fd(copy, 1);
	free(copy);
   va_end(args);
	return (0);
}