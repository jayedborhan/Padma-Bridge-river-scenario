
#include<cstdio>
#include <GL/gl.h>
#include <GL/glut.h>
#include<math.h>
#include<Windows.h>
#include<Mmsystem.h>
#define PI 3.14159265358979323846

void displayMor();
void displayDay();
void displayNight();

void automated_mor(int val){
    glutDisplayFunc(displayMor);
}
void automated_day(int val){
    glutDisplayFunc(displayDay);
}
void automated_night(int val){
    glutDisplayFunc(displayNight);
}



void roadriver(int val){
    glBegin(GL_POLYGON); //river

    if(val==9)
        glColor3f(0.43f, 0.65f, 0.76);
        glVertex2f( 1.0f, -0.30f);

        glColor3f(0.36f, 0.54f, 0.66f);
        glVertex2f(-1.0f, -0.30f);

        glColor3f(0.43f, 0.65f, 0.76f);
        glVertex2f(-1.0f, 0.295f);

        glColor3f(0.91f, 0.92f, 0.96f);
        glVertex2f( 1.0f, 0.295f);

    if(val==1)
        glColor3f(0.03f, 0.23f, 0.40);
        glVertex2f( 1.0f, -0.30f);

        glColor3f(0.30f, 0.24f, 0.42f);
        glVertex2f(-1.0f, -0.30f);

        glColor3f(0.43f, 0.65f, 0.76f);
        glVertex2f(-1.0f, 0.295f);

        glColor3f(0.02f, 0.20f, 0.35f);
        glVertex2f( 1.0f, 0.295f);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.30f, 0.50f, 0.35f);
        glVertex2f(-1.0f, -0.35f);
        glVertex2f( 1.0f, -0.35f);
        glVertex2f( 1.0f, -0.30f);
        glVertex2f(-1.0f, -0.30f);
    glEnd();

    glBegin(GL_POLYGON); //road
    glColor3f(0.4f, 0.4f, 0.5f);

        glVertex2f(-1.0f, -0.35f);
        glVertex2f(1.0f, -0.35f);
        glVertex2f(1.0f, -1.0f);
        glVertex2f(-1.0f, -1.0f);
    glEnd();

    glBegin(GL_QUADS); //divider
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(-0.3f,-0.63f);
        glVertex2f( 0.3f, -0.63f);
        glVertex2f( 0.35f, -0.57f);
        glVertex2f(-0.25f,-0.57f);

        glVertex2f( 0.4f, -0.63f);
        glVertex2f( 1.0f, -0.63f);
        glVertex2f( 1.0f, -0.57f);
        glVertex2f( 0.45f,- 0.57f);

        glVertex2f(-0.45f, -0.63f);
        glVertex2f(-1.0f, -0.63f);
        glVertex2f(-1.0f, -0.57f);
        glVertex2f(-0.4f,- 0.57f);
    glEnd();
}


void displayMor(){
    int val = 1;

    glLoadIdentity();
    glPushMatrix();
    glTranslatef(-0.37f,0.043f,0.0f);
    glScaled(0.5,0.8,1);

    glPopMatrix();




    roadriver(val);

    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0f,0.40f,0.0f);
    glScaled(1.8,1.5,1);







    glFlush();
    glutTimerFunc(2500,automated_day,0);
}

void displayDay(){
    int val = 1;



    //vehicles road
    glPushMatrix();
    glTranslatef(0.0f,0.80f,0.0f);
    glScaled(1.5,1.4,1);

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f,0.30f,0.0f);
    glScaled(1.5,1.2,1);

    glPopMatrix();


        glPushMatrix();
        glPointSize(1.5);
        glPopMatrix();
    }







void displayNight(){
    int val = 9;

    //vehicles road
    glPushMatrix();
    glTranslatef(0.0f,0.80f,0.0f);
    glScaled(1.5,1.4,1);

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f,0.30f,0.0f);
    glScaled(1.5,1.2,1);

    glPopMatrix();


        glPushMatrix();
        glPointSize(1.5);
        glPopMatrix();
    }





void info(){
glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
glClear(GL_COLOR_BUFFER_BIT);

glBegin(GL_POLYGON);

    glEnd();

glFlush();

}

void handleKeypress(unsigned char key, int x, int y){
	switch (key)
	{
	    case 'x':
        case 'X':
            glutDisplayFunc(displayMor);
            break;
        case '0':

        case 'D':
        case 'd':
            glutDisplayFunc(displayDay);
            break;
        case 'M':
        case 'm':
            glutDisplayFunc(displayMor);
            break;
        case 'N':
        case 'n':
            glutDisplayFunc(displayNight);
            break;

        glutPostRedisplay();
	}
}


int main(int argc, char** argv){
   glutInit(&argc, argv);
   glutInitWindowSize(1600,900);
   glutInitWindowPosition(150,80);
   glutCreateWindow("Padma Bridge Scenario");
   gluOrtho2D(-2, 2, -1, 1);
    glutDisplayFunc(displayMor);
   glutKeyboardFunc(handleKeypress);

   glutMainLoop();
   return 0;
}

