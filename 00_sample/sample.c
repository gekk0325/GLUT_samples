
#include <GLUT/glut.h>
#include <OpenGL/glext.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>

void display();
void init();

int main(int argc, char** argv){
	
	//create window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(250, 250);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	
	init();
	
	glutDisplayFunc(display);
	
	glutMainLoop();
	
	return 0;
}

void init(){
	glClearColor(0, 0 , 0, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 1, 0, 1, -1, 1);	
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);{
		glVertex3f(0.25, 0.25, 0);
		glVertex3f(0.75, 0.25, 0);
		glVertex3f(0.75, 0.75, 0);
		glVertex3f(0.25, 0.75, 0);
	}glEnd();
	glFlush();
}
