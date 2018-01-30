#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>

void Bresenhams(int x1,int y1,int x2,int y2){
    mNew=2*(y2-y1);
    slopeErr=mNew-(x2-x1);

}

void display()
{
glClear(GL_COLOR_BUFFER_BIT);
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

