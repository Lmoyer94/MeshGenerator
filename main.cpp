#include "Mesh.h"

int main()
{
	Mesh plane;
	create_plane(plane, 2, 2);
	save_mesh("plane.obj", plane);

	Mesh rect;
	create_rect(rect, 2, 2, 2);
	save_mesh("rect.obj", rect);

	Mesh sphere;
	create_sphere(sphere, 2);
	save_mesh("sphere.obj", sphere);

	return 0;
}