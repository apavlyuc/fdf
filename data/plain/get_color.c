
#include <fdf.h>

int						get_color(char *color_line)
{
	char				*c_spec;

	if ((c_spec = ft_strchr(color_line, ',')))
		return (ft_atoi(c_spec + 1));
	return (0xFFFFFFFF);
}
