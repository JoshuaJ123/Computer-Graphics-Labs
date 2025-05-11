#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <common/shader.hpp>
#include <common/texture.hpp>
#include <common/maths.hpp>

// Include the glm library
#include <glm/glm.hpp>
#include <glm/gtx/io.hpp>

// Function prototypes
void keyboardInput(GLFWwindow *window);

int main( void )
{
    // defining two vectors for exercise 4
    glm::vec3 P, V;
    P = glm::vec3(0.0f, 0.0f, 0.0f);
    V = glm::vec3(0.01f, 0.005f, 0.0f);

    // =========================================================================
    // Window creation - you shouldn't need to change this code
    // -------------------------------------------------------------------------
    // Initialise GLFW
    if( !glfwInit() )
    {
        fprintf( stderr, "Failed to initialize GLFW\n" );
        getchar();
        return -1;
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_RESIZABLE,GL_FALSE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Open a window and create its OpenGL context
    GLFWwindow* window;
    window = glfwCreateWindow(1024, 768, "Lab05 Transformations", NULL, NULL);
    
    if( window == NULL ){
        fprintf(stderr, "Failed to open GLFW window.\n");
        getchar();
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // Initialize GLEW
    glewExperimental = true; // Needed for core profile
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
        getchar();
        glfwTerminate();
        return -1;
    }
    // -------------------------------------------------------------------------
    // End of window creation
    // =========================================================================
    
    // Ensure we can capture keyboard inputs
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    
    // Define vertex positions
    static const float vertices[] = {
        // x     y     z      index
        -0.5f, -0.5f, 0.0f,  // 0     3 -- 2
         0.5f, -0.5f, 0.0f,  // 1     |  / |
         0.5f,  0.5f, 0.0f,  // 2     | /  |
        -0.5f,  0.5f, 0.0f   // 3     0 -- 1
    };

    // Define texture co-ordinates
    static const float uv[] = {
        // u    v      index
        0.0f,  0.0f,  // 0
        1.0f,  0.0f,  // 1
        1.0f,  1.0f,  // 2
        0.0f,  1.0f,  // 3
    };
    
    // Define indices
    static const unsigned int indices[] = {
        0, 1, 2,  // lower right triangle
        0, 2, 3   // upper left triangle
    };
    
    // Create the Vertex Array Object (VAO)
    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    
    // Create Vertex Buffer Object (VBO)
    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    // Create texture buffer
    unsigned int uvBuffer;
    glGenBuffers(1, &uvBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, uvBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(uv), uv, GL_STATIC_DRAW);
    
    // Create Element Buffer Object (EBO)
    unsigned int EBO;
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices,
                 GL_STATIC_DRAW);
    
    // Compile shader program
    unsigned int shaderID;
    shaderID = LoadShaders("vertexShader.glsl", "fragmentShader.glsl");
    
    // Load the textures
    unsigned int texture;
    texture = loadTexture("../assets/mario.png");
    
    // Send the texture uniforms to the fragment shader
    glUseProgram(shaderID);
    unsigned int textureID;
    textureID = glGetUniformLocation(shaderID, "texture");
    glUniform1i(textureID, 0);
    
    // Render loop
    while (!glfwWindowShouldClose(window))
    {
        // Get inputs
        keyboardInput(window);
        
        // Clear the window
        glClearColor(0.2f, 0.2f, 0.2f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Send the VBO to the GPU
        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
        
        // Send the UV buffer to the GPU
        glEnableVertexAttribArray(1);
        glBindBuffer(GL_ARRAY_BUFFER, uvBuffer);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);

        //define the translation matrix
        //glm::mat4 translate;
        //translate[3][0] = 0.4f, translate[3][1] = 0.3f, translate[3][2] = 0.0f;
        //glm::mat4 translate = Maths::translate(glm::vec3(0.4f, 0.3f, 0.0f));

        // Define the scaling matrix
        //glm::mat4 scale;
        //scale[0][0] = 0.4f, scale[1][1] = 0.3f, scale[2][2] = 1.0f;
        //glm::mat4 scale = Maths::scale(glm::vec3(0.4f, 0.3f, 1.0f));

        // Define the rotation matrix
        //glm::mat4 rotate;
        //float angle = 45.0f * 3.1416f / 180.0f; // Convert degrees to radians
        //rotate[0][0] = cos(angle), rotate[0][1] = sin(angle);
        //rotate[1][0] = -sin(angle), rotate[1][1] = cos(angle);
        //float angle = Maths::radians(45.0f);
        //glm::mat4 rotate = Maths::rotate(angle, glm::vec3(0.0f, 0.0f, 1.0f));

        // Animate rectangle
        //float angle = Maths::radians(glfwGetTime() * 360.0f / 5.0f);
        //glm::mat4 translate = Maths::translate(glm::vec3(0.5f, 0.0f, 0.0f));
        //glm::mat4 scale = Maths::scale(glm::vec3(0.25f, 0.25f, 0.0f));
        //glm::mat4 rotate = Maths::rotate(angle, glm::vec3(0.0f, 0.0f, 1.0f));

        //exercise 1
        //float angle = Maths::radians(glfwGetTime() * 360.0f / 5.0f);
        //float x = 0.5f * cos(angle);
        //float y = 0.5f * sin(angle);
        //glm::vec3 position = glm::vec3(x, y, 0.0f);
        //glm::mat4 translate = Maths::translate(position);
        //glm::mat4 scale = Maths::scale(glm::vec3(0.25f, 0.25f, 1.0f));
        //glm::mat4 transformation = translate * scale;

        //exercise 2
        //float angle = Maths::radians(glfwGetTime() * 360.0f / 5.0f);
        //float x = 0.5f * cos(angle);
        //float y = 0.5f * sin(angle);
        //glm::vec3 position = glm::vec3(x, y, 0.0f);
        //glm::mat4 translate = Maths::translate(position);
        //glm::mat4 scale = Maths::scale(glm::vec3(0.25f, 0.25f, 1.0f));
        //glm::mat4 rotate = Maths::rotate(-2*angle, glm::vec3(0.0f, 0.0f, 1.0f));
        //glm::mat4 transformation = translate * scale * rotate;

        //exercise 3
        //float angle = Maths::radians(glfwGetTime() * 360.0f / 5.0f);
        //float x = 0.5f * cos(angle);
        //float y = 0.5f * sin(angle);
        //float baseScale = 0.25f;
        //float amplitude = 0.15f;
        //float imageScale = baseScale + amplitude * sin(glfwGetTime()*6);
        //glm::vec3 position = glm::vec3(x, y, 0.0f);
        //glm::mat4 translate = Maths::translate(position);
        //glm::mat4 scale = Maths::scale(glm::vec3(imageScale, imageScale, 1.0f));
        //glm::mat4 rotate = Maths::rotate(-2 * angle, glm::vec3(0.0f, 0.0f, 1.0f));
        //glm::mat4 transformation = translate * scale * rotate;

        //exercise 4
        P += V;

        glm::mat4 scale = Maths::scale(glm::vec3(0.2f, 0.2f, 1.0f));
        glm::mat4 translate = Maths::translate(glm::vec3(P.x, P.y, 0.0f));
        glm::mat4 transformation = translate * scale;

        if (P.x > 0.9f || P.x < -0.9f)
            V.x = -V.x;

        if (P.y > 0.9f || P.y < -0.9f)
            V.y = -V.y;

        //send the transformation matrix to the vertex shader
        //glm::mat4 transformation = rotate * translate * scale;
        unsigned int transformationID = glGetUniformLocation(shaderID, "transformation");
        glUniformMatrix4fv(transformationID, 1, GL_FALSE, &transformation[0][0]);
        
        // Draw the triangles
        glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(unsigned int),
                       GL_UNSIGNED_INT, 0);
        
        glDisableVertexAttribArray(0);
        glDisableVertexAttribArray(1);
        
        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    // Cleanup
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    glDeleteBuffers(1, &uvBuffer);
    glDeleteProgram(shaderID);
    
    // Close OpenGL window and terminate GLFW
    glfwTerminate();
    return 0;
}

void keyboardInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}
