#include <stdlib.h>
#include <glut.h>
void Inicializa (void) {
	// Define a cor de fundo da janela de visualização como azul
	glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
}
// Função callback chamada para fazer o desenho
void Desenha(void) {
	//Limpa a janela de visualização com a cor de fundo especificada
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_POLYGON);
		glVertex2f(-0.2f, 0.3f);       
		glVertex2f( 0.0f, 0.5f);       
		glVertex2f(0.2f,0.3f);
		glVertex2f(0.0f,0.1f);
	glEnd();
	
	glColor3f(1.0f, 1.0f, 0.0f);
	glBegin(GL_POLYGON);
		glVertex2f(-0.5f, 0.0f);       
		glVertex2f( -0.3f, 0.2f);       
		glVertex2f(-0.1f,0.0f);
		glVertex2f(-0.3f,-0.2f);
	glEnd();
	
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_POLYGON);
		glVertex2f(0.1f, 0.0f);       
		glVertex2f( 0.3f, 0.2f);       
		glVertex2f(0.5f,0.0f);
		glVertex2f(0.3f,-0.2f);
	glEnd();
	
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_POLYGON);
		glVertex2f(-0.2f, -0.3f);       
		glVertex2f( 0.0f, -0.1f);       
		glVertex2f(0.2f,-0.3f);
		glVertex2f(0.0f,-0.5f);
	glEnd();
	//Executa os comandos OpenGL para renderização.
	glFlush();
	
	
}


int main(void) {
	glutInitWindowSize(400,400);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("Primeiro Programa");
	glutDisplayFunc(Desenha);
	Inicializa();
	glutMainLoop();
}
