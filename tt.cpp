#include <GL/glut.h>
#include <math.h>

const int n = 100;
const GLfloat raidus = 0.5f; //半径太大会显示不了
const GLfloat Pi = 3.1415926536f;

void display(void)
{
	int i;
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLE_FAN);
	for(i=0;i<n;++i)
		//glVertex3f(raidus*cos(2*Pi/n*i),raidus*sin(2*Pi/n*i),0.0);
		glVertex3f(raidus*cos(0.5*Pi/n*i),raidus*sin(0.5*Pi/n*i),0.0);
	glEnd();
	
	//glBegin(GL_QUADS);
	//glVertex3f(-0.5,-0.5,0.0);
	//glVertex3f(0.5,-0.5,0.0);
	//glVertex3f(0.5,0.5,0.0);
	//glVertex3f(-0.5,0.5,0.0);
	//glEnd();
	
	glFlush();
	
}

int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(400,400);
	glutCreateWindow("First OpenGL");
	glutDisplayFunc(&display );
	glutMainLoop();
	return 0;
}



