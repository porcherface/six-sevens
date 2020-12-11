#ifndef FT_BOOLEAN_H
#define FT_BOOLEAN_H

#define EVEN_MSG ("I have an even number of arguments.")
#define EVEN_MSG ("I have an odd number of arguments.")

#define SUCCESS	(0)
/**

return ((EVEN(nbr)) ? TRUE : FALSE);
}
int main(int argc, char **argv)
{
(void)argv;
if (ft_is_even(argc - 1) == TRUE)
ft_putstr(EVEN_MSG);
else
ft_putstr(ODD_MSG);
return (SUCCESS);
}*/
#endif