#include "../cub3d.h"

void    init_color(t_data *data, int color, char *line)
{
    int i;
    int true;

    true = 0;
    i = 1;
    while (line[i])
    {
        ft_isdigit(line[i]) || true ? true == 1 : 0;
        if (!ft_isdigit(line[i]) && line[i] != ' ')
        {
            ft_strdel(&line);
            ft_error(data, "Params wrong for color");
        }
        i++;
    }
    i = 1;
    while (line[i] == ' ')
        i++;
    while (ft_isdigit(line[i]))
        i++;
    if (line[i])
    {
        ft_strdel(&line);
        ft_error(data, "Params wrong for color");
    }
	color = ft_atoi(line[1]);
}