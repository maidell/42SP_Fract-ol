#include "libft.h"

int    ft_isnumber(const char *s)
{
    int    verify;

    verify = 0;
    if (s[ft_strlen(s) - 1] == '.')
        return (0);
    if (*s == '-' || *s == '+')
        s++;
    if (*s == '.')
        return (0);
    while (*s)
    {
        if (*s == '.')
            verify++;
        if (verify > 1)
            return (0);
        if (!ft_isdigit(*s) && *s != '.' && *s)
            return (0);
        s++;
    }
    return (1);
}