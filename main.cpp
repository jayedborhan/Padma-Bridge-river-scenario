#include<cstdio>
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

GLfloat positionBridgeCar1 = 0.8f;
GLfloat speedBridgeCar1 = 0.2f;
void updateBridgeCar1(int value){ //1
    if(positionBridgeCar1 < -7.7)
    {
        positionBridgeCar1 = 4.1f;
    }
    positionBridgeCar1 -= speedBridgeCar1;
	glutPostRedisplay();
	glutTimerFunc(100, updateBridgeCar1, 0);
}
GLfloat positionBridgeCar2 = -5.0f;
GLfloat speedBridgeCar2 = 0.08f;
void updateBridgeCar2(int value){ //2

    if(positionBridgeCar2 > 4.0)
        positionBridgeCar2 = -8.2f;

    positionBridgeCar2 += speedBridgeCar2;
	glutPostRedisplay();
	glutTimerFunc(100, updateBridgeCar2, 0);
}

void bridgeCar1(int val){
    glPushMatrix();

    glTranslatef(positionBridgeCar1,0.0f, 0.0f);
    float angle;
    float radius = 0.15f, r=0.10f;
    float x1,y1, x2,y2, a1,b1, a2,b2;

    x1 = -0.3f;
    y1 = -0.15f;
    a1 = 0.18f;
    b1 = -0.15f;

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(x1,y1);
    for(angle = 0.0f; angle<360.0f; angle+=0.1)
        {
            x2 = x1+sin(angle)*radius;
            y2 = y1+cos(angle)*radius;
            glVertex2f(x2,y2);
        }
    glEnd();
    x1 = -0.3f;
    y1 = -0.15f;
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(x1,y1);
    for(angle = 0.0f; angle<360.0f; angle+=0.1)
        {
            x2 = x1+sin(angle)*r;
            y2 = y1+cos(angle)*r;
            glVertex2f(x2,y2);
        }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(a1,b1);
    for(angle = 0.0f; angle<360.0f; angle+=0.1)
        {
            a2 = a1+sin(angle)*radius;
            b2 = b1+cos(angle)*radius;
            glVertex2f(a2,b2);
        }
    glEnd();
    a1 = 0.18f;
    b1 = -0.15f;
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(a1,b1);
    for(angle = 0.0f; angle<360.0f; angle+=0.1)
        {
            a2 = a1+sin(angle)*r;
            b2 = b1+cos(angle)*r;
            glVertex2f(a2,b2);
        }
   glEnd();
   glBegin(GL_POLYGON);
      glColor3f(0.22f,0.24f,0.25f);
      glVertex2f( 0.4f,-0.2f);
      glVertex2f( 0.4f, 0.3f);
      glVertex2f(-0.1f, 0.3f);
      glVertex2f(-0.5f, 0.0f);
      glVertex2f(-0.5f,-0.2f);
   glEnd();
   glBegin(GL_QUADS);
      glColor3f(0.42f,0.41f,0.46f);
      glVertex2f(-0.080f, 0.280f);
      glVertex2f( 0.371f, 0.280f);
      glVertex2f( 0.371f, -0.00f);
      glVertex2f(-0.080f, -0.00f);

      glColor3f(0.25f, 0.24f, 0.26f);
      glVertex2f(-0.460f,-0.03f);
      glVertex2f(-0.460f,-0.16f);
      glVertex2f( 0.371f,-0.16f);
      glVertex2f( 0.371f,-0.03f);
   glEnd();
   glBegin(GL_TRIANGLES);
      glColor3f(0.42f,0.41f,0.46f);
      glVertex2f(-0.090f, 0.0f);
      glVertex2f(-0.090f, 0.28f);
      glVertex2f(-0.460f, 0.0f);
   glEnd();

   if(val == 9){
    glBegin(GL_TRIANGLES); //light
      glColor3f(1.0f,1.f,0.0f);
      glVertex2f(-0.75f, -0.3f);
      glVertex2f(-0.80f,  0.0f);
      glVertex2f(-0.450f, -0.1f);
    glEnd();
   }


glPopMatrix();

}

