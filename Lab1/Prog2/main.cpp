#include <windows.h>
#include <GL/glut.h>


GLfloat angle = 0.0f;

void initGL() {

   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}


void idle() {
   glutPostRedisplay();
}

void display() {
   glClear(GL_COLOR_BUFFER_BIT);
  glRotatef(1, 1.0f, 0.0f, 0.0f);
   glBegin(GL_POLYGON);
      glColor3f(0.0f, 1.0f, 0.0f);
      glVertex2f(-0.3f, -0.3f);
      glColor3f(0.2f, 0.2f, 0.2f);
      glVertex2f( 0.3f, -0.5f);
      glColor3f(0.4f, .5f, .4f);
      glVertex2f( 0.3f,  0.3f);
      glColor3f(0.5f, 0.4f, 0.5f);
      glVertex2f(0.45f,  0.7f);
      glColor3f(0.2f, 0.2f, 0.5f);
    glVertex2f(-0.3f,  0.5f);
   glEnd();
   glutSwapBuffers();

}



void reshape(int w, int h)
{
glViewport(0.0, 0.0, w, h);
}


int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE);
   glutInitWindowSize(640, 480);
   glutInitWindowPosition(50, 50);
   glutCreateWindow("Animation via Idle Function");
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutIdleFunc(idle);
   initGL();
   glutMainLoop();
   return 0;
}
