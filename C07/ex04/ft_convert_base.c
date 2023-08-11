int	ft_atoi(char *str);
int check_base(char *base);
char	*ft_strcat(char *dest, char *src,char *base);

char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
    int size_from;
    int size_to;

    size_from = check_base(base_from);
    size_to =  check_base(base_to);
    if (size_from && size_to)
        return (0);
    

}



int nbr_base_to_dec(char *nbr, char *base)
{
    int dec;
    int c_sign;
    char str;

    ft_strcat(str, ft_atoi(nbr, base, &c_sign), base);
    //str ya tiene todo el string a convertir a número.


}