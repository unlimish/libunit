#include <unistd.h>

void    ft_putchar_fd(char c, int fd)
{
        write(fd, &c, 1);
}

void    ft_putendl_fd(char *s)
{
        ft_putstr_fd(s, fd);
        write(1, "\n", 1);
}

void    ft_putstr_fd(char *s, int fd)
{
        int     i;

        if (s == NULL)
                return ;
        i = 0;
        while (s[i] != '\0')
        {
                ft_putchar_fd(s[i], fd);
                i++;
        }
}

void    ft_putnbr_fd(int n, int fd)
{
        if (n == -2147483648)
                ft_putstr_fd("-2147483648", fd);
        else if (n == 0)
                ft_putchar_fd('0', fd);
        else if (n < 0)
        {
                ft_putchar_fd('-', fd);
                ft_putnbr_fd(n * -1, fd);
        }
        else if (n >= 10)
                ft_putnbr_fd(n / 10, fd);
        if (n > 0)
                ft_putchar_fd((n % 10) + '0', fd);
}
