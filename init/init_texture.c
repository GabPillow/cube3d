#include "../cub3d.h"

void    init_texture(t_data *data, t_txt *txt, char *line)
{
    int i;

    i = 2;
    while (line[i] == ' ')
        i++;
    if (!(txt->id  = mlx_xpm_file_to_image(data->mlx, line + i, \
    &txt->height, &txt->width)))
    {
        ft_strdel(&line);
        ft_error(data, "Wrong path for texture");
    }
	txt->data = (int*)mlx_get_data_addr(txt->id, &txt->bpp, \
    &txt->size_l, &txt->endian);
}