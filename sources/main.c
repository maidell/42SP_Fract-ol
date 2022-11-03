#include "fractol.h"


// ponteiro é uma variável que guarda o endereço de memória de outra variável
// . quando eu quero acessar o valor de uma variavel da struct
// quando eu quero acessa o valor de uma variavel da struct por meio de um ponteiro
//

void	init_mlx(t_mlx *m)
{
	m->mlx = mlx_init();
	m->win = mlx_new_window(m->mlx, WIDTH, HEIGHT, TITLE);
	m->img = mlx_new_image(m->mlx, WIDTH, HEIGHT);
	m->addr = mlx_get_data_addr(m->img, &m->bits_per_pixel, &m->line_length,
			&m->endian);
}

void	init_var(t_fractol *f)
{
	f->min[REAL] = -1.5;
	f->max[REAL] = 1.5;
	f->min[IMAGINARY] = -1.5;
	f->max[IMAGINARY] = 1.5;
}



void    error_argument(int err)
{
    if (err == 1)
    {
        printf("\033[0;31mError: Missing argument or invite number\n");
        printf("\033[0;35mif you are using Julia fractal, you must\n");
        printf("add the complex number as a second argument\n");
        printf("\033[0;37mExample: ./fractol Julia -0.4 0.6\n");
    }
    else if (err == 2)
    {
        printf("\033[0;31mError: Invalid fractal name\n");
        printf("\033[0;35mAvailable fractals\n");
        printf("./fractol mandelbrot\n./fractol julia [number] [number]\n");
    }
    exit(EXIT_FAILURE);
}

void    handle_args(int argc, char **argv, t_fractol *var)
{
    if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
        var->fractal = mandelbrot;
    else if (argc >= 2 && !ft_strncmp(argv[1], "julia", 10))
    {
        var->fractal = julia;
        if (argc == 4 && ft_isnumber(argv[2]) && ft_isnumber(argv[3]))
        {
            var->complex[2] = ft_atof(argv[2]);
            var->complex[3] = ft_atof(argv[3]);
        }
        else
            error_argument(1);
    }
    else
        error_argument(2);
}

int	main(int argc, char **argv)
{
	t_mlx mlx;
	t_fractol var;

    handle_args(argc, argv, &var);
	init_var(&var);
	init_mlx(&mlx);
	var.fractal = mandelbrot;
	 draw_fractol(&mlx, &var);
	//my_mlx_pixel_put(&mlx, 400, 400, 0xFFF000);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
	mlx_loop(mlx.mlx);
}
