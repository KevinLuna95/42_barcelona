#include <unistd.h>
#include <fcntl.h>
void ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int main(void)
{
	int file = open("file.txt", O_WRONLY);
	if (!file)
		return (0);
	ft_putchar_fd('a', file);
	return (0);
}