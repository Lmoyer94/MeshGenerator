#include "Mesh.h"

using std::to_string;
using std::string;

using std::pow;

void create_plane(Mesh& mesh, float width, float height)
{
	vec3 point;

	//create vertices
	mesh.vertices.push_back(vec3(width/2, height/2, 0));
	mesh.vertices.push_back(vec3(-width/2, height/2, 0));
	mesh.vertices.push_back(vec3(-width/2, -height/2, 0));
	mesh.vertices.push_back(vec3(width/2, -height/2, 0));

	//create index information
	mesh.indices.push_back(1);
	mesh.indices.push_back(2);
	mesh.indices.push_back(3);
	mesh.indices.push_back(4);

}

void create_rect(Mesh& mesh, float width, float height, float depth)
{
	vec3 point;

	//create vertices
	mesh.vertices.push_back(vec3(width/2, height/2, depth/2));
	mesh.vertices.push_back(vec3(-width/2, height/2, depth/2));
	mesh.vertices.push_back(vec3(-width/2, -height/2, depth/2));
	mesh.vertices.push_back(vec3(width/2, -height/2, depth/2));

	mesh.vertices.push_back(vec3(-width/2, height/2, -depth/2));
	mesh.vertices.push_back(vec3(width/2, height/2, -depth/2));
	mesh.vertices.push_back(vec3(width/2, -height/2, -depth/2));
	mesh.vertices.push_back(vec3(-width/2, -height/2, -depth/2));


	//create index information
	mesh.indices.push_back(1);
	mesh.indices.push_back(2);
	mesh.indices.push_back(3);
	mesh.indices.push_back(4);

	mesh.indices.push_back(6);
	mesh.indices.push_back(1);
	mesh.indices.push_back(4);
	mesh.indices.push_back(7);

	mesh.indices.push_back(5);
	mesh.indices.push_back(6);
	mesh.indices.push_back(7);
	mesh.indices.push_back(8);

	mesh.indices.push_back(2);
	mesh.indices.push_back(5);
	mesh.indices.push_back(8);
	mesh.indices.push_back(3);

	mesh.indices.push_back(6);
	mesh.indices.push_back(5);
	mesh.indices.push_back(2);
	mesh.indices.push_back(1);

	mesh.indices.push_back(4);
	mesh.indices.push_back(3);
	mesh.indices.push_back(8);
	mesh.indices.push_back(7);
}

void create_sphere(Mesh& mesh, float radius)
{
	vec3 point;

	float r = radius;		//radial distance
	float heading;			//horizontal angle
	float pitch;			//pitch

	//create vertices
	for (heading = 0.0f; heading < 360.0f; heading+= 10.0f)
	{
		for (pitch = 0.0f; pitch < 360.0f; pitch+= 10.0f)
		{
			point = vec3(
				r * cos(pitch) * cos(heading),
				r * cos(pitch) * sin(heading),
				r * sin(pitch));

			mesh.vertices.push_back(point);
		}
	}

	for (pitch = 0.0f; pitch < 360.0f; pitch += 1.0f)
	{
		for (heading = 0.0f; heading < 360.0f; heading += 1.0f)
		{
			point = vec3(
				r * cos(pitch) * cos(heading),
				r * cos(pitch) * sin(heading),
				r * sin(pitch));

			mesh.vertices.push_back(point);
		}
	}


	//create index information
	for (int i = 0; i < mesh.vertices.size(); i++)
	{
		mesh.indices.push_back(i + 1);
	}
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