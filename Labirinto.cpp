#include <stdlib.h>
#include <windows.h>
#include <glut.h>
#include<time.h>

GLfloat tx = 0,ty=0, aux=0;
unsigned int x1=0,x2=0,x3=0;
void Inicializa (void) {
    // Define a cor de fundo da janela de visualização como azul
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    //gluOrtho2D(-4.1,4.1,-4.1,4.1);
}

void triangulo() {
	glLineWidth(2);
	glTranslatef(tx, ty, 0.0f);
	glBegin(GL_TRIANGLES);
		glColor3f(0,1,0);
		glVertex3f(-0.2,-4.0,0);
		glVertex3f(-0.7,-4.0,0);
		glVertex3f(-0.45,-3.5,0);
	glEnd();
	glFlush();
}
// Função callback chamada para fazer o desenho
void Desenha(void) {
    glMatrixMode(GL_MODELVIEW);
	// Inicializa a matriz de transformação corrente
	glLoadIdentity();
     
	// Limpa a janela de visualização com a cor  
	// de fundo definida previamente
	glClear(GL_COLOR_BUFFER_BIT);

    glLineWidth(10);
    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2d(-4, -4);
        glVertex2d(-4, 4.1);

        glVertex2d(-4.1, -4);
        glVertex2d(-1, -4);

        glVertex2d(-3, 4);
        glVertex2d(4.1, 4);

        glVertex2d(4, 4);
        glVertex2d(4, -4.1);

        glVertex2d(4, -4);
        glVertex2d(0, -4);

        glVertex2d(-4, -1);
        glVertex2d(-3, -1);

        glVertex2d(-3, -1);
        glVertex2d(-3, -3);

        glVertex2d(-3, 0);
        glVertex2d(-2, 0);

        glVertex2d(-2, 0);
        glVertex2d(-2, -3);

        glVertex2d(-1, -4.1);
        glVertex2d(-1, -3);

        glVertex2d(-1, -3);
        glVertex2d(1, -3);

        glVertex2d(0, 0);
        glVertex2d(0, -2);

        glVertex2d(0, -1);
        glVertex2d(1, -1);

        glVertex2d(1, -1);
        glVertex2d(1, -2);

        glVertex2d(1, -2);
        glVertex2d(2, -2);

        glVertex2d(2, -2);
        glVertex2d(2, -4);

        glVertex2d(3, 1);
        glVertex2d(3, -3);

        glVertex2d(3, 4);
        glVertex2d(3, 2);

        glVertex2d(1, 0);
        glVertex2d(2, 0);

        glVertex2d(2, 0);
        glVertex2d(2, -1);

        glVertex2d(2, -1);
        glVertex2d(3, -1);

        glVertex2d(-1, 1);
        glVertex2d(-1, -1);

        glVertex2d(-3, 1);
        glVertex2d(1, 1);

        glVertex2d(-4, 2);
        glVertex2d(-3, 2);

        glVertex2d(-3, 2);
        glVertex2d(-3, 1);

        glVertex2d(2, 1);
        glVertex2d(3, 1);

        glVertex2d(2, 3);
        glVertex2d(2, 1);

        glVertex2d(1, 3);
        glVertex2d(2, 3);

        glVertex2d(1, 3);
        glVertex2d(1, 2);

        glVertex2d(0, 2);
        glVertex2d(1, 2);

        glVertex2d(-1, 3);
        glVertex2d(0, 3);

        glVertex2d(-1, 3);
        glVertex2d(-1, 2);

        glVertex2d(-1, 2);
        glVertex2d(-2, 2);

        glVertex2d(-2, 2);
        glVertex2d(-2, 3);

        glVertex2d(-2, 3);
        glVertex2d(-3, 3);

        glVertex2d(-3, 3);
        glVertex2d(-3, 4);
    glEnd();
    
    // Desenha um objeto modelado com transformações hierárquicas
    
	glPushMatrix();                   
                    
	glTranslatef(tx,ty,0.0f);
    
	glPushMatrix();
	glColor3f(1.0f,0.0f,0.0f);
	triangulo();
	
    glPushMatrix();  
    // Executa os comandos OpenGL 
    glPopMatrix();
    
    //Executa os comandos OpenGL para renderização.
    glFlush();
}

void AlteraTamanhoJanela(GLsizei w, GLsizei h) {
	GLsizei largura, altura;

	// Evita a divisao por zero
	if(h == 0) h = 1;

	// Atualiza as variáveis
	largura = w;
	altura = h;

	// Especifica as dimensões da Viewport
	glViewport(0, 0, largura, altura);

	// Inicializa o sistema de coordenadas
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Estabelece a janela de seleção (esquerda, direita, inferior,
	// superior) mantendo a proporção com a janela de visualização
	if (largura <= altura) {
		gluOrtho2D (-4.1f, 4.1f, -4.1f*altura/largura, 4.1f*altura/largura);
		aux=4.1f*altura/largura;
	}
	else {
		gluOrtho2D (-4.1f*largura/altura, 4.1f*largura/altura, -4.1f, 4.1f);
		aux=4.1f*largura/altura;
	}
}

// Função callback chamada para gerenciar eventos de teclas
void Teclado (unsigned char key, int x, int y) {
	if (key == 27)
		exit(0);
}

void TeclasEspeciais(int key, int x, int y)
{
	// Move a base
	if(key == GLUT_KEY_LEFT)
	{
		tx-=0.2;
		if ( tx < -4.1f )
			tx = -4.1f; 
	}
	if(key == GLUT_KEY_RIGHT)
	{
		tx+=0.2;
		if ( tx > 4.1f )
			tx = 4.1f; 			
	}
	if(key == GLUT_KEY_UP)
	{
		ty+=0.2;
		if ( ty > aux )
			ty = aux; 		
	}
	if(key == GLUT_KEY_DOWN)
	{
		ty-=0.2;
		if ( ty < -aux )
			ty = -aux; 
	}
	glutPostRedisplay();
}


int main(void) {
    glutInitWindowSize(400,400);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Labirinto");
    Desenha();
    glutDisplayFunc(Desenha);
    glutReshapeFunc(AlteraTamanhoJanela);
	glutSpecialFunc(TeclasEspeciais);
	glutKeyboardFunc(Teclado);
    Inicializa();
    glutMainLoop();
}
