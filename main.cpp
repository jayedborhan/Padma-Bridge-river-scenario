/*Group 01
[20-43400-1]    S.M. Nowshan Al-Nahian Pavel
[20-43391-1]    Abu Sakib Molla
[20-43337-1]    Parthib Banik
[20-43405-1]    S.M. Kamrul Hasan Koche

Instructions:
	"Automated Morning-Day-Night-Morning"
Press:
    'x'/'X' - Welcome menu will change to the Project Scenario
    'r'/'R' - Rain (with sound), press again, rain will stop.
    '0'     - Stop All The Moving Vehicles
    '1'     - Car 1(Black van on Bridge) Starts Moving
    '2'     - Car 2(Red Car on Bridge) Starts Moving
    '3'     - Car 3(Dark Red Car on Road) Starts Moving
    '5'     - Truck Starts Moving
    '7'     - Ships Start Moving
    '9'     - Train Start Moving

Click:
    'LMB'   - Sound On
    'RMB'   - Sound Off
*/


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

void Idle(){
    glutPostRedisplay();//// marks the current window as needing to be redisplayed
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

void soundTrain(){
    PlaySound("train.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
}

void soundRain(){
    PlaySound("rain.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
}
void soundCar(){
    PlaySound("car.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
}
void soundTruck(){
    PlaySound("truck.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
}
void soundWave(){
    PlaySound("wave.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
}

void soundNull(){
    PlaySound(NULL, NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
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

GLfloat position_rain = 0.0f; // for rain
GLfloat speed_rain = 0.05f;
GLfloat position_rain2 = 2.0f; // for rain
GLfloat speed_rain2 = 0.05f;

void update_rain(int value) {
    if(position_rain < -0.1)
        position_rain = 0.3f;

    position_rain -= speed_rain;

    if(position_rain2 > 2.0)
        position_rain2 = 1.8f;

    position_rain2 += speed_rain2;

	glutPostRedisplay();
	glutTimerFunc(100, update_rain, 0);
}

void rain(){
    glPushMatrix();
    glTranslatef(position_rain2, position_rain, 0.0f);
    glLineWidth(2.0f);
    glBegin(GL_LINES);
        glColor3ub(255, 255, 255);
        glVertex2f(0.0f, 0.9f);
        glVertex2f(0.05f, 0.85f);
    glEnd();
    glBegin(GL_LINES);
        glColor3ub(255, 255, 255);
        glVertex2f(0.0f, 0.7f);
        glVertex2f(0.05f, 0.65f);
    glEnd();
    glBegin(GL_LINES);
        glColor3ub(255, 255, 255);
        glVertex2f(0.0f, 0.5f);
        glVertex2f(0.05f, 0.45f);
    glEnd();
    glBegin(GL_LINES);
        glColor3ub(255, 255, 255);
        glVertex2f(0.0f, 0.3f);
        glVertex2f(0.05f, 0.25f);
    glEnd();
    glBegin(GL_LINES);
        glColor3ub(255, 255, 255);
        glVertex2f(0.0f, 0.1f);
        glVertex2f(0.05f, 0.05f);
    glEnd();

    glBegin(GL_LINES);
        glColor3ub(255, 255, 255);
        glVertex2f(0.05f, -0.9f);
        glVertex2f(0.0f, -0.85f);
    glEnd();
    glBegin(GL_LINES);
        glColor3ub(255, 255, 255);
        glVertex2f(0.05f, -0.7f);
        glVertex2f(0.0f, -0.65f);
    glEnd();
    glBegin(GL_LINES);
        glColor3ub(255, 255, 255);
        glVertex2f(0.05f, -0.5f);
        glVertex2f(0.0f, -0.45f);
    glEnd();
    glBegin(GL_LINES);
        glColor3ub(255, 255, 255);
        glVertex2f(0.05f, -0.3f);
        glVertex2f(0.0f, -0.25f);
    glEnd();
    glBegin(GL_LINES);
        glColor3ub(255, 255, 255);
        glVertex2f(0.05f, -0.1f);
        glVertex2f(0.0f, -0.05f);
    glEnd();

    for(int i = 0; i < 100; i++) {
        glTranslatef(-0.2, 0.0, 0.0f);
        glBegin(GL_LINES);
            glColor3ub(255, 255, 255);
            glVertex2f(0.0f, 0.9f);
            glVertex2f(0.05f, 0.85f);
        glEnd();
        glBegin(GL_LINES);
            glColor3ub(255, 255, 255);
            glVertex2f(0.0f, 0.7f);
            glVertex2f(0.05f, 0.65f);
        glEnd();
        glBegin(GL_LINES);
            glColor3ub(255, 255, 255);
            glVertex2f(0.0f, 0.5f);
            glVertex2f(0.05f, 0.45f);
        glEnd();
        glBegin(GL_LINES);
            glColor3ub(255, 255, 255);
            glVertex2f(0.0f, 0.3f);
            glVertex2f(0.05f, 0.25f);
        glEnd();
        glBegin(GL_LINES);
            glColor3ub(255, 255, 255);
            glVertex2f(0.0f, 0.1f);
            glVertex2f(0.05f, 0.05f);
        glEnd();

        glBegin(GL_LINES);
            glColor3ub(255, 255, 255);
            glVertex2f(0.05f, -0.9f);
            glVertex2f(0.0f, -0.85f);
        glEnd();
        glBegin(GL_LINES);
            glColor3ub(255, 255, 255);
            glVertex2f(0.05f, -0.7f);
            glVertex2f(0.0f, -0.65f);
        glEnd();
        glBegin(GL_LINES);
            glColor3ub(255, 255, 255);
            glVertex2f(0.05f, -0.5f);
            glVertex2f(0.0f, -0.45f);
        glEnd();
        glBegin(GL_LINES);
            glColor3ub(255, 255, 255);
            glVertex2f(0.05f, -0.3f);
            glVertex2f(0.0f, -0.25f);
        glEnd();
        glBegin(GL_LINES);
            glColor3ub(255, 255, 255);
            glVertex2f(0.05f, -0.1f);
            glVertex2f(0.0f, -0.05f);
        glEnd();
    }

    for(int i = 0; i < 100; i++) {
        glTranslatef(0.2, 0.0, 0.0f);
        glBegin(GL_LINES);
            glColor3ub(255, 255, 255);
            glVertex2f(0.0f, 0.9f);
            glVertex2f(0.05f, 0.85f);
        glEnd();
        glBegin(GL_LINES);
            glColor3ub(255, 255, 255);
            glVertex2f(0.0f, 0.7f);
            glVertex2f(0.05f, 0.65f);
        glEnd();
        glBegin(GL_LINES);
            glColor3ub(255, 255, 255);
            glVertex2f(0.0f, 0.5f);
            glVertex2f(0.05f, 0.45f);
        glEnd();
        glBegin(GL_LINES);
            glColor3ub(255, 255, 255);
            glVertex2f(0.0f, 0.3f);
            glVertex2f(0.05f, 0.25f);
        glEnd();
        glBegin(GL_LINES);
            glColor3ub(255, 255, 255);
            glVertex2f(0.0f, 0.1f);
            glVertex2f(0.05f, 0.05f);
        glEnd();

        glBegin(GL_LINES);
            glColor3ub(255, 255, 255);
            glVertex2f(0.05f, -0.9f);
            glVertex2f(0.0f, -0.85f);
        glEnd();
        glBegin(GL_LINES);
            glColor3ub(255, 255, 255);
            glVertex2f(0.05f, -0.7f);
            glVertex2f(0.0f, -0.65f);
        glEnd();
        glBegin(GL_LINES);
            glColor3ub(255, 255, 255);
            glVertex2f(0.05f, -0.5f);
            glVertex2f(0.0f, -0.45f);
        glEnd();
        glBegin(GL_LINES);
            glColor3ub(255, 255, 255);
            glVertex2f(0.05f, -0.3f);
            glVertex2f(0.0f, -0.25f);
        glEnd();
        glBegin(GL_LINES);
            glColor3ub(255, 255, 255);
            glVertex2f(0.05f, -0.1f);
            glVertex2f(0.0f, -0.05f);
        glEnd();
    }
    glPopMatrix();
}

GLfloat positionBridgeCar2 = -5.0f;
GLfloat speedBridgeCar2 = 0.2f;
void updateBridgeCar2(int value){ //2

    if(positionBridgeCar2 > 4.0)
        positionBridgeCar2 = -8.2f;

    positionBridgeCar2 += speedBridgeCar2;
	glutPostRedisplay();
	glutTimerFunc(100, updateBridgeCar2, 0);
}

GLfloat trainPosition = 0.3f;
GLfloat trainSpeed = 0.09f;
void updateTrain(int value){ //9
    if(trainPosition > 1.5)
    {
        trainPosition = -0.4f;
    }
    trainPosition += trainSpeed;

    glutPostRedisplay();

    glutTimerFunc(100, updateTrain, 0);
}

GLfloat truckPosition = 0.0f;
GLfloat truckSpeed = 0.05f;
void updateTruck(int value){ //5
    if(truckPosition > 1.45)
    {
        truckPosition = -0.4f;
    }
    truckPosition += truckSpeed;

    glutPostRedisplay();

    glutTimerFunc(100, updateTruck, 0);
}

GLfloat boatPosition = 0.0f;
GLfloat boatSpeed = 0.03f;
void updateBoat(int value) {

    if(boatPosition > 1.45)
        {
            boatPosition = 0;
        }
    boatPosition += boatSpeed;

	glutPostRedisplay();

	glutTimerFunc(100, updateBoat, 0);
}

GLfloat carPosition = 0.0f;
GLfloat carSpeed = 0.05f;
void updateCar(int value){ //car utso
    if(carPosition < - 1.0)
    {
        carPosition = 0.6f;
    }
    carPosition -= carSpeed;

    glutPostRedisplay();

    glutTimerFunc(100, updateCar, 0);
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

    glColor3d(0.0f,0.0f,0.0f); /////Exhaust
    glBegin(GL_POLYGON);
        glVertex2f(0.03f, 0.2f);
        glVertex2f(0.03f, 0.15f);
        glVertex2f(-0.0f, 0.15f);
        glVertex2f(-0.0f, 0.2f);
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

void vehicleTruck(int val){//This is the truck
    glPushMatrix();
    glTranslatef(truckPosition,0.0f, 0.0f);

   //body
    glColor3ub(0,255,255);
    glBegin(GL_POLYGON);
    glVertex2f(-0.9f,-0.86f);
    glVertex2f(-0.68f, -0.86f);
    glVertex2f(-0.68f,-0.67f);
    glVertex2f(-0.9f,-0.67f);
    glEnd();

    //base of the truck
    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.9f,-0.86f);
    glVertex2f(-0.58f, -0.86f);
    glVertex2f(-0.58f,-0.9f);
    glVertex2f(-0.9f,-0.9f);
    glEnd();

    //front
    glColor3ub(240,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.67f,-0.86f);
    glVertex2f(-0.58f, -0.86f);
    glVertex2f(-0.58f,-0.79f);
    glVertex2f(-0.61f,-0.735f);
    glVertex2f(-0.67f,-0.735f);
    glEnd();

    //wheels
    glColor3ub(20,20,120);
    circleSolid(-0.84f,-0.88f,0.034);
    circleSolid(-0.64f,-0.88f,0.034);
    glColor3ub(130,130,130);
    circleSolid(-0.84f,-0.88f,0.02);
    circleSolid(-0.64f,-0.88f,0.02);

    //door
    glColor3ub(0,0,0);
    glLineWidth(5.0);
    glBegin(GL_LINES);
    glVertex2f(-.59619,-0.815);
    glVertex2f(-0.61,-0.815);
    glEnd();

    //window
    glColor3ub(153,206,250);
    glBegin(GL_POLYGON);
    glVertex2f(-0.66,-0.797);
    glVertex2f(-0.596,-0.797);
    glVertex2f(-0.596,-0.781);
    glColor3ub(100,149,237);
    glVertex2f(-0.615,-0.747);
    glVertex2f(-0.66,-0.747);
    glEnd();

    if(val == 9){
    glBegin(GL_TRIANGLES); //light
      glColor3f(1.0f,1.f,0.0f);
      glVertex2f(-0.4f, -0.9f);
      glVertex2f(-0.4f,  -0.8f);
      glVertex2f(-0.58f, -0.85f);
    glEnd();
    }

    glPopMatrix();
}

void vehicleCar(int val){//This is the car(utso)
    glPushMatrix();
    glTranslatef(carPosition,0.0f, 0.0f);
    //body
    glColor3ub(199, 0, 57 );
    glBegin(GL_POLYGON);
    glVertex2f(0.0f,-0.94f);
    glVertex2f(0.275f, -0.94f);
    glVertex2f(0.275f,-0.859f);
    glVertex2f(0.22f,-0.842f);
    glVertex2f(0.18f,-0.758f);
    glVertex2f(0.1f, -0.758f);
    glVertex2f(0.08f,-0.842f);
    glVertex2f(0.0f,-0.856f);
    glEnd();
    //wheels
    glColor3ub(103,13,124);
    circleSolid(0.07,-0.938,0.035);
    circleSolid(0.2,-0.938,0.035);
    //
    glColor3ub(0,0,0);
    glLineWidth(1.1);
    glBegin(GL_LINES);
    glVertex2f(0.141f,-0.758f);
    glVertex2f(0.141f,-0.842f);
    glEnd();
    //window
    glColor3ub(153,206,250);
    glBegin(GL_POLYGON);
    glVertex2f(0.071,-0.842);
    glVertex2f(0.132,-0.842);
    glColor3ub(100,149,237);
    glVertex2f(0.132,-0.77);
    glVertex2f(0.106,-0.77);
    glEnd();
    glColor3ub(153,206,250);
    glBegin(GL_POLYGON);
    glVertex2f(0.148,-0.842);
    glVertex2f(0.206,-0.842);
    glColor3ub(100,149,237);
    glVertex2f(0.173,-0.77);
    glVertex2f(0.148,-0.77);
    glEnd();
    //door
    glColor3ub(0,0,0);
    glLineWidth(5.0);
    glBegin(GL_LINES);
    glVertex2f(0.11,-0.863);
    glVertex2f(0.13,-0.863);
    glVertex2f(0.186,-0.863);
    glVertex2f(0.206,-0.863);
    glColor3ub(255,255,255);
    glEnd();

    if(val == 9){
    glBegin(GL_TRIANGLES); //light
      glColor3f(1.0f,1.f,0.0f);
      glVertex2f(-0.15f, -0.84f);
      glVertex2f(-0.15f,  -0.93f);
      glVertex2f(0.018f, -0.90f);
    glEnd();
    }

    glPopMatrix();
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

void cloud1(int value){

    if(position > 1.0)
        position = -1.0f;

    position += speed;

	glutPostRedisplay();


	glutTimerFunc(100, cloud1, 0);
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
    glPushMatrix();
	glTranslatef(position,0.0f, 0.0f);

	x=-0.0f; y=0.8f; radius =.1f;
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
	x=0.1f; y=0.8f; radius =.07f;
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
	x=-0.1f; y=0.8f; radius =.07f;
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
        glVertex2f(-0.9f, 0.75f);
        glVertex2f(-0.7f, 0.73f);
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

    //solar panel


    glBegin(GL_POLYGON);
    glColor3f(0.17f, 0.17f, 0.28f);

        glVertex2f(-0.45f, 0.38f);
        glVertex2f(0.45f, 0.38f);
        glVertex2f(0.55f, 0.63f);
        glVertex2f(-0.35f, 0.63f);

    glEnd();

//inside partition

    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);

        glVertex2f(-0.27f, 0.38f);
        glVertex2f(-0.17f, 0.63f);

    glEnd();

    glBegin(GL_LINES);
   glColor3f(1.0f, 1.0f, 1.0f);

        glVertex2f(-0.09f, 0.38f);
        glVertex2f(0.01f, 0.63f);

    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);

        glVertex2f(0.09f, 0.38f);
        glVertex2f(0.19f, 0.63f);

    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);

        glVertex2f(0.27f, 0.38f);
        glVertex2f(0.37f, 0.63f);

    glEnd();

    ////////////

    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);

        glVertex2f(-0.40f, 0.505f);
        glVertex2f(0.50f, 0.505f);

    glEnd();

    ///////////////////////

//sideBar
    glBegin(GL_POLYGON);
    glColor3f(0.5f, 0.4f, 0.0f);

        glVertex2f(0.55f, 0.63f);
        glVertex2f(0.60f, 0.58f);
        glVertex2f(0.50f, 0.33f);
        glVertex2f(0.45f, 0.38f);

    glEnd();
//downBar
    glBegin(GL_POLYGON);
    glColor3f(0.4f, 0.3f, 0.0f);

        glVertex2f(0.45f, 0.38f);
        glVertex2f(0.50f, 0.33f);
        glVertex2f(-0.40f, 0.33f);
        glVertex2f(-0.45f, 0.38f);

    glEnd();

    /////////////////////////////

//holder

    glBegin(GL_POLYGON);
        glColor3f(0.4f, 0.52f, 0.47f);

        glVertex2f(0.0f, 0.2f);
        glVertex2f(0.05f, 0.3f);
        glVertex2f(0.03f, 0.35f);
        glVertex2f(-0.09f, 0.35f);
    glEnd();

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

void windows(){
    glBegin(GL_QUADS); //
        glColor3ub(201, 192, 187);  //left_3rd
        glVertex2f(-0.96f,  0.94f);
        glVertex2f(-0.94f,  0.94f);
        glVertex2f(-0.94f, -0.94f);
        glVertex2f(-0.96f, -0.94f);

        glColor3ub(201, 192, 187);  //rest_body
        glVertex2f(-0.94f,  0.94f);
        glVertex2f(-0.88f,  0.94f);
        glVertex2f(-0.88f,  0.90f);
        glVertex2f(-0.94f,  0.90f);

        glVertex2f(-0.88f,  0.94f);
        glVertex2f(-0.78f,  0.92f);
        glVertex2f(-0.78f,  0.88f);
        glVertex2f(-0.88f,  0.90f);

        glVertex2f(-0.78f,  0.92f);
        glVertex2f(-0.77f,  0.92f);
        glVertex2f(-0.77f, -0.87f);
        glVertex2f(-0.78f, -0.81f);

        glVertex2f(-0.94f, -0.94f);
        glVertex2f(-0.77f, -0.87f);
        glVertex2f(-0.78f, -0.81f);
        glVertex2f(-0.94f, -0.87f);

        glVertex2f(-0.94f,  0.31f);
        glVertex2f(-0.77f,  0.34f);
        glVertex2f(-0.77f,  0.31f);
        glVertex2f(-0.94f,  0.27f);

        glVertex2f(-0.94f, -0.27f);
        glVertex2f(-0.77f, -0.20f);
        glVertex2f(-0.77f, -0.25f);
        glVertex2f(-0.94f, -0.31f);

        glVertex2f(-0.87f, 0.94f);
        glVertex2f(-0.845f,  0.94f);
        glVertex2f(-0.845f, -0.87f);
        glVertex2f(-0.87f,-0.87f);
    glEnd();

    //mirror
    glBegin(GL_QUADS);
        glColor3ub(201, 192, 187);
        glVertex2f(0.96f,  0.94f);
        glVertex2f(0.94f,  0.94f);
        glVertex2f(0.94f, -0.94f);
        glVertex2f(0.96f, -0.94f);

        glColor3ub(201, 192, 187);
        glVertex2f(0.94f,  0.94f);
        glVertex2f(0.88f,  0.94f);
        glVertex2f(0.88f,  0.90f);
        glVertex2f(0.94f,  0.90f);

        glVertex2f(0.88f,  0.94f);
        glVertex2f(0.78f,  0.92f);
        glVertex2f(0.78f,  0.88f);
        glVertex2f(0.88f,  0.90f);

        glVertex2f(0.78f,  0.92f);
        glVertex2f(0.77f,  0.92f);
        glVertex2f(0.77f, -0.87f);
        glVertex2f(0.78f, -0.81f);

        glVertex2f(0.94f, -0.94f);
        glVertex2f(0.77f, -0.87f);
        glVertex2f(0.78f, -0.81f);
        glVertex2f(0.94f, -0.87f);

        glVertex2f(0.94f,  0.31f);
        glVertex2f(0.77f,  0.34f);
        glVertex2f(0.77f,  0.31f);
        glVertex2f(0.94f,  0.27f);

        glVertex2f(0.94f, -0.27f);
        glVertex2f(0.77f, -0.20f);
        glVertex2f(0.77f, -0.25f);
        glVertex2f(0.94f, -0.31f);

        glVertex2f(0.87f, 0.94f);
        glVertex2f(0.845f,  0.94f);
        glVertex2f(0.845f, -0.87f);
        glVertex2f(0.87f,-0.87f);
        glEnd();
}

void turbine(){

    //Left circle (small) = LcS
    //Left box (small)= Lb
    //Middle circle (big) = McB
    //Middle box (big)= Mb
    //Right circle (big) = Rb
    //Right_back circle (small) = R_bC
    //Right_front circle (small) = R_fC

////////////////////////////////////////////////////////////////////               AXIS            ////////////////////////////////

//1st box

    glBegin(GL_POLYGON);
    glColor3f(0.79f, 0.72f, 0.29f);

    glVertex2f(-0.3f, 0.05f);
    glVertex2f(-0.1f, 0.05f);
    glVertex2f(-0.1f, -0.05f);
    glVertex2f(-0.3f, -0.05f);

    glEnd();

    //////////////////////////////////////////////////////////////////////////////////////

    float LcS_angle;
    float LcS_radius = 0.05;
    float LcS_x,LcS_y, LcS_xx, LcS_yy;

    LcS_x = -0.3f;
    LcS_y = 0.0f;

    glBegin(GL_POLYGON);
    glColor3f(0.79f, 0.72f, 0.29f);

    glVertex2f(LcS_x,LcS_y);

    for(LcS_angle = 0.0f; LcS_angle<360.0f; LcS_angle++){
        LcS_xx = LcS_x+sin(LcS_angle)*LcS_radius;
        LcS_yy = LcS_y+cos(LcS_angle)*LcS_radius;

        glVertex2f(LcS_xx,LcS_yy);
    }

    glEnd();

    //////////////////////////////////////////////////////////////////////////////////////

//2nd box

    glBegin(GL_POLYGON);
    glColor3f(0.42f, 0.50f, 0.49f);

    glVertex2f(-0.1f, 0.15f);
    glVertex2f(0.1f, 0.15f);
    glVertex2f(0.1f, -0.15f);
    glVertex2f(-0.1f, -0.15f);

    glEnd();

    //////////////////////////////////////////////////////////////////////////////////////

    float McB_angle;
    float McB_radius = 0.15;
    float McB_x,McB_y, McB_xx, McB_yy;

    McB_x = -0.1f;
    McB_y = 0.0f;

    glBegin(GL_POLYGON);
    glColor3f(0.42f, 0.50f, 0.49f);

    glVertex2f(McB_x,McB_y);

    for(McB_angle = 0.0f; McB_angle<360.0f; McB_angle++){
        McB_xx = McB_x+sin(McB_angle)*McB_radius;
        McB_yy = McB_y+cos(McB_angle)*McB_radius;

        glVertex2f(McB_xx,McB_yy);
    }

    glEnd();

    //////////////////////////////////////////////////////////////////////////////////

    float RcB_Under_angle;
    float RcB_Under_radius = 0.165;
    float RcB_Under_x,RcB_Under_y, RcB_Under_xx, RcB_Under_yy;

    RcB_Under_x = 0.1f;
    RcB_Under_y = 0.0f;

    glBegin(GL_POLYGON);
    glColor3f(0.28f, 0.33f, 0.32f);

    glVertex2f(RcB_Under_x,RcB_Under_y);

    for(RcB_Under_angle = 0.0f; RcB_Under_angle<360.0f; RcB_Under_angle++){
        RcB_Under_xx = RcB_Under_x+sin(RcB_Under_angle)*RcB_Under_radius;
        RcB_Under_yy = RcB_Under_y+cos(RcB_Under_angle)*RcB_Under_radius;

        glVertex2f(RcB_Under_xx,RcB_Under_yy);
    }

    glEnd();

   //////////////////////////////////////////////////////////////////////////////////
    float RcB_angle;
    float RcB_radius = 0.15;
    float RcB_x,RcB_y, RcB_xx, RcB_yy;

    RcB_x = 0.1f;
    RcB_y = 0.0f;

    glBegin(GL_POLYGON);
    glColor3f(0.42f, 0.50f, 0.49f);

    glVertex2f(RcB_x,RcB_y);

    for(RcB_angle = 0.0f; RcB_angle<360.0f; RcB_angle++){
        RcB_xx = RcB_x+sin(RcB_angle)*RcB_radius;
        RcB_yy = RcB_y+cos(RcB_angle)*RcB_radius;

        glVertex2f(RcB_xx,RcB_yy);
    }

    glEnd();

      //////////////////////////////////////////////////////////////////////////////////

//3rd box

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.5f, 0.45f);

    glVertex2f(0.1f, 0.05f);
    glVertex2f(0.14f, 0.05f);
    glVertex2f(0.14f, -0.05f);
    glVertex2f(0.1f, -0.05f);

    glEnd();
}

void blade(){
     //8
      glBegin(GL_TRIANGLES);
      glColor3f(1.0f, 1.01f, 1.0f);
        glVertex2f(0.12f, 0.0f);
        glVertex2f(0.14f, 0.15f);
        glVertex2f(0.10f, 0.15f);
      glEnd();
      //6
      glBegin(GL_TRIANGLES);
      glColor3f(1.0f, 1.01f, 1.0f);
        glVertex2f(0.12f, 0.0f);
        glVertex2f(0.25f,0.02f);
        glVertex2f(0.25f, -0.02f);
      glEnd();
      //2
      glBegin(GL_TRIANGLES);
      glColor3f(1.0f, 1.01f, 1.0f);
        glVertex2f(0.12f, 0.0f);
        glVertex2f(0.10f,-0.15f);
        glVertex2f(0.14f, -0.15f);
      glEnd();
      //4
      glBegin(GL_TRIANGLES);
      glColor3f(1.0f, 1.01f, 1.0f);
        glVertex2f(0.12f, 0.0f);
        glVertex2f(-0.05f,0.02f);
        glVertex2f(-0.05f, -0.02f);
      glEnd();
}

void center_ball(){
    float R_bCs_angle;
    float R_bCs_radius = 0.05;
    float R_bCs_x,R_bCs_y, R_bCs_xx, R_bCs_yy;

    R_bCs_x = 0.1f;
    R_bCs_y = 0.0f;

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.5f, 0.45f);

    glVertex2f(R_bCs_x,R_bCs_y);

    for(R_bCs_angle = 0.0f; R_bCs_angle<360.0f; R_bCs_angle++){
        R_bCs_xx = R_bCs_x+sin(R_bCs_angle)*R_bCs_radius;
        R_bCs_yy = R_bCs_y+cos(R_bCs_angle)*R_bCs_radius;

        glVertex2f(R_bCs_xx,R_bCs_yy);
    }
    glEnd();
  //////////////////////////////////////////////////////////////////////////////////
    float R_fCs_angle;
    float R_fCs_radius = 0.05;
    float R_fCs_x,R_fCs_y, R_fCs_xx, R_fCs_yy;

    R_fCs_x = 0.13f;
    R_fCs_y = 0.0f;

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 1.0f, 1.0f);

    glVertex2f(R_fCs_x,R_fCs_y);

    for(R_fCs_angle = 0.0f; R_fCs_angle<360.0f; R_fCs_angle++){
        R_fCs_xx = R_fCs_x+sin(R_fCs_angle)*R_fCs_radius;
        R_fCs_yy = R_fCs_y+cos(R_fCs_angle)*R_fCs_radius;

        glVertex2f(R_fCs_xx,R_fCs_yy);
    }
    glEnd();
}


void blade_translation(){
    glPushMatrix();
    glTranslatef(0.033f, -0.079f, 0.0f);
    glRotated(45, 0, 0, 1);
    blade();
    glPopMatrix();
}

void turbineHolder(){
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.5f, -0.1f);
    glVertex2f(-0.5f, 0.1f);
    glVertex2f(-0.4f, 0.1f);
    glVertex2f(-0.4f, -0.2f);

    //glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.5f, 0.1f);
    glVertex2f(-0.4f, 0.1f);
    glVertex2f(-0.35f, 0.22f);
    glVertex2f(-0.45f, 0.22f);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3f(0.2f, 0.5f, 0.9f);
    glVertex2f(-0.5f, 0.1f);
    glVertex2f(-0.4f, 0.1f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.4f, 0.1f);
    glVertex2f(-0.4f,-0.2f);
    glVertex2f(-0.2f,-0.2f);
    glVertex2f(-0.2f, 0.22f);
    glVertex2f(-0.35f, 0.22f);
    glEnd();
}
GLfloat i_turbine = -5.0f;
void Xturbine(){
    turbineHolder();
    turbine();

    glPushMatrix();
    glTranslatef(0.105f, 0.0f, 0.0f);
    glRotatef(i_turbine,0.0,0.0,0.5);
    glTranslatef(-0.105f, -0.0f, 0.0f);
    blade();
    blade_translation();
    glPopMatrix();
    i_turbine+=0.8f;

    center_ball();
}

void lampPost_panelRoad(int val){


//main panel

    glBegin(GL_POLYGON);
    glColor3f(0.42f, 0.39f, 0.47f);

        glVertex2f(-0.025f, 0.2f);
        glVertex2f(0.025f, 0.2f);
        glVertex2f(0.025f, -0.9f);
        glVertex2f(-0.025f, -0.9f);

    glEnd();

    //////////////////////////

//right panel shadow

    glBegin(GL_POLYGON);
    glColor3f(0.27f, 0.25f, 0.30f);

        glVertex2f(0.0f, 0.2f);
        glVertex2f(0.025f, 0.2f);
        glVertex2f(0.025f, -0.9f);
        glVertex2f(0.0f, -0.9f);

    glEnd();

    ////////////////////////////
    ///////////////////////////


//joint

    glBegin(GL_POLYGON);
    glColor3f(0.42f, 0.39f, 0.47f);

        glVertex2f(-0.05f, 0.2f);
        glVertex2f(0.0f, 0.2f);
        glVertex2f(-0.05f, 0.3f);
        glVertex2f(-0.1f, 0.3f);

    glEnd();

    /////////////////////

    glBegin(GL_POLYGON);
    glColor3f(0.18f, 0.16f, 0.20f);

        glVertex2f(0.05f, 0.2f);
        glVertex2f(0.0f, 0.2f);
        glVertex2f(0.05f, 0.3f);
        glVertex2f(0.1f, 0.3f);

    glEnd();

    /////////////////////////////////////////
    ////////////////////////////////////////

//tube_holder

    glBegin(GL_POLYGON);
    glColor3f(0.42f, 0.39f, 0.47f);

        glVertex2f(-0.05f, 0.25f);
        glVertex2f(-0.05f, 0.3f);
        glVertex2f(-0.55f, 0.3f);
        glVertex2f(-0.55f, 0.25f);

    glEnd();

    ////////////////

    glBegin(GL_POLYGON);
    glColor3f(0.18f, 0.16f, 0.20f);

        glVertex2f(0.05f, 0.25f);
        glVertex2f(0.05f, 0.3f);
        glVertex2f(0.55f, 0.3f);
        glVertex2f(0.55f, 0.25f);

    glEnd();

    //////////////////////////////////
    /////////////////////////////////


//tube

    glBegin(GL_POLYGON);
    glColor3f(0.27f, 0.25f, 0.30f);

        glVertex2f(-0.55f, 0.25f);
        glVertex2f(-0.6f, 0.2f);
        glVertex2f(-0.1f, 0.2f);
        glVertex2f(-0.15f, 0.25f);

    glEnd();

    ///////////////////

    glBegin(GL_POLYGON);
    glColor3f(0.27f, 0.25f, 0.30f);

        glVertex2f(0.55f, 0.25f);
        glVertex2f(0.6f, 0.2f);
        glVertex2f(0.1f, 0.2f);
        glVertex2f(0.15f, 0.25f);

    glEnd();

    /////////////////////////////////
    ////////////////////////////////

    //solar panel


    glBegin(GL_POLYGON);
    glColor3f(0.17f, 0.17f, 0.28f);

        glVertex2f(-0.45f, 0.38f);
        glVertex2f(0.45f, 0.38f);
        glVertex2f(0.55f, 0.63f);
        glVertex2f(-0.35f, 0.63f);

    glEnd();

//inside partition


    glBegin(GL_LINES);
     glColor3f(1.0f, 1.0f, 1.0f);

        glVertex2f(-0.27f, 0.38f);
        glVertex2f(-0.17f, 0.63f);

    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);

        glVertex2f(-0.09f, 0.38f);
        glVertex2f(0.01f, 0.63f);

    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);

        glVertex2f(0.09f, 0.38f);
        glVertex2f(0.19f, 0.63f);

    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);

        glVertex2f(0.27f, 0.38f);
        glVertex2f(0.37f, 0.63f);

    glEnd();

    ////////////

    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);

        glVertex2f(-0.40f, 0.505f);
        glVertex2f(0.50f, 0.505f);

    glEnd();

    ///////////////////////


