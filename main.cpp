#include "Mesh.h"
#include <TextureSaver.h>

int main()
{
	SimplexNoise noise(vec2(512, 512), 1.0f, 1.0f, 2.0f, 0.5f, 3, 0.0015f);
	noise.GenerateNoise(vec2(512, 512));

	Mesh plane;
	load_mesh("plane512x512.obj", plane);
	apply_heightmap(noise, plane, 512, 512);
	save_mesh("terrain.obj", plane);

	/*
	create_plane(plane, 1024, 1024);
	subdivide_mesh(plane, 10);
	cout << "Saving 1024x1024 planar mesh." << "\n";
	save_mesh("plane1024x1024.obj", plane);

	create_plane(plane, 2048, 2048);
	subdivide_mesh(plane, 11);
	cout << "Saving 2048x2048 planar mesh." << "\n";
	save_mesh("plane2048x2048.obj", plane);

	create_plane(plane, 4096, 4096);
	subdivide_mesh(plane, 12);
	cout << "Saving 4096x4096 planar mesh." << "\n";
	save_mesh("plane4096x4096.obj", plane);
	*/

	return 0;
}