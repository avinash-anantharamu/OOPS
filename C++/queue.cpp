//Queue Implementation using Open GL and C++
#include "stdafx.h"
#include <windows.h>
#include <glut.h>
int sel=-1,f,r,push,pop,s=5,speed=10;
int q[5]={-1,-1,-1,-1,-1},step,qe,qf,obj=1;
float p[][3]={{200,-150,0},{200,-70,0},{200,10,0},{200,90,0},{200,170,0}};
float color[][3]={{1.0,0.0,0.0},{0.0,1.0,0.0},{0.0,0.0,1.0},{0.0,1.0,1.0},{0.4,0.7,0.2}};
float theta=0.0,v[3]={0,0,0};

void keys( unsigned char key,int x,int y)
{
	if(key=='0')obj=0;
	if(key=='1')obj=1;
	if(key=='2')obj=2;
	if(key=='3')obj=3;
	glutPostRedisplay();
}

void display()
{
	int	i=0;
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glColor3f(0.0,0.0,0.0);
	glPushMatrix();
	glTranslatef(-220,-50,0.0);
	glScalef(01.0,3.5,1.0);
	glutWireCube(100);
	glPopMatrix();
	glPushMatrix();
	
	glColor3ub(60,200,80);
	glRasterPos2d(-170.0,-250+r*70);
	glutBitmapCharacter(GLUT_BITMAP_8_BY_13,'<');
	glutBitmapCharacter(GLUT_BITMAP_8_BY_13,'<');
	glutBitmapCharacter(GLUT_BITMAP_8_BY_13,'<');
	glutBitmapCharacter(GLUT_BITMAP_8_BY_13,'r');

	glColor3ub(218,182,37);
	glRasterPos2d(-170.0,-270+f*70);
	glutBitmapCharacter(GLUT_BITMAP_8_BY_13,'<');
	glutBitmapCharacter(GLUT_BITMAP_8_BY_13,'<');
	glutBitmapCharacter(GLUT_BITMAP_8_BY_13,'<');
	glutBitmapCharacter(GLUT_BITMAP_8_BY_13,'f');

	

	if(pop==1)
	{
		glColor3f(1.0,0.0,0.0);
		glRasterPos2d(170,270);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'D');
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'e');
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'l');
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'e');
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'t');
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'e');
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,' ');
		
		if(sel==0)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'0');
		if(sel==1)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'1');
		if(sel==2)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'2');
		if(sel==3)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'3');
		if(sel==4)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'4');
		if(sel==5)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'5');
	}

	if(qf)
	{
		glColor3f(1.0,0.0,0.0);
		glRasterPos2d(170,260);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'Q');
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'u');
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'e');
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'u');
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'e');
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,' ');
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'F');
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'u');
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'l');
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'l');
		glFlush();
	}
	if(qe)
	{
		
		glColor3f(1.0,0.0,0.0);
		glRasterPos2d(160,260);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'Q');
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'u');
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'e');
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'u');
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'e');
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,' ');
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'E');
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'m');
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'p');
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'t');
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'y');
		
	}
	if(push==1)
	{
		glColor3f(1.0,0.0,0.0);
		glRasterPos2d(200,260);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'I');
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'n');
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'s');
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'e');
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'r');
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'t');
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,' ');
		
		
		if(sel==0)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'0');
		if(sel==1)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'1');
		if(sel==2)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'2');
		if(sel==3)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'3');
		if(sel==4)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'4');
		if(sel==5)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'5');
		
	}
	
	for(i=0;i<5;i++)
	{
		glPushMatrix();
		glColor3f(0.7,0.7,0.7);
		glTranslatef(p[i][0],p[i][1],p[i][2]);
		if((push==1 || pop==1) && sel==i)
		{
		glRotatef(theta,3.0,1.0,-1.0);
		glColor3fv(color[i]);
		}
		if(obj==0)
		{
			glutWireTorus(10,20,10,10);
		}
		if(obj==1)
		{
			glutWireSphere(30,25,25);
		}
		if(obj==2)
		{
			glutWireCube(35);
		}
		if(obj==3)
		{
			glRotated(-90,1,0,0);
			glutWireCone(30,50,30,30);
		}
		
		glPopMatrix();
	}
	glPopMatrix();
	glutSwapBuffers();
}
void demo_menu(int i)
{
	if(i<4)
	obj=i;
	if(i==4)
		speed=1;
	else if(i==5)
		speed=5;
	else if(i==6)
		speed=10;
}
void rot()
{
	if(theta>360)
	{
		theta-=360;
	}
	else theta+=10;
	
	if(push==1)
	{
		
	if(p[sel][0]>100)
		{
			p[sel][0]-=speed;
			if(p[sel][0]<100)
				p[sel][0]=100;
		}
	if(p[sel][0]==100)
	{
		if(p[sel][1]<200)
		{
			p[sel][1]+=speed;
		}
		if(p[sel][1]>200)
		{
			p[sel][1]=200;
		}
	}
	if(p[sel][1]==200)
	{
		if(p[sel][0]>-220)
		{
			p[sel][0]-=speed;
		}
		if(p[sel][0]<-220)
		{
			p[sel][0]=-220;
		}
	}
	if(p[sel][0]==-220)
	{
		if(p[sel][1]>-260+70*r)
		{
			p[sel][1]-=speed;
			if(p[sel][1]<-260+70*r)
			{
				p[sel][1]=-260+70*r;
			}
		}
		if(p[sel][1]==-260+70*r)
		{
			push=0;
			pop=0;
		}
	}
	}
	if(pop==1)
	{
		if(p[sel][0]==-220 && step==0)
		{
			if(p[sel][1]>-260)
			{
				p[sel][1]-=speed;
			}
			if(p[sel][1]<-260)
			{
				p[sel][1]=-260;
			}
			if(p[sel][1]==-260)
				step=1;
		}
		if(p[sel][1]==-260 && step==1)
		{
			if(p[sel][0]<100)
			{
				p[sel][0]+=speed;
			}
			if(p[sel][0]>100)
			{
				p[sel][0]=100;
			}
			if(p[sel][0]==100)
				step=2;
		}
		if(p[sel][0]==100 && step==2)
		{
			if(p[sel][1]<-150+sel*80)
			{
				p[sel][1]+=speed;
			}
			if(p[sel][1]>-150+sel*80)
			{
				p[sel][1]=-150+sel*80;
			}
			if(p[sel][1]==-150+sel*80)
				step=3;
		}
		if(p[sel][1]==-150+sel*80 && step==3)
		{
			if(p[sel][0]<200)
			{
				p[sel][0]+=speed;
			}
			if(p[sel][0]==200)
			{
				p[sel][0]=200;
			}
			if(p[sel][0]==200)
				step=4;
		}
		if(p[sel][0]==200 && step==4)
		{
			pop=0;
			push=0;
			step=0;
		}
	}
	glutPostRedisplay();
}
void init()
{
    // Populate the window with initial co-ordinates 
	glClearColor(1.0,1.0,1.0,1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-300,300,-300,300,-300,300);
	
}
void reshape(int w,int h)
{
    // Resize the Window 
	glViewport(0,0,600,600);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(w<=h)
		glOrtho(-300,300,-300*h/w,300*h/w,-300,300);
	else
		glOrtho(-300*h/w,300*h/w,-300,300,-300,300);
}

