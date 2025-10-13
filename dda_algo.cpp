//DDA Line draw

#include<windows.h>
#include<GL/glut.h>
#include<bits/stdc++.h>
using namespace std;


void drawPixel(float x,float y){
    glPointSize(10);
glBegin(GL_POINTS);

glVertex2f((x/100),( y/100));

glEnd();


}
float x_1,y_1,x_2,y_2;

void display(){
glClear(GL_COLOR_BUFFER_BIT);

float dx=x_2-x_1;
float dy =y_2-y_1;

float m= dx/dy;
int k= max(abs(dx),abs(dy));

if(k==0){
    cout<<"invalid steps"<<endl;
    return;
}
float xk=x_1,yk=y_1;

if(m>1.0){
  drawPixel(round(xk),round(yk));
    for(int i=1;i<=k;i++){
        xk+=(1/m);
        yk+=1;
       drawPixel(round(xk),round(yk));
    }
}

else if(m<1.0){
      drawPixel(round(xk),round(yk));
    for(int i=1;i<=k;i++){
        xk+=1;
        yk+=m;
        drawPixel(round(xk),round(yk));
    }
}
else{
       drawPixel(round(xk),round(yk));
    for(int i=1;i<=k;i++){
        xk+=1;
        yk+=1;
        drawPixel(round(xk),round(yk));
    }
}

glFlush();
}







int main(int argc,char *argv[]){


glutInit(&argc,argv);


cin>>x_1>>y_1>>x_2>>y_2;

glutInitWindowSize(640,480);
glutInitWindowPosition(50,50);


glutInitDisplayMode(GLUT_RGB| GLUT_SINGLE|GLUT_DEPTH);

glutCreateWindow("Junayed");

glutDisplayFunc(display);


glutMainLoop();


return 0;





}