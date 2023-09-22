#include <unistd.h>
#include <fcntl.h>
void ft_putstr_fd(char *s, int fd)
{
	int c;

	c = -1;
	while (s[++c])
		write(fd, &s[c], 1);
}

int main(void)
{
	int file = open("file.txt", O_WRONLY);
	if (!file)
		return (0);
	ft_putstr_fd("Hola soy kevin y estoy escribiendo en un fichero\nAhora en una nueva línea", file);
	return (0);
}