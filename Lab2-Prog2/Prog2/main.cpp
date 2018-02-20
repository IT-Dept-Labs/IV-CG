#include <windows.h>
#include <GL/glut.h>

void initGL() {
   glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

GLfloat angle = 0.0f;

void idle() {
   glutPostRedisplay();
}

void display() {
   glClear(GL_COLOR_BUFFER_BIT);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glPushMatrix();
   glTranslatef(-0.2f, 0.2f, 0.0f);
   glRotatef(angle, 0.0f, 0.0f, 1.0f);
   float p1[2] = {-0.4f, -0.3f}, p2[2] = {0.4f, -0.3f}, p3[2] = {0.4f, 0.3f}, p4[2] = {-0.4f, 0.3f};
   glBegin(GL_QUADS);
      glColor3f(1.0f, 0.0f, 0.0f);
      glVertex2fv(p1);
      glVertex2fv(p2);
      glVertex2fv(p3);
      glVertex2fv(p4);
   glEnd();
   glPopMatrix();

   glutSwapBuffers();

   angle += 1.0f;
}

void reshape(GLsizei width, GLsizei height) {
   if (height == 0) height = 1;
   GLfloat aspect = (GLfloat)width / (GLfloat)height;

   glViewport(0, 0, width, height);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   if (width >= height) {
      gluOrtho2D(-1.0 * aspect, 1.0 * aspect, -1.0, 1.0);
   } else {
      gluOrtho2D(-1.0, 1.0, -1.0 / aspect, 1.0 / aspect);
   }
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE);
   glutInitWindowSize(240, 240);
   glutInitWindowPosition(100, 100);
   glutCreateWindow("Assignment 2 - Question 2");
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutIdleFunc(idle);
   initGL();
   glutMainLoop();
   return 0;
}

