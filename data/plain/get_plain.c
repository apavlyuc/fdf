
#include <fdf.h>

static t_list			*copy_point_el(t_list *point_el)
{
	t_list				*copy;

	if (point_el)
	{
		copy = ft_lstnew(point_el->content,
						 point_el->content_size);
	}
	return (copy);
}

t_plain					*get_plain(t_list *lst, int width, int height)
{
	t_plain				*p;

	if ((p = (t_plain*)ft_memalloc(sizeof(t_plain))))
	{
		if (lst)
			p->points = ft_lstmap(lst, &copy_point_el);
		else
			p->points = NULL;
		p->width = width;
		p->height = height;
	}
	return (p);
}
