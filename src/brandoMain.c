#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include < stdbool.h >
#include < time.h >


/*
// Vertex Shader Source Code
const char* vertexShaderSource =
"#version 330 core\n"
"layout(location = 0) in vec3 aPos;\n"
"void main() {\n"
"    gl_Position = vec4(aPos, 1.0);\n"
"}\n";


// Fragment Shader Source Code
const char* fragmentShaderSource =
"#version 330 core\n"
"out vec4 FragColor;\n"
"void main() {\n"
"    FragColor = vec4(1.0, 0.5, 0.2, 1.0);\n"
"}\n";



int main() {
    // Initialize GLFW
    if (!glfwInit()) {
        printf("Failed to initialize GLFW!\n");
        return -1;
    }

    // Set OpenGL version to 3.3 Core
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create a window
    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Window", NULL, NULL);
    if (!window) {
        printf("Failed to create GLFW window!\n");
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // Load OpenGL function pointers using GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        printf("Failed to initialize GLAD!\n");
        return -1;
    }

    // Compile Vertex Shader
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    checkShaderCompileErrors(vertexShader);


    // Compile Fragment Shader
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    checkShaderCompileErrors(fragmentShader);

    // Link Shaders into a Program
    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    checkProgramLinkErrors(shaderProgram);

    // Clean up shaders (they're linked now)
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);


    // Vertex data for a triangle
    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };

    // Create a Vertex Buffer Object (VBO) and Vertex Array Object (VAO)
    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Set vertex attribute pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        // Clear the screen
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Use the shader program and bind the VAO
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);

        // Draw the triangle
        glDrawArrays(GL_TRIANGLES, 0, 3);

        // Swap buffers and poll events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Cleanup
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}










// Vertex Shader Source Code
const char* vertexShaderSource =
"#version 330 core\n"
"layout(location = 0) in vec3 aPos;\n"
"void main() {\n"
"    gl_Position = vec4(aPos, 1.0);\n"
"}\n";

// Fragment Shader Source Code
const char* fragmentShaderSource =
"#version 330 core\n"
"out vec4 FragColor;\n"
"void main() {\n"
"    FragColor = vec4(1.0, 0.5, 0.2, 1.0);\n"
"}\n";

// Function to check shader compilation errors
void checkShaderCompileErrors(unsigned int shader) {
    int success;
    char infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        printf("Shader compilation error: %s\n", infoLog);
    }
}

// Function to check shader program linking errors
void checkProgramLinkErrors(unsigned int program) {
    int success;
    char infoLog[512];
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(program, 512, NULL, infoLog);
        printf("Shader program linking error: %s\n", infoLog);
    }
}

int main() {
    // Initialize GLFW
    if (!glfwInit()) {
        printf("Failed to initialize GLFW!\n");
        return -1;
    }

    // Set OpenGL version to 3.3 Core
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create a window
    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Window", NULL, NULL);
    if (!window) {
        printf("Failed to create GLFW window!\n");
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // Load OpenGL function pointers using GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        printf("Failed to initialize GLAD!\n");
        return -1;
    }

    // Compile Vertex Shader
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    checkShaderCompileErrors(vertexShader);

    // Compile Fragment Shader
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    checkShaderCompileErrors(fragmentShader);

    // Link Shaders into a Program
    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    checkProgramLinkErrors(shaderProgram);

    // Clean up shaders (they're linked now)
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    // Vertex data for a triangle
    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };

    // Create a Vertex Buffer Object (VBO) and Vertex Array Object (VAO)
    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Set vertex attribute pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        // Clear the screen
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Use the shader program and bind the VAO
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);

        // Draw the triangle
        glDrawArrays(GL_TRIANGLES, 0, 3);

        // Swap buffers and poll events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Cleanup
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}*/
void processInput(GLFWwindow* window);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

/*
// Vertex Shader Source Code
const char* vertexShaderSource =
"#version 330 core\n"
"layout(location = 0) in vec3 aPos;\n"
"void main() {\n"
"    gl_Position = vec4(aPos, 1.0);\n"
"}\n";

// Fragment Shader Source Code
const char* fragmentShaderSource =
"#version 330 core\n"
"out vec4 FragColor;\n"
"void main() {\n"
"    FragColor = vec4(1.0, 0.5, 0.2, 1.0);\n"
"}\n";

// Function to check shader compilation errors
void checkShaderCompileErrors(unsigned int shader) {
    int success;
    char infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        printf("Shader compilation error: %s\n", infoLog);
    }
}

// Function to check shader program linking errors
void checkProgramLinkErrors(unsigned int program) {
    int success;
    char infoLog[512];
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(program, 512, NULL, infoLog);
        printf("Shader program linking error: %s\n", infoLog);
    }
}*/

