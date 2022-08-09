//Group 10

//[20-44024-2]   KHALID SAIFULLAH



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

GLfloat position = -0.5f; //cloud1
GLfloat position1 = 0.5f; //cloud2
GLfloat speed = 0.02f;
//GLfloat speed1 = 0.02f;
GLfloat x, y, radius, twicePi;
int triangleAmount; //sun
int rval = 0;
char play = '1';

void initGL(){
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
}
void automated_mor(int val){
    glutDisplayFunc(displayMor);
}
void automated_day(int val){
    glutDisplayFunc(displayDay);
}
void automated_night(int val){
    glutDisplayFunc(displayNight);
}

void cloud2(int value){

    if(position1 > 1.0)
        position1 = -1.0f;

    position1 += speed;

	glutPostRedisplay();


	glutTimerFunc(100, cloud2, 0);
}

void sun(int sval){
	x=-0.8f; y=0.85f; radius =0.1f;
	triangleAmount = 50;
	twicePi = 2.0f * PI;
	if(sval==1)
        glColor3ub(255, 224, 102);
    if(sval==8)
        glColor3ub(226, 148, 13);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
}

void moon(){
    // moon start
    x=-0.8f; y=0.85f; radius =0.1f;
	triangleAmount = 50;
	twicePi = 2.0f * PI;
	glColor3ub(255, 255, 204);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

}

void cloud(int val){

    // cloud 2
    glPushMatrix();
	glTranslatef(position1,0.0f, 0.0f);
	x=0.0f; y=0.9f; radius =.1f;
	triangleAmount = 50;
	twicePi = 2.0f * PI;

	if(val==1)
        glColor3ub(255, 255, 255);

    if(val==9)
        glColor3ub(110, 113, 115);

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	x=-0.1f; y=0.9f; radius =.07f;
	triangleAmount = 50;
	twicePi = 2.0f * PI;

	if(val==1)
        glColor3ub(255, 255, 255);

    if(val==9)
        glColor3ub(110, 113, 115);

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	glPopMatrix();
}

int frameNumber = 0; //windmill
void doFrame(int v){ //windmill rotate
    frameNumber++;
    glutPostRedisplay();
    glutTimerFunc(30,doFrame,0);
}

void hill(int val){

    glBegin(GL_POLYGON);      //Hill_back

    if(val==1)
        glColor3f(0.0f, 0.3f, 0.0f);

    if(val==9)
        glColor3f(0.03f, 0.23f, 0.02f);

        glVertex2f(-1.0f, 0.4f);
        glVertex2f(-1.0f, 0.7f);
        glVertex2f(0.9f, 0.75f);
        glVertex2f(0.7f, 0.43f);
        glVertex2f(-0.4f, 0.78f);
        glVertex2f(-0.1f, 0.86f);
        glVertex2f(0.5f, 0.65f);
        glVertex2f(0.9f, 0.73f);
        glVertex2f(1.0f, 0.7f);
        glVertex2f(1.0f, 0.4f);

    glEnd();

    glBegin(GL_POLYGON);      //Hill_back_shadow

     if(val==1)
        glColor3f(0.0f, 0.5f, 0.0f);

    if(val==9)
        glColor3f(0.0f, 0.4f, 0.0f);

        glVertex2f(-1.0f, 0.4f);
        glVertex2f(-1.0f, 0.7f);
        glVertex2f(-0.9f, 0.75f);
        glVertex2f(-0.7f, 0.73f);
        glVertex2f(-0.4f, 0.78f);
        glVertex2f(-0.1f, 0.86f);
        glVertex2f(0.0f, 0.75f);
        glVertex2f(-0.2f, 0.7f);
        glVertex2f(-0.35f, 0.4f);

    glEnd();

    glBegin(GL_POLYGON);      //Hill_second_left

    if(val==1)
        glColor3f(0.0f, 0.5f, 0.0f);

    if(val==9)
        glColor3f(0.04f, 0.29f, 0.02f);

        glVertex2f(-0.6f, 0.4f);
        glVertex2f(-0.4f, 0.55f);
        glVertex2f(-0.2f, 0.6f);
        glVertex2f(-0.15f, 0.55f);
        glVertex2f(0.0f, 0.50f);
        glVertex2f(0.15f, 0.53f);
        glVertex2f(0.3f, 0.4f);

    glEnd();

    glBegin(GL_POLYGON);      //Hill_second_left_shadow

    if(val==1)
        glColor3f(0.0f, 0.7f, 0.0f);

    if(val==9)
        glColor3f(0.0f, 0.52f, 0.0f);

        glVertex2f(-0.6f, 0.4f);
        glVertex2f(-0.4f, 0.4f);
        glVertex2f(-0.4f, 0.45f);
        glVertex2f(-0.38f, 0.47f);

        glVertex2f(-.29f, 0.5f);
        glVertex2f(-0.4f, 0.55f);
        glVertex2f(-0.2f, 0.6f);

    glEnd();
}

