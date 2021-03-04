void	ft_putdouble_fd(double d, int fd, int num)
{
	int		i;

	i = 0;
	ft_putnbr_fd(fd, (int)d);
	ft_putchar_fd(fd, '.');
	d -= (int)d;
	while (i++ < num)
		d *= 10;
	ft_putnbr_fd(fd, (int)d);
}

void	ft_putdouble_fd(double d, int fd)
{
	int		i;

	i = 0;
	ft_putnbr_fd(fd, (int)d);
	ft_putchar_fd(fd, '.');
	d -= (int)d;
	while (d - (int)d > 0)
		d *= 10;
	ft_putnbr_fd(fd, (int)d);
}