#include "../cub3d.h"

void    init_sprite(t_data *data)
{
    int y;
    int x;
    int i;

    i = 0;
    y = 0;
    x = 0;
    if (data->nbsprite)
    {
        data->tab_sprite = ft_calloc(data->nbsprite, sizeof(t_sprite));
        while (x < data->map_h)
        {
            while (data->map[x][y])
            {
                if (data->map[x][y] == '2')
                {
                    data->tab_sprite[i].x = x + 0.1;
                    data->tab_sprite[i].y = y + 0.1;
                    i++;
                }
                y++;
            }
            y = 0;
            x++;
        }
    }
}