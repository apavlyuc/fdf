
#include <point.h>
#include <stdio.h>

void					print_point_el(t_list *point_el)
{
	t_point				*p;

	if (point_el && (p = (t_point*)point_el->content))
		printf("(%.1f %.1f %.1f) %#x\n", p->x, p->y, p->z, p->color);
	else
		printf("no point\n");
}
