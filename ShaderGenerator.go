package main

import "fmt"

type UniformValue struct {
	name string
	glslType string
}

type Shader struct {
	name string
	vertexUniform map[int]UniformValue
	fragmentUniform map[int]UniformValue
	in map[int]string
	out map[int]string
	outCode []string
	
}

func (shader Shader) ToString() string {
	ret := "namespace Blob::Shaders {\n"
	ret += "class " + shader.name + " : public Shader {\n"
	ret += "private:\n"
	ret += "public:\n"
	ret += "    inline static ClassName instance;\n"
	
	ret += "\n"
	for key, value := range shader.vertexUniform {
		ret += fmt.Sprintf("    static const int %s = %d\n", value.name, key)
	}
	ret += "\n"
	for key, value := range shader.fragmentUniform {
		ret += fmt.Sprintf("    static const int %s = %d\n", value.name, key)
	}
	ret += "\n"
	
	ret += "    void build() {\n"
	ret += "        addVertexShader(R\"=====(#version 450\n"
	
	for key, value := range shader.in {
		ret += fmt.Sprintf("layout(location = %d) in %s\n", key, value)
	}
	ret += "\n"
	for key, value := range shader.out {
		ret += fmt.Sprintf("layout(location = %d) out %s\n", key, value)
	}
	ret += "\n"
	for key, value := range shader.vertexUniform {
		ret += fmt.Sprintf("layout(location = %d) uniform %s %s\n", key, value.glslType, value.name)
	}
	
	ret += "void main() {\n"
	for _, value := range shader.outCode {
		ret += fmt.Sprintf("    %s\n", value)
	}
	ret += "})=====\");\n"
	
	ret += "        addFragmentShader(R\"=====(#version 450\nlayout(location=0) out vec4 color;\n"

	ret += "\n"
	for key, value := range shader.out {
		ret += fmt.Sprintf("layout(location = %d) in %s\n", key, value)
	}
	ret += "\n"
	for key, value := range shader.fragmentUniform {
		ret += fmt.Sprintf("layout(location = %d) uniform %s %s\n", key, value.glslType, value.name)
	}
	ret += "\n"
	
	ret += "void main() {\n"
	ret += "})=====\");"
	ret += "    }\n"
	ret += "    void destroy() {\n"
	ret += "        GL::Shader::destroy();\n"
	ret += "    }\n"
	ret += "};\n"
	ret += "}\n"
	return ret
}

func makeShader(MVP2d, color, colorArray, texture, PBR  bool) Shader {
	var shader Shader
	uniformPos := 0;
	shader.vertexUniform = make(map[int]UniformValue)
	shader.fragmentUniform = make(map[int]UniformValue)
	if(PBR) { shader.name += "PBR" }
	if(color) { shader.name += "SingleColor" }
	if(texture) { shader.name += "SingleTexture" }
	if(colorArray) { shader.name += "ColorArray"}
	if(MVP2d) { shader.name += "2D" } 
	
	shader.in = map[int]string{
		0: "vec3 POSITION",
		1: "vec3 NORMAL",
		2: "vec3 TANGENT",
		3: "vec3 TEXCOORD_0",
		4: "vec3 TEXCOORD_1",
		5: "vec3 COLOR_0",
		6: "vec3 JOINTS_0",
		7: "vec3 WEIGHTS_0",
	}
	shader.out = map[int]string{
		0: "vec3 position",
		1: "vec3 texCoord",
		2: "vec3 normal",
		3: "vec3 tangent",
		4: "vec3 binormal",
		5: "vec3 color_0",
	}
	
	shader.outCode = []string{
		"position = vec3(model * vec4(POSITION, 1.0));", 
		"texCoord = TEXCOORD_0;",
		"normal = normalize(mat3(transpose(inverse(model))) * NORMAL);",
		"tangent = TANGENT;",
		"binormal = cross(NORMAL, TANGENT);",
		"color_0 = COLOR_0;",
		"gl_Position =  projection * view * model * vec4(POSITION, 1.0);",
	}
	
	if(!MVP2d){
		shader.vertexUniform[uniformPos] = UniformValue{"model", "mat4"}
		uniformPos++
		shader.vertexUniform[uniformPos] = UniformValue{"view", "mat4"}
		uniformPos++
		shader.vertexUniform[uniformPos] = UniformValue{"projection", "mat4"}
		uniformPos++
	}
	if(color) {
		shader.fragmentUniform[uniformPos] = UniformValue{"albedo", "vec3"}
		uniformPos++
	}
    return shader
}

type Matrial struct {
	shader Shader
    name string
}

func makeMaterial(MVP2d, color, colorArray, texture, PBR  bool) Matrial {
	var material Matrial
	material.shader = makeShader(MVP2d, color, colorArray, texture, PBR)
	
	material.name = material.shader.name
    return material
}

func (material Matrial) ToString() string {
	ret := material.shader.ToString()
	
	ret += "namespace Blob::Materails {\n"
	ret += "class " + material.name + " : public Matrial {\n"
	ret += "};\n"
	ret += "}\n"
	
	return ret
}

func main() {
	material := makeMaterial(false, true, false, false, false)
	fmt.Println(material.ToString())


}
