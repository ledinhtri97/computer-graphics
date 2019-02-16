#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
GLfloat angle;

void mydisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    GLfloat x = 640 / 2, y = 480 / 2;
    GLint R = 200;
    GLfloat PI = 3.14;

    glBegin(GL_LINE_STRIP);
    for (int i = 0; i <= 360; i += 10)
    {
        glVertex2f(x + R * cos(i * PI / 180), y + R * sin(i * PI / 180));
    }
    glEnd();

    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x + R * cos((angle)*PI / 180), y + R * sin((angle)*PI / 180));
    glVertex2f(x + R * cos((angle + 10) * PI / 180), y + R * sin((angle + 10) * PI / 180));
    glEnd();

    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x + R * cos((angle + 120) * PI / 180), y + R * sin((angle + 120) * PI / 180));
    glVertex2f(x + R * cos((angle + 120 + 10) * PI / 180), y + R * sin((angle + 120 + 10) * PI / 180));
    glEnd();

    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x + R * cos((angle + 120 + 120) * PI / 180), y + R * sin((angle + 120 + 120) * PI / 180));
    glVertex2f(x + R * cos((angle + 120 + 120 + 10) * PI / 180), y + R * sin((angle + 120 + 120 + 10) * PI / 180));
    glEnd();

    glFlush();
    glutSwapBuffers();
}

void processTimer(int value)
{
    angle += (GLfloat)value;
    if (angle > 360)
        angle -= 360.0f;
    glutTimerFunc(100, processTimer, 10);
    glutPostRedisplay();
}
int main(int argc, char **argv)
{
    angle = 0.0f;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(640, 480); //set window size
    glutInitWindowPosition(100, 150);
    glutCreateWindow("simple");
    glutDisplayFunc(mydisplay);
    glutTimerFunc(100, processTimer, 10);
    glOrtho(0, 640, 0, 480, -1, 1);
    glutMainLoop();
    return 0;
}