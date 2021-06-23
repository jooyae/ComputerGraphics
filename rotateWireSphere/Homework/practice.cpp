#include <gl/glut.h>
#include <time.h>
#include <iostream>

unsigned char PALETTE[7][3] = {
	{255,0,0}, //빨
	{255,50,0}, //주
	{255,255,0}, //노
	{0,255,0}, //초
	{0,0,255}, //파
	{0,5,255}, //남
	{100,0,255} //보
};
GLfloat Delta = 0.0;
GLint Index=0;
GLfloat Red=0.0;
GLfloat Green =0.0;
GLfloat Blue =0.0;

void MyDisplay(){
	Red = PALETTE[Index][0]/255.0f;
	Green = PALETTE[Index][1]/255.0f;
	Blue = PALETTE[Index][2]/255.0f;
	glColor3f(Red,Green,Blue);
	glBegin(GL_LINES);
		glVertex3f(-1.0+Delta,1.0,0.0);
		glVertex3f(1.0-Delta,-1.0,0.0);
		glVertex3f(-1.0,-1.0+Delta,0.0);
		glVertex3f(1.0,1.0-Delta,0.0);
		
	glEnd();
	glutSwapBuffers();
}
void MyTimer(int Value){
	if(Delta <2.0f)
		Delta =Delta + 0.01;
	else{
		Delta =0.0;
		if(++Index >= 6) Index = 0;
		glClear(GL_COLOR_BUFFER_BIT);
	}
	glutPostRedisplay();
	glutTimerFunc(10,MyTimer,0.5);
}
int main(int argc,char** argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("OpenGl Timer Animation Sample");
	glClearColor(0.0,0.0,0.0,1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0,1.0,-1.0,1.0,-1.0,1.0);
	glutTimerFunc(10,MyTimer,0.5);
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}
