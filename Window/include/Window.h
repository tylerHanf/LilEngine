#pragma once

#include "OpenGLContext.h"

class Window {
public:
	Window(float width, float height, const char* name);
	~Window(void);
	bool WindowClosed(void);
	void SwapBuffers(void);

	float width;
	float height;
	const char* name;
	void* window = NULL;
private:
};
