
#include <point.h>

t_list					*get_point_el(float x, float y, float z, int color)
{
	t_list				*el;
	t_point				*p;

	if ((p = get_point(x, y, z, color)))
	{
		el = ft_lstnew(p, sizeof(t_point));
		delete_point(&p);
	}
	return (el);
}
