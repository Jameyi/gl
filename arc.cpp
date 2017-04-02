#include <GL/glut.h>
#include <math.h>
//#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

#define width 640
#define height 480
//const int n = 100;
//const GLfloat raidus = 0.5f; //半径太大会显示不了
const GLfloat PI = 3.14159265358979323846f;


void connectPoint(double x,double y,double start_angle,double end_angle,double outrad,double innerrad){

	double out_startX = x + outrad * cos(start_angle);
	double out_startY = y + outrad * sin(start_angle);
	double out_endX = x + outrad * cos(end_angle);
	double out_endY = y + outrad * sin(end_angle);
	double inner_startX = x + innerrad * cos(start_angle);
	double inner_startY = y + innerrad * sin(start_angle);
	double inner_endX = x + innerrad * cos(end_angle);
	double inner_endY = y + innerrad * sin(end_angle);
	glBegin(GL_LINE_STRIP);
	glVertex2d(inner_startX,inner_startY);
	glVertex2d(out_startX,out_startY);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2d(inner_endX,inner_endY);
	glVertex2d(out_endX,out_endY);
	glEnd();
}


void glArc(double x,double y,double start_angle,double end_angle,double delta_angle,double rad,int Mode){

	glBegin(Mode);
	for(double i=start_angle;i<=end_angle;i+=delta_angle)
	{
		double ox = x + rad * cos(i);
		double oy = y + rad * sin(i);
		glVertex2f(ox,oy);
	}
	glEnd();
}


void drawArc(double x,double y,double start_angle,double end_angle,double delta_angle,double outrad,double innerrad,int Mode){
	
	glBegin(Mode);
	for(double i=start_angle; i<=end_angle; i+=delta_angle){
		double ox = x + outrad * cos(i);
		double oy = y + outrad * sin(i);
		double ix = x + innerrad * cos(i);
		double iy = y + innerrad * sin(i);
		
		glVertex2f(ox,oy);
		glVertex2f(ix,iy);
		//glVertex2f(ix,ox);
		//glVertex2f(iy,oy);
	}
	glEnd();
}



static void init(void){

	glClearColor(0.0,0.0,0.0,0.0);
	glColor3f(0.0,0.0,1.0);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-width/2.0,width/2.0,-height/2.0,height/2.0);
	glLineWidth(2.0);
}

void display(void)
{
	
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,0.0,0.0);
	//画出笛卡尔坐标
	glBegin(GL_LINES);
	glVertex2f(-width/2.0,0);
	glVertex2f(width/2.0,0);
	glEnd();
	
	glBegin(GL_LINES);
	glVertex2f(0,height/2.0);
	glVertex2f(0,-height/2.0);
	glEnd();
	glLineWidth(8.0);
	glColor3f(0.0,0.0,1.0);
	glArc(0,0,0.1,PI/2.1,PI/180,2,GL_LINE_STRIP);
	glArc(0,0,0.1,PI/2.1,PI/180,1,GL_LINE_STRIP);
	connectPoint(0,0,0.1,PI/2.1,2,1);
	glLineWidth(2.0);
	glColor3f(0.0,1.0,1.0);
	//draw arcs
	drawArc(0,0,0.1,PI/2.1,PI/180,2,1,GL_TRIANGLE_STRIP);

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
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
	glutInitWindowPosition(200,200);
	glutInitWindowSize(width,height);
	glutCreateWindow("First OpenGL");
	init();
	glutReshapeFunc(&reshape);
	glutDisplayFunc(&display );
	glutMainLoop();
	return 0;
}