//sideBar
    glBegin(GL_POLYGON);
    glColor3f(0.5f, 0.4f, 0.0f);

        glVertex2f(0.55f, 0.63f);
        glVertex2f(0.60f, 0.58f);
        glVertex2f(0.50f, 0.33f);
        glVertex2f(0.45f, 0.38f);

    glEnd();
//downBar
    glBegin(GL_POLYGON);
    glColor3f(0.4f, 0.3f, 0.0f);

        glVertex2f(0.45f, 0.38f);
        glVertex2f(0.50f, 0.33f);
        glVertex2f(-0.40f, 0.33f);
        glVertex2f(-0.45f, 0.38f);

    glEnd();

    /////////////////////////////

//holder

    glBegin(GL_POLYGON);
    glColor3f(0.4f, 0.52f, 0.47f);

        glVertex2f(-0.35f, 0.3f);
        glVertex2f(-0.25f, 0.3f);
        glVertex2f(-0.25f, 0.35f);
        glVertex2f(-0.35f, 0.35f);

    glEnd();

    //////////////////////

    glBegin(GL_POLYGON);
    glColor3f(0.4f, 0.52f, 0.47f);

        glVertex2f(0.35f, 0.3f);
        glVertex2f(0.25f, 0.3f);
        glVertex2f(0.25f, 0.35f);
        glVertex2f(0.35f, 0.35f);

    glEnd();

    if(val == 9){
        glBegin(GL_POLYGON);
        glColor4f(1.0f, 1.0f, 0.0f, 5.0f);

            glVertex2f(0.6f, 0.2f);
            glVertex2f(0.1f, 0.2f);
            glVertex2f(0.15f, 0.15f);
            glVertex2f(0.55f, 0.15f);

        glEnd();

        glBegin(GL_POLYGON);
        glColor4f(1.0f, 1.0f, 0.0f, 5.0f);

            glVertex2f(-0.6f, 0.2f);
            glVertex2f(-0.1f, 0.2f);
            glVertex2f(-0.15f, 0.15f);
            glVertex2f(-0.55f, 0.15f);

        glEnd();
    }


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