void bridgeCar2(int val){
    glPushMatrix();
    glTranslatef(positionBridgeCar2,0.0f, 0.0f);

   glBegin(GL_POLYGON);
      glColor3f(1.0f, 0.0f, 0.0f);
      glVertex2f(-0.1f, 0.3f);
      glVertex2f(0.4f, 0.3f);
      glVertex2f(0.5f, 0.2f);
      glVertex2f(0.7f, 0.2f);
      glVertex2f(0.7f, 0.0f);
      glVertex2f(-0.3f, 0.0f);
      glVertex2f(-0.3f, 0.2f);
      glVertex2f(-0.2f, 0.2f);
   glEnd();

   glBegin(GL_POLYGON);
      glColor3f(0.0f, 0.0f, 0.0f);
      glVertex2f(0.1f, 0.28f);
      glVertex2f(0.4f, 0.28f);
      glVertex2f(0.45f, 0.22f);
      glVertex2f(0.1f, 0.22f);
    glEnd();

    glBegin(GL_POLYGON);
      glColor3f(0.0f, 0.0f, 0.0f);
      glVertex2f(-0.1f, 0.28f);
      glVertex2f(0.05f, 0.28f);
      glVertex2f(0.05f, 0.22f);
      glVertex2f(-0.15f, 0.22f);
    glEnd();

     glBegin(GL_POLYGON);       //tube light
      glColor3f(1.0f, 1.0f, 0.0f);
      glVertex2f(0.6f, 0.15f);
      glVertex2f(0.7f, 0.15f);
      glVertex2f(0.7f, 0.1f);
      glVertex2f(0.6f, 0.1f);
    glEnd();

    float t1_angle;        //tire 1
    float t1_radius = 0.1;
    float t1_x,t1_y, t1_p, t1_q;

    t1_x = -0.1f;
    t1_y = 0.0f;

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 1.0f);

    glVertex2f(t1_x, t1_y);
    for(t1_angle = 0.0f; t1_angle<360.0f; t1_angle++){
        t1_p = t1_x+sin(t1_angle)*t1_radius;
        t1_q = t1_y+cos(t1_angle)*t1_radius;

        glVertex2f(t1_p,t1_q);
    }
    glEnd();

    float i1_angle;        //tire 1 inside
    float i1_radius = 0.07;
    float i1_x,i1_y, i1_p, i1_q;

    i1_x = -0.1f;
    i1_y = 0.0f;

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(i1_x,i1_y);
    for(i1_angle = 0.0f; i1_angle<360.0f; i1_angle++){
        i1_p = i1_x+sin(i1_angle)*i1_radius;
        i1_q = i1_y+cos(i1_angle)*i1_radius;

        glVertex2f(i1_p,i1_q);
    }
    glEnd();

    float t2_angle;        //tire 2
    float t2_radius = 0.1;
    float t2_x,t2_y, t2_p, t2_q;

    t2_x = 0.4f;
    t2_y = 0.0f;

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 1.0f);

    glVertex2f(t2_x,t2_y);
    for(t2_angle = 0.0f; t2_angle<360.0f; t2_angle++){
        t2_p = t2_x+sin(t2_angle)*t2_radius;
        t2_q = t2_y+cos(t2_angle)*t2_radius;
        glVertex2f(t2_p,t2_q);
    }
    glEnd();

    float i2_angle;        //tire 2 inside
    float i2_radius = 0.07;
    float i2_x,i2_y, i2_p, i2_q;

    i2_x = 0.4f;
    i2_y = 0.0f;

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(i2_x,i2_y);
    for(i2_angle = 0.0f; i2_angle<360.0f; i2_angle++){
        i2_p = i2_x+sin(i2_angle)*i2_radius;
        i2_q = i2_y+cos(i2_angle)*i2_radius;

        glVertex2f(i2_p,i2_q);
    }
    glEnd();
    if(val == 9){
    glBegin(GL_TRIANGLES); //light
      glColor3f(1.0f,1.f,0.0f);
      glVertex2f(0.95f,  0.2f);
      glVertex2f(0.69f,  0.12f);
      glVertex2f(0.95f,  -0.03f);
    glEnd();
   }
    glPopMatrix();
}
void bridgeTop(){
    glBegin(GL_POLYGON);
    glColor3ub (150, 161, 177);
        glVertex2f(0.60f, -0.10f);
        glVertex2f(0.60f, -0.15f);
        glVertex2f(-1.0f, 0.15f);
        glVertex2f(-1.0f, 0.20f);
    glEnd();
}

void bridgeSupport(){
    glBegin(GL_POLYGON);
    glColor3ub (70,87,112);
        glVertex2f(-1.0f, 0.15f);
        glVertex2f(-1.0f, 0.12f);
        glVertex2f(-0.835f, 0.042f);
        glVertex2f(-0.785f, 0.042f);
        glVertex2f(-0.6f, 0.043f);
        glVertex2f(-0.6f, 0.075f);
    glEnd();
}

