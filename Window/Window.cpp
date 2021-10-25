#include "Window.h"
#include "OpenGLContext.h"
#include "Config.h"

Window::Window(float width, float height, const char* name) {
	this->width = width;
	this->height = height;
	this->name = name;
	window = NULL;

#ifdef OPENGL
	window = OpenGL::MakeWindow(width, height, name);
#endif
}

Window::~Window(void) {
#ifdef OPENGL
	OpenGL::DestroyWindow((GLFWwindow*)window);
#endif
}

bool Window::WindowClosed(void) {
#ifdef OPENGL
	return OpenGL::WindowShouldClose((GLFWwindow*)window);
#endif
}

void Window::SwapBuffers(void) {
#ifdef OPENGL
	OpenGL::SwapBuffers((GLFWwindow*)window);
#endif
}