//As you can see, GLSL looks similar to C. 
// Each shader begins with a declaration of its version.
// Next we declare all the input vertex attributes in the vertex shader 
// with the in keyword.
// Right now we only care about position data so we only need a single vertex 3 attribute.
// GLSL has a vector datatype that contains 1 to 4 floats based on its postfix digit.
// Since each vertex has a 3D coordinate we create a vec3 input variable with the name aPos.
// layout(location = 0) later see
// 
//GLSL vector represents positions/directions in any space and has useful mathematical properties. 
// A vector in GLSL has a maximum size of 4 
// and each of its values can be retrieved via vec.x, vec.y, vec.z and vec.w  
// where each of them represents a coordinate in space. 
// vec.w component is not a position in space is used for something called perspective division. 
// 
// To set the output of the vertex shader we assign the position data to the predefined gl_Position variable 
// which is a vec4. 
// At the end of the main function, gl_Position to will be used as the output of the vertex shader.
// our input is a vector of size 3 we have to cast this to a vector of size 4.
// We can do this by inserting the vec3 values inside the constructor of vec4 and set its w component to 1.0f
// 
//We take the source code for the vertex shader and store it in a const C string at the top of the code file for now:
const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";

//Fragment shader is calculating the color output of your pixels
// RGBA with values between 0.0 and 1.0
// The fragment shader only requires one output variable and that is a vector of size 4 
// that defines the final color output that we should calculate ourselves. 
// We can declare output values with the out keyword, that we here promptly named FragColor
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\n\0";


