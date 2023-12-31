#include "so_long.h"

// int comm(t_data *img)
// {
//             img->x += 1;
//             img->y += 1;
//             mlx_put_image_to_window(img->mlx, img->win,img->img, img->x, img->y);

// }

int com(t_data *img)
{
        printf("x = %d\n", img->x);
        if (img->x > 0)
        {
            img->x -= 1;
            img->y -= 1;
            mlx_put_image_to_window(img->mlx, img->win,img->img, img->x, img->y);
            // mlx_clear_window(img->mlx, img->win);
            // mlx_do_sync(img->mlx);
        }
        if (img->x < 150)
        {
            img->x += 100;
            img->y += 100;
            mlx_put_image_to_window(img->mlx, img->win,img->img, img->x, img->y);
            // mlx_clear_window(img->mlx, img->win);
            mlx_do_sync(img->mlx);
        }
        sleep(3);
}

void    ft_print_img(t_data *img, int color)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (x < 500)
    {
        while(y < 450)
        {
        mlx_pixel_put(img->mlx, img->win, x, y, color);
        y++;
        }
    y = 0;
    x++;
    }
    while (x < 900)
    {
        while(y < 950)
        {
        mlx_pixel_put(img->mlx, img->win, x, y, color);
        y++;
        }
    y = 950;
    x++;
    }
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
    int size;
    char *s;
    char **map;
    t_data    *img;
    
    size = 920;
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
            map[i] = ft_g_strdup(s, 1);
            i++;
        }
        map[i] = NULL;
        img = malloc(sizeof(t_data));
        close(fd);
        map_check(map);
        img->x = 0;
        img->y = 0;
        printf("\nvalid map");
        img->mlx = mlx_init();
	    img->win = mlx_new_window(img->mlx, 1920, 1200, "Hello world!");
        // img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
        // ft_print_img(img->mlx, img->img, 0x00990000);
        img->img = mlx_xpm_file_to_image(img->mlx, "earth.xpm", &size, &size);
        if (img->img == NULL)
            return (ft_printf("error"));
        mlx_put_image_to_window(img->mlx, img->win,img->img, 0, 0);
        mlx_loop_hook(img->mlx, com, &img);
        mlx_loop(img->mlx);
        return (0);
    }
    else
        return printf("there's no map");
    return (0);
}