void bridgePillers(){
    glBegin(GL_QUADS);
    glColor3ub (40,58,84);
        glVertex2f(-0.835f,  0.042f);
        glVertex2f(-0.835f, -0.275f);
        glVertex2f(-0.810f, -0.300f);
        glVertex2f(-0.810f,  0.042f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub (50,75,111);
        glVertex2f(-0.810f,  0.042f);
        glVertex2f(-0.810f, -0.300f);
        glVertex2f(-0.785f, -0.275f);
        glVertex2f(-0.785f,  0.042f);
    glEnd();
}

void bridge(){
    bridgeTop();
    glPushMatrix();
    glTranslatef(0.0f,0.005f,0.0f);
    bridgeSupport();
    bridgePillers();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.1994f,-0.22f,0.0f);
    bridgeSupport();
    glTranslatef(0.0f,0.026f,0.0f);
    glScaled(1,0.38,1);
    bridgePillers();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.8f,-0.145f,0.0f);
    bridgeSupport();
    glTranslatef(0.0f,0.019f,0.0f);
    glScaled(1,0.58,1);
    bridgePillers();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.4f,-0.069f,0.0f);
    bridgeSupport();
    glTranslatef(0.0f,0.011f,0.0f);
    glScaled(1,0.79,1);
    bridgePillers();

    glPopMatrix();
}
void lampPost_panel(int val){ //for bridge


//right panel

    glBegin(GL_POLYGON);
    glColor3f(0.36f, 0.39f, 0.44f);

        glVertex2f(0.0f, 0.2f);
        glVertex2f(0.05f, 0.2f);
        glVertex2f(0.05f, -0.9f);
        glVertex2f(0.0f, -0.9f);

    glEnd();

    ////////////////////////////

//joint
    glBegin(GL_POLYGON);
    glColor3f(0.36f, 0.39f, 0.44f);

        glVertex2f(0.05f, 0.2f);
        glVertex2f(0.0f, 0.2f);
        glVertex2f(0.05f, 0.3f);
        glVertex2f(0.1f, 0.3f);

    glEnd();

    /////////////////////////////////////////

//tube_holder
    ////////////////

    glBegin(GL_POLYGON);
    glColor3f(0.36f, 0.39f, 0.44f);

        glVertex2f(0.05f, 0.25f);
        glVertex2f(0.05f, 0.3f);
        glVertex2f(0.55f, 0.3f);
        glVertex2f(0.55f, 0.25f);

    glEnd();

    ////////////////////////////////

//tube

    glBegin(GL_POLYGON);
    glColor3f(0.29f, 0.20f, 0.23f);

        glVertex2f(0.55f, 0.25f);
        glVertex2f(0.6f, 0.2f);
        glVertex2f(0.1f, 0.2f);
        glVertex2f(0.15f, 0.25f);

    glEnd();

    /////////////////////////////////

    //night light
    if(val == 9){
     glBegin(GL_POLYGON);
        glColor4f(1.0f, 1.0f, 0.0f, 5.0f);
        glVertex2f(0.6f, 0.2f);
        glVertex2f(0.1f, 0.2f);
        glVertex2f(0.15f, 0.15f);
        glVertex2f(0.55f, 0.15f);
     glEnd();
    }
}

void borders(){
    glBegin(GL_QUADS); //border
        glColor3ub(200, 204, 210);
        glVertex2f(-1.0f, 0.95f);
        glVertex2f(-1.0f, 1.0f);
        glVertex2f( 1.0f, 1.0f);
        glVertex2f( 1.0f, 0.95f);

        glVertex2f(-1.0f, -0.95f);
        glVertex2f(-1.0f, -1.0f);
        glVertex2f( 1.0f, -1.0f);
        glVertex2f( 1.0f, -0.95f);

        glVertex2f(-1.00f,  1.0f);
        glVertex2f(-0.97f,  1.0f);
        glVertex2f(-0.97f, -1.0f);
        glVertex2f(-1.00f, -1.0f);

        glVertex2f(1.00f,  1.0f);
        glVertex2f(0.97f,  1.0f);
        glVertex2f(0.97f, -1.0f);
        glVertex2f(1.00f, -1.0f);

        glColor3ub(111, 118, 131);
        glVertex2f(-0.97f,  0.95f);
        glVertex2f(-0.96f,  0.95f);
        glVertex2f(-0.96f, -0.95f);
        glVertex2f(-0.97f, -0.95f);

        glColor3ub(111, 118, 131);
        glVertex2f(0.97f,  0.95f);
        glVertex2f(0.96f,  0.95f);
        glVertex2f(0.96f, -0.95f);
        glVertex2f(0.97f, -0.95f);

        glColor3ub(111, 118, 131);
        glVertex2f(-0.97f,  0.95f);
        glVertex2f( 0.97f,  0.95f);
        glVertex2f( 0.97f,  0.94f);
        glVertex2f(-0.97f,  0.94f);

        glColor3ub(111, 118, 131);
        glVertex2f(-0.97f,  -0.95f);
        glVertex2f( 0.97f,  -0.95f);
        glVertex2f( 0.97f,  -0.94f);
        glVertex2f(-0.97f,  -0.94f);
    glEnd();
}


