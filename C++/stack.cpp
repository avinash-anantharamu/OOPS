#include "stdafx.h"
#include <stdio.h>
#include <windows.h>
#include <glut.h>
GLfloat color[][3]={{1.0,0.8,0.2},{1.0,0.5,1.0},{0.4,0.0,0.0},{0.7,0.2,1.0},{.30,0.60,.40}};
GLint t,s=5;
int q[6],x0,x1,y0,y1;
void insertout(int t,int insert_e)
{
	int i;		
	for(i=0;i<=t;i++)
	{
		glBegin(GL_POLYGON);
		glColor3fv(color[q[i]]);
		glVertex3f(100.0,150.0+i*50,0.0);
		glVertex3f(100.0,100.0+i*50,0.0);
		glVertex3f(200.0,100.0+i*50,0.0);
		glVertex3f(200.0,150.0+i*50,0.0);
		glEnd();
		glFlush();
	}
}
void delout(int t)
{
	int i;
		glBegin(GL_POLYGON);
		glColor3f(1.0,1.0,1.0);
		glVertex3f(100.0,150.0+t*50.0,0.0);
		glVertex3f(100.0,100.0+t*50.0,0.0);
		glVertex3f(200.0,100.0+t*50.0,0.0);
		glVertex3f(200.0,150.0+t*50.0,0.0);
		glEnd();
		glFlush();
}
void insert_transform(int insert_e)
{
	x0=450;
	x1=550;
	y0=600-(100+insert_e*60);
	y1=600-(150+insert_e*60);
	glBegin(GL_POLYGON);
	glColor3f(1.0,1.0,1.0);
	glVertex3f(x0,y0,0.0);
	glVertex3f(x1,y0,0.0);
	glVertex3f(x1,y1,0.0);
	glVertex3f(x0,y1,0.0);
	glEnd();
	glFlush();
	
	for(x0=450;x0>300;)
	{
		glBegin(GL_POLYGON);
		glColor3fv(color[insert_e]);
		glVertex3f(x0,y0,0.0);
		glVertex3f(x1,y0,0.0);
		glVertex3f(x1,y1,0.0);
		glVertex3f(x0,y1,0.0);
		glEnd();
		glFlush();
		Sleep(5);
		glBegin(GL_POLYGON);
		glColor3f(1.0,1.0,1.0);
		glVertex3f(x0,y0,0.0);
		glVertex3f(x1,y0,0.0);
		glVertex3f(x1,y1,0.0);
		glVertex3f(x0,y1,0.0);
		glEnd();
		x0-=1;
		x1-=1;
	}
	for(;y0<500;)
	{
		glBegin(GL_POLYGON);
		glColor3fv(color[insert_e]);
		glVertex3f(x0,y0,0.0);
		glVertex3f(x1,y0,0.0);
		glVertex3f(x1,y1,0.0);
		glVertex3f(x0,y1,0.0);
		glEnd();
		glFlush();
		Sleep(5);
		glBegin(GL_POLYGON);
		glColor3f(1.0,1.0,1.0);
		glVertex3f(x0,y0,0.0);
		glVertex3f(x1,y0,0.0);
		glVertex3f(x1,y1,0.0);
		glVertex3f(x0,y1,0.0);
		glEnd();
		y0+=1;
		y1+=1;
	}
	for(;x0>100;)
	{
		glBegin(GL_POLYGON);
		glColor3fv(color[insert_e]);
		glVertex3f(x0,y0,0.0);
		glVertex3f(x1,y0,0.0);
		glVertex3f(x1,y1,0.0);
		glVertex3f(x0,y1,0.0);
		glEnd();
		glFlush();
		Sleep(5);
		glBegin(GL_POLYGON);
		glColor3f(1.0,1.0,1.0);
		glVertex3f(x0,y0,0.0);
		glVertex3f(x1,y0,0.0);
		glVertex3f(x1,y1,0.0);
		glVertex3f(x0,y1,0.0);
		glEnd();
		x0-=1;
		x1-=1;
	}
	for(;y0>150+t*50;)
	{
		glBegin(GL_POLYGON);
		glColor3fv(color[insert_e]);
		glVertex3f(x0,y0,0.0);
		glVertex3f(x1,y0,0.0);
		glVertex3f(x1,y1,0.0);
		glVertex3f(x0,y1,0.0);
		glEnd();
		glFlush();
		Sleep(5);
		glBegin(GL_POLYGON);
		glColor3f(1.0,1.0,1.0);
		glVertex3f(x0,y0,0.0);
		glVertex3f(x1,y0,0.0);
		glVertex3f(x1,y1,0.0);
		glVertex3f(x0,y1,0.0);
		glEnd();
		y0-=1;
		y1-=1;
	}
}
void insert(int inserting_element)
{
	int i;
	if(t>s-1)
	{
		printf("queue is full\n");
	}
	else
	{
		insert_transform(inserting_element);
		printf("pushed %d\n",inserting_element);
		q[t]=inserting_element;
		insertout(t,inserting_element);
		t++;
	}
}
void del_transform(int t,int del_e)
{
	int i;
	x0=100;
	x1=200;
	y0=(100+t*50);
	y1=(150+t*50);
	for(;y0<450;)
	{
		glBegin(GL_POLYGON);
		glColor3fv(color[del_e]);
		glVertex3f(x0,y0,0.0);
		glVertex3f(x1,y0,0.0);
		glVertex3f(x1,y1,0.0);
		glVertex3f(x0,y1,0.0);
		glEnd();
		glFlush();
		Sleep(5);
		glBegin(GL_POLYGON);
		glColor3f(1.0,1.0,1.0);
		glVertex3f(x0,y0,0.0);
		glVertex3f(x1,y0,0.0);
		glVertex3f(x1,y1,0.0);
		glVertex3f(x0,y1,0.0);
		glEnd();
		glFlush();
		y0+=1;
		y1+=1;
	}
	for(;x0<300;)
	{
		glBegin(GL_POLYGON);
		glColor3fv(color[del_e]);
		glVertex3f(x0,y0,0.0);
		glVertex3f(x1,y0,0.0);
		glVertex3f(x1,y1,0.0);
		glVertex3f(x0,y1,0.0);
		glEnd();
		glFlush();
		Sleep(5);
		glBegin(GL_POLYGON);
		glColor3f(1.0,1.0,1.0);
		glVertex3f(x0,y0,0.0);
		glVertex3f(x1,y0,0.0);
		glVertex3f(x1,y1,0.0);
		glVertex3f(x0,y1,0.0);
		glEnd();
		x0+=1;
		x1+=1;
	}
	for(;y0>550-(100+del_e*60);)
	{
		glBegin(GL_POLYGON);
		glColor3fv(color[del_e]);
		glVertex3f(x0,y0,0.0);
		glVertex3f(x1,y0,0.0);
		glVertex3f(x1,y1,0.0);
		glVertex3f(x0,y1,0.0);
		glEnd();
		glFlush();
		Sleep(5);
		glBegin(GL_POLYGON);
		glColor3f(1.0,1.0,1.0);
		glVertex3f(x0,y0,0.0);
		glVertex3f(x1,y0,0.0);
		glVertex3f(x1,y1,0.0);
		glVertex3f(x0,y1,0.0);
		glEnd();
		glFlush();
		y0-=1;
		y1-=1;
	}
	for(;x0<450;)
	{
		glBegin(GL_POLYGON);
		glColor3fv(color[del_e]);
		glVertex3f(x0,y0,0.0);
		glVertex3f(x1,y0,0.0);
		glVertex3f(x1,y1,0.0);
		glVertex3f(x0,y1,0.0);
		glEnd();
		glFlush();
		Sleep(5);
		glBegin(GL_POLYGON);
		glColor3f(1.0,1.0,1.0);
		glVertex3f(x0,y0,0.0);
		glVertex3f(x1,y0,0.0);
		glVertex3f(x1,y1,0.0);
		glVertex3f(x0,y1,0.0);
		glEnd();
		x0+=1;
		x1+=1;
	}
	glBegin(GL_POLYGON);
	glColor3fv(color[del_e]);
	glVertex3f(x0,y0,0.0);
	glVertex3f(x1,y0,0.0);
	glVertex3f(x1,y1,0.0);
	glVertex3f(x0,y1,0.0);
	glEnd();
	glFlush();
}
void del()
{
	int del_element;
	if(t==-1)
	{
		printf("Queue is empty\n");
	}
	else
	{
		del_element=q[--t];
		delout(t);
		del_transform(t,del_element);
	}
}
int identify_insert(int x,int y)
{
	int i,j;
	if(450<=x && x<=550)
	{
		for(i=0;i<s-1;i++)
		if(100+i*60<=y && y<=150+i*60)
		{
			for(j=0;j<s;j++)
			{
				if(q[j]==i)
					return -1;
			}
			return i;
		}
	}
	else
	{
		printf("Click on the boxes\n");
		return -1;
	}
}
void mouse(int button,int state,int x,int y)
{
	int inserting_element;
	if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
	{
		if((inserting_element=identify_insert(x,y))!=-1)
		insert(inserting_element);
	}
	if(button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
	{
		del();
	}
}
void init()
{
	glClearColor(1.0,1.0,1.0,1.0);
	gluOrtho2D(0.0,599.0,0.0,599.0);
}
void display()
{
	int i=0;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINES);
	glVertex3f(99.0,400.0,0.0);
	glVertex3f(99.0,100.0,0.0);
	glVertex3f(200.0,100.0,0.0);
	glVertex3f(200.0,400.0,0.0);
	glFlush();
	glEnd();

	for(i=0;i<s;i++)
	{
		glBegin(GL_POLYGON);
		glColor3fv(color[i]);
		glVertex3f(450,600-(100+i*60),0.0);
		glVertex3f(550,600-(100+i*60),0.0);
		glVertex3f(550,600-(150+i*60),0.0);
		glVertex3f(450,600-(150+i*60),0.0);
		glEnd();
		glFlush();
	}
}

void main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(600,600);
	glutCreateWindow("queue");
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	init();
	glutMainLoop();
}
