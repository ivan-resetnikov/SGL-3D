namespace sgl { namespace render {

class Object {

public:
	Object(float* vertices, std::string vertexShaderPath, std::string fragmentShaderPath);
	~Object();

	void render(sgl::render::Window);

};


Object::Object(float* vertices, std::string vertexShaderPath, std::string fragmentShaderPath) {
	// TODO: Add 3D model loading (use ASSIMP)
}


Object::~Object() {

}


void Object::render(sgl::render::Window) {
	// TODO: Implement rendering
}


}}