void hill3rd(int val){
    glBegin(GL_POLYGON);      //Hill_third_right

    if(val==1)
        glColor3f(0.0f, 0.5f, 0.0f);

    if(val==9)
       glColor3f(0.04f, 0.29f, 0.02f);


        glVertex2f(0.35f, 0.4f);
        glVertex2f(0.45f, 0.5f);
        glVertex2f(0.77f, 0.61f);
        glVertex2f(.83f, 0.49f);
        glVertex2f(1.0f, 0.4f);


    glEnd();

    glBegin(GL_POLYGON);      //Hill_third_right_shadow

    if(val==1)
        glColor3f(0.0f, 0.7f, 0.0f);

    if(val==9)
        glColor3f(0.0f, 0.52f, 0.0f);


        glVertex2f(0.35f, 0.4f);
        glVertex2f(0.45f, 0.5f);
        glVertex2f(0.77f, 0.61f);
        glVertex2f(0.6f, 0.58f);
        glVertex2f(0.5f, 0.56f);
        glVertex2f(0.55f, 0.5f);
        glVertex2f(0.57f, 0.45f);
        glVertex2f(0.59f, 0.4f);

    glEnd();
}

void sky(int val){ //change color

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)

    glBegin(GL_POLYGON);        //sky

    if(val==1){
        glColor3ub(245, 146, 47);
        glVertex2f(-1.0f, 1.0f);

        glColor3ub(138, 105, 14);
        glVertex2f( 1.0f, 1.0f);

        glColor3ub(138, 67, 46);
        glVertex2f( 1.0f, 0.5f);

        glColor3ub(235, 158, 59);
        glVertex2f(-1.0f, 0.5f);
    }

    if(val==8){
        glColor3ub(193, 214, 58);
        glVertex2f(-1.0f, 1.0f);

        glColor3ub(214, 170, 24);
        glVertex2f( 1.0f, 1.0f);

        glColor3ub(27, 191, 164);
        glVertex2f( 1.0f, 0.5f);

        glColor3ub(94, 190, 209);
        glVertex2f(-1.0f, 0.5f);
    }

    if(val==9){
        glColor3ub(28,142,255);
        glVertex2f(-1.0f, 1.0f);

        glColor3ub(18,8,54);
        glVertex2f( 1.0f, 1.0f);

        glColor3ub(18,8,54);
        glVertex2f( 1.0f, 0.5f);

        glColor3ub(18,8,54);
        glVertex2f(-1.0f, 0.5f);
    }

    glEnd();
}

void windmill(int val){ //change
    int i;

    if(val==1)
        glColor3f(0.8f, 0.8f, 0.9f);

    if(val==9)
        glColor3f(0.40f, 0.45f, 0.53f);

	glBegin(GL_POLYGON);
	glVertex2f(-0.05f, 0);
	glVertex2f(0.05f, 0);
	glVertex2f(0.05f, 3);
	glVertex2f(-0.05f, 3);
	glEnd();
	glTranslatef(0, 3, 0);
	glRotated(frameNumber * (180.0/46), 0, 0, 1);

	if(val==1)
        glColor3f(0.4f, 0.4f, 0.8f);

    if(val==9)
        glColor3f(0.16f, 0.12f, 0.30f);

	for (i = 0; i < 3; i++)
        {
            glRotated(120, 0, 0, 1);
            glBegin(GL_POLYGON);
            glVertex2f(0,0);
            glVertex2f(0.5f, 0.1f);
            glVertex2f(1.5f,0);
            glVertex2f(0.5f, -0.1f);
            glEnd();
        }
}



