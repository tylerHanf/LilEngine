#include "OpenGLContext.h"
#include "RenderContext.h"
#include "Config.h"

RenderContext::RenderContext() {
#ifdef OPENGL
	OpenGL::GLFWInit();
#endif
	currentWindow = NULL;
}

RenderContext::~RenderContext(void) {
#ifdef OPENGL
	OpenGL::DestroyContext();
#endif
}

void RenderContext::Init(Window* window) {
	OpenGL::SetCurrentContext((GLFWwindow*)window->window);
	OpenGL::GLEWInit();
	OpenGL::SetGLFWSwap(1);

	buffers.resize(OpenGL::VERT_TEXTURE_NORMAL + 1);
	for (int i = 0; i <= OpenGL::VERT_TEXTURE_NORMAL; ++i) {
		buffers[i].type = (OpenGL::BufferType)i;
		buffers[i].VAO_ID = 0;
		OpenGL::GenVAOs(&(buffers[i].VAO_ID));
		OpenGL::InitVAO(buffers[i].VAO_ID, buffers[i].type);
	}
}

void RenderContext::SetCurrentWindow(Window* window) {
#ifdef OPENGL
	OpenGL::SetCurrentContext((GLFWwindow*)window->window);
	currentWindow = window;
#endif
}

void RenderContext::PollEvents(void) {
#ifdef OPENGL
	OpenGL::PollEvents();
#endif
}

void RenderContext::ClearBuffers(void) {
#ifdef OPENGL
	OpenGL::ClearColorBuffer();
	OpenGL::ClearDepthBuffer();
#endif
}

void RenderContext::Render(void) {
	OpenGL::ClearGLBuffers();
}

double RenderContext::GetTime(void) {
#ifdef OPENGL
	return OpenGL::GetTime();
#endif
}

/*
void RenderContext::LoadModel(Model* model, Importer::Data& data) {
#ifdef OPENGL
    OpenGL::BufferType type = OpenGL::NONE;
    unsigned int VBO_ID = 0;
    ModelComponent* component;
    for (int i = 0; i < model->numComponents; ++i) {
	    component = &model->components[i];
	    OpenGL::BindVAO(buffers[component->Buffer_idx].VAO_ID);
	    OpenGL::GenVBOs(&VBO_ID);
	    OpenGL::BindVBO(VBO_ID);
	    OpenGL::BufferData(component->numPoints*sizeof(float),
			       &data.buffers[component->Buffer_idx][component->interleaveDataIndex]);
	    buffers[component->Buffer_idx].VBO_IDs.push_back(VBO_ID);
    }
#endif
}
*/

unsigned int RenderContext::LoadData(float* data, 
									 int data_size, 
	                                 OpenGL::BufferType dataType, 
	                                 unsigned int* VBO) 
{
#ifdef OPENGL
	unsigned int VBO_ID = 0;
	unsigned int VAO = buffers[dataType].VAO_ID;
	OpenGL::BindVAO(VAO);
	OpenGL::GenVBOs(&VBO_ID);
	OpenGL::BindVBO(VBO_ID);
	OpenGL::BufferData(data_size, data);
	OpenGL::BindVBO(0);
	OpenGL::BindVAO(0);
	buffers[dataType].VBO_IDs.push_back(VBO_ID);
	*VBO = VBO_ID;
	return VAO;
#endif
}
