#include "cub3d.h"

static  void sort_sprite(t_data *data, t_sprite *tab_sprite)
{
    t_sprite tmp;
    double dista;
    double distb;
    int i;

    i = 0;
    while (i < data->nbsprite - 1)
    {
        dista = ((data->posx - tab_sprite[i].x) * \
        (data->posx - tab_sprite[i].x) + (data->posy - tab_sprite[i].y) \
        * (data->posy - tab_sprite[i].y));
        distb = dista = ((data->posx - tab_sprite[i + 1].x) * \
        (data->posx - tab_sprite[i + 1].x) + (data->posy - tab_sprite[i+ 1].y)\
        * (data->posy - tab_sprite[i + 1].y));
        if (dista < distb)
        {
            tmp = tab_sprite[i];
            tab_sprite[i] = tab_sprite[i + 1];
            tab_sprite[i + 1] = tmp;
            i = 0;
        }
        i++;
    }
}

void    ft_raycasting_sprite(t_data *data, t_sprite *tab_sprite, t_txt txtsp, \
double *zbuffer)
{
    int i;
    int stripe;
    double spx;
    double spy;
    double invdet;
    double transx;
    double transy;
    int spscreen;
    int sp_h;
    int sp_w;
    int starty;
    int endy;
    int startx;
    int endx;
    int yt;
    int xt;
    int y;
    int d;

    i = 0;
    sort_sprite(data, tab_sprite);
    while (i < data->nbsprite)
    {
        spx = tab_sprite[i].x - data->posx;
        spy = tab_sprite[i].y - data->posy;
        invdet = 1.0 / (data->planex * data->diry - data->dirx * data->planey);
        transx = invdet * (data->diry * spx - data->dirx * spy);
        transy = invdet * (-data->planey * spx + data->planex * spy);
        spscreen = (int)((data->wd_w / 2) * (1 + transx / transy));
        sp_h = abs((int)(data->wd_h / (transy)));
        starty = -sp_h / 2 + data->wd_h / 2;
        if(starty < 0)
            starty = 0;
        endy = sp_h / 2 + data->wd_h / 2;
        if(endy >= data->wd_h)
            endy = data->wd_h;
        sp_w = abs((int)(data->wd_h / (transy)));
        startx = -sp_w / 2 + spscreen;
        if (startx < 0)
            startx = 0;
        endx = sp_w / 2 + spscreen;
        if(endx >= data->wd_w)
            endx = data->wd_w;
        stripe = startx;
        while (stripe < endx)
        {
            xt = (int)(256 * (stripe - (-sp_w / 2 + spscreen)) * txtsp.width /\
            sp_w) / 256;
            y = starty;
            if(transy > 0 && stripe > 0 && stripe < data->wd_w && transy < zbuffer[stripe])
            {
                while(y < endy)
                {
                    d = (y) * 256 - data->wd_h * 128 + sp_h * 128;
                    yt = ((d * txtsp.height) / sp_h) / 256;
                    if (txtsp.data[yt * txtsp.width + xt] != 0)
                        data->img.data[y * data->wd_w - 1 + stripe] = txtsp.data[yt * txtsp.width + xt];
                    y++;
                }
            }
            stripe++;
        }
        i++;
    }
}