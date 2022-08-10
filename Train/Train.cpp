// Hadiur Rahman Nabil
// Group -10

#include<cstdio>
#include<bits/stdc++.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include<math.h>
#include<Windows.h>
#include<Mmsystem.h>
#define PI 3.14159265358979323846


void displayMor();


void initGL(){
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
}

void automated_mor(int val){
    glutDisplayFunc(displayMor);
}
void Idle(){
    glutPostRedisplay();//// marks the current window as needing to be redisplayed
}


GLfloat trainPosition = 0.3f;
GLfloat trainSpeed = 0.08f;
void updateTrain(int value){ //9
    if(trainPosition > 1.5)
    {
        trainPosition = -0.4f;
    }
    trainPosition += trainSpeed;

    glutPostRedisplay();

    glutTimerFunc(100, updateTrain, 0);
}


void train(int val){    //train

glMatrixMode(GL_MODELVIEW);

glPushMatrix();
glTranslatef(trainPosition , 0.0f, 0.0f);

    glColor3d(0.0f,0.0f,0.0f); ////engine
    glBegin(GL_POLYGON);

        glVertex2f(-0.06f, 0.15f);
        glVertex2f(-0.06f, 0.025f);
        glVertex2f(0.06f, 0.025f);
        glVertex2f(0.06f, 0.15f);
    glEnd();

    glColor3d(1.0f,0.0f,0.0f); ////engine cover1
    glBegin(GL_POLYGON);

        glVertex2f(0.06f, 0.15f);
        glVertex2f(0.06f, 0.06f);
        glVertex2f(0.062f, 0.06f);
        glVertex2f(0.062f, 0.15f);
    glEnd();

    glColor3d(1.0f,1.0f,0.0f); ////engine cover2
    glBegin(GL_POLYGON);

        glVertex2f(0.062f, 0.068f);
        glVertex2f(0.062f, 0.135f);
        glVertex2f(0.067f, 0.135f);
        glVertex2f(0.067f, 0.068f);
    glEnd();

    glColor3d(0.0f,0.0f,0.0f); /////Cabin
    glBegin(GL_POLYGON);
        glVertex2f(-0.15f, 0.2f);
        glVertex2f(-0.15f, 0.025f);
        glVertex2f(-0.05f, 0.025f);
        glVertex2f(-0.05f, 0.2f);
    glEnd();


    glColor3d(1.0f,1.0f,0.0f); /////door
    glBegin(GL_POLYGON);
        glVertex2f(-0.145f, 0.175f);
        glVertex2f(-0.145f, 0.028f);
        glVertex2f(-0.105f, 0.028f);
        glVertex2f(-0.105f, 0.175f);
    glEnd();

    glColor3d(1.0f,1.0f,0.0f); /////window
    glBegin(GL_POLYGON);
        glVertex2f(-0.1f, 0.175f);
        glVertex2f(-0.1f, 0.115f);
        glVertex2f(-0.06f, 0.115f);
        glVertex2f(-0.06f, 0.175f);
    glEnd();

    glColor3d(1.0f,0.0f,0.0f); ////roof
    glBegin(GL_POLYGON);
        glVertex2f(-0.155f, 0.225f);
        glVertex2f(-0.155f, 0.2f);
        glVertex2f(-0.045f, 0.2f);
        glVertex2f(-0.045f, 0.225f);
    glEnd();

    glColor3d(0.0f,0.0f,0.0f); ////bumper
    glBegin(GL_POLYGON);
        glVertex2f(0.055f, 0.06f);
        glVertex2f(0.055f, 0.0075f);
        glVertex2f(0.085f, 0.0075f);
        glVertex2f(0.06f, 0.06f);
    glEnd();

    glColor3d(1.0f,0.0f,0.0f); ////floor
    glBegin(GL_POLYGON);
        glVertex2f(-0.155f, 0.06f);
        glVertex2f(-0.155f, 0.0175f);
        glVertex2f(0.055f, 0.0175f);
        glVertex2f(0.055f, 0.06f);
    glEnd();

    glTranslatef(0.028f, 0.0175f, 0.0f); //// Wheel 1
    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {
            glColor3ub(51, 51, 51);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.02;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

glEnd();

    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {
            glColor3ub(100,100,100);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.013;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

glEnd();


    glTranslatef(-0.045f, 0.0f, 0.0f); //// Wheel 2
    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {
            glColor3ub(51, 51, 51);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.02;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

glEnd();

    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {
            glColor3ub(100,100,100);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.013;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

glEnd();

    glTranslatef(-0.1f, 0.005f, 0.0f); //// Wheel 3
    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {
            glColor3ub(51, 51, 51);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.03;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

glEnd();

    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {
            glColor3ub(100,100,100);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.023;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

glEnd();

glTranslatef(-0.1f, -0.025f, 0.0f);////////boggey1

glColor3d(0.0f,0.0f,0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.15f, 0.145f);
        glVertex2f(-0.15f, 0.0175f);
        glVertex2f(0.05f, 0.0175f);
        glVertex2f(0.05f, 0.145f);
    glEnd();

    glColor3d(1.0f,0.0f,0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.155f, 0.045f);
        glVertex2f(-0.155f, 0.0175f);
        glVertex2f(0.055f, 0.0175f);
        glVertex2f(0.055f, 0.045f);
    glEnd();

    glTranslatef(0.028f, 0.0175f, 0.0f); //// Wheel 1
    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {
            glColor3ub(51, 51, 51);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.02;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
glEnd();

    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {
            glColor3ub(100,100,100);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.013;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

glEnd();

    glTranslatef(-0.045f, 0.0f, 0.0f); //// Wheel 2
    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {
            glColor3ub(51, 51, 51);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.02;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

glEnd();

    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {
            glColor3ub(100,100,100);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.013;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
glEnd();

    glTranslatef(-0.065f, 0.0025f, 0.0f); //// Wheel 3
    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {
            glColor3ub(51, 51, 51);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.02;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

glEnd();

    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {
            glColor3ub(100,100,100);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.013;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

glEnd();

    glTranslatef(-0.045f, 0.0f, 0.0f); //// Whee4
    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {
            glColor3ub(51, 51, 51);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.02;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

glEnd();

    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {
            glColor3ub(100,100,100);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.013;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

glEnd();

glTranslatef(-0.09f, -0.025f, 0.0f);////////boggey2

glColor3d(0.0f,0.0f,0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.15f, 0.145f);
        glVertex2f(-0.15f, 0.0175f);
        glVertex2f(0.05f, 0.0175f);
        glVertex2f(0.05f, 0.145f);
    glEnd();

    glColor3d(1.0f,0.0f,0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.155f, 0.045f);
        glVertex2f(-0.155f, 0.0175f);
        glVertex2f(0.055f, 0.0175f);
        glVertex2f(0.055f, 0.045f);
    glEnd();

    glTranslatef(0.028f, 0.0175f, 0.0f); //// Wheel 1
    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {
            glColor3ub(51, 51, 51);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.02;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

glEnd();

    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {
            glColor3ub(100,100,100);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.013;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

glEnd();


    glTranslatef(-0.045f, 0.0f, 0.0f); //// Wheel 2
    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {
            glColor3ub(51, 51, 51);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.02;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

glEnd();

    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {
            glColor3ub(100,100,100);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.013;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

glEnd();


    glTranslatef(-0.065f, 0.0025f, 0.0f); //// Wheel 3
    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {
            glColor3ub(51, 51, 51);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.02;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

glEnd();

    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {
            glColor3ub(100,100,100);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.013;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

glEnd();

    glTranslatef(-0.05f, 0.0f, 0.0f); //// Whee4
    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {
            glColor3ub(51, 51, 51);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.02;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

glEnd();

    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {
            glColor3ub(100,100,100);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.013;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glTranslatef(-0.09f, -0.025f, 0.0f);////////boggey3

glColor3d(0.0f,0.0f,0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.15f, 0.145f);
        glVertex2f(-0.15f, 0.0175f);
        glVertex2f(0.05f, 0.0175f);
        glVertex2f(0.05f, 0.145f);
    glEnd();

    glColor3d(1.0f,0.0f,0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.155f, 0.045f);
        glVertex2f(-0.155f, 0.0175f);
        glVertex2f(0.055f, 0.0175f);
        glVertex2f(0.055f, 0.045f);
    glEnd();

    glTranslatef(0.028f, 0.0175f, 0.0f); //// Wheel 1
    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {
            glColor3ub(51, 51, 51);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.02;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

glEnd();

    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {
            glColor3ub(100,100,100);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.013;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

glEnd();


    glTranslatef(-0.045f, 0.0f, 0.0f); //// Wheel 2
    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {
            glColor3ub(51, 51, 51);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.02;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

glEnd();

    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {
            glColor3ub(100,100,100);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.013;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

glEnd();


    glTranslatef(-0.065f, 0.0025f, 0.0f); //// Wheel 3
    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {
            glColor3ub(51, 51, 51);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.02;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

glEnd();

    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {
            glColor3ub(100,100,100);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.013;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

glEnd();

    glTranslatef(-0.05f, 0.0f, 0.0f); //// Whee4
    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {
            glColor3ub(51, 51, 51);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.02;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

glEnd();

    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {
            glColor3ub(100,100,100);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.013;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();

    if(val == 9){
    glBegin(GL_TRIANGLES); //light
      glColor3f(1.0f,1.f,0.0f);
      glVertex2f(1.0f, 0.3f);
      glVertex2f(1.0f,  0.0f);
      glVertex2f(0.80f, 0.1f);
    glEnd();
   }

glPopMatrix();
glutSwapBuffers();
}


void railhover(){
    //rail-hover
    glLineWidth(4.0f);
    glBegin(GL_LINES);

    glColor3ub(100,150,200);
        //outline
        glVertex2f(-1.0f, -0.45f);
        glVertex2f(-0.9f, -0.09f);
        glVertex2f(-0.9f, -0.09f);
        glVertex2f(-0.5f, -0.09f);
        glVertex2f(-0.5f, -0.09f);
        glVertex2f(-0.4f, -0.45f);

        //vertical line
        glVertex2f(-0.9f, -0.09f);
        glVertex2f(-0.9f, -0.45f);
        glVertex2f(-0.77f, -0.09f);
        glVertex2f(-0.77f, -0.45f);
        glVertex2f(-0.62f, -0.09f);
        glVertex2f(-0.62f, -0.45f);
        glVertex2f(-0.5f, -0.09f);
        glVertex2f(-0.5f, -0.45f);

        //angular line
        glVertex2f(-0.9f, -0.45f);
        glVertex2f(-0.77f, -0.09f);
        glVertex2f(-0.77f, -0.45f);
        glVertex2f(-0.62f, -0.09f);
        glVertex2f(-0.62f, -0.45f);
        glVertex2f(-0.5f, -0.09f);

        glVertex2f(-0.9f, -0.09f);
        glVertex2f(-0.77f, -0.45f);
        glVertex2f(-0.77f, -0.09f);
        glVertex2f(-0.62f, -0.45f);
        glVertex2f(-0.62f, -0.09f);
        glVertex2f(-0.5f, -0.45f);
    glEnd();
}

void railrd(){
    //rail-roard
    glBegin(GL_POLYGON);
    glColor3ub(100,150,200);
        glVertex2f(-1.2f, -0.45f);
        glVertex2f(0.80f, -0.45f);
        glVertex2f(0.80f, -0.53f);
        glVertex2f(-1.2f, -0.53f);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0.0f, 0.7f, 0.0f);
        glVertex2f(1.20f, -0.45f);
        glVertex2f(1.20f, -0.53f);
        glVertex2f(0.548f, -0.53f);
        glVertex2f(0.548f, -0.45f);
    glEnd();

    glPushMatrix();
    glTranslatef(-0.2f,0.0f,0.0f);
    railhover();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.4f,0.0f,0.0f);
    railhover();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.0f,0.0f,0.0f);
    railhover();
    glPopMatrix();
}


void displayMor(){
    int val = 1;

    glPushMatrix();//train
    glTranslatef(0.0f,0.32f,0.0f);
	glScaled(1,0.5,1);
	glRotated(180,0,1,0);
    train(val);
    glPopMatrix();

    glPushMatrix();//railrd
    glTranslatef(-0.055f,0.48f,0.0f);
	glScaled(0.75,0.35,1);
    railrd();
    glPopMatrix();

}

void displayDay(){
    int val = 1;

    glPushMatrix();//train
    glTranslatef(0.0f,0.32f,0.0f);
	glScaled(1,0.5,1);
	glRotated(180,0,1,0);
    train(val);
    glPopMatrix();

    glPushMatrix();//railrd
    glTranslatef(-0.055f,0.48f,0.0f);
	glScaled(0.75,0.35,1);
    railrd();
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

            trainSpeed = 0.0f;

            break;
        case '1':

            break;
        case '2':

            break;
        case '3':

            break;
        case '4':

            break;
        case '5':

            break;
        case '6':

            break;
        case '7':

            break;
        case '8':

            break;

        case '9':
            trainSpeed = 0.09f;
            break;

        case 'D':
        case 'd':

            break;
        case 'M':
        case 'm':
            glutDisplayFunc(displayMor);
            break;
        case 'N':
        case 'n':

            break;

        glutPostRedisplay();
	}
}


int main(int argc, char** argv){
   glutInit(&argc, argv);
   glutInitWindowSize(1600,900);
   glutInitWindowPosition(150,80);
   glutCreateWindow("Train");
   gluOrtho2D(-2, 2, -1, 1);
   glutDisplayFunc(info);
   glutKeyboardFunc(handleKeypress);
   glutTimerFunc(100, updateTrain, 0);
   initGL();
   glutIdleFunc(Idle);
   glutMainLoop();
   return 0;
}

