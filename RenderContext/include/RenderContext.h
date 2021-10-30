#pragma once

#include "OpenGLContext.h"
#include "OBJ_Importer.h"
#include "Window.h"
#include "ModelData.h"
#include <vector>

struct Buffer {
	OpenGL::BufferType type;
	unsigned int VAO_ID;
	std::vector<unsigned int> VBO_IDs;
};

class RenderContext {
 public:
    RenderContext();
    ~RenderContext(void);
    void Init(Window* window);
    void SetCurrentWindow(Window* window);
    void PollEvents(void);
    void ClearBuffers(void);
    double GetTime(void);
    void Render();
    void LoadModel(Model* model, Importer::Data& data);
    unsigned int LoadData(float* data, 
                          int data_size, 
                          OpenGL::BufferType dataType, 
                          unsigned int* VBO);

    /*
	TODO: Find a way to manage buffers effectively-i.e. make changes to game objects not tedious
	
	Current architecture:
	    array of Buffer objects

	    A buffer object contains:
		Buffer Type (defined by layout (VERT/VERT_TEXTURE/etc.))
		VAO
		array of VBO id's
        Buffers are indexed by attribute type:
            OpenGL::VERT,
            OpenGL::TEXTURE,
            OpenGL::NORMAL,
            OpenGL::VERT_TEXTURE,
            etc.
    */

 private:
    std::vector<Buffer> buffers;
    Window* currentWindow;
};
