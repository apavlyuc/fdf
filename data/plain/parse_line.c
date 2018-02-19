
#include <plain.h>
#include <point.h>

static int				get_len_and_validate(char **data, t_plain *plain)
{
	int					len;

	len = 0;
	if (data == NULL)
		return (-1);
	while (*data)
	{
		data++;
		len++;
	}
	if (plain->width == 0)
		plain->width = len;
	if (plain->width == 0 || plain->width != len)
		return (-1);
	return (len);
}

t_plain					*parse_line(t_plain *plain, char *line)
{
	char				**data;
	t_list				*el;
	int					i;
	int					len;

	len = get_len_and_validate((data = ft_strsplit(line, ' ')), plain);
	if ((i = 0) == 0 && len == -1)
		delete_plain(&plain, 1);
	while (data[i] && plain != NULL)
	{
		if (!(el = get_point_el(i, plain->height, ft_atof(data[i]),
								get_color(data[i]))))
			delete_plain(&plain, 1);
		ft_lstadd(&plain->points, el);
		i++;
	}
	if (plain != NULL)
		plain->height++;
	ft_delsplit(&data);
	return (plain);
}
