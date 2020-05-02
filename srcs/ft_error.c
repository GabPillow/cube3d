#include "../cub3d.h"

void    ft_error(t_data *data, char *s)
{
    write(2, "Error : ", 8);
    write(2, s, ft_strlen(s));
    write(2, "\n", 1);
    ft_exit_cub(&data);
}