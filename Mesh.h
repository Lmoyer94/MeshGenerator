#include <cmath>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

using glm::vec3;
using std::vector;

struct Mesh
{
	vector<vec3> vertices;
	vector<int> indices;
};

Mesh create_plane(int width, int height);
void save_mesh(Mesh mesh);