void tree(){

    glBegin(GL_POLYGON);
        glColor3f(0.8f, 0.55f, 0.0f);
        glVertex2f(-0.05f, -0.7f);

        glColor3f(0.34f, 0.22f, 0.09f);
        glVertex2f(0.05f, -0.7f);

        glColor3f(0.34f, 0.22f, 0.09f);
        glVertex2f(0.05f, -0.02f);

        glColor3f(0.34f, 0.22f, 0.09f);
        glVertex2f(-0.05f, -0.02f);
    glEnd();


    glBegin(GL_TRIANGLES);
        glColor3f(0.0f, 0.55f, 0.0f);
        glVertex2f(-0.4f, -0.4f);

        glColor3f(0.16f, 0.44f, 0.05f);
        glVertex2f(0.4f, -0.4f);

        glColor3f(0.27f, 0.44f, 0.03f);
        glVertex2f(0.0f, -0.1f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.27f, 0.44f, 0.03f);
        glVertex2f(-0.3f, -0.3f);

        glColor3f(0.16f, 0.44f, 0.05f);
        glVertex2f(0.3f, -0.3f);

        glColor3f(0.0f, 0.55f, 0.0f);
        glVertex2f(0.0f, 0.0f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.16f, 0.44f, 0.05f);
        glVertex2f(-0.3f, -0.2f);

        glColor3f(0.0f, 0.55f, 0.0f);
        glVertex2f(0.3f, -0.2f);

        glColor3f(0.27f, 0.44f, 0.03f);
        glVertex2f(0.0f, 0.1f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.27f, 0.44f, 0.03f);
        glVertex2f(-0.2f, -0.1f);

        glColor3f(0.16f, 0.44f, 0.05f);
        glVertex2f(0.2f, -0.1f);

        glColor3f(0.0f, 0.55f, 0.0f);
        glVertex2f(0.0f, 0.0f);
    glEnd();
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

    glPushMatrix(); //Windmill 1
	glTranslated(0.50,0.38,0);
	glScaled(0.11,0.11,1);
	windmill(val);
	glPopMatrix();
	glPushMatrix(); //Windmill 2
	glTranslated(0.77,0.31,0);
	glScaled(0.13,0.12,1);
	windmill(val);
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
    train(val);
    glPopMatrix();

    glPushMatrix();//railrd
    glTranslatef(-0.055f,0.48f,0.0f);
	glScaled(0.75,0.35,1);
    railrd();
    glPopMatrix();

    glPushMatrix(); //hill part
    glTranslatef(0.0f,-0.15f,0.0f);
    glScaled(1,1.15,1);
    hill3rd(val);
    glPopMatrix();



    glPushMatrix();
    glTranslatef(0.741f,0.32f,0.0f);
    glScaled(0.3,0.25,1);
    Xturbine();
    glPopMatrix();

    roadriver(val);

    glPushMatrix();
    glTranslatef(0.0f,0.60f,0.0f);
    glScaled(1.8,1.5,1);
    glRotated(180,0,1,0);
    boat(1); //1
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0f,0.40f,0.0f);
    glScaled(1.8,1.5,1);
    boat(2); //2
    glPopMatrix();

    //lights road
    glPushMatrix();//lampost
    glLineWidth(1);
    glTranslatef(0.7f,-0.08f,0.0f);
	glScaled(0.3,0.3,1);
	lampPost_panelRoad(val);
    glPopMatrix();
    glPushMatrix();//lampost
    glLineWidth(1);
    glTranslatef(0.0f,-0.08f,0.0f);
	glScaled(0.3,0.3,1);
	lampPost_panelRoad(val);
    glPopMatrix();
    glPushMatrix();//lampost
    glLineWidth(1);
    glTranslatef(-0.7f,-0.08f,0.0f);
	glScaled(0.3,0.3,1);
	lampPost_panelRoad(val);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.33f,0.14f,0.0f);
    glScaled(0.4,0.7,1);
    tree();
    glTranslatef(1.73f,0.0f,0.0f);
    tree();
    glPopMatrix();

    //vehicles road
    glPushMatrix();
    glTranslatef(0.0f,0.80f,0.0f);
    glScaled(1.5,1.4,1);
    vehicleTruck(val);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f,0.30f,0.0f);
    glScaled(1.5,1.2,1);
    vehicleCar(val);
    glPopMatrix();

    if(rval == 1){
        glPushMatrix();
        glPointSize(2.0);
        rain();
        glPopMatrix();
    }

    borders();
    windows();

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

    glPushMatrix(); //Windmill 1
	glTranslated(0.50,0.38,0);
	glScaled(0.11,0.11,1);
	windmill(val);
	glPopMatrix();
	glPushMatrix(); //Windmill 2
	glTranslated(0.77,0.31,0);
	glScaled(0.13,0.12,1);
	windmill(val);
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
    train(val);
    glPopMatrix();

    glPushMatrix();//railrd
    glTranslatef(-0.055f,0.48f,0.0f);
	glScaled(0.75,0.35,1);
    railrd();
    glPopMatrix();

    glPushMatrix(); //hill part
    glTranslatef(0.0f,-0.15f,0.0f);
    glScaled(1,1.15,1);
    hill3rd(val);
    glPopMatrix();



    glPushMatrix();
    glTranslatef(0.741f,0.32f,0.0f);
    glScaled(0.3,0.25,1);
    Xturbine();
    glPopMatrix();

    roadriver(val);

    glPushMatrix();
    glTranslatef(0.0f,0.60f,0.0f);
    glScaled(1.8,1.5,1);
    glRotated(180,0,1,0);
    boat(1); //1
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0f,0.40f,0.0f);
    glScaled(1.8,1.5,1);
    boat(2); //2
    glPopMatrix();

    //lights road
    glPushMatrix();//lampost
    glLineWidth(1);
    glTranslatef(0.7f,-0.08f,0.0f);
	glScaled(0.3,0.3,1);
	lampPost_panelRoad(val);
    glPopMatrix();
    glPushMatrix();//lampost
    glLineWidth(1);
    glTranslatef(0.0f,-0.08f,0.0f);
	glScaled(0.3,0.3,1);
	lampPost_panelRoad(val);
    glPopMatrix();
    glPushMatrix();//lampost
    glLineWidth(1);
    glTranslatef(-0.7f,-0.08f,0.0f);
	glScaled(0.3,0.3,1);
	lampPost_panelRoad(val);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.33f,0.14f,0.0f);
    glScaled(0.4,0.7,1);
    tree();
    glTranslatef(1.73f,0.0f,0.0f);
    tree();
    glPopMatrix();

    //vehicles road
    glPushMatrix();
    glTranslatef(0.0f,0.80f,0.0f);
    glScaled(1.5,1.4,1);
    vehicleTruck(val);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f,0.30f,0.0f);
    glScaled(1.5,1.2,1);
    vehicleCar(val);
    glPopMatrix();

    if(rval == 1){
        glPushMatrix();
        glPointSize(2.0);
        rain();
        glPopMatrix();
    }

    borders();
    windows();

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

    glPushMatrix(); //Windmill 1
	glTranslated(0.50,0.38,0);
	glScaled(0.11,0.11,1);
	windmill(val);
	glPopMatrix();
	glPushMatrix(); //Windmill 2
	glTranslated(0.77,0.31,0);
	glScaled(0.13,0.12,1);
	windmill(val);
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
	//glRotated(180,0,1,0);
    train(val);
    glPopMatrix();

    glPushMatrix();//railrd
    glTranslatef(-0.055f,0.48f,0.0f);
	glScaled(0.75,0.35,1);
    railrd();
    glPopMatrix();

    glPushMatrix(); //hill part
    glTranslatef(0.0f,-0.15f,0.0f);
    glScaled(1,1.15,1);
    hill3rd(val);
    glPopMatrix();



    glPushMatrix();
    glTranslatef(0.741f,0.32f,0.0f);
    glScaled(0.3,0.25,1);
    Xturbine();
    glPopMatrix();

    roadriver(val);

    glPushMatrix();
    glTranslatef(0.0f,0.60f,0.0f);
    glScaled(1.8,1.5,1);
    boat(1); //1
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0f,0.40f,0.0f);
    glScaled(1.8,1.5,1);
    glRotated(180,0,1,0);
    boat(2); //2
    glPopMatrix();

    //lights road
    glPushMatrix();//lampost
    glLineWidth(1);
    glTranslatef(0.7f,-0.08f,0.0f);
	glScaled(0.3,0.3,1);
	lampPost_panelRoad(val);
    glPopMatrix();
    glPushMatrix();//lampost
    glLineWidth(1);
    glTranslatef(0.0f,-0.08f,0.0f);
	glScaled(0.3,0.3,1);
	lampPost_panelRoad(val);
    glPopMatrix();
    glPushMatrix();//lampost
    glLineWidth(1);
    glTranslatef(-0.7f,-0.08f,0.0f);
	glScaled(0.3,0.3,1);
	lampPost_panelRoad(val);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.33f,0.14f,0.0f);
    glScaled(0.4,0.7,1);
    tree();
    glTranslatef(1.73f,0.0f,0.0f);
    tree();
    glPopMatrix();

    //vehicles road
    glPushMatrix();
    glTranslatef(0.0f,0.80f,0.0f);
    glScaled(1.5,1.4,1);
    vehicleTruck(val);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f,0.30f,0.0f);
    glScaled(1.5,1.2,1);
    vehicleCar(val);
    glPopMatrix();

    if(rval == 1){
        glPushMatrix();
        glPointSize(2.0);
        rain();
        glPopMatrix();
    }

    borders();
    windows();

    glFlush();
    glutTimerFunc(2500,automated_mor,0);
}

