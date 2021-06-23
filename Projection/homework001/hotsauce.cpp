#include <gl/glut.h>
#include <iostream>
GLint TopLeftX, TopLeftY, BottomRightX, BottomRightY;
GLboolean IsSphere = true;

GLdouble radius = 0.5;
GLint slice = 10;
GLint stack = 10;

void MyDisplay(){
	glViewport(0,0,300,300);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.5,0.0,0.5);
	if (IsSphere)
		glutWireSphere(radius,slice,stack);
	else	
		glutSolidSphere(radius,slice,stack);
	glBegin(GL_POLYGON);
	glEnd();
	glFlush();
}
void MyMouseClick ( GLint Button, GLint State, GLint X, GLint Y) {
	if( Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) {
		TopLeftX = X;
		TopLeftY = Y;
		//glutWireSphere(0.5,20,10);
		slice++;
		stack++;
	}
	if(Button == GLUT_RIGHT_BUTTON && State == GLUT_DOWN) {
		TopLeftX = X;
		TopLeftY = Y;
		//glutWireSphere(0.5,20,10);
		slice--;
		stack--;
	}

	glutPostRedisplay();
}
void MyKeyboard(unsigned char KeyPressed, int X, int Y){
	switch (KeyPressed){
	case 's':
	case 'S':
		IsSphere = true;
		break;
	case 'w':
	case 'W':
		IsSphere = false;
		break;
	case GLUT_KEY_UP:
		radius += 0.1;
		break;
	case GLUT_KEY_DOWN:
		radius -= 0.1;
		break;
	case 27:
		exit(0);
		break;
	}

	glutPostRedisplay();
}
int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(300,300);
	glutInitWindowPosition(0,0);
	glutCreateWindow("OpenGL Drawing Sample");
	glClearColor(1.0,1.0,1.0,1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0,1.0,-1.0,1.0,-1.0,1.0);

	glutMouseFunc(MyMouseClick);
	glutKeyboardFunc(MyKeyboard);
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}