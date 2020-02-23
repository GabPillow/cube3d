#include "cub3d.h"

int main(int argc, char **argv)
{
    t_data  data;
    int     i;

    i = 0;
    if (argc == 2)
    {
        parsing_data(argv[1], &data);
        printf("MAP=\n");
        while (i < data.map_h)
        {
            printf("%.*s\n", data.map_w, data.map[i]);
            i++;
        }
        printf("MAP_W=%d\n", data.map_w);   
        printf("MAP_H=%d\n", data.map_h);
        printf("POSX=%f\n", data.posx);
        printf("POSY=%f\n", data.posy);
        printf("DIRX=%f\n", data.dirx);
        printf("DIRY=%f\n", data.diry);
        printf("PLANEX=%f\n", data.planex);
        printf("PLANEY=%f\n", data.planey);
        printf("WD_H=%d\n", data.wd_h);
        printf("WD_w=%d\n", data.wd_w);
        ft_strdel(&data.map[0]);
        free(data.map);
    }
    return (0);
}