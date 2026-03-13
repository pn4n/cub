#include "header.h"

static void	init_image(t_img *i, void *mlx)
{
	i->img = mlx_new_image(mlx, WIN_W, WIN_H);
	i->addr = mlx_get_data_addr(i->img, &i->bits_per_pixel, &i->line_length,
			&i->endian);
	i->bytes_per_pixel = i->bits_per_pixel / 8;
}


int main(int ac, char **av)
{
	t_data	d;
	
	d.mlx = mlx_init();
	d.win = mlx_new_window(d.mlx, WIN_W, WIN_H, "cub");
	init_image(&d.img0, d.mlx);
	init_image(&d.img1, d.mlx);
	d.img_n = 1;

	draw(&d);
	mlx_hook(d.win, 17, 0, close_window, &d);
	mlx_hook(d.win, 2, 1L << 0, key_hook, &d);
	mlx_loop(d.mlx);

	return av[ac] ? 1 : 0;
}