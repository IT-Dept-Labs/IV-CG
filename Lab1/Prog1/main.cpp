#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>

void DDA(int x0,int y0,int x1,int y1){
    int dx=x1-x0;
    int dy=y1-y0;
    int steps=abs(dx)>abs(dy)?abs(dx):abs(dy);

    float XInc=dx/float(steps);
    float YInc=dy/float(steps);
    float x=x0;
    float y=y0;
    glBegin(GL_POINTS);
    for(int i=0;i<steps;i++){
        glVertex2f(x/250,y/250);
        x+=XInc;
        y+=YInc;
    }
    glEnd();
}

void display()
{
glClear(GL_COLOR_BUFFER_BIT);
DDA(0,0,100,100);
glColor3b(1.0,0,0);
//DDA(-300.2,200.4,200.3,150);
glutSwapBuffers();
}
void reshape(int w, int h)
{
glViewport(0.0, 0.0, w, h);
}
void intiopenGL()
{
glClearColor(1.0, 1.0, 1.0, 1.0);
}

int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
glutInitWindowSize(500, 500);
glutInitWindowPosition(100, 100);
glutCreateWindow("OpenGL Test");
intiopenGL();
glutDisplayFunc(display);
glutIdleFunc(display);
glutReshapeFunc(reshape);
glutMainLoop();
return 0;
}
































/*
void DDA(float x0,float y0,float x1,float y1){
    float dx=x1-x0;
    float acc=0.001;
    float dy=y1-y0;
    int steps=abs(dx)>abs(dy)?abs(dx)/float(acc):abs(dy)/float(acc);

    float XInc=dx/float(steps);
    float YInc=dy/float(steps);
    float x=x0;
    float y=y0;
    glBegin(GL_POINTS);
    for(int i=0;i<steps;i+=acc){
        glVertex2f(x/250,y/250);
        x+=XInc;
        y+=YInc;
    }
    glEnd();
}
*/

