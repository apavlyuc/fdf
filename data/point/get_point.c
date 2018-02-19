
#include <point.h>

t_point					*get_point(float x, float y, float z, int color)
{
	t_point				*p;

	if ((p = (t_point*)ft_memalloc(sizeof(t_point))))
	{
		p->x = x;
		p->y = y;
		p->z = z;
		p->color = color;
	}
	return (p);
}
