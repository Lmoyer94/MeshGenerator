#include "Mesh.h"
#include <TextureSaver.h>

#include <sstream>
#include <thread>
#include <chrono>

using std::thread;
using std::ref;
using std::chrono::steady_clock;

const int blocks_wide = 32;
const int blocks_high = 32;


int main()
{
	steady_clock::time_point begin = steady_clock::now();

	Mesh plane;
	load_mesh("plane128x128.obj", plane);
	SimplexNoise noise(vec2(129, 129), 1.0f, 1.0f, 2.0f, 0.5f, 3, 0.0025f);


	for (int y = 0; y < blocks_high; y++)
	{
		for (int x = 0; x < blocks_wide; x++)
		{
			Mesh terrain;
			terrain = plane;

			noise.GenerateNoise(vec2(blocks_wide * x, blocks_high * y));
			apply_heightmap(noise, terrain, 129, 129);

			std::stringstream filename;
			filename << "terrain" << (x + 1) << "-" << (y + 1) << ".obj";
			save_mesh(filename.str(), terrain);
		}
	}


	/*

	//load mesh
	Mesh plane;
	load_mesh("plane128x128.obj", plane);
	Mesh plane1, plane2, plane3, plane4;
	plane4 = plane3 = plane2 = plane1 = plane;

	//create noise textures
	SimplexNoise noise1(vec2(129, 129), 1.0f, 1.0f, 2.0f, 0.5f, 3, 0.0015f);
	SimplexNoise noise2, noise3, noise4;
	noise4 = noise3 = noise2 = noise1;
	noise1.GenerateNoise(vec2(0, 0));
	noise2.GenerateNoise(vec2(129, 0));
	noise3.GenerateNoise(vec2(0, 129));
	noise4.GenerateNoise(vec2(129, 129));

	//apply height maps
	thread apply1(apply_heightmap, ref(noise1), ref(plane1), 129, 129);
	thread apply2(apply_heightmap, ref(noise2), ref(plane2), 129, 129);
	thread apply3(apply_heightmap, ref(noise3), ref(plane3), 129, 129);
	thread apply4(apply_heightmap, ref(noise4), ref(plane4), 129, 129);

	apply1.join();
	apply2.join();
	apply3.join();
	apply4.join();

	//save meshes
	thread save1(save_mesh, "terrain1.obj", ref(plane1));
	thread save2(save_mesh, "terrain2.obj", ref(plane2));
	thread save3(save_mesh, "terrain3.obj", ref(plane3));
	thread save4(save_mesh, "terrain4.obj", ref(plane4));

	save1.join();
	save2.join();
	save3.join();
	save4.join();

	*/

	steady_clock::time_point end = steady_clock::now();
	cout << "Time elapsed (sec) : " << (std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count()) / 1000000.0 << "\n";

	return 0;
}