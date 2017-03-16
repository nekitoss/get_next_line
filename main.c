#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		main(void)
{
    char	*line;
    int r;
    
    r = 1;
    int fd1 = open("/nfs/2016/m/mpochuka/Desktop/getnextline/getnextline/text.txt", O_RDONLY);
//while(1){
        
    while (r > 0)
    {
        line = NULL;
        r = get_next_line(fd1, &line);
        printf("%s\n", line);
    }
    close(fd1);
//}
    return (0);
}
