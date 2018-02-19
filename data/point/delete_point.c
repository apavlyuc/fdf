
#include <point.h>

void					delete_point(t_point **pp)
{
	if (pp && *pp)
		ft_memdel((void**)pp);
}
