#include <GL/gl.h>
#include <GL/glut.h>
#include<math.h>
#include<Windows.h>
#define PI 3.14159265358979323846

void displayMor();
GLfloat x, y, radius, twicePi;
int triangleAmount; //sun
int rval = 0;
char play = '1';

void initGL(){
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
}

void Idle(){
    glutPostRedisplay();//// marks the current window as needing to be redisplayed
}

void automated_mor(int val){
    glutDisplayFunc(displayMor);
}


GLfloat boatPosition = 0.0f;
GLfloat boatSpeed = 0.01f;
void updateBoat(int value) {

    if(boatPosition > 1.45)
        {
            boatPosition = 0;
        }
    boatPosition += boatSpeed;

	glutPostRedisplay();

	glutTimerFunc(100, updateBoat,100);
}

void circleSolid(float x, float y, float radius){
	int triangleAmount = 100; //# of triangles used to draw circle

	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
        {
            glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
		}
    glEnd();
}


void boat(int vehicle){
    glPushMatrix();
    glTranslatef(boatPosition,0.0f, 0.0f);
    if (vehicle == 1)
        glColor3ub(255,110,0);
    if (vehicle == 2)
        glColor3ub(112,36,104);
    glBegin(GL_POLYGON);
    glVertex2f(-0.69f, -0.30f);
    glVertex2f(-0.62f, -0.30f);
    glVertex2f(-0.58f, -0.24f);
    glVertex2f(-0.73f, -0.24f);
    glEnd();

    //stick
    glColor3ub(160,82,35);
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2f(-0.65,-0.24);
    glVertex2f(-0.65,-0.1);
    glEnd();

    glColor3ub(255,255,255);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.655,-0.13);
    glVertex2f(-0.655,-0.24);
    glVertex2f(-0.71,-0.24);
    glEnd();

    glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
    glVertex2f(-0.648,-0.08);
    glVertex2f(-0.648,-0.24);
    glVertex2f(-0.59,-0.24);
    glVertex2f(-0.59,-0.18);
    glVertex2f(-0.6,-0.19);
    glVertex2f(-0.61,-0.16);
    glVertex2f(-0.63,-0.12);
    glEnd();

    glPopMatrix();
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
    boat(2); //2
    glPopMatrix();




    //vehicles road
    glPushMatrix();
    glTranslatef(0.0f,0.80f,0.0f);
    glScaled(1.5,1.4,1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f,0.30f,0.0f);
    glScaled(1.5,1.2,1);
    glPopMatrix();

    if(rval == 1){
        glPushMatrix();
        glPointSize(2.0);
        glPopMatrix();
    }
    glFlush();
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

            boatSpeed = 0.01f;
            break;

        case 'M':
        case 'm':
            glutDisplayFunc(displayMor);
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
   glutTimerFunc(100, updateBoat, 0);
   initGL();
   glutIdleFunc(Idle);
   glutMainLoop();
   return 0;
//return 0;
}
}

