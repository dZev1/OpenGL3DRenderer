#define _USE_MATH_DEFINES

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

int main()
{
	glfwInit();

	/* trying GLM
	// translating
	glm::vec4 v(1.0f, 0.0f, 0.0f, 1.0f);
	glm::mat4 transformMatrix = glm::mat4(1.0f);
	transformMatrix = glm::translate(transformMatrix, glm::vec3(1.0f, 1.0f, 0.0f));
	
	v = transformMatrix * v;
	std::cout << v.x << v.y << v.z << v.w << std::endl;

	// rotating
	float angle;
	angle = M_PI / 2.0f;
	transformMatrix = glm::mat4(1.0f);
	transformMatrix = glm::rotate(transformMatrix, angle, glm::vec3(0.0f, 0.0f, 1.0f));
	transformMatrix = glm::scale(transformMatrix, glm::vec3(0.5f, 0.5f, 0.5f));
	
	v = transformMatrix * v;
	std::cout << v.x << v.y << v.z << v.w << std::endl;
	*/

	// openGL v3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	// Use the main openGL profile
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(1200, 800, "Hello Window!", NULL, NULL);
	
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initizalize GLAD" << std::endl;
		return -1;
	}

	glViewport(0, 0, 1200, 800);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	while (!glfwWindowShouldClose(window))
	{
		// input
		processInput(window);

		// rendering commands
		glClearColor(1.0f, 0.6f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		
		// send new frame to window
		glfwPollEvents();
		glfwSwapBuffers(window);
	}
	glfwTerminate();
	return 0;
}

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		std::cout << "DWIGHT ";
	}
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}