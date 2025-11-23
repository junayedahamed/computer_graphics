// bd FLAG





#include <GL/glut.h>

#include <stdio.h>



int pk, i, r, cx, cy;

int xpts[1000], ypts[1000];



void init(void)

{

   glClearColor(0.0,0.0,0.0,0.0);

   glMatrixMode(GL_PROJECTION);

   gluOrtho2D(0.0,300.0,0.0,300.0);

}



void computeCircle()

{

   pk = 1 - r;

   xpts[0] = 0;

   ypts[0] = r;



   for(i=0;;i++)

   {

       if(pk >= 0){

           xpts[i+1] = xpts[i] + 1;

           ypts[i+1] = ypts[i] - 1;

           pk = pk + 2*xpts[i+1] - 2*ypts[i+1] + 1;

       }

       else{

           xpts[i+1] = xpts[i] + 1;

           ypts[i+1] = ypts[i];

           pk = pk + 2*xpts[i+1] + 1;

       }

       if(xpts[i] >= ypts[i]) break;

   }

}



void fillCircle()

{

   glColor3f(1.0, 0.0, 0.0);



   for(int k=0;;k++)

   {

       int xx = xpts[k];

       int yy = ypts[k];





       glBegin(GL_LINES);

           glVertex2i(cx - xx, cy + yy);

           glVertex2i(cx + xx, cy + yy);



           glVertex2i(cx - yy, cy + xx);

           glVertex2i(cx + yy, cy + xx);



           glVertex2i(cx - xx, cy - yy);

           glVertex2i(cx + xx, cy - yy);



           glVertex2i(cx - yy, cy - xx);

           glVertex2i(cx + yy, cy - xx);

       glEnd();



       if(xpts[k] >= ypts[k]) break;

   }

}



void display()

{

   glClear(GL_COLOR_BUFFER_BIT);



   glColor3f(0.0, 1.0, 0.0);

   glBegin(GL_QUADS);

          glVertex2i(20, 80);

       glVertex2i(280, 80);

       glVertex2i(280, 220);

       glVertex2i(20, 220);

   glEnd();





   computeCircle();

   fillCircle();



   glutSwapBuffers();

}



int main(int argc,char **argv)

{

   r = 60;

   cx = 150;

   cy = 150;



   glutInit(&argc, argv);

   glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

   glutInitWindowSize(500, 500);

   glutCreateWindow("Filled Midpoint Circle Inside Rectangle");



   init();

   glutDisplayFunc(display);

   glutMainLoop();

   return 0;

}