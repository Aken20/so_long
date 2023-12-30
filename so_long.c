#include "so_long.h"

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define MAX_MAP_SIZE 100 // Define the maximum map size

int ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
    int i;
    unsigned char *p1;
    unsigned char *p2;

    i = 0;
    p1 = (unsigned char *)s1;
    p2 = (unsigned char *)s2;
    if (n == 0)
        return (0);
    while (p1[i] && p2[i] && --n)
    {
        if (p1[i] == p2[i])
            ++i;
        else
            return (p1[i] - p2[i]);
    }
    return (p1[i] - p2[i]);
}

int map_check(char **map)
{
    int i = 0;
    while (map[i])
    {
        printf("%s", map[i]);
        free (map[i]);
        i++;
    }
    free(map);
    return(0);
}

int main(int ac, char **av)
{
    int i;
    int fd;
    char *s;
    char **map;

    i = 0;
    s = "a";
    if (ac == 2)
    {
        while (av[1][i])
            i++;
        i -= 4;
        if (ft_strncmp(av[1] + i, ".ber", 4))
            return printf("wrong map");
        i = 0;
        fd = open(av[1], O_RDONLY);
        map = malloc(sizeof(char *) * (5 + 1));
        while (s)
        {
            s = get_next_line(fd);
            if (!s)
                break;
            map[i] = malloc(sizeof(char) * (ft_strlen(s) + 1));
            map[i] = ft_strdup(s, 1);
            i++;
        }
        map[i] = NULL;
        close(fd);
        map_check(map);
        return printf("\nvalid map");
        return (0);
    }
    else
        return printf("there's no map");
    return (0);
}
