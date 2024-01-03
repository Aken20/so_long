#include "so_long.h"

int ft_render(t_data *img)
{
    mlx_clear_window(img->mlx, img->win);
    while (img->y < img->map_s->y)
    {
        while(img->x < img->map_s->x)
        {
            if (img->map_s->map[img->y][img->x] == '1')
                mlx_put_image_to_window(img->mlx, img->win, img->img_s->wall, (img->x * img->size), (img->y * img->size));
            else if (img->map_s->map[img->y][img->x] == 'C')
                mlx_put_image_to_window(img->mlx, img->win, img->img_s->collectable, (img->x * img->size), (img->y * img->size));
            else if (img->map_s->map[img->y][img->x] == 'P')
            {
                img->map_s->p_x = img->x;
                img->map_s->p_y = img->y;
                mlx_put_image_to_window(img->mlx, img->win, img->img_s->player, (img->x * img->size), (img->y * img->size));
            }
            else if (img->map_s->map[img->y][img->x] == 'E')
                mlx_put_image_to_window(img->mlx, img->win, img->img_s->exit, (img->x * img->size), (img->y * img->size));
            img->x++;
        }
        img->x = 0;
        img->y++;
    }
    img->x = 0;
    img->y = 0;
    return (0);
}

// int ft_up(t_data *img)
// {
//     while (img->y < img->map_s->y)
//     {
//         while(img->x < img->map_s->x)
//         {
//             if (img->map_s->map[img->y][img->x] == 'P')
//                 mlx_put_image_to_window(img->mlx, img->win, img->img_s->wall, (img->x * img->size - 30), (img->y * img->size));
//             img->x++;
//         }
//         img->x = 0;
//         img->y++;
//     }
//     img->x = 0;
//     img->y = 0;
//     return (0);
// }

int ft_hocks(int keycode, t_data *img)
{
    if (keycode == ESC)
    {
        mlx_destroy_window(img->mlx, img->win);
        free(img);
        exit(0);
    }
    if (keycode == W)
    {
        if(img->map_s->map[img->map_s->p_y - 1][img->map_s->p_x] == '0')
        {
            img->map_s->map[img->map_s->p_y - 1][img->map_s->p_x] = 'P';
            img->map_s->map[img->map_s->p_y][img->map_s->p_x] = '0';
        }
        else if(img->map_s->map[img->map_s->p_y - 1][img->map_s->p_x] == 'C')
        {
            img->map_s->map[img->map_s->p_y - 1][img->map_s->p_x] = 'P';
            img->map_s->map[img->map_s->p_y][img->map_s->p_x] = '0';
        }
    }
    if (keycode == A)
    {
        if(img->map_s->map[img->map_s->p_y][img->map_s->p_x - 1] == '0')
        {
            img->map_s->map[img->map_s->p_y][img->map_s->p_x - 1] = 'P';
            img->map_s->map[img->map_s->p_y][img->map_s->p_x] = '0';
        }
        else if(img->map_s->map[img->map_s->p_y][img->map_s->p_x - 1] == 'C')
        {
            img->map_s->map[img->map_s->p_y][img->map_s->p_x - 1] = 'P';
            img->map_s->map[img->map_s->p_y][img->map_s->p_x] = '0';
        }
    }
    if (keycode == S)
    {
        if(img->map_s->map[img->map_s->p_y + 1][img->map_s->p_x] == '0')
        {
            img->map_s->map[img->map_s->p_y + 1][img->map_s->p_x] = 'P';
            img->map_s->map[img->map_s->p_y][img->map_s->p_x] = '0';
        }
        else if(img->map_s->map[img->map_s->p_y + 1][img->map_s->p_x] == 'C')
        {
            img->map_s->map[img->map_s->p_y + 1][img->map_s->p_x] = 'P';
            img->map_s->map[img->map_s->p_y][img->map_s->p_x] = '0';
        }
    }
    if (keycode == D)
    {
        if(img->map_s->map[img->map_s->p_y][img->map_s->p_x + 1] == '0')
        {
            img->map_s->map[img->map_s->p_y][img->map_s->p_x + 1] = 'P';
            img->map_s->map[img->map_s->p_y][img->map_s->p_x] = '0';
        }
        else if(img->map_s->map[img->map_s->p_y][img->map_s->p_x + 1] == 'C')
        {
            img->map_s->map[img->map_s->p_y][img->map_s->p_x + 1] = 'P';
            img->map_s->map[img->map_s->p_y][img->map_s->p_x] = '0';
        }
    }
    return (0);
}

int map_check(char **map)
{
    int i = 0;

    while (map[i])
    {
        ft_printf("%s\n", map[i]);
        i++;
    }
    exit(ft_putstr("complete"));
}

// int	key_hook(int keycode, t_data *img)
// {
// 	printf("Hello from key_hook!\n");
// 	return (0);
// }

int main(int ac, char **av)
{
    int i;
    t_data    *img;
    
    i = 0;
    if (ac == 2)
    {
        img = malloc(sizeof(t_data));
        img->size = 60;
        while (av[1][i])
            i++;
        i -= 4;
        if (ft_strncmp(av[1] + i, ".ber", 4))
            return printf("wrong map");
        i = 0;
        img = malloc(sizeof(t_data));
        img->map_s = malloc(sizeof(t_map));
        img->img_s = malloc(sizeof(t_imgs));
        img->map_s->map = ft_read_map(img->map_s->map, av[1]);
        img->map_s->x = (int)ft_strlen(img->map_s->map[0]);
        while (img->map_s->map[i])
            i++;
        img->map_s->y = i;
        // map_check(img->map_s->map);
        ft_check_map(img->map_s->map);
        img->x = 0;
        img->y = 0;
        img->mlx = mlx_init();
	    img->win = mlx_new_window(img->mlx, (img->map_s->x * 60), (img->map_s->y * 60), "Hello world!");
        img->img_s->wall = mlx_xpm_file_to_image(img->mlx, "wall.xpm", &img->size, &img->size);
        img->img_s->exit = mlx_xpm_file_to_image(img->mlx, "exit.xpm", &img->size, &img->size);
        img->img_s->collectable = mlx_xpm_file_to_image(img->mlx, "collectable.xpm", &img->size, &img->size);
        img->img_s->player = mlx_xpm_file_to_image(img->mlx, "player.xpm", &img->size, &img->size);
        // ft_render(img);
        mlx_loop_hook(img->mlx, ft_render, img);
        mlx_hook(img->win, 2, 0, ft_hocks, img);
        mlx_loop(img->mlx);
        return (0);
    }
    else
        return printf("there's no map");
    return (0);
}
