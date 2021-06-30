#include "GL/gl.h"
#include "GL/glut.h"

void display() {
  glClear(GL_COLOR_BUFFER_BIT);

  // Draw a white grid "floor" for the tetrahedron to sit on.
  glColor3f(1.0, 1.0, 1.0);
  glBegin(GL_LINES);
  for (GLfloat i = -2.5; i <= 2.5; i += 0.25) {
    glVertex3f(i, 0, 2.5);
    glVertex3f(i, 0, -2.5);
    glVertex3f(2.5, 0, i);
    glVertex3f(-2.5, 0, i);
  }
  glEnd();

  // Draw the tetrahedron.  It is a four sided figure, so when defining it
  // with a triangle strip we have to repeat the last two vertices.
  glBegin(GL_TRIANGLE_STRIP);
  glColor3f(1, 1, 1);
  glVertex3f(0, 2, 0);
  glColor3f(1, 0, 0);
  glVertex3f(-1, 0, 1);
  glColor3f(0, 1, 0);
  glVertex3f(1, 0, 1);
  glColor3f(0, 0, 1);
  glVertex3f(0, 0, -1.4);
  glColor3f(1, 1, 1);
  glVertex3f(0, 2, 0);
  glColor3f(1, 0, 0);
  glVertex3f(-1, 0, 1);
  glEnd();

  glFlush();
}

void init() {

  // Set the current clear color to black and the current drawing color to
  // white.
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glColor3f(1.0, 1.0, 1.0);

  // Set the camera lens to have a 60 degree (vertical) field of view, an
  // aspect ratio of 4/3, and have everything closer than 1 unit to the
  // camera and greater than 40 units distant clipped away.
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60.0, 4.0 / 3.0, 1, 40);

  // Position camera at (4, 6, 5) looking at (0, 0, 0) with the vector
  // <0, 1, 0> pointing upward.
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(4, 6, 5, 0, 0, 0, 0, 1, 0);
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("OpenGL - Creating a triangle");
  glutDisplayFunc(display);
  init();
  glutMainLoop();
  return 0;
}