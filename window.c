#include "defines.h"

void put_pixel(char *data, int x, int y, int color, int size_line, int bpp) {
    int pixel = y * size_line + x * (bpp / 8);
    data[pixel] = color & 0xFF; // Blue
    data[pixel + 1] = (color >> 8) & 0xFF; // Green
    data[pixel + 2] = (color >> 16) & 0xFF; // Red
}

void	draw(t_data *d)
{
	// float		scale_x;
	// float		scale_y;
	t_img		*img;

	if ((int)d->img_n == 1)
		img = &d->img1;
	else
		img = &d->img0;
	d->img_n *= -1;
	// scale_x = (f->maxx - f->minx) / WIN_W;
	// scale_y = (f->maxy - f->miny) / WIN_H;
	// rgb_phases(f);
	// pixel_loop(scale_x, scale_y, f, img);
	// put_pixel(img, 10, 10, 1, 1, )

	int x = 10, y = 10;
	int color = 0xFF0000;
	*(int *)(img->img + (y * img->line_length) + (x * (img->bytes_per_pixel))) = color;
		
	mlx_put_image_to_window(d->mlx, d->win, img->img, 0, 0);
	// add_menu_text(f->mlx, f->win);
	// if (f->f == JULIA)
	// 	add_julia_text(f->mlx, f->win, f->kr, f->ki);
}

int	key_hook(int key, t_data *f)
{
	if (key == 65307)
		close_window(f);
	// else if (key >= CODE_LEFT && key < CODE_LEFT + 5)
	// 	move_view(f, key - CODE_LEFT);
	// else if (key == ' ')
	// 	f->rgb_shift = (f->rgb_shift + 1) % 10;
	// else if (key == 61)
	// 	zoom(f, 0.8, WIN_H / 2, WIN_W / 2);
	// else if (key == 45)
	// 	zoom(f, 1.2, WIN_H / 2, WIN_W / 2);
	// else if (key > '0' && key < '0' + FNUM + 1)
	// 	f->f = key - '0' - 1;
	// else if (f->f == JULIA)
	// 	julia_hook(f, key);
	// draw_f(f);
	return (0);
}

int	close_window(t_data *f)
{
	mlx_destroy_image(f->mlx, f->img1.img);
	mlx_destroy_image(f->mlx, f->img0.img);
	mlx_destroy_window(f->mlx, f->win);
	mlx_destroy_display(f->mlx);
	free(f->mlx);
	exit(0);
	return (0);
}
