#include "../cub3d.h"

void    init_position(char p, int x, int y, t_data *data)
{
	if (data->posx != 0 || data->posy != 0)
		ft_error(&data, "Position already set");
    if (x == 0 || y == 0 || x == data->map_w || y == data->map_h)
		ft_error(&data, "Imposible to start at this position");
	data->posx = x + 0.5;
	data->posy = y + 0.5;
	if (p == 'S')
	{
		data->dirx = 1;
		data->planey = -0.66;
	}
	else if (p == 'N')
	{
		data->dirx = -1;
		data->planey = 0.66;
	}
	else if (p == 'E')
	{
		data->diry = 1;
		data->planex = 0.66;
	}
	else if (p == 'W')
	{
		data->diry = -1;
		data->planex = -0.66;
	}
	else
		ft_error(&data, "Position have to be marked with : S N E W only");
}