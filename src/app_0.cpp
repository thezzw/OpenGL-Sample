// #define STB_IMAGE_IMPLEMENTATION
// #include <glad/glad.h>
// #include <glfw/glfw3.h>
// #include <stb_image.h>
// #include <glm/glm.hpp>
// #include <glm/gtc/matrix_transform.hpp>
// #include <glm/gtc/type_ptr.hpp>
// 
// #include "shader.hpp"
// 
// #include <iostream>
// 
// void framebuffer_size_callback(GLFWwindow* window, int width, int height);
// void processInput(GLFWwindow* window);
// void mouse_callback(GLFWwindow* window, double xpos, double ypos);
// void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
// 
// // settings
// const unsigned int SCR_WIDTH = 1024;
// const unsigned int SCR_HEIGHT = 1024;
// 
// // mix value
// float mixValue = 0.2f;
// 
// // camera para
// glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
// glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
// glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
// 
// // time value
// float deltaTime = 0.0f; // 当前帧与上一帧的时间差
// float lastFrame = 0.0f; // 上一帧的时间
// 
// // mouse 
// bool firstMouse = true;
// float yaw = -90.0f;	// yaw is initialized to -90.0 degrees since a yaw of 0.0 results in a direction vector pointing to the right so we initially rotate a bit to the left.
// float pitch = 0.0f;
// float lastX = SCR_WIDTH / 2.0;
// float lastY = SCR_HEIGHT / 2.0;
// float fov = 45.0f;
// 
// int main()
// {
//     // glfw: initialize and configure
//     // ------------------------------
//     glfwInit();
//     glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//     glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//     glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
// 
// #ifdef __APPLE__
//     glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
// #endif
// 
//     // glfw window creation
//     // --------------------
//     GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
//     if (window == NULL)
//     {
//         std::cout << "Failed to create GLFW window" << std::endl;
//         glfwTerminate();
//         return -1;
//     }
//     glfwMakeContextCurrent(window);
//     glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//     glfwSetCursorPosCallback(window, mouse_callback);
//     glfwSetScrollCallback(window, scroll_callback);
// 
//     // glad: load all OpenGL function pointers
//     // ---------------------------------------
//     if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//     {
//         std::cout << "Failed to initialize GLAD" << std::endl;
//         return -1;
//     }
// 
//     // build and compile our shader program
//     // ------------------------------------
//     Shader ourShader("simple.v", "simple.f"); // you can name your shader files however you like
// 
//     // set up vertex data (and buffer(s)) and configure vertex attributes
//     // ------------------------------------------------------------------
//     float vertices[] = {
//          -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//           0.5f, -0.5f, -0.5f,  2.0f, 0.0f,
//           0.5f,  0.5f, -0.5f,  2.0f, 2.0f,
//           0.5f,  0.5f, -0.5f,  2.0f, 2.0f,
//          -0.5f,  0.5f, -0.5f,  0.0f, 2.0f,
//          -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
// 
//          -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//           0.5f, -0.5f,  0.5f,  2.0f, 0.0f,
//           0.5f,  0.5f,  0.5f,  2.0f, 2.0f,
//           0.5f,  0.5f,  0.5f,  2.0f, 2.0f,
//          -0.5f,  0.5f,  0.5f,  0.0f, 2.0f,
//          -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
// 
//          -0.5f,  0.5f,  0.5f,  2.0f, 0.0f,
//          -0.5f,  0.5f, -0.5f,  2.0f, 2.0f,
//          -0.5f, -0.5f, -0.5f,  0.0f, 2.0f,
//          -0.5f, -0.5f, -0.5f,  0.0f, 2.0f,
//          -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//          -0.5f,  0.5f,  0.5f,  2.0f, 0.0f,
// 
//           0.5f,  0.5f,  0.5f,  2.0f, 0.0f,
//           0.5f,  0.5f, -0.5f,  2.0f, 2.0f,
//           0.5f, -0.5f, -0.5f,  0.0f, 2.0f,
//           0.5f, -0.5f, -0.5f,  0.0f, 2.0f,
//           0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//           0.5f,  0.5f,  0.5f,  2.0f, 0.0f,
// 
//          -0.5f, -0.5f, -0.5f,  0.0f, 2.0f,
//           0.5f, -0.5f, -0.5f,  2.0f, 2.0f,
//           0.5f, -0.5f,  0.5f,  2.0f, 0.0f,
//           0.5f, -0.5f,  0.5f,  2.0f, 0.0f,
//          -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//          -0.5f, -0.5f, -0.5f,  0.0f, 2.0f,
// 
//          -0.5f,  0.5f, -0.5f,  0.0f, 2.0f,
//           0.5f,  0.5f, -0.5f,  2.0f, 2.0f,
//           0.5f,  0.5f,  0.5f,  2.0f, 0.0f,
//           0.5f,  0.5f,  0.5f,  2.0f, 0.0f,
//          -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
//          -0.5f,  0.5f, -0.5f,  0.0f, 2.0f
//     };
// 
//     glm::vec3 cubePositions[] =
//     {
//         glm::vec3(0.0f,  0.0f,  -1.0f),
//         glm::vec3(2.0f,  5.0f, -15.0f),
//         glm::vec3(-1.5f, -2.2f, -2.5f),
//         glm::vec3(-3.8f, -2.0f, -12.3f),
//         glm::vec3(2.4f, -0.4f, -3.5f),
//         glm::vec3(-1.7f,  3.0f, -7.5f),
//         glm::vec3(1.3f, -2.0f, -2.5f),
//         glm::vec3(1.5f,  2.0f, -2.5f),
//         glm::vec3(1.5f,  0.2f, -1.5f),
//         glm::vec3(-1.3f,  1.0f, -1.5f)
//     };
// 
//     unsigned int VBO, VAO;
//     glGenVertexArrays(1, &VAO);
//     glGenBuffers(1, &VBO);
// 
//     glBindVertexArray(VAO);
// 
//     glBindBuffer(GL_ARRAY_BUFFER, VBO);
//     glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
// 
//     // position attribute
//     glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
//     glEnableVertexAttribArray(0);
//     // texture coord attribute
//     glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
//     glEnableVertexAttribArray(1);
// 
//     // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
//     // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
//     // glBindVertexArray(0);
// 
//     unsigned int texture_0, texture_1;
//     glGenTextures(1, &texture_0);
//     glBindTexture(GL_TEXTURE_2D, texture_0);
// 
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
// 
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
// 
//     int width, height, nrChannels;
//     unsigned char* data = stbi_load("horse.jpg", &width, &height, &nrChannels, 0);
//     if (data)
//     {
//         glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
//         glGenerateMipmap(GL_TEXTURE_2D);
//     }
//     else
//     {
//         std::cout << "Failed to load texture" << std::endl;
//     }
//     stbi_image_free(data);
// 
//     glGenTextures(1, &texture_1);
//     glBindTexture(GL_TEXTURE_2D, texture_1);
// 
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
// 
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
// 
//     data = stbi_load("awesomeface.png", &width, &height, &nrChannels, 0);
//     if (data)
//     {
//         glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
//         glGenerateMipmap(GL_TEXTURE_2D);
//     }
//     else
//     {
//         std::cout << "Failed to load texture" << std::endl;
//     }
//     stbi_image_free(data);
// 
//     // Set uniform para.
//     ourShader.use();
// 
//     ourShader.setInt("texture_0", 0);
//     ourShader.setInt("texture_1", 1);
//     
//     glEnable(GL_DEPTH_TEST);
//     glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
// 
//     // render loop
//     // -----------
//     while (!glfwWindowShouldClose(window))
//     {
//         // calculate time
//         float currentFrame = glfwGetTime();
//         deltaTime = currentFrame - lastFrame;
//         lastFrame = currentFrame;
// 
//         // input
//         // -----
//         processInput(window);
// 
//         // render
//         // ------
//         glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//         glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
// 
//         glActiveTexture(GL_TEXTURE0);
//         glBindTexture(GL_TEXTURE_2D, texture_0);
//         glActiveTexture(GL_TEXTURE1);
//         glBindTexture(GL_TEXTURE_2D, texture_1);
// 
// 
//         // render the triangle
//         ourShader.use();
// 
//         // up down set mix
//         ourShader.setFloat("mixValue", mixValue);
//         float sinTimeValue = 0.75f + 0.25f * (sin((float)glfwGetTime()));
//         ourShader.setFloat("sinTimeValue", sinTimeValue);
// 
//         glm::mat4 view = glm::mat4(1.0f);
//         view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
//         ourShader.setMat4("view", view);
// 
//         glm::mat4 projection = glm::mat4(1.0f);
//         projection = glm::perspective(glm::radians(fov), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
//         ourShader.setMat4("projection", projection);
// 
//         glBindVertexArray(VAO);
//         // glDrawArrays(GL_TRIANGLES, 0, 36);
//         for (unsigned int i = 0; i < 10; i++)
//         {
//             glm::mat4 model = glm::mat4(1.0f);
//             model = glm::translate(model, cubePositions[i]);
//             float angle = 20.0f * i;
//             model = glm::rotate(model, glm::radians((float)glfwGetTime() * angle), glm::vec3(1.0f, 0.3f, 0.5f));
//             ourShader.setMat4("model", model);
// 
//             glDrawArrays(GL_TRIANGLES, 0, 36);
//         }
// 
//         // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
//         // -------------------------------------------------------------------------------
//         glfwSwapBuffers(window);
//         glfwPollEvents();
//     }
// 
//     // optional: de-allocate all resources once they've outlived their purpose:
//     // ------------------------------------------------------------------------
//     glDeleteVertexArrays(1, &VAO);
//     glDeleteBuffers(1, &VBO);
// 
//     // glfw: terminate, clearing all previously allocated GLFW resources.
//     // ------------------------------------------------------------------
//     glfwTerminate();
//     return 0;
// }
// 
// // process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// // ---------------------------------------------------------------------------------------------------------
// void processInput(GLFWwindow* window)
// {
//     if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//         glfwSetWindowShouldClose(window, true);
// 
//     if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
//     {
//         mixValue += 0.001f;
//         if (mixValue >= 1.0f)
//         {
//             mixValue = 1.0f;
//         }
//     }
// 
//     if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
//     {
//         mixValue -= 0.001f;
//         if (mixValue <= 0.0f)
//         {
//             mixValue = 0.0f;
//         }
//     }
// 
//     float cameraSpeed = 2.5f * deltaTime;
//     if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
//         cameraPos += cameraSpeed * cameraFront;
//     if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
//         cameraPos -= cameraSpeed * cameraFront;
//     if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
//         cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
//     if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
//         cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
// }
// 
// // glfw: whenever the window size changed (by OS or user resize) this callback function executes
// // ---------------------------------------------------------------------------------------------
// void framebuffer_size_callback(GLFWwindow* window, int width, int height)
// {
//     // make sure the viewport matches the new window dimensions; note that width and 
//     // height will be significantly larger than specified on retina displays.
//     glViewport(0, 0, width, height);
// }
// void mouse_callback(GLFWwindow* window, double xpos, double ypos)
// {
//     if (firstMouse)
//     {
//         lastX = xpos;
//         lastY = ypos;
//         firstMouse = false;
//     }
// 
//     float xoffset = xpos - lastX;
//     float yoffset = lastY - ypos;
//     lastX = xpos;
//     lastY = ypos;
// 
//     float sensitivity = 0.05;
//     xoffset *= sensitivity;
//     yoffset *= sensitivity;
// 
//     yaw += xoffset;
//     pitch += yoffset;
// 
//     if (pitch > 89.0f)
//         pitch = 89.0f;
//     if (pitch < -89.0f)
//         pitch = -89.0f;
// 
//     glm::vec3 front;
//     front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
//     front.y = sin(glm::radians(pitch));
//     front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
//     cameraFront = glm::normalize(front);
// }
// void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
// {
//     if (fov >= 1.0f && fov <= 45.0f)
//         fov -= yoffset;
//     if (fov <= 1.0f)
//         fov = 1.0f;
//     if (fov >= 45.0f)
//         fov = 45.0f;
// }