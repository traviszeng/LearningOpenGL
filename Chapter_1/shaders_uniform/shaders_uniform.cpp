//#include<glad/glad.h>
//#include<GLFW/glfw3.h>
//
//#include<iostream>
//
//#include"Shader.h"
//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//void processInput(GLFWwindow* window);
//
//// settings
//const unsigned int SCR_WIDTH = 800;
//const unsigned int SCR_HEIGHT = 600;
//
////顶点着色器
//const char* vertexShaderSource = "#version 330 core\n"
//	"layout(location = 0) in vec3 aPos;\n"
//	"layout(location = 1) in vec3 aColor;\n"
//	"out vec3 ourColor;\n"
//	"void main()\n"
//	"{\n"
//	"	gl_Position = vec4(aPos, 1.0);\n"
//	"	ourColor = aColor;\n"
//	"};\0";
//
////片段着色器
//const char* framentShaderSource ="#version 330 core\n"
//	"out vec4 FragColor;\n"
//	"in vec3 ourColor;\n"
//	"void main()\n"
//	"{\n"
//	"	FragColor = vec4(ourColor, 1.0f);\n"
//	"}\n\0";	
//
//
//int main() {
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//#ifdef __APPLE__
//	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//#endif
//
//	// glfw window creation
//	// --------------------
//	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
//	if (window == NULL)
//	{
//		std::cout << "Failed to create GLFW window" << std::endl;
//		glfwTerminate();
//		return -1;
//	}
//	glfwMakeContextCurrent(window);
//	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//
//	// glad: load all OpenGL function pointers
//	// ---------------------------------------
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//	{
//		std::cout << "Failed to initialize GLAD" << std::endl;
//		return -1;
//	}
//
//
//	//unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
//	//glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
//	//glCompileShader(vertexShader);
//
//	//int success;
//	//char infoLog[512];
//	//glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
//
//	//if (!success) {
//	//	glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
//	//	std::cout<< "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
//	//}
//
//
//	//unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//	//glShaderSource(fragmentShader, 1, &framentShaderSource, NULL);
//	//glCompileShader(fragmentShader);
//
//	//glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
//	//
//	//if (!success) {
//	//	glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
//	//	std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
//	//}
//
//
//
//	//// 链接着色器
//	//unsigned int shaderProgram;
//	//shaderProgram = glCreateProgram();
//
//	//glAttachShader(shaderProgram, vertexShader);
//	//glAttachShader(shaderProgram, fragmentShader);
//	//glLinkProgram(shaderProgram);
//
//	////检查着色器链接
//	//glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
//	//if (!success) {
//	//	glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
//	//	std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
//	//}
//	//glDeleteShader(vertexShader);
//	//glDeleteShader(fragmentShader);
//	Shader shader("shader.vs", "shader.fs");
//	
//
//	float vertices[] = {
//		// 位置              // 颜色
//		 0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // 右下
//		-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // 左下
//		 0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // 顶部
//	};
//
//
//	unsigned int VBO, VAO;
//	glGenVertexArrays(1, &VAO);
//	glGenBuffers(1, &VBO);
//
//	glBindVertexArray(VAO);
//
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	//将数据复制到缓存 
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//	// 配置layout position=0的顶点数据
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//
//	// 配置layout position=1的顶点数据
//	// 内存分布
//	//|   vertex 1 |   vertex 2 |   vertex 3 |
//	//|X Y Z R G B | X Y Z R G B| X Y Z R G B
//	// 偏移量指针为(3 * sizeof(float))
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
//	glEnableVertexAttribArray(1);
//
//	//glUseProgram(shaderProgram);
//
//	//render loop
//	while (!glfwWindowShouldClose(window)) {
//		processInput(window);
//
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//
//		shader.use();
//		/*glUseProgram(shaderProgram);
//
//		float timeValue = glfwGetTime();
//		float greenValue = sin(timeValue) / 2.0f + 0.5f;
//		int vertexColorLocation = glGetUniformLocation(shaderProgram, "outColor");
//		glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);*/
//		float offset = 0.6f;
//		shader.setFloat("movePace", offset);
//
//
//		glBindVertexArray(VAO);
//		glDrawArrays(GL_TRIANGLES, 0, 3);
//
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//	}
//
//	glDeleteVertexArrays(1, &VAO);
//	glDeleteBuffers(1, &VAO);
//
//
//	glfwTerminate();
//	return 0;
//
//}
//
//
//// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
//// ---------------------------------------------------------------------------------------------------------
//void processInput(GLFWwindow* window)
//{
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, true);
//}
//
//// glfw: whenever the window size changed (by OS or user resize) this callback function executes
//// ---------------------------------------------------------------------------------------------
//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//	// make sure the viewport matches the new window dimensions; note that width and 
//	// height will be significantly larger than specified on retina displays.
//	glViewport(0, 0, width, height);
//}
//
