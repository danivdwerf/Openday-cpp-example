//Include the libraries
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>

//Function for keyinput
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GL_TRUE);
	}
}

//Function that is called first
int main(void)
{
	//Check if GLFW can initialize, else close program
	if(!glfwInit())
	{
		fprintf(stderr,"Failed to initialize glfw");
		exit(EXIT_FAILURE);
	}
	
	//Create a variable to store the window in
	GLFWwindow* window;
	//Create the window
	window = glfwCreateWindow(640, 480, "WOW", NULL, NULL);
	//Check if window is created, else close program
	if(!window)
	{
		fprintf(stderr,"Failed to create window");
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	
	// make the window the current context
	glfwMakeContextCurrent(window);
	//make the window listen to keyinput
	glfwSetKeyCallback(window, key_callback);
	
	//while window is open
	while (!glfwWindowShouldClose(window))
	{
		//Draw a red triangle
		glBegin(GL_TRIANGLES);
		glColor3f(0.8,0.2,0.3);
		glVertex3f(0,0,0);
		glVertex3f(0.5,0,0);
		glVertex3f(0,0.5,0);
		glEnd();
		
		//Swap the buffers
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	//If the window should close, close window and exit program
	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}