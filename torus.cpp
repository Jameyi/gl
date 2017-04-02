#include <GL/glut.h>
#include <math.h>
//#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

//const int n = 100;
//const GLfloat raidus = 0.5f; //半径太大会显示不了
const GLfloat PI = 3.14159265358979323846f;

GLuint theTorus;

static void torus(int numc,int numt){
	int i,j,k;
	double x,y;
	double s,t;
	double z = 0.0;
	for(i=0;i<numc;i++){
		glBegin(GL_QUAD_STRIP);
		for(j=0;j<=numt;j++){
			for(k=1;k>=0;k--){
				s = (i + k) % numc + 0.5;
				t = j % numt;

				x = (1+0.1*cos(s*2*PI/numc)) * cos(t*2*PI/numt);
				y = (1+0.1*cos(s*2*PI/numc)) * sin(t*2*PI/numt);
				//z = 0.1 * sin(s*2*PI/numc);

				glVertex3f(x,y,z);
			}

		}
		glEnd();
	}
}

static void init(void){
	theTorus = glGenLists(1);
	glNewList(theTorus,GL_COMPILE);
	torus(8,25);
	glEndList();

	glShadeModel(GL_FLAT);
	glClearColor(0.0,0.0,0.0,0.0);
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,0.0,0.0);
	glCallList(theTorus);
	glFlush();
}

void reshape(int w, int h){
	glViewport(0,0,(GLsizei)w,(GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(30,(GLfloat)w / (GLfloat)h,1.0,100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0,0,10,0,0,0,0,1,0);
}


int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(200,200);
	glutInitWindowSize(400,400);
	glutCreateWindow("First OpenGL");
	init();
	glutReshapeFunc(&reshape);
	glutDisplayFunc(&display );
	glutMainLoop();
	return 0;
}



