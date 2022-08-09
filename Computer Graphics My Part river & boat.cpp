#include <GL/gl.h>
#include <GL/glut.h>
#include<math.h>
#include<Windows.h>
#define PI 3.14159265358979323846






int main(int argc, char** argv){
   glutInit(&argc, argv);
   glutInitWindowSize(1600,900);
   glutInitWindowPosition(150,80);
   glutCreateWindow("Padma Bridge Scenario");
   gluOrtho2D(-2, 2, -1, 1);
   initGL();
   glutIdleFunc(Idle);
   glutMainLoop();
   return 0;
}



