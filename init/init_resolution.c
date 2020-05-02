#include "../cub3d.h"

static void correct_wd_size(t_data *data, char *line)
{
    int sizex;
    int sizey;

    if (!data->wd_h || !data->wd_w)
    {
        ft_strdel(&line);
        ft_error(data, "Params for resolution can't be 0");
    }
    mlx_get_screen_size(data->mlx, &sizex, &sizey);
    if (data->wd_w > sizex || data->wd_h > sizey)
    {
        data->wd_w = sizex;
        data->wd_h = sizey;
    }
}

void   init_resolution(t_data *data, char *line)
{
    int i;

    i = 1;
    while (line[i])
    {
        if (!ft_isdigit(line[i]) && line[i] != ' ')
        {
            ft_strdel(&line);
           ft_error(data, "Params wrong for resolution");
        }
        i++;
    }
    i = 1;
    while (line[i] == ' ')
        i++;
    data->wd_w = ft_atoi(line + 1);
    while (ft_isdigit(line[i]))
        i++;
    data->wd_h = ft_atoi(line + i);
    while (ft_isdigit(line[i]))
        i++;
    if (line[i])
    {
        ft_strdel(&line);
        ft_error(data, "Params wrong for resolution");
    }
    correct_wd_size(data, line);       
}