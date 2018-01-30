#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>

void Bresenhams(int x1,int y1,int x2,int y2){
    int mNew=2*(y2-y1);
    int dy=y2-y1;
    int dx=x2-x1;
    int slopeErr=mNew-dx;
    glBegin(GL_POINTS);
    for(int x=x1,y=y1;x<=x2;x++){
        glVertex2i(x,y);
        slopeErr+=mNew;
        if( slopeErr>=0){
            y++;
            slopeErr-=2*dx;
        }
    }
    glEnd();
}

void display()
{
glClear(GL_COLOR_BUFFER_BIT);
glColor3b(1.0,1.0,0);
Bresenhams(50,250,280,500);
glutSwapBuffers();
}
void reshape(int w, int h)
{
glViewport(0.0, 0.0, w, h);
}
void intiopenGL()
{
glClearColor(1.0, 1.0, 0, 1.0);
glOrtho(0,500,0,500,0,1);
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

