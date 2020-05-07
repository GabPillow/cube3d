#include "../cub3d.h"

static void texture_to_default(t_alltxt *lst)
{
    lst->south.id = NULL;
    lst->south.data = NULL;
    lst->south.width = 0;
    lst->south.height = 0;
    lst->north.id = NULL;
    lst->north.data = NULL;
    lst->north.width = 0;
    lst->north.height = 0;
    lst->east.id = NULL;
    lst->east.data = NULL;
    lst->east.width = 0;
    lst->east.height = 0;
    lst->west.id = NULL;
    lst->west.data = NULL;
    lst->west.width = 0;
    lst->west.height = 0;
    lst->sprite.data = NULL;
    lst->sprite.width = 0;
    lst->sprite.height = 0;
}

void    init_to_default(t_data *data)
{
    data->window = NULL;
    data->map = NULL;
    data->img.img_ptr = NULL;
    data->map_h = 0;
    data->map_w = 0;
	data->posx = 0;
	data->posy = 0;
	data->dirx = 0;
	data->diry = 0;
	data->planex = 0;
	data->planey = 0;
	data->wd_h = 0;
	data->wd_w = 0;
    data->list.floor = -1;
    data->list.ceiling = -1;
    texture_to_default(&data->list);
}
