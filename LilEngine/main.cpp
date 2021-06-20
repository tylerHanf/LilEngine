#include "glew.h"
#include "glfw3.h"

#include <iostream>
#include "Logger.h"

int main() {
	Logger::InitLog("test.log");

	if (!glfwInit()) {
		std::cout << "Failed to init GLFW\n";
		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	GLFWwindow* window = glfwCreateWindow(400, 400, "Hello Window!", NULL, NULL);

	if (!window) {
		std::cout << "Failed to make window\n";
		return -1;
	}

	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK) {
		std::cout << "Failed to init GLEW\n";
		return -1;
	}

	glfwSwapInterval(1);

	while (!glfwWindowShouldClose(window)) {
		glClear(GL_DEPTH_BUFFER_BIT);
		glClear(GL_COLOR_BUFFER_BIT);


		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}