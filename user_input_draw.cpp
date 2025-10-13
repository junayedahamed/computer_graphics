#include<windows.h>
#include<GL/glut.h>
#include<iostream>
using namespace std;
float x,y;
void display(){

    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);
    glVertex2f(1.0,0.0);   glVertex2f(-1.0,0.0);   glVertex2f(0.0,1.0);   glVertex2f(0.0,-1.0);
    glEnd();

    //point
 glPointSize(10);
/* glColor3f(255,0,0);
    glBegin(GL_POINTS);

    glVertex2f(.5,.5);
    glEnd();
    //sec
    // glPointSize(10);
 glColor3f(0,128,0);
    glBegin(GL_POINTS);

    glVertex2f(-.5,-.5);
    glEnd();

    //third

         //glPointSize(10);
 glColor3f(255,250,0);
    glBegin(GL_POINTS);

    glVertex2f(.5,-.5);
    glEnd();

     glColor3f(255,55,55);
    glBegin(GL_POINTS);

    glVertex2f(-.5,.5);
    glEnd();*/



    //user input draw

      glColor3f(120,128,0);
    glBegin(GL_POINTS);

  // glVertex2f(x,y);

    for(float i=-x;i<=x;i=i+0.0001){
        glVertex2f(i,y);
    }
       for(float i=-x;i<=x;i=i+0.0001){
        glVertex2f(i,-y);
    }
    for(float i=x;i>=-x;i=i-0.0001){
        glVertex2f(y,-i);
    }
    for(float i=x;i>=-x;i=i-0.0001){
        glVertex2f(-y,i);
    }
    // glVertex2f(-x,-y);

       //glVertex2f(x,-y);
       //  glVertex2f(-x,y);

         glEnd()
  ;/*  //first


     glColor3f(0,128,0);
    glBegin(GL_POINTS);

    for(float i=-.25;i<=.25;i=i+0.0001){
        glVertex2f(i,0.25);
    }


//second


   glColor3f(0,128,0);
    glBegin(GL_POINTS);

    for(float i=-.25;i<=.25;i=i+0.0001){
        glVertex2f(i,-0.25);
    }



    //third

       glColor3f(0,128,0);
    glBegin(GL_POINTS);

    for(float i=.25;i>=-.25;i=i-0.0001){
        glVertex2f(0.25,-i);
    }

//fourth

    glColor3f(0,128,0);
    glBegin(GL_POINTS);

    for(float i=.25;i>=-.25;i=i-0.0001){
        glVertex2f(-.25,i);
    }
    glEnd();*/





    glFlush();
}

int main(int argc,char *argv[]){

glutInit(&argc,argv);
glutInitWindowSize(640,480);
glutInitWindowPosition(50,50);

glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH);

glutCreateWindow("hELLO")
;

cin>>x>>y;
glutDisplayFunc(display);

glutMainLoop();
return 0;

}