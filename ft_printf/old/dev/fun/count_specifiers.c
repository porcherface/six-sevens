
/* parses a string to return va_count */

int		count_specifiers(const char *str)
{
	int		va_count;

    /* if string is fuffa */
    if (!str)
        return (-1);
    va_count = 0;
    /* count % */
    while(*str)
    {
        if (*str == '%')
            va_count++; 
        str++;
        if (*str == '%')
        {
            str++;
            va_count--;
        }
    }
	return va_count;
}