void mouse(int bt,int st,int x,int y)
{
    // Mouse Click Event
	int i,j;
	if(push==0 && pop==0)
	if(bt==GLUT_LEFT_BUTTON && st==GLUT_DOWN)
		if(465<=x && x<=535)
		{
			for(i=0;i<5;i++)
			{
				if(415-i*80<y && y<485-i*80)
				{
										
					if(r==s)
						{
							qf=1;
							qe=0;
						}
						else 
						push=1;
						if(push==1 )
						{
					
							qe=0;
							qf=0;
							q[r]=i;
							r++;
							sel=i;
						
						}
				}
			}
		}
	if(push==0 && pop ==0)
	if(bt==GLUT_RIGHT_BUTTON && st==GLUT_DOWN)
	{
		if(f==r)
		{
			qe=1;
			qf=0;
			printf("queue is empty");
		}
		else
		{
			pop=1;
			qe=0;
			qf=0;
			sel=q[f];
			f++;
		}
	}
}
void obj_menu(int i)
{
	obj=i;
}
void main(int argc,char** argv)
{
	int sub_menu1,sub_menu2;
	//Initialize Window Parameters
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowPosition(100.0,100.0);
	glutInitWindowSize(600.0,600.0);
	// Assign Name to the Window
	glutCreateWindow("queue");
	glutDisplayFunc(display);
	glutIdleFunc(rot);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keys);
	glutMouseFunc(mouse);
	sub_menu1=glutCreateMenu(demo_menu);
	glutAddMenuEntry("slow",4);
	glutAddMenuEntry("medium",5);
	glutAddMenuEntry("Fast",6);
	sub_menu2=glutCreateMenu(demo_menu);
	glutAddMenuEntry("Torus",0);
	glutAddMenuEntry("Sphere",1);
	glutAddMenuEntry("Cube",2);
	glutAddMenuEntry("Cone",3);
	glutAddSubMenu("Speed",sub_menu1);
	glutAttachMenu(GLUT_MIDDLE_BUTTON);
	glEnable(GL_DEPTH_TEST);
	init();
	glutMainLoop();
}