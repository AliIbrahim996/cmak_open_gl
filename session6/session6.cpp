#include <Windows.h>
#include <stdio.h>
#include "GLUT.h"
#include "GLAUX.H"
#pragma comment(lib, "legacy_stdio_definitions.lib")
#pragma comment(lib, "GLAUX.LIB")

static int spin=0;

static void redraw(void);
int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(400,400);
   	glutCreateWindow("First Example");
	glutDisplayFunc(redraw);	
	glMatrixMode(GL_PROJECTION);					
	gluPerspective(45,1.0,10.0,200.0);
	glMatrixMode(GL_MODELVIEW);
	
	glutMainLoop();
	return 0; 
}		

//static void redraw(void) { 
//glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); glLoadIdentity(); 
//glTranslatef(-12.0f,-12.0f,-70.0f); 
//    /*smooth /* œ—Ã ·Ê‰Ì */
//	glShadeModel(GL_SMOOTH); //GL_SMOOTH   ›⁄Ì· ‰„ÿ «· Ÿ·Ì· 
//	glBegin(GL_TRIANGLES);     // —”„ „À·À 
//	glColor3f(1.0f,0.0f,0.0f);// √Õ„— 
//	glVertex3f( 0.0f, 10.0f, 0.0f); 
//	glColor3f(0.0f,1.0f,0.0f);// √Œ÷— 
//	glVertex3f(-10.0f,-10.0f, 0.0f); 
//	glColor3f(0.0f,0.0f,1.0f);// √“—ﬁ 
//	glVertex3f( 10.0f,-10.0f, 0.0f); 
//	glEnd();// ‰Â«Ì… «·„À·À 
//	/*flat /*·Ê‰ Ê«Õœ */
//	glShadeModel(GL_FLAT);  //GL_FLAT   ›⁄Ì· ‰„ÿ «· Ÿ·Ì· 
//	glLoadIdentity(); 
//	glTranslatef(15.0f,-12.0f,-70.0f); 
//	glBegin(GL_TRIANGLES);// —”„ „À·À 
//	glColor3f(1.0f,0.0f,0.0f);// √Õ„— 
//	glVertex3f( 0.0f, 10.0f, 0.0f); 
//	glColor3f(0.0f,1.0f,0.0f);// √Œ÷— 
//	glVertex3f(-10.0f,-10.0f, 0.0f); 
//	glColor3f(0.0f,0.0f,1.0f);// √“—ﬁ 
//	glVertex3f( 10.0f,-10.0f, 0.0f); 
//	glEnd(); 
//	glutSwapBuffers();
//	} 


static void redraw(void) { 
	GLfloat position[] = { 0.0, 0.0, 1.5, 1.0 };
	glClearColor(1.0,0.0,0.0,0.0); 
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); glPushMatrix(); 
	glTranslatef(0.0f,0.0f,-50.0); 
	glPushMatrix(); 
		glRotated ((GLdouble) spin, 1.0, 0.0, 0.0);
		glRotated (0.0, 1.0, 0.0, 0.0);
		glLightfv (GL_LIGHT0, GL_POSITION, position);
		glTranslated (0.0, 0.0, 15.0); 
		glDisable (GL_LIGHTING); 
		glColor3f (1.0, 0.0, 1.0);
		auxWireSphere(10.0);//—»ÿ «·÷Ê¡ „⁄ „ﬂ⁄» ”·ﬂÌ ·—ƒÌ… Õ—ﬂ Â
		glEnable (GL_LIGHTING);
		glEnable(GL_LIGHT0);
	glPopMatrix(); 
	auxSolidTorus(2.75, 8.5); 
	glPopMatrix(); 
	spin = (spin+1) % 360; 
	glutPostRedisplay(); 
	glutSwapBuffers();
}


