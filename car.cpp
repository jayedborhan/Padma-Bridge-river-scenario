#include <iostream>
#include <cstdio>
#include<GL/gl.h>
#include <GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define PI 3.14

using namespace std;

GLfloat position = 0.0;
GLfloat position2 = 0.0;
GLfloat position3 = 0.0;
GLfloat speed = 3.5;
GLfloat speed2 = 2.0;
GLfloat speed3 = 30.5;
GLfloat position4 = 0.0;

GLfloat onOff;
GLfloat frd = false;
GLfloat bck = false;


void update2(int value) {

    if(position2 > 1800.0)
        position2 = -1800.0;

    position2 += speed2;

	glutPostRedisplay();


	glutTimerFunc(100, update2, 0);
}
void update3(int value) {

    if(position3 > 1800.0)
        position3 = -1800.0;

    position3 += speed3;

	glutPostRedisplay();


	glutTimerFunc(100, update3, 0);
}

float theta;
void wheel(int x, int y)
{
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    for(int i=0; i<360; i++)
    {
    theta = i*PI/180;

    glVertex2f(x+8*cos(theta),y+8*sin(theta));
    }
    glEnd();

}

void Cars()
{
    glPushMatrix();
glTranslatef(-position3,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(0,119,189);
    glVertex2i(300, 250);
    glVertex2i(400, 250);
    glVertex2i(400, 270);
    glVertex2i(300, 270);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,153,230);
    glVertex2i(315, 270);
    glVertex2i(385, 270);
    glVertex2i(375, 285);
    glVertex2i(325, 285);

    glEnd();






    wheel(320,250);
    wheel(375,250);


glPopMatrix();
}
void Cars2()
{
    glPushMatrix();
glTranslatef(position3,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(55,0,15);
    glVertex2i(300, 350);
    glVertex2i(400, 350);
    glVertex2i(400, 370);
    glVertex2i(300, 370);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,153,230);
    glVertex2i(315, 370);
    glVertex2i(385, 370);
    glVertex2i(375, 385);
    glVertex2i(325, 385);

    glEnd();






    wheel(320,350);
    wheel(375,350);


glPopMatrix();
}

void Cars3()
{
    glPushMatrix();
glTranslatef(position3,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(102, 153, 153);
    glVertex2i(900, 350);
    glVertex2i(1000, 350);
    glVertex2i(1000, 370);
    glVertex2i(900, 370);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(51, 153, 102);
    glVertex2i(915, 370);
    glVertex2i(985, 370);
    glVertex2i(975, 385);
    glVertex2i(925, 385);

    glEnd();






    wheel(920,350);
    wheel(975,350);


glPopMatrix();
}
void Cars4()
{
    glPushMatrix();
glTranslatef(position3,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(134, 179, 0);
    glVertex2i(1500, 350);
    glVertex2i(1600, 350);
    glVertex2i(1600, 370);
    glVertex2i(1500, 370);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 153, 153);
    glVertex2i(1515, 370);
    glVertex2i(1585, 370);
    glVertex2i(1575, 385);
    glVertex2i(1525, 385);

    glEnd();






    wheel(1520,350);
    wheel(1575,350);


glPopMatrix();
}




void myDisplay(void)
{
glClear (GL_COLOR_BUFFER_BIT);
glPointSize(5.0);
Cars2();
Cars3();
Cars4();

glFlush ();

}
void myInit (void)
{
glClearColor(0.0,0.5,0.8,1.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 1800.0, 0.0, 900.0);
}



int main(int argc, char** argv)
{
   cout << endl <<" Padma Bridge" << endl << endl;

    cout << "Press LEFT Button on Mouse : For Increase Speed" << endl << endl;
    cout << "Press RIGHT Button on Mouse : For Decrease Speed" << endl << endl;

glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (1800, 900);
glutInitWindowPosition (100, 150);
glutCreateWindow ("Natural View of a car");
glutDisplayFunc(myDisplay);

myInit ();
glutTimerFunc(1000, update2, 0);
glutTimerFunc(1000, update3, 0);
glutMainLoop();
}
