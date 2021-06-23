#include <gl/glut.h>
#include <iostream>

GLboolean IsSphere = true;

void MyDisplay(){
	glViewport(0,0,300,300);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.5,0.0,0.5);
	if (IsSphere)
		glutWireSphere(0.5,10,10);
	else	
		glutSolidSphere(0.5,5,5);
	glFlush();
}
void MyMouseClick ( GLint Button, GLint State, GLint X, GLint Y) {
	if( Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) {
		glutWireSphere(0.5,20,10);
	}
	if(Button == GLUT_RIGHT_BUTTON && State == GLUT_DOWN) {
		glutWireSphere(0.5,20,10);
	}
}
void MyKeyboard(unsigned char KeyPressed, int X, int Y){
	switch (KeyPressed){
	case 's':
		glutSolidSphere(0.5,5,5);
		break;
	case 'S':
		glutSolidSphere(0.5,5,5);
		break;
	case 'w':
		glutWireSphere(0.5,5,5);
		break;
	case 'W':
		glutWireSphere(0.5,5,5);
		break;
	case 27:
		exit(0);
		break;
	}
	if(glutGetModifiers()==GLUT_KEY_UP)
	{
		glutWireSphere(0.8,10,10);
	}
	if(glutGetModifiers()==GLUT_KEY_DOWN)
	{
		glutWireSphere(0.3,10,10);
	}
}
int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(300,300);
	glutInitWindowPosition(0,0);
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

