#ifndef _DEFINES_H_
#define _DEFINES_H_


# define WIN_H 1000
# define WIN_W 1000


typedef struct s_complex
{
	float			r;
	float			i;
}					t_complex;

typedef struct s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct t_img
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				bytes_per_pixel;
	int				line_length;
	int				endian;
}					t_img;

typedef struct s_main
{
	void			*mlx;
	void			*win;
	t_img			img0;
	t_img			img1;
	char 			img_n;
}					t_data;


#endif