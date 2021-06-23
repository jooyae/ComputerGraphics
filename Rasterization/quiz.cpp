#include <glut.h>
#include <iostream>
GLfloat Delta =0.0;
GLboolean IsSolidTeapot = true;
int Width, Height;
void Init()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();
	glOrtho(-2.0, 2.0, -2.0, 2.0, 0.5, 5.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	int a = 0;
	int b = 0;
	int c = 0;
}

void DrawScene()
{	
	//���� 7-1 �ڵ� �����Ͽ� teapot �ֱ�
	// �������: 1.0�� ũ�⸦ �����
	glColor3f(0.7,0.7,0.7);
	glPushMatrix();
	glTranslatef(0.0,-1.0,0.0);
	glBegin(GL_QUADS);
		glVertex3f(2.0,0.0,2.0);
		glVertex3f(2.0,0.0,-2.0);
		glVertex3f(-2.0,0.0,-2.0);
		glVertex3f(-2.0,0.0,2.0);
	glEnd();
	glPopMatrix();
	glColor3f(0.3,0.3,0.7);
	glPushMatrix();
		glTranslatef(0.0,0.0,-0.5);
		glutWireTeapot(1.0);
	glPopMatrix();

}

void MyDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_POLYGON);
			glVertex3f(-0.5,-0.5,0.0);
			glVertex3f(0.5,-0.5,0.0);
			glVertex3f(0.5,0.5,0.0);
			glVertex3f(-0.5,0.5,0.0);
	if(IsSolidTeapot)
		glutSolidTeapot(1.0);
	else	
		glutWireTeapot(1.0);
	glViewport(0,0,Width/2, Height/2);
	glPushMatrix();
		gluLookAt(0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0,0.0); 
		DrawScene();
	glPopMatrix();
	glViewport(Width/2,0,Width/2, Height/2);
	glPushMatrix();
		gluLookAt(1.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0);
		DrawScene();
	glPopMatrix();
	glViewport(0,Height/2,Width/2, Height/2);
	glPushMatrix();
		gluLookAt(0.5,-0.5,0.0,0.0,0.0,-1.0,0.0,1.0,0.0);
		DrawScene();
	glPopMatrix();
	glViewport(Width/2, Height/2, Width/2, Height/2);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
		glLoadIdentity();
		gluPerspective(30,1.0,3.0,50.0);
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
			gluLookAt(5.0,5.0,5.0,0.0,0.0,0.0,0.0,1.0,0.0);
			DrawScene();
		glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glEnd();
	glFlush();
		



}

void MyReshape(int w, int h)  //�ְ���� 
{
	Width = w;
	Height = h;
	glViewport(0,0,(GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(30,(GLdouble)w/(GLdouble)h, 1.0,50.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(1.0,1.0,1.0,0.0,0.0,0.0,0.0,1.0,0.0);
	glutPostRedisplay();
}


void MyKeyboard(unsigned char KeyPressed, int a, int b)
{
	switch(KeyPressed){
	case 'x':
		glRotatef(30,1.0,0.0,0.0);
		break;
	case 'X':
		glRotatef(-30,1.0,0.0,0.0);
		break;
	case 'y':
		glRotatef(30,0.0,1.0,0.0);
		break;
	case 'Y':
		glRotatef(-30,0.0,1.0,0.0);
		break;
	case 'z':
		glRotatef(30,0.0,0.0,1.0);
		break;
	case 'Z':
		glRotatef(-30,0.0,0.0,1.0);
		break;
}
}


void MySpecialKey(int key, int x, int y)
{
	switch(key) {
	case '100':
		Delta = Delta + 0.1;
		break;
	case '101':
		Delta = Delta + 0.1;
		break;
	case '102':
		Delta = Delta + 0.1;
		break;
	case '103':
		Delta = Delta + 0.1;
		break;

	}
}

void MyMainMenu(int entryID)
{
	if(entryID == 1)
		IsSolidTeapot = true;
	else if(entryID == 2)
		IsSolidTeapot = false;
	else if(entryID == 3)
		exit(0);
	glutPostRedisplay();


}

int main(int argc, char** argv)
{
	// �⺻ window size�� 500, 500���� ������
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL Sample Drawing");
	Init();
	glutDisplayFunc(MyDisplay);
	glutReshapeFunc(MyReshape);
	glutKeyboardFunc(MyKeyboard);

	glClearColor(1.0,1.0,1.0,1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0,1.0,-1.0,1.0,-1.0,1.0);
	GLint MyMainMenuID = glutCreateMenu(MyMainMenu);
	glutAddMenuEntry("Solid",1);
	glutAddMenuEntry("Wire",2);
	glutAddMenuEntry("Exit",3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutDisplayFunc(MyDisplay);
	// ������ �̺�Ʈ���� ���� �κ�
	// �޴��̹�Ʈ������ ���콺 ������ Ű�� �޴�����
	// x,y,z Ű���忡 ���� �̺�Ʈ
	// ȭ��ǥ ���� Ű�� ���� �̺�Ʈ
	// ȭ�� ũ�� ���濡 ���� �̺�Ʈ
	// ���÷��� �̺�Ʈ
	glutMainLoop();
	return 0;
}