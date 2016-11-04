#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

#include "math_3d.h"
#include <iostream>

const float PI = 3.14159;
const float DEG2RAD = 3.14159/180.0;

void RenderSceneCB()
{
	Vector3f Vertices[3];
	Vertices[0] = Vector3f(-1.0f, -1.0f, 0.0f);
	Vertices[1] = Vector3f(1.0f, -1.0f, 0.0f);
	Vertices[2] = Vector3f(0.0f, 1.0f, 0.0f);

	GLuint VBO;
	glGenBuffers(1, &VBO); //1 means the number of objects to generate, VBO is the address of an aray of GLuints to store the handles
 	glBindBuffer(GL_ARRAY_BUFFER, VBO);  // In OpenGL we bind the handle to a target name and then execute commands on that target. 
 	                                     // The target GL_ARRAY_BUFFER means that the buffer will contain an array of vertices. 
 										// Another useful target is GL_ELEMENT_ARRAY_BUFFER which means that the buffer contains the indices of the vertices in another buffer
 	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW); //we fill it with data. The call above takes the target name, the size of the data in bytes, 
 																			// address of the array of vertices and a flag that indicates the usage pattern for this data.

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);  // 3 is for x, y and z
	//The third parameter is the data type of each component. The next parameter indicates whether we want our attribute to be normalized before it is used in the pipeline.
	glDrawArrays(GL_TRIANGLES, 0, 3);
	//glDrawArrays(GL_POINTS, 0, 1); //draw the geometry, it's a ordered draws, means to draw in order, one-by-one, the other type is index draw
 	/*the above set the stage for the draw command. This is where the GPU really starts to work.*/


	glDisableVertexAttribArray(0);
		//glClear(GL_COLOR_BUFFER_BIT);
	glutSwapBuffers();
}

int main(int argc, char **argv){

//this is init function
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
  glutInitWindowSize(800, 600);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("OpenGL - First window demo");

	GLenum res = glewInit();
	if (res != GLEW_OK) {
	fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
	return 1;
	}

	 glutDisplayFunc(RenderSceneCB);
	 glClearColor(0.0f, 0.0f, 0.0f, 0.0f);


	glutMainLoop();




}


