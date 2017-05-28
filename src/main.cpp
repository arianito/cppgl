#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include <unistd.h>
#include <ios>
#include <fstream>
#include <string>


void fbsize_callback(GLFWwindow *window, int width, int height){
    //printf("%ix%i\n", width, height);
    glViewport(0, 0, width, height);
}


int main(){
    GLFWwindow *window;
    
    if(!glfwInit()) {
        
        fprintf(stderr, "Failed to initialize GLFW\n");
        return -1;
    }
    
    glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE); // 4x antialiasing
    //glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2); // We want OpenGL 3.3
    //glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
    //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // We don't want the old OpenGL
    
    window = glfwCreateWindow(800, 600, "Aryan", nullptr, nullptr);
    
    //glfwSetWindowPos(window, 100, 100);
    // glfwSetWindowSizeCallback(window, fbsize_callback);
    
    if(window == nullptr) {
        fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, "
                "they are not 3.3 compatible. Try the 2.1 version of the "
                "tutorials.\n");
        glfwTerminate();
        return -1;
    }
    
    
   glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
    {
        fprintf(stderr, "Failed to initialize OpenGL context");
        return -1;
    }
    
    // Ensure we can capture the escape key being pressed below
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    
    // Dark blue background
    glClearColor(0.1f, 0.2f, 0.3f, 0.0f);
    
    do{
        
        // Clear the screen
        glClear(GL_COLOR_BUFFER_BIT);
        
        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
        
    }// Check if the ESC key was pressed or the window was closed
    while(glfwGetKey(window, GLFW_KEY_ESCAPE)!=GLFW_PRESS&&
          glfwWindowShouldClose(window)==0);
    
        
    // Close OpenGL window and terminate GLFW
    glfwTerminate();
    
    return 0;
}
