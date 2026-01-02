long ft_atol(char *str)
{
    long res;
    int i;
    int sign;

    i = 0;
    sign = 1;
    res = 0;

    while (str[i] && (str[i] == '+' || str[i] == '-'))
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] && (str[i] >= '0' && str[i] <= '9'))
        res = res * 10 + (str[i++] - '0');
    return (res * sign);
}