

void ft_striteri(char *s, void (*f)(unsigned int, char *))
{
    int c;

    c = -1;
    while (s[++c])
        f(c, s[c])
}