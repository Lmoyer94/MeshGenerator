#include "Mesh.h"

using std::to_string;
using std::string;

using std::pow;

Mesh create_plane(float width, float height)
{
	Mesh output;
	vec3 point;

	output.vertices.push_back(vec3(width/2, height/2, 0));
	output.vertices.push_back(vec3(-width/2, height/2, 0));
	output.vertices.push_back(vec3(-width/2, -height/2, 0));
	output.vertices.push_back(vec3(width/2, -height/2, 0));

	output.indices.push_back(1);
	output.indices.push_back(2);
	output.indices.push_back(3);
	output.indices.push_back(4);

	return output;
}

Mesh create_rect(float width, float height, float depth)
{
	Mesh output;
	vec3 point;

	output.vertices.push_back(vec3(width/2, height/2, depth/2));
	output.vertices.push_back(vec3(-width/2, height/2, depth/2));
	output.vertices.push_back(vec3(-width/2, -height/2, depth/2));
	output.vertices.push_back(vec3(width/2, -height/2, depth/2));

	output.vertices.push_back(vec3(-width/2, height/2, -depth/2));
	output.vertices.push_back(vec3(width/2, height/2, -depth/2));
	output.vertices.push_back(vec3(width/2, -height/2, -depth/2));
	output.vertices.push_back(vec3(-width/2, -height/2, -depth/2));



	//create index information
	output.indices.push_back(1);
	output.indices.push_back(2);
	output.indices.push_back(3);
	output.indices.push_back(4);

	output.indices.push_back(6);
	output.indices.push_back(1);
	output.indices.push_back(4);
	output.indices.push_back(7);

	output.indices.push_back(5);
	output.indices.push_back(6);
	output.indices.push_back(7);
	output.indices.push_back(8);

	output.indices.push_back(2);
	output.indices.push_back(5);
	output.indices.push_back(8);
	output.indices.push_back(3);

	output.indices.push_back(6);
	output.indices.push_back(5);
	output.indices.push_back(2);
	output.indices.push_back(1);

	output.indices.push_back(4);
	output.indices.push_back(3);
	output.indices.push_back(8);
	output.indices.push_back(7);

	return output;
}

Mesh create_sphere(float radius)
{
	Mesh output;
	vec3 point;

	return output;
}




void subdivide_mesh(Mesh& mesh, int times)
{

}



void save_mesh(string filepath, Mesh mesh)
{
	std::ofstream file(filepath);
	std::string str;

	for (int i = 0; i < mesh.vertices.size(); i++)
	{
		file << "v " << mesh.vertices[i].x << " " << mesh.vertices[i].y << " " << mesh.vertices[i].z << "\n";
	}

	for (int i = 0; i < mesh.indices.size()-3; i += 4)
	{
		file << "f " << mesh.indices[i] << " " << mesh.indices[i + 1] << " " << mesh.indices[i + 2] << " " << mesh.indices[i + 3] <<  "\n";
	}

	file.close();
	
	return;
}