
#include <OpenGL/gl.h>
#include <OpenGL/glext.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <stdlib.h>

#define drawOneLine(x1, y1, x2, y2)\
glBegin(GL_LINES); \
glVertex2f(x1,y1);\
glVertex2f(x2,y2);\
glEnd();

void spinDisplay();
void reshape(int w, int h);
void display();
void displayFly();
void init();

static GLfloat spin = 0.0;

int main(int argc, char** argv){
	
	//create window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400, 150);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	
	//init
	init();
	
	//register callbacks
	glutDisplayFunc(displayFly);
	glutReshapeFunc(reshape);
	
	//the loop
	glutMainLoop();
	
	return 0;
}

void init(){
	glClearColor(0, 0 , 0, 0);
	glShadeModel(GL_FLAT);	
}

//refresh screen
void display(){
	int i;
	
	glClear(GL_COLOR_BUFFER_BIT);
	
	glColor3f(1.0, 1.0, 1.0);
	
	glEnable(GL_LINE_STIPPLE);
	
	/* in 1st row, 3 lines, each with glEnable (GL_LINE_STIPPLE);a different stipple */
	glLineStipple (1, 0x0101); 
	
	/* drawOneLine (50.0, 125.0, 150.0, 125.0); glLineStipple (1, 0x00FF); /* dashed */ 
	drawOneLine (150.0, 125.0, 250.0, 125.0); 
	
	glLineStipple (1, 0x1C47); 	/* dash/dot/dash */
	drawOneLine (250.0, 125.0, 350.0, 125.0);
	
	/* in 2nd row, 3 wide lines, each with different stipple */ 
	glLineWidth (5.0); 
	
	glLineStipple (1, 0x0101); 	/* dotted */ 
	drawOneLine (50.0, 100.0, 150.0, 100.0);
	
	glLineStipple (1, 0x00FF); 	/* dashed */
	drawOneLine (150.0, 100.0, 250.0, 100.0);
	
	glLineStipple (1, 0x1C47);	/* dash/dot/dash */ 
	drawOneLine (250.0, 100.0, 350.0, 100.0);
	
	glLineWidth (1.0);
	/* in 3rd row, 6 lines, with dash/dot/dash stipple */ /* as part of a single connected line strip	*/
	glLineStipple (1, 0x1C47);	/* dash/dot/dash */
	glBegin (GL_LINE_STRIP); 
	for (i = 0; i < 7; i++)
		glVertex2f (50.0 + ((GLfloat) i * 50.0), 75.0); 
	glEnd ();
	
	/* in 4th row, 6 independent lines with same stipple */ 
	for (i = 0; i < 6; i++) {
		drawOneLine (50.0 + ((GLfloat) i * 50.0), 50.0, 50.0 + ((GLfloat)(i+1) * 50.0), 50.0);
	}
	
	/* in 5th row, 1 line, with dash/dot/dash stipple	*/ /* and a stipple repeat factor of 5	*/ 
	glLineStipple (5, 0x1C47); 
	
	/* dash/dot/dash */
	drawOneLine (50.0, 25.0, 350.0, 25.0);
	
	glDisable (GL_LINE_STIPPLE); 
	glFlush ();
}

void displayFly(){
	GLubyte fly[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x80, 0x01, 0xC0, 0x06, 0xC0, 0x03, 0x60, 0x04, 0x60, 0x06, 0x20, 0x04, 0x30, 0x0C, 0x20, 0x04, 0x18, 0x18, 0x20, 0x04, 0x0C, 0x30, 0x20, 0x04, 0x06, 0x60, 0x20, 0x44, 0x03, 0xC0, 0x22, 0x44, 0x01, 0x80, 0x22, 0x44, 0x01, 0x80, 0x22, 0x44, 0x01, 0x80, 0x22, 0x44, 0x01, 0x80, 0x22, 0x44, 0x01, 0x80, 0x22, 0x44, 0x01, 0x80, 0x22, 0x66, 0x01, 0x80, 0x66, 0x33, 0x01, 0x80, 0xCC, 0x19, 0x81, 0x81, 0x98, 0x0C, 0xC1, 0x83, 0x30, 0x07, 0xe1, 0x87, 0xe0, 0x03, 0x3f, 0xfc, 0xc0, 0x03, 0x31, 0x8c, 0xc0, 0x03, 0x33, 0xcc, 0xc0, 0x06, 0x64, 0x26, 0x60, 0x0c, 0xcc, 0x33, 0x30, 0x18, 0xcc, 0x33, 0x18, 0x10, 0xc4, 0x23, 0x08, 0x10, 0x63, 0xC6, 0x08, 0x10, 0x30, 0x0c, 0x08, 0x10, 0x18, 0x18, 0x08, 0x10, 0x00, 0x00, 0x08};
	GLubyte halftone[] = { 0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55, 0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55, 0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55, 0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55, 0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55, 0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55, 0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55, 0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55, 0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55, 0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55, 0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55, 0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55, 0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55, 0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55, 0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55, 0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55};
	
	glClear (GL_COLOR_BUFFER_BIT); 
	glColor3f (1.0, 1.0, 1.0);
	/* draw one solid, unstippled rectangle,	*/ /* then two stippled rectangles	*/
	glRectf (25.0, 25.0, 125.0, 125.0); 
	glEnable (GL_POLYGON_STIPPLE); 
	
	glPolygonStipple (fly);
	glRectf (125.0, 25.0, 225.0, 125.0); 
	//glPolygonStipple (halftone); 
	//glRectf (225.0, 25.0, 325.0, 125.0); 
	
	glDisable (GL_POLYGON_STIPPLE);
	glFlush ();
}

/*callback for window resize*/
void reshape(int w, int h){
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);
}
