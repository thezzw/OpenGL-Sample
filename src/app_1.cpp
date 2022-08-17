// #include <glad/glad.h>
// #include <glfw/glfw3.h>
// 
// // 数学库
// #include <glm.hpp>
// #include <gtc/matrix_transform.hpp>
// #include <gtc/type_ptr.hpp>
// 
// // 图片加载
// #include <stb_image.h>
// 
// // 封装的渲染器类和相机类
// #include "shader.hpp"
// #include "camera.hpp"
// 
// #include <iostream>
// 
// // 定义函数原型
// void framebuffer_size_callback(GLFWwindow* window, int width, int height);
// void mouse_callback(GLFWwindow* window, double xpos, double ypos);
// void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
// void processInput(GLFWwindow* window);
// unsigned int loadTexture(const char* path);
// 
// // 设置窗口宽高 单位：像素
// const unsigned int SCR_WIDTH = 1200;
// const unsigned int SCR_HEIGHT = 900;
// 
// // 定义相机类
// Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
// float lastX = SCR_WIDTH / 2.0f;
// float lastY = SCR_HEIGHT / 2.0f;
// bool firstMouse = true;
// 
// // 定义时间
// float deltaTime = 0.0f;
// float lastFrame = 0.0f;
// 
// // 定义光照位置
// glm::vec3 lightPos(1.2f, 1.0f, 2.0f);
// 
// // 主函数
// int main()
// {
//     // 初始化GLFW窗口
//     glfwInit();
//     glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//     glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//     glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
// 
//     // 创建GLFW窗口
//     GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
//     if (window == NULL)
//     {
//         std::cout << "Failed to create GLFW window" << std::endl;
//         glfwTerminate();
//         return -1;
//     }
// 
//     // 设置窗口上下文
//     glfwMakeContextCurrent(window);
// 
//     // 绑定回调函数
//     glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//     glfwSetCursorPosCallback(window, mouse_callback);
//     glfwSetScrollCallback(window, scroll_callback);
// 
//     // 隐藏鼠标指针
//     glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
// 
//     // 通过GLAD加载所有OPENGL函数指针
//     if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//     {
//         std::cout << "Failed to initialize GLAD" << std::endl;
//         return -1;
//     }
// 
//     // 配置全局OPENGL状态，打开深度测试
//     glEnable(GL_DEPTH_TEST);
// 
//     // 加载编译GLSL
//     Shader lightingShader("../res/obj.vert", "../res/obj.frag");
//     Shader lightCubeShader("../res/light.vert", "../res/light.frag");
// 
//     // 设置顶点数据，配置顶点属性
//     // 边长为1的正方体
//     float vertices[] = {
//         // positions          // normals           // texture coords
//         -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,
//          0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 0.0f,
//          0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
//          0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
//         -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 1.0f,
//         -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,
// 
//         -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,
//          0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 0.0f,
//          0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
//          0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
//         -0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 1.0f,
//         -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,
// 
//         -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
//         -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
//         -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
//         -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
//         -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
//         -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
// 
//          0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
//          0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
//          0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
//          0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
//          0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
//          0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
// 
//         -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,
//          0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 1.0f,
//          0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
//          0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
//         -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 0.0f,
//         -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,
// 
//         -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f,
//          0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 1.0f,
//          0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
//          0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
//         -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 0.0f,
//         -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f
//     };
//     // 多个方块的位置
//     glm::vec3 cubePositions[] = {
//         glm::vec3(0.0f,  0.0f,  0.0f),
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
//     // 点光源位置
//     glm::vec3 pointLightPositions[] = {
//         glm::vec3(0.7f,  0.2f,  2.0f),
//         glm::vec3(2.3f, -3.3f, -4.0f),
//         glm::vec3(-4.0f,  2.0f, -12.0f),
//         glm::vec3(0.0f,  0.0f, -3.0f)
//     };
// 
//     // 配置缓冲内存 VBO
//     unsigned int VBO;
//     glGenBuffers(1, &VBO);
// 
//     // 配置环境立方体 cudeVAO
//     unsigned int cubeVAO;
//     glGenVertexArrays(1, &cubeVAO);
//     glBindBuffer(GL_ARRAY_BUFFER, VBO);
//     glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
// 
//     glBindVertexArray(cubeVAO);
//     glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
//     glEnableVertexAttribArray(0);
//     glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
//     glEnableVertexAttribArray(1);
//     glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
//     glEnableVertexAttribArray(2);
// 
//     // 配置光源立方体 lightCubeVAO
//     unsigned int lightCubeVAO;
//     glGenVertexArrays(1, &lightCubeVAO);
//     glBindVertexArray(lightCubeVAO);
//     glBindBuffer(GL_ARRAY_BUFFER, VBO);     // VBO里已有lightCubeVAO需要的所有数据，所以不用再用glBufferData再设置一遍。
// 
//     glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
//     glEnableVertexAttribArray(0);
// 
//     unsigned int diffuseMap = loadTexture("../img/container2.png");
//     unsigned int specularMap = loadTexture("../img/container2_specular.png");
// 
//     lightingShader.setInt("material.diffuse", 0);
//     lightingShader.setInt("material.specular", 1);
// 
//     // 渲染循环
//     while (!glfwWindowShouldClose(window))
//     {
//         // 帧前逻辑
//         float currentFrame = static_cast<float>(glfwGetTime());
//         deltaTime = currentFrame - lastFrame;
//         lastFrame = currentFrame;
// 
//         // 处理输入
//         processInput(window);
// 
//         // 渲染
//         glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
//         glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
// 
//         // 设置环境立方体
//         lightingShader.use();
//         lightingShader.setVec3("viewPos", camera.position().x, camera.position().y, camera.position().z);
//         // 设置直射光源
//         lightingShader.setVec3("dirLight.direction", -0.2f, -1.0f, -0.3f);
//         lightingShader.setVec3("dirLight.ambient", 0.05f, 0.05f, 0.05f);
//         lightingShader.setVec3("dirLight.diffuse", 0.4f, 0.4f, 0.4f);
//         lightingShader.setVec3("dirLight.specular", 0.5f, 0.5f, 0.5f);
//         // 设置点光源
//         // point light 1
//         lightingShader.setVec3("pointLights[0].position", pointLightPositions[0]);
//         lightingShader.setVec3("pointLights[0].ambient", 0.05f, 0.05f, 0.05f);
//         lightingShader.setVec3("pointLights[0].diffuse", 0.8f, 0.8f, 0.8f);
//         lightingShader.setVec3("pointLights[0].specular", 1.0f, 1.0f, 1.0f);
//         lightingShader.setFloat("pointLights[0].constant", 1.0f);
//         lightingShader.setFloat("pointLights[0].linear", 0.09f);
//         lightingShader.setFloat("pointLights[0].quadratic", 0.032f);
//         // point light 2
//         lightingShader.setVec3("pointLights[1].position", pointLightPositions[1]);
//         lightingShader.setVec3("pointLights[1].ambient", 0.05f, 0.05f, 0.05f);
//         lightingShader.setVec3("pointLights[1].diffuse", 0.8f, 0.8f, 0.8f);
//         lightingShader.setVec3("pointLights[1].specular", 1.0f, 1.0f, 1.0f);
//         lightingShader.setFloat("pointLights[1].constant", 1.0f);
//         lightingShader.setFloat("pointLights[1].linear", 0.09f);
//         lightingShader.setFloat("pointLights[1].quadratic", 0.032f);
//         // point light 3
//         lightingShader.setVec3("pointLights[2].position", pointLightPositions[2]);
//         lightingShader.setVec3("pointLights[2].ambient", 0.05f, 0.05f, 0.05f);
//         lightingShader.setVec3("pointLights[2].diffuse", 0.8f, 0.8f, 0.8f);
//         lightingShader.setVec3("pointLights[2].specular", 1.0f, 1.0f, 1.0f);
//         lightingShader.setFloat("pointLights[2].constant", 1.0f);
//         lightingShader.setFloat("pointLights[2].linear", 0.09f);
//         lightingShader.setFloat("pointLights[2].quadratic", 0.032f);
//         // point light 4
//         lightingShader.setVec3("pointLights[3].position", pointLightPositions[3]);
//         lightingShader.setVec3("pointLights[3].ambient", 0.05f, 0.05f, 0.05f);
//         lightingShader.setVec3("pointLights[3].diffuse", 0.8f, 0.8f, 0.8f);
//         lightingShader.setVec3("pointLights[3].specular", 1.0f, 1.0f, 1.0f);
//         lightingShader.setFloat("pointLights[3].constant", 1.0f);
//         lightingShader.setFloat("pointLights[3].linear", 0.09f);
//         lightingShader.setFloat("pointLights[3].quadratic", 0.032f);
//         // 设置材质
//         lightingShader.setFloat("material.shininess", 32.0f);
//         // 设置漫反射贴图
//         glActiveTexture(GL_TEXTURE0);
//         glBindTexture(GL_TEXTURE_2D, diffuseMap);
//         // 设置镜面光贴图
//         glActiveTexture(GL_TEXTURE1);
//         glBindTexture(GL_TEXTURE_2D, specularMap);
//         // 设置裁剪空间->屏幕空间转换矩阵
//         glm::mat4 projection = glm::perspective(glm::radians(camera.zoom()), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
//         lightingShader.setMat4("projection", projection);
//         // 设置观察空间->裁剪空间转换矩阵
//         glm::mat4 view = camera.GetViewMatrix();
//         lightingShader.setMat4("view", view);
//         // 设置模型空间->世界空间转换矩阵
//         glm::mat4 model = glm::mat4(1.0f);
//         lightingShader.setMat4("model", model);
//         // 渲染环境立方体
//         glBindVertexArray(cubeVAO);
//         for (unsigned int i = 0; i < 10; i++)
//         {
//             glm::mat4 model = glm::mat4(1.0f);
//             model = glm::translate(model, cubePositions[i]);
//             lightingShader.setMat4("model", model);
// 
//             glDrawArrays(GL_TRIANGLES, 0, 36);
//         }
//         glDrawArrays(GL_TRIANGLES, 0, 36);
// 
//         // 设置光源立方体
//         lightCubeShader.use();
//         // 设置坐标变换矩阵
//         lightCubeShader.setMat4("projection", projection);
//         lightCubeShader.setMat4("view", view);
//         model = glm::mat4(1.0f);
//         model = glm::translate(model, lightPos);
//         model = glm::scale(model, glm::vec3(0.2f)); // a smaller cube
//         lightCubeShader.setMat4("model", model);
//         // 渲染光源立方体
//         glBindVertexArray(lightCubeVAO);
//         for (unsigned int i = 0; i < 4; i++)
//         {
//             model = glm::mat4(1.0f);
//             model = glm::translate(model, pointLightPositions[i]);
//             model = glm::scale(model, glm::vec3(0.2f)); // Make it a smaller cube
//             lightCubeShader.setMat4("model", model);
//             glDrawArrays(GL_TRIANGLES, 0, 36);
//         }
// 
//         // 交换缓存，处理IO事件
//         glfwSwapBuffers(window);
//         glfwPollEvents();
//     }
// 
//     // 释放资源
//     glDeleteVertexArrays(1, &cubeVAO);
//     glDeleteVertexArrays(1, &lightCubeVAO);
//     glDeleteBuffers(1, &VBO);
// 
//     // 终止窗口程序，清理资源
//     glfwTerminate();
//     return 0;
// }
// 
// // 处理所有输入
// void processInput(GLFWwindow* window)
// {
//     if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//         glfwSetWindowShouldClose(window, true);
// 
//     if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
//         camera.ProcessKeyboard(kForward, deltaTime);
//     if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
//         camera.ProcessKeyboard(kBackward, deltaTime);
//     if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
//         camera.ProcessKeyboard(kLeft, deltaTime);
//     if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
//         camera.ProcessKeyboard(kRight, deltaTime);
// }
// 
// // 回调：处理窗口大小变化
// void framebuffer_size_callback(GLFWwindow* window, int width, int height)
// {
//     // make sure the viewport matches the new window dimensions; note that width and 
//     // height will be significantly larger than specified on retina displays.
//     glViewport(0, 0, width, height);
// }
// 
// 
// // 回调：处理鼠标移动
// void mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
// {
//     float xpos = static_cast<float>(xposIn);
//     float ypos = static_cast<float>(yposIn);
// 
//     if (firstMouse)
//     {
//         lastX = xpos;
//         lastY = ypos;
//         firstMouse = false;
//     }
// 
//     float xoffset = xpos - lastX;
//     float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top
// 
//     lastX = xpos;
//     lastY = ypos;
// 
//     camera.ProcessMouseMovement(xoffset, yoffset);
// }
// 
// // 回调：处理滚轮滚动
// void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
// {
//     camera.ProcessMouseScroll(static_cast<float>(yoffset));
// }
// 
// // 加载贴图
// unsigned int loadTexture(char const* path)
// {
//     unsigned int textureID;
//     glGenTextures(1, &textureID);
// 
//     int width, height, nrComponents;
//     unsigned char* data = stbi_load(path, &width, &height, &nrComponents, 0);
//     if (data)
//     {
//         GLenum format;
//         if (nrComponents == 1)
//             format = GL_RED;
//         else if (nrComponents == 3)
//             format = GL_RGB;
//         else if (nrComponents == 4)
//             format = GL_RGBA;
// 
//         glBindTexture(GL_TEXTURE_2D, textureID);
//         glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
//         glGenerateMipmap(GL_TEXTURE_2D);
// 
//         glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//         glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//         glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
//         glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
// 
//         stbi_image_free(data);
//     }
//     else
//     {
//         std::cout << "Texture failed to load at path: " << path << std::endl;
//         stbi_image_free(data);
//     }
// 
//     return textureID;
// }