void displayMor(){
    int val = 1;


    glLoadIdentity();
    glPushMatrix();
    glTranslatef(-0.37f,0.043f,0.0f);
    glScaled(0.5,0.8,1);

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f,-0.15f,0.0f);
    glScalef(1.0f,1.15f,0.0f);

    glPopMatrix();

	glPopMatrix();
	glPushMatrix(); //Windmill 3
	glTranslated(-0.35,0.40,0);
	glScaled(0.13,0.12,1);

	glPopMatrix();
	glPushMatrix(); //Windmill 4
	glTranslated(-0.60,0.31,0);
	glScaled(0.13,0.15,1);

	glPopMatrix();

	glPushMatrix();//bridge
    glTranslatef(-0.055f,0.55f,0.0f);
	glScaled(1.4,0.9,1);
	glRotated(50, 0,1,0);
	bridge();
    glPopMatrix();

    glPushMatrix();//bridgeCar2
    glTranslated(0,0.55,0);
	glScaled(0.12,0.18,0);
	glRotatef(-8,0.5f,0.0f,1.0f);
    bridgeCar2(val);
    glPopMatrix();
    glPushMatrix();//bridgeCar1
    glTranslated(0,0.545,0);
	glScaled(0.13,0.125,0);
	glRotatef(-13,0.5f,0.0f,1.0f);
    bridgeCar1(val);
    glPopMatrix();

    glPushMatrix();//lampost
    glLineWidth(1);
    glTranslatef(0.15f,0.6f,0.0f);
	glScaled(0.13,0.13,1);
	lampPost_panel(val);
    glPopMatrix();
    glPushMatrix();//lampost
    glLineWidth(1);
    glTranslatef(-0.24f,0.68f,0.0f);
	glScaled(0.14,0.14,1);
	lampPost_panel(val);
    glPopMatrix();

    glPushMatrix();//train
    glTranslatef(0.0f,0.32f,0.0f);
	glScaled(1,0.5,1);
	glRotated(180,0,1,0);

    glPopMatrix();

    glPushMatrix();//railrd
    glTranslatef(-0.055f,0.48f,0.0f);
	glScaled(0.75,0.35,1);

    glPopMatrix();

    glPushMatrix(); //hill part
    glTranslatef(0.0f,-0.15f,0.0f);
    glScaled(1,1.15,1);

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.741f,0.32f,0.0f);
    glScaled(0.3,0.25,1);

    glPopMatrix();


    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0f,0.40f,0.0f);
    glScaled(1.8,1.5,1);

    glPopMatrix();

    //lights road
    glPushMatrix();//lampost
    glLineWidth(1);
    glTranslatef(0.7f,-0.08f,0.0f);
	glScaled(0.3,0.3,1);

    glPopMatrix();
    glPushMatrix();//lampost
    glLineWidth(1);
    glTranslatef(0.0f,-0.08f,0.0f);
	glScaled(0.3,0.3,1);

    glPopMatrix();
    glPushMatrix();//lampost
    glLineWidth(1);
    glTranslatef(-0.7f,-0.08f,0.0f);
	glScaled(0.3,0.3,1);

    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.33f,0.14f,0.0f);
    glScaled(0.4,0.7,1);

    glTranslatef(1.73f,0.0f,0.0f);

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


 borders();

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
            speedBridgeCar1 = 0.0f;
            speedBridgeCar2 = 0.0f;




            break;
        case '1':
            speedBridgeCar1 = 0.20f;
            break;
        case '2':
            speedBridgeCar2 = 0.20f;
            break;
        case '3':

            break;
        case '4':

            break;
        case '5':

            break;
        case '6':

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
   glutCreateWindow("PADMA BRIDGE SCENARIO");
   gluOrtho2D(-2, 2, -1, 1);
   glutDisplayFunc(info);
   glutKeyboardFunc(handleKeypress);
   glutTimerFunc(100, updateBridgeCar1, 0);
   glutTimerFunc(100, updateBridgeCar2, 0);


   initGL();
   glutMainLoop();
   return 0;
}


