#ifndef MINILBX_H
#define MINILBX_H

typedef struct s_mlx
{
	void	*win;
	void	*ptr;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_mlx;

#endif
