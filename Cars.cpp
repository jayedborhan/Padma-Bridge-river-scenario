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

GLfloat _rain = 0.0;
GLfloat _nt = 0.0;

GLfloat rainday = false;
GLfloat night = false;

void update(int value) {

    if(position > 1800.0)
        position = -1800.1;

    position += speed;

	glutPostRedisplay();


	glutTimerFunc(100, update, 1);
}
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

void ambulance1()
{
    glPushMatrix();
    glTranslatef(-position3,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2i(930, 250);
    glVertex2i(1000, 250);
    glVertex2i(1000, 270);
    glVertex2i(930, 270);

    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2i(940, 270);
    glVertex2i(1000, 270);
    glVertex2i(1000, 285);
    glVertex2i(950, 285);

    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex2i(960, 265);
    glVertex2i(990, 265);
    glVertex2i(990, 275);
    glVertex2i(960, 275);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex2i(970, 260);
    glVertex2i(980, 260);
    glVertex2i(980, 280);
    glVertex2i(970, 280);

    glEnd();


    wheel(950,250);
    wheel(985,250);

    glBegin(GL_POLYGON);
glColor3ub(255, 0, 0);
for(int i=0; i<360; i++)
{
    theta = i*PI/180;
    glVertex2f(955+3*cos(theta),286+3*sin(theta));
}
glEnd();


glPopMatrix();

}

void ambulance2()
{
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2i(1000, 410);
    glVertex2i(1070, 410);
    glVertex2i(1070, 430);
    glVertex2i(1000, 430);

    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2i(1010, 430);
    glVertex2i(1070, 430);
    glVertex2i(1070, 445);
    glVertex2i(1020, 445);

    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 153, 204);
    glVertex2i(1012, 430);
    glVertex2i(1023, 430);
    glVertex2i(1023, 445);



    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex2i(1033, 425);
    glVertex2i(1058, 425);
    glVertex2i(1058, 435);
    glVertex2i(1033, 435);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex2i(1040, 420);
    glVertex2i(1050, 420);
    glVertex2i(1050, 440);
    glVertex2i(1040, 440);

    glEnd();


    wheel(1020,410);
    wheel(1055,410);


    glBegin(GL_POLYGON);
glColor3ub(255, 0, 0);
for(int i=0; i<360; i++)
{
    theta = i*PI/180;
    glVertex2f(1026+3*cos(theta),446+3*sin(theta));
}
glEnd();



}



void schoolBus()
{

glPushMatrix();
glTranslatef(-position3,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex2i(1400, 250);
    glVertex2i(1500, 250);
    glVertex2i(1500, 270);
    glVertex2i(1400, 270);

    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex2i(1405, 270);
    glVertex2i(1500, 270);
    glVertex2i(1500, 285);
    glVertex2i(1410, 285);

    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(0, 172, 230);
    glVertex2i(1412, 255);
    glVertex2i(1427, 255);
    glVertex2i(1427, 280);
    glVertex2i(1412, 280);

    glEnd();

    glBegin(GL_LINES);
glColor3ub (0, 0, 0);
glVertex2i(1419, 255);
glVertex2i(1419, 280);
glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 172, 230);
    glVertex2i(1435, 270);
    glVertex2i(1460, 270);
    glVertex2i(1460, 280);
    glVertex2i(1435, 280);

    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 172, 230);
    glVertex2i(1465, 270);
    glVertex2i(1490, 270);
    glVertex2i(1490, 280);
    glVertex2i(1465, 280);

    glEnd();


    wheel(1435,250);
    wheel(1485,250);
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
/// Rain
void Rain(int value){

if(rainday){

    _rain += 0.01f;

    glBegin(GL_POINTS);
    for(int i=1;i<=1000;i++)
    {
        int x=rand(),y=rand();
        x%=1800; y%=1800;
        glBegin(GL_LINES);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2d(x,y);
        glVertex2d(x+5,y+5);
        glEnd();
    }

	glutPostRedisplay();
	glutTimerFunc(5, Rain, 0);

    glFlush();

}
}
/// Night
void Night(int value){
if(night){


    glClearColor(0.0,0.0,0.0,0.0);
	glutPostRedisplay();
    glutTimerFunc(5, Night, 0);

    float theta;

glBegin(GL_POLYGON);
glColor3ub(204, 204, 204);
for(int i=0; i<360; i++)
{
    theta = i*PI/180;
    glVertex2f(500+45*cos(theta),800+40*sin(theta));
}
glEnd();

    glFlush();

}
}
void handleMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			speed3 += 5.1f;
			printf("clicked at (%d, %d)\n", x, y);
		}
	}
if (button == GLUT_RIGHT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			speed3 -= 5.1f;
			printf("clicked at (%d, %d)\n", x, y);
		}
	}

	glutPostRedisplay();
}

void myKeyboard(unsigned char key, int x, int y){
	switch (key)
	{
	case 'a':
        frd = false;
	    bck = true;
//	    railBackward(position4);
	break;

	case 'd':
	     frd = true;
	     bck = false;
//         railForward(position4);
	    break;

    case 's':
        frd = false;
        bck = false;
        break;

    case 'r':
        rainday = true;
        Rain(_rain);

        break;

    case 'e':
        rainday = false;

        break;

    case 'n':
        night = true;
        Night(_nt);
        break;

    case 'b':
        night = false;
        glClearColor(0.0,0.5,0.8,1.0);
        break;

    case 27:     // ESC key
        exit(0);
        break;

	default:
	break;
	}
}
int main(int argc, char** argv)
{
   cout << endl << "*********** Natural View of a Town ********************" << endl << endl;

    cout << "Press D : To Forward the Train" << endl << endl;
    cout << "Press A : To Backward the Train" << endl << endl;
    cout << "Press S : To Stop the Train" << endl << endl;

    cout << "Press R : For Rain " << endl << endl;
    cout << "Press E : For Stop Rain" << endl << endl;

    cout << "Press N : For Night " << endl << endl;
    cout << "Press B : For Day" << endl << endl;

    cout << "Press LEFT Button on Mouse : For Increase Speed" << endl << endl;
    cout << "Press RIGHT Button on Mouse : For Decrease Speed" << endl << endl;

glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (1800, 900);
glutInitWindowPosition (100, 150);
glutCreateWindow ("Natural View of a car");
glutDisplayFunc(myDisplay);
glutMouseFunc(handleMouse);
glutKeyboardFunc(myKeyboard);
myInit ();
glutTimerFunc(1000, update, 0);
glutTimerFunc(1000, update2, 0);
glutTimerFunc(1000, update3, 0);
glutMainLoop();
}

