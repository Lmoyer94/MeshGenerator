#include <cmath>
#include <fstream>
#include <numbers>
#include <string>
#include <sstream>
#include <vector>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

using glm::vec3;
using std::vector;
using std::string;

struct Mesh
{
	vector<vec3> vertices;
	vector<int> indices;
};



const float TWOPI = 2.0f * std::numbers::pi;
const float TWOOVERPI = 2.0f / std::numbers::pi;


void create_plane(Mesh& mesh, float width, float height);
void create_rect(Mesh& mesh, float width, float height, float depth);
void create_sphere(Mesh& mesh, float radius);

void subdivide_mesh(Mesh& mesh, int times);

void save_mesh(string filepath, Mesh mesh);