#include <unistd.h>
#include <fcntl.h>

static void rec_nb_fd(int num, int fd)
{
    int mod;
    char c_num;

    mod = num % 10;
    num /= 10;
    if (num != 0)
        rec_nb_fd(num, fd);
    if (mod < 0)
        mod *= -1;
    c_num = '0' + mod;
    write(fd, &c_num, 1);
}

void ft_putnbr_fd(int n, int fd)
{
    if (n < 0)
        write(fd, "-", 1);
    rec_nb_fd(n, fd);
}

int main(void)
{
    int file = open("file.txt", O_WRONLY);
    if (!file)
        return (0);
    ft_putnbr_fd(-456, file);
    return (0);
}