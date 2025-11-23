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

   glColor3f(1.0, 0.0, 0.0);  // RED FILLED CIRCLE



   for(int k=0;;k++)

   {

       int xx = xpts[k];

       int yy = ypts[k];



       // horizontal scan lines between symmetric points

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





void rect(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4){



 glColor3f(1.0, 1.0, 1.0);

 glBegin(GL_QUADS);

          glVertex2i(x1, y1);  // left bottom

       glVertex2i(x2, y2);  // right bottom (LONG)

       glVertex2i(x3, y3); // right top

       glVertex2i(x4, y4); // left top

   glEnd();

}







void display()

{

   glClear(GL_COLOR_BUFFER_BIT);



   // ---------------------------------------

   // LARGE GREEN RECTANGLE BEHIND EVERYTHING

   // ---------------------------------------



   rect(50,80,90,80,90,200,50,200



        ); //left



  rect(120,80,180,80,180,220,120,220); //center rect







   rect(200,80,250,80,250,200,200,200



        ); //left

   // draw filled circle

   computeCircle();

   fillCircle();



   glutSwapBuffers();

}



int main(int argc,char **argv)

{

   r = 40;      // radius

   cx = 150;    // circle center X

   cy = 150;    // circle center Y



   glutInit(&argc, argv);

   glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

   glutInitWindowSize(500, 500);

   glutCreateWindow("Filled Midpoint Circle Inside Rectangle");



   init();

   glutDisplayFunc(display);

   glutMainLoop();

   return 0;

}