void info(){
glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
glClear(GL_COLOR_BUFFER_BIT);

glBegin(GL_POLYGON);
    glColor3ub(255,255,0);
    glVertex2f(-2.0f, 2.0f);
    glColor3ub(147,112,219);
    glVertex2f(2.0f, 2.0f);
    glColor3ub(30,144,255);
    glVertex2f(2.0f, -2.0f);
    glColor3ub(70,130,180);
    glVertex2f(-2.0f, -2.0f);
    glEnd();

    glColor3ub(255,255,255);
    char *C="Computer Graphics[N]";
    glRasterPos2f( -0.4 , 0.9 );
    for(int i = 0; C[i] !='\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, C[i]);


glColor3ub(255,255,255);
    char *D="AWS ENERGY PLANT";
    glRasterPos2f( -0.4 , 0.7 );
    for(int i = 0; D[i] !='\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, D[i]);


glColor3ub(255,255,255);
    char *E="Group:1 ";
    glRasterPos2f( -0.22 , 0.5 );
    for(int i = 0; E[i] !='\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, E[i]);


glColor3ub(255,255,255);
    char *F="Submitted by  ";
    glRasterPos2f( -0.7 , 0.2 );
    for(int i = 0; F[i] !='\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, F[i]);


glColor3ub(255,255,255);
    char *G="ID:20-43391-1      ABU SAKIB MOLLA";
    glRasterPos2f( -0.7 , 0.05 );
    for(int i = 0; G[i] !='\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, G[i]);


glColor3ub(255,255,255);
    char *H="ID:20-43337-1      PARTHIB BANIK";
    glRasterPos2f( -0.7, -0.1 );
    for(int i = 0; H[i] !='\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, H[i]);


glColor3ub(255,255,255);
    char *I="ID:20-43400-1      S.M. NOWSHAN AL-NAHIN PAVEL";
    glRasterPos2f( -0.7 , -0.25 );
    for(int i = 0; I[i] !='\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, I[i]);


glColor3ub(255,255,255);
    char *J="ID:20-43405-1      S.M. KAMRUL HASAN KOCHE";
    glRasterPos2f( -0.7 , -0.4 );
    for(int i = 0; J[i] !='\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, J[i]);

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
            trainSpeed = 0.0f;
            truckSpeed = 0.0f;
            carSpeed = 0.0f;
            boatSpeed = 0.0f;
            break;
        case '1':
            speedBridgeCar1 = 0.20f;
            break;
        case '2':
            speedBridgeCar2 = 0.20f;
            break;
        case '3':
            carSpeed = 0.05f;
            break;
        case '9':
            trainSpeed = 0.09f;
            break;
        case '5':
            truckSpeed = 0.05f;
            break;
        case '7':
            boatSpeed = 0.03f;
            break;

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
        case 'R':
        case 'r':
            if(rval == 0){
                rval = 1;
                glutTimerFunc(100, update_rain, 0);
                soundRain();
            }
            else if(rval == 1){
                rval = 0;
                //glutTimerFunc(100, update_rain, 0);
                soundNull();
            }
            break;
        glutPostRedisplay();
	}
}

void handleMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON)
	{
	    switch(play){
        case '1':
            soundCar();
            play='2';
            break;
        case '2':
            soundTruck();
            play='3';
            break;
        case '3':
            soundTrain();
            play='4';
            break;
        case '4':
            soundWave();
            play='1';
            break;
	    }
	}
	if (button == GLUT_RIGHT_BUTTON)
	{
			soundNull();
	}

	glutPostRedisplay();
}

int main(int argc, char** argv){
   glutInit(&argc, argv);
   glutInitWindowSize(1600,900);
   glutInitWindowPosition(150,80);
   glutCreateWindow("AWS ENERGY PLANT");
   gluOrtho2D(-2, 2, -1, 1);
   glutDisplayFunc(info);
   glutKeyboardFunc(handleKeypress);
   glutMouseFunc(handleMouse);
   glutTimerFunc(100, updateBridgeCar1, 0);
   glutTimerFunc(100, updateBridgeCar2, 0);
   glutTimerFunc(100, updateTrain, 0);
   glutTimerFunc(100, updateBoat, 0);
   glutTimerFunc(100, updateTruck, 0);
   glutTimerFunc(100, updateCar, 0);
   glutTimerFunc(200, cloud1,0);
   glutTimerFunc(200, cloud2, 0);
   glutTimerFunc(200, doFrame,0);
   initGL();
   glutIdleFunc(Idle);
   glutMainLoop();
   return 0;
}

