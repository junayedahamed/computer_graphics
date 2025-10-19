//chess board

#include <GL/glut.h>




void poly(float a,float b,float c,float d,float e,float f,float g,float h){
 //glClear(GL_COLOR_BUFFER_BIT);
   glBegin(GL_POLYGON);
 glVertex2f(a,b);
 glVertex2f(c,d);
 glVertex2f(e,f);
 glVertex2f(g,h);
 glEnd();

}


void display() {
    glClear(GL_COLOR_BUFFER_BIT);

  /*  int squareSize = 1; // size of each square (in OpenGL units)

    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            // Set color based on whether the square is black or white
            if ((row + col) % 2 == 0)
                glColor3f(1.0f, 1.0f, 1.0f); // white
            else
                glColor3f(0.0f, 0.0f, 0.0f); // black

            int x = col * squareSize;
            int y = row * squareSize;

            // Draw the square as a filled quad
            glBegin(GL_QUADS);
                glVertex2i(x, y);
                glVertex2i(x + squareSize, y);
                glVertex2i(x + squareSize, y + squareSize);
                glVertex2i(x, y + squareSize);
            glEnd();
        }
    }*/

    glBegin(GL_LINES);
     glVertex2f(1.0,0.0);
    glVertex2f(-1.0,0.0);
    glVertex2f(0.0,1.0);
    glVertex2f(0.0,-1.0);



    glEnd();

   for(float x=0;x<1.0;x=x+0.25){
        for(float y=0;y<1.0;y+=0.25){

                float sum=x+y;
                if(sum==0||sum ==0.5||sum==1||sum==1.5){
                      poly(x,y,x+0.25,y,x+.25,y+.25,x,y+.25);
                }


        }
    }
    // next

       for(float x=0.0;x>-1.0;x=x-0.25){
        for(float y=0.0;y>-1.0;y-=0.25){

                float sum=x+y;
                if(sum==0||sum ==-0.5||sum==-1||sum==-1.5){
                      poly(x,y,x-0.25,y,x-.25,y-.25,x,y-.25);
                }


        }
    }

  for(float x=0.0;x<1.0;x=x+0.25){
        for(float y=0.0;y>-1.0;y-=0.25){

                float sum=x+y;
                if(sum==-0.25||sum ==-0.75||sum==0.25||sum==.75){
                      poly(x,y,x+0.25,y,x+.25,y-.25,x,y-.25);
                }


        }
    }



     for(float x=0.0;x>-1.0;x=x-0.25){
        for(float y=0.0;y<1.0;y+=0.25){

                float sum=x+y;
                if(sum==-0.25||sum ==-0.75||sum==0.25||sum==.75){
                      poly(x,y,x-0.25,y,x-.25,y+.25,x,y+.25);
                }


        }
    }
   /* poly(0,0,0.25,0,0.25,0.25,0.0,0.25);
   poly(0.5,0.0,0.75,0.0,0.75,0.25,0.5,0.250);
    poly(0.25,0.250,0.5,0.250,0.5,0.5,0.25,0.50);
      poly(0.75,0.250,1,0.250,1,0.5,0.75,0.50);*/


    glFlush();
}


int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(650, 400);
    glutCreateWindow("8x8 Chessboard");
    //init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}