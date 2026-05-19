#include "get_next_line.h"

char *get_next_line(int fd)
{
    char *ret;
    char c;
    int i = 0;
    int rd = 0;

    if(fd < 0)
        return(NULL);
    ret = malloc(100000);
    if(!ret)
        return (NULL);
    while((rd = read(fd, &c,1)) >0)
    {
        ret[i++] = c;
        if (c == '\n')
            break;
    }
    if ((i ==0 && rd ==0) || rd <0)
    {
        free(ret);
        return (NULL);
    }
    ret[i] = '\0';
    return (ret);
}