int main() {
    // Initialize GLFW
    if (!glfwInit()) {
        printf("Failed to initialize GLFW!\n");
        return -1;
    }

    // Set OpenGL version to 3.3 Core
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);//set version of open gl to 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);//set version of open gl to 3.3
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);// core-profile means we'll get access to a smaller subset of OpenGL features without backwards-compatible features we no longer need.
    //glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

    // Create a windows GLFWAPI GLFWwindow* glfwCreateWindow(int width, int height,const char* title,GLFWmonitor* monitor,GLFWwindow* share)
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "OpenGL Window", NULL, NULL);
    if (window == NULL) {
        printf("Failed to create GLFW window!\n");
        glfwTerminate();
        return -1;
    }
    //we tell GLFW to make the context of our window the main context on the current thread.
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Load OpenGL function pointers using GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        printf("Failed to initialize GLAD!\n");
        return -1;
    }

    //In order for OpenGL to use the shader it has to dynamically compile it at run-time from its source code. 
    // The first thing we need to do is create a shader object, again referenced by an ID. 
    // So we store the vertex shader as an unsigned int and create the shader with glCreateShader:
    // We provide the type of shader we want to create as an argument to glCreateShader.
    // Since we're creating a vertex shader we pass in GL_VERTEX_SHADER.
    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    //Next we attach the shader source code to the shader object and compile the shader:
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    // check if compilation was successfull
    int  success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        printf("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n%s\n",  infoLog);
    }

    //The process for compiling a fragment shader is similar to the vertex shader,
    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    // check for shader compile errors
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        printf("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n%s\n", infoLog);
    }


    //A shader program object is the final linked version of multiple shaders combined. 
    // To use the recently compiled shaders we have to link them to a shader program object 
    // and then activate this shader program when rendering objects. 
    // The activated shader program's shaders will be used when we issue render calls.
    // When linking the shaders into a program it links 
    // the outputs of each shader to the inputs of the next shader.
    // This is also where you'll get linking errors if your outputs and inputs do not match.
    // 
    // link shaders, Creating a program object
    unsigned int shaderProgram = glCreateProgram();
    //we need to attach the previously compiled shaders to the program object and then link them with glLinkProgram:
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    // check for linking errors
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        printf("ERROR::SHADER::PROGRAM::LINKING_FAILED\n%s\n", infoLog);
    }
    // don't forget to delete the shader objects
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    /* 
    * The result is a program object that we can activate by calling glUseProgram 
    with the newly created program object as its argument:
    * glUseProgram(shaderProgram);
    * Every shader and rendering call after glUseProgram will now use this program object (and thus the shaders).
    */
    /*Before we can start rendering we have to do one last thing.
        We have to tell OpenGL the size of the rendering window so OpenGL knows 
        how we want to display the data and coordinates with respect to the window.
        We can set those dimensions via the glViewport function :
        The first two parameters of glViewport set the location of the lower left corner of the window. 
        The third and fourth parameter set the width and height of the rendering window in pixels, 
        which we set equal to GLFW's window size.
        */
    /*
    glViewport(0, 0, 800, 600);
    void framebuffer_size_callback(GLFWwindow * window, int width, int height);
    void framebuffer_size_callback(GLFWwindow * window, int width, int height){
        glViewport(0, 0, width, height);
    }
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);*/

    //This will synchronize your frame rate with your monitor's refresh rate (typically 60Hz), 
    // preventing unnecessary rendering.
    // Add this after creating the OpenGL context (after glfwMakeContextCurrent)
    //glfwSwapInterval(1); // Enable vsync

    //OpenGL only processes 3D coordinates when they're in a specific range 
    // between -1.0 and 1.0 on all 3 axes (x, y and z). 
    // All coordinates within this so called normalized device coordinates
    float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f,
     // second triangle
     0.5f, -0.5f, 0.0f,  // bottom right
    -0.5f, -0.5f, 0.0f,  // bottom left
    -0.5f,  0.5f, 0.0f   // top left
    };

    //We manage this memory via so called vertex buffer objects (VBO) 
    // that can store a large number of vertices in the GPU's memory.
    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    //The process to generate a VAO looks similar to that of a VBO:
    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    // 1. bind Vertex Array Object
    glBindVertexArray(VAO);
    // 2. copy our vertices array in a buffer for OpenGL to use
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    //The fourth parameter specifies how we want the graphics card to manage the given data. This can take 3 forms:
    // GL_STREAM_DRAW: the data is set only once and used by the GPU at most a few times.
    // GL_STATIC_DRAW : the data is set only once and used many times.
    // GL_DYNAMIC_DRAW : the data is changed a lot and used many times.
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    //we can tell OpenGL how it should interpret the vertex data (per vertex attribute
    // The first parameter specifies which vertex attribute we want to configure. 
    // The next argument specifies the size of the vertex attribute.
    // The vertex attribute is a vec3 so it is composed of 3 values.
    // The third argument specifies the type of the data which is GL_FLOAT
    // The next argument specifies if we want the data to be normalized.
    // If we're inputting integer data types (int, byte) and we've set this to GL_TRUE, 
    // the integer data is normalized to 0 (or -1 for signed data) 
    // and 1 when converted to float.This is not relevant for us so we'll leave this at GL_FALSE.
    // The fifth argument is known as the stride and tells us the space between consecutive vertex attributes.
    // The last parameter is of type void* and thus requires that weird cast
    // This is the offset of where the position data begins in the buffer.
    // Since the position data is at the start of the data array this value is just 0.
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    //enable the vertex attribute with glEnableVertexAttribArray giving the vertex attribute location as its argument
    glEnableVertexAttribArray(0);

    int count = 0;
    time_t current_time;
    time(&current_time);
    printf("Current time: %s", ctime(&current_time));

    //a while loop, that we now call the render loop, that keeps on running until we tell GLFW to stop.
    while (!glfwWindowShouldClose(window))
    {
        
        //check key presses
        processInput(window);

        // render
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // draw our first triangle
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
        glDrawArrays(GL_TRIANGLES, 0, 3);
        //glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        //glDrawArrays(GL_TRIANGLES, 0, 6);
        // glBindVertexArray(0); // no need to unbind it every time 


        //The glfwSwapBuffers will swap the color buffer 
        // (a large 2D buffer that contains color values for each pixel in GLFW's window) 
        // that is used to render to during this render iteration and show it as output to the screen.
        //so we work on one and than swich them 
        glfwSwapBuffers(window);
        // glfwPollEvents function checks if any events are triggered (like keyboard input or mouse movement events), 
        // updates the window state, and calls the corresponding functions 
        // (which we can register via callback methods).
        glfwPollEvents();
    }

    //clean/delete all of GLFW's resources that were allocated
    glfwTerminate();
    return 0;


    /*
    // Compile Vertex Shader
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    checkShaderCompileErrors(vertexShader);

    // Compile Fragment Shader
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    checkShaderCompileErrors(fragmentShader);

    // Link Shaders into a Program
    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    checkProgramLinkErrors(shaderProgram);

    // Clean up shaders (they're linked now)
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    // Vertex data for a triangle
    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };

    // Create a Vertex Buffer Object (VBO) and Vertex Array Object (VAO)
    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Set vertex attribute pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        // Clear the screen
        glClearColor(0.2f, 0.3f, 0.3f, 0.5f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Use the shader program and bind the VAO
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);

        // Draw the triangle
        glDrawArrays(GL_TRIANGLES, 0, 3);

        // Swap buffers and poll events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Cleanup
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);

    glfwDestroyWindow(window);
    glfwTerminate();
    */

    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}


//Normalized Device Coordinates (NDC)
// Your NDC coordinates will then be transformed to screen-space coordinates 
// via the viewport transform using the data you provided with glViewport. 
// glfw: whenever the window size changed (by OS or user resize) this callback function executes
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}