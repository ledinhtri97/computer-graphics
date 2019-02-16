#include <math.h>
#include <GL/glut.h>
#include <GL/gl.h>

void myInit()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glColor3f(1.0f, 1.0f, 1.0f);
    glPointSize(9.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void myDisplay()
{
    GLfloat x = 640 / 2, y = 480 / 2;
    GLint R = 200;
    GLfloat PI = 3.14;
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();

    glBegin(GL_LINE_STRIP);
    for(int i = 0; i <= 360; i+=10){
        glVertex2f(x+R*cos(i * PI / 180), y+R*sin(i * PI / 180));
    }
    glEnd();

    glBegin(GL_LINES);
    for(int i = 0; i<= 360; i+=10){
        glVertex2f(x, y);
        glVertex2f(x + R * cos(i * PI / 180), y + R * sin(i * PI / 180));
    }
    glEnd();

    GLfloat angle = 220.0;
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x + R * cos((angle)*PI / 180), y + R * sin((angle)*PI / 180));
    glVertex2f(x + R * cos((angle + 10) * PI / 180), y + R * sin((angle + 10) * PI / 180));
    glEnd();

    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x + R * cos((angle + 120)*PI / 180), y + R * sin((angle + 120)*PI / 180));
    glVertex2f(x + R * cos((angle + 120 + 10) * PI / 180), y + R * sin((angle + 120 + 10)*PI / 180));
    glEnd();

    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x + R * cos((angle + 120 + 120) * PI / 180), y + R * sin((angle + 120 + 120) * PI / 180));
    glVertex2f(x + R * cos((angle + 120 + 120 + 10) * PI / 180), y + R * sin((angle + 120 + 120 + 10)*PI / 180));
    glEnd();

    glFlush();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, (char **)argv);              //initialize the tool kit
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //set the display mode
    glutInitWindowSize(640, 480);                //set window size
    glutInitWindowPosition(100, 150);            // set window position on screen
    glutCreateWindow("Ex3 360");                 //open the screen window

    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
    return 0;
}