void displayMor(){
    int val = 1;

    sky(val);
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(-0.37f,0.043f,0.0f);
    glScaled(0.5,0.8,1);
    sun(val);
    glPopMatrix();
    cloud(val);
    glPushMatrix();
    glTranslatef(0.0f,-0.15f,0.0f);
    glScalef(1.0f,1.15f,0.0f);
    hill(val);
    glPopMatrix();

	glPopMatrix();
	glPushMatrix(); //Windmill 3
	glTranslated(-0.35,0.40,0);
	glScaled(0.13,0.12,1);
	windmill(val);
	glPopMatrix();
	glPushMatrix(); //Windmill 4
	glTranslated(-0.60,0.31,0);
	glScaled(0.13,0.15,1);
	windmill(val);
	glPopMatrix();


    glPushMatrix(); //hill part
    glTranslatef(0.0f,-0.15f,0.0f);
    glScaled(1,1.15,1);
    hill3rd(val);
    glPopMatrix();


    if(rval == 1){
        glPushMatrix();
        glPointSize(2.0);

        glPopMatrix();
    }

    glFlush();
    glutTimerFunc(2500,automated_day,0);
}

void displayDay(){
    int val = 1;

    sky(8);
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(-0.37f,0.14f,0.0f);
    glScaled(0.5,0.8,1);
    sun(8);
    glPopMatrix();
    cloud(val);
    glPushMatrix();
    glTranslatef(0.0f,-0.15f,0.0f);
    glScalef(1.0f,1.15f,0.0f);
    hill(val);
    glPopMatrix();

	glPopMatrix();
	glPushMatrix(); //Windmill 3
	glTranslated(-0.35,0.40,0);
	glScaled(0.13,0.12,1);
	windmill(val);
	glPopMatrix();
	glPushMatrix(); //Windmill 4
	glTranslated(-0.60,0.31,0);
	glScaled(0.13,0.15,1);
	windmill(val);
	glPopMatrix();


    glPushMatrix(); //hill part
    glTranslatef(0.0f,-0.15f,0.0f);
    glScaled(1,1.15,1);
    hill3rd(val);
    glPopMatrix();


    if(rval == 1){
        glPushMatrix();
        glPointSize(1.5);

        glPopMatrix();
    }



    glFlush();
    glutTimerFunc(2500,automated_night,0);
}

void displayNight(){
    int val = 9;

    sky(val);
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(0.95f,0.10f,0.0f);
    glScaled(0.5,0.8,1);
    moon();
    glPopMatrix();
    cloud(val);
    glPushMatrix();
    glTranslatef(0.0f,-0.15f,0.0f);
    glScalef(1.0f,1.15f,0.0f);
    hill(val);
    glPopMatrix();

	glPushMatrix(); //Windmill 3
	glTranslated(-0.35,0.40,0);
	glScaled(0.13,0.12,1);
	windmill(val);
	glPopMatrix();
	glPushMatrix(); //Windmill 4
	glTranslated(-0.60,0.31,0);
	glScaled(0.13,0.15,1);
	windmill(val);
	glPopMatrix();



    glPushMatrix(); //hill part
    glTranslatef(0.0f,-0.15f,0.0f);
    glScaled(1,1.15,1);
    hill3rd(val);
    glPopMatrix();



    if(rval == 1){
        glPushMatrix();
        glPointSize(1.5);

        glPopMatrix();
    }


    glFlush();
    glutTimerFunc(2500,automated_mor,0);
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

        case 'X':
            glutDisplayFunc(displayMor);
            break;

        case 'd':
            glutDisplayFunc(displayDay);
            break;

        case 'm':
            glutDisplayFunc(displayMor);
            break;

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
   glutCreateWindow("AWS ENERGY PLANT");
   gluOrtho2D(-2, 2, -1, 1);
   glutDisplayFunc(info);
   glutKeyboardFunc(handleKeypress);

   glutTimerFunc(200, cloud2, 0);
   glutTimerFunc(200, doFrame,0);

   initGL();
   glutMainLoop();
   return 0;
}




