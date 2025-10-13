//star
#include<windows.h>
#include<GL/glut.h>
#include<iostream>
using namespace std;

void triangle (float x1, float y1, float x2, float y2, float x3, float y3){
glBegin(GL_POLYGON);
glVertex2f(x1,y1);
glVertex2f(x2,y2);
glVertex2f(x3,y3);
glEnd();
}

void display(){

    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,0.0);
    glVertex2f(0.25,0.25);
    glVertex2f(-0.25,0.25);
    glVertex2f(-0.25,-0.25);
    glVertex2f(0.25,-0.25);
    glEnd();

    triangle(0.0,0.7,-0.25,0.25,0.25,0.25);
    triangle(-0.25,-0.25,-0.25,0.25,-0.7,0.0);
    triangle(-0.25,-0.25,0.0,-0.7,0.25,-0.25);
    triangle(0.25,-0.25,0.25,0.25,0.7,0.0);







    glFlush();
}

int main(int argc,char *argv[]){

glutInit(&argc,argv);
glutInitWindowSize(640,480);
glutInitWindowPosition(50,50);

glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH);

glutCreateWindow(" polygon design");

glutDisplayFunc(display);

glutMainLoop();
return 0;

}