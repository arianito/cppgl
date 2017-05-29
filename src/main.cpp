#include <iostream>
#include <memory>
#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>


#include <imgui.h>
#include "imgui_impl_glfw_gl3.h"



const GLchar* vertexSource = R"glsl(
    #version 150 core
    in vec2 position;
    in vec3 color;
    out vec3 Color;
    void main()
    {
        Color = color;
        gl_Position = vec4(position, 0.0, 1.0);
    }
)glsl";

const GLchar* fragmentSource = R"glsl(
    #version 150 core
    in vec3 Color;
    out vec4 outColor;
    void main()
    {
        outColor = vec4(Color, 1.0);
    }
)glsl";

int main(){
    GLFWwindow *window;
    //NVGcontext *nvg = nullptr;
    
    if(!glfwInit()) {   
        fprintf(stderr, "Failed to initialize GLFW\n");
        return -1;
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#if __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif



    window = glfwCreateWindow(600, 600, "Aryan", nullptr, nullptr);
    
    
    if(window == nullptr) {
		fprintf(stderr, "Failed to load opengl.\n");
        glfwTerminate();
        return -1;
    }


    glfwSetWindowPos(window, 100, 100);
    glfwMakeContextCurrent(window);
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        fprintf(stderr, "Failed to initialize OpenGL context.\n");
        return -1;
    }


	ImGui_ImplGlfwGL3_Init(window, true);


	bool show_default = true;
	bool show_another_window = false;

	ImVec4 clear_color = ImColor(10, 20, 30);

	float f = 0.0f;


    do {
	    glfwPollEvents();
	    ImGui_ImplGlfwGL3_NewFrame();

	    // 1. Show a simple window
	    // Tip: if we don't call ImGui::Begin()/ImGui::End() the widgets appears in a window automatically called "Debug"
	    {
		    ImGui::Begin("Another Window");

		    ImGui::Text("Hello, world!");
		    ImGui::SliderFloat("float", &f, 0.0f, 1.0f);
		    ImGui::ColorEdit3("clear color", (float*)&clear_color);
		    if (ImGui::Button("Another Window")) show_another_window ^= 1;
		    ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
		    ImGui::End();
	    }

	    // 2. Show another simple window, this time using an explicit Begin/End pair
	    if (show_another_window)
	    {
		    ImGui::Begin("Another Window 2");
		    char buff[16];
		    sprintf(buff, "%f", f);
		    ImGui::Text(buff);
		    ImGui::End();
	    }

	    // Rendering
	    int display_w, display_h;
	    glfwGetFramebufferSize(window, &display_w, &display_h);
	    glViewport(0, 0, display_w, display_h);
	    glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
	    glClear(GL_COLOR_BUFFER_BIT);
	    ImGui::Render();
	    glfwSwapBuffers(window);
        
    }
    while( glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0 );

	ImGui_ImplGlfwGL3_Shutdown();
    glfwTerminate();
    
    return 0;
}
