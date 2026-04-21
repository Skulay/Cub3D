#include <stdlib.h>
#include <unistd.h>
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BOLD "\033[6m"
size_t ft_strlen(char *s)
{
    size_t i = 0;

    while (s[i])
        i++;
    return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;

	len = ft_strlen(s);
	write(fd, s, len);
}

int main()
{
    ft_putstr_fd(RED BOLD "Salut a ", 1);
    ft_putstr_fd(GREEN BOLD "tous", 1);
    return (0);
}