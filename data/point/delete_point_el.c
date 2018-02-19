
#include <point.h>

void					delete_point_el(void *point_el, size_t size)
{
	t_point				*p;

	(void)size;
	if (point_el)
	{
		p = (t_point*)point_el;
		delete_point(&p);
	}
}
