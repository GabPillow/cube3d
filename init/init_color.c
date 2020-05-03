#include "../cub3d.h"

int    init_color(t_data *data, char *line)
{
    int i;
    int true;

    true = 0;
    i = 2;
    if (line[1] != ' ')
    {
        ft_strdel(&line);
        ft_error(data, "Params wrong for color");
    }
    while (line[i])
    {
        ft_isdigit(line[i]) || true ? true = 1 : 0;
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
    if (line[i] || !true)
    {
        ft_strdel(&line);
        ft_error(data, "Params wrong for color");
    }
	return (ft_atoi(line + 1));
}