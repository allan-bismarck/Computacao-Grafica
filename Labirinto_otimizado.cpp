#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <glut.h>
#include <time.h>
#include <math.h>
#include<string.h>

GLfloat tx = 0,ty = 0, aux=0, t1x=0, t2x=0, t3x=0, t1y=0, t2y=0, t3y=0, circle_points = 50;
unsigned int x1=1,x2=1,x3=1,x4=0,x5=1,x6=0,x7=0,x8=0,x9=0, i=0;
double angle = 0;
int janelas[2], contador=4;
char frase[30];
void Desenha(void);
void triangulo(void);
void AlteraTamanhoJanela(GLsizei, GLsizei );
void Teclado (unsigned char , int , int );
void Mouse(int, int, int, int );
void TeclasEspeciais(int, int, int );

void DesenhaTexto(void *font, char *string) {
	// Exibe caractere a caractere
	while(*string)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15,*string++); 
}

void DesenhaTextoStroke(void *font, char *string) {  
	// Exibe caractere a caractere
	while(*string)
		glutStrokeCharacter(GLUT_STROKE_ROMAN,*string++); 
}

void Derrota(void) {		
	sprintf(frase,"Derrota");
	DesenhaTextoStroke(GLUT_STROKE_ROMAN,frase);
	glPopMatrix();

	glColor3f(0,0,1);
    glRasterPos2f(-47,-10); 
    sprintf(frase,"Vidas Restantes: %d",contador);
	DesenhaTexto(GLUT_BITMAP_9_BY_15,frase);
	glRasterPos2f(-70,-20); 
    sprintf(frase,"Clique na tela para continuar...");
	DesenhaTexto(GLUT_BITMAP_9_BY_15,frase);
	// Exibe o desenha na janela
	glutSwapBuffers();
}

void Vitoria(void) {		
	sprintf(frase,"Vitoria");
	DesenhaTextoStroke(GLUT_STROKE_ROMAN,frase);
	glPopMatrix();

	glColor3f(0,0,1);
    glRasterPos2f(-30,-10); 
    sprintf(frase,"Parabens!");
	DesenhaTexto(GLUT_BITMAP_9_BY_15,frase);
	glRasterPos2f(-70,-20); 
    sprintf(frase,"Clique na tela para continuar...");
	DesenhaTexto(GLUT_BITMAP_9_BY_15,frase);
	// Exibe o desenha na janela
	glutSwapBuffers();
}

void Prepara_tela() {
	glutSetWindow(janelas[1]);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100,100,-100,100);
	glMatrixMode(GL_MODELVIEW);
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	// Limpa a janela de visualização com a cor de fundo definida
	glClear(GL_COLOR_BUFFER_BIT);
	// Define a cor para os textos: preto
	glColor3f(1,0,0);
	// Posiciona o texto stroke usando transformações geométricas
	glPushMatrix();	
	glTranslatef(-50,0,0);
	glScalef(0.2, 0.2, 0.2); // diminui o tamanho do fonte
	glLineWidth(2); // define a espessura da linha
}

void Mouse2(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) {
    	if (state == GLUT_DOWN) {
    		glutDestroyWindow(janelas[1]);
    		glutSetWindow(janelas[0]);
    		tx=0;
    		ty=0;
        }
    }
    glutPostRedisplay();
}

void triangulo() {
	glLineWidth(2);
	glTranslatef(tx, ty, 0.0f);
	glBegin(GL_TRIANGLES);
		glColor3f(x4,x5,x6);
		t1x= (-0.875);
		t2x= (-0.125);
		t1y=t2y=(-4.0);
		t3x=(-0.5);
		t3y=(-3.25);
		glVertex3f(t1x,t1y,0);
		glVertex3f(t2x,t2y,0);
		glVertex3f(t3x,t3y,0);
	glEnd();
	glFlush();
}

// Função callback chamada para fazer o desenho
void Desenha(void) {
	glMatrixMode(GL_PROJECTION);
	glClearColor(x1, x2, x3, 1.0f);
    glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT);

    glLineWidth(5);
    glBegin(GL_LINES);
        glColor3f(x7, x8, x9);
        glVertex2d(-4, -4);
        glVertex2d(-4, 4.1);

        glVertex2d(-4, -4);
        glVertex2d(-1, -4);

        glVertex2d(-3, 4);
        glVertex2d(4, 4);

        glVertex2d(4, 4);
        glVertex2d(4, -4);

        glVertex2d(4, -4);
        glVertex2d(0, -4);

		//
		
        glVertex2d(-4, -1);
        glVertex2d(-3, -1);

		

        glVertex2d(-3, -1);
        glVertex2d(-3, -3);

        glVertex2d(-3, 0);
        glVertex2d(-2, 0);

        glVertex2d(-2, 0);
        glVertex2d(-2, -3);

        glVertex2d(-1, -4);
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
           
	glBegin(GL_LINE_LOOP);
		for (i = 0; i < circle_points; i++) {
			angle = 2*M_PI*i/circle_points;
			glVertex2f(-3.5+(cos(angle)/4), 3.60+(sin(angle)/4));
		}
	glEnd();
	
	triangulo();
		     
    if(true){
    	printf("\nPonto 1: %.2f, %.2f\n", (t1x+tx), (t1y+ty));
    	printf("Ponto 2: %.2f, %.2f\n", (t2x+tx), (t2y+ty));
    	printf("Ponto 3: %.2f, %.2f\n", (t3x+tx), (t3y+ty));
    }
    
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB );
    glutInitWindowSize(400,400);
    
    if(
    
    // Configurção do toque nas paredes verticais (da direita pra esquerda)
    (((t2x+tx)>=3.95))||
	((((t2x+tx)>=(2.95))&&((t1x+tx)<3.05))&&(((((t1y+ty)>(-3))&&((t1y+ty)<=1))||(((t3y+ty)>(-3))&&((t3y+ty)<=1)))||((t1y+ty)>2)||((t3y+ty)>2.05)))||
	((((t2x+tx)>=(1.95))&&((t1x+tx)<2.05))&&(((((t1y+ty)>=(-3.95))&&((t1y+ty)<=(-1.95)))||((((t1y+ty)>=(-1.05))&&((t1y+ty)<=(0.05)))||(((t3y+ty)>=(-1.05))&&((t3y+ty)<=(0.05)))))||((((t1y+ty)>=(0.95))&&((t1y+ty)<=(3.05)))||(((t3y+ty)>=0.95)&&((t3y+ty)<=3.05)))))||
	((((t2x+tx)>=(0.95))&&((t1x+tx)<1.05))&&(((((t1y+ty)>=(2.05))&&((t1y+ty)<=(3)))||(((t3y+ty)>=2.05)&&((t3y+ty)<=3)))||((((t1y+ty)>=(-2))&&((t1y+ty)<=(-1)))||(((t3y+ty)>=(-2))&&((t3y+ty)<=(-1))))))||
	((((t2x+tx)>=(-0.05))&&((t1x+tx)<(0.05)))&&(((((t1y+ty)>=(-2.05))&&((t1y+ty)<(0))))||(((t3y+ty)>=(-2.05))&&((t3y+ty)<0))))||
	((((t2x+tx)>=(-1.05))&&((t1x+tx)<(-0.95)))&&((((t1y+ty)>=(-4))&&((t1y+ty)<=(-3)))||((((t1y+ty)>=(-1))&&((t1y+ty)<=(0.95)))||(((t3y+ty)>=(-1))&&((t3y+ty)<=(0.95))))||((((t1y+ty)>=(2))&&((t1y+ty)<=(3)))||(((t3y+ty)>=2)&&((t3y+ty)<=3)))))||
	((((t2x+tx)>=(-2.05))&&((t1x+tx)<(-1.95)))&&(((((t1y+ty)>=(-3))&&((t1y+ty)<=(0)))||(((t3y+ty)>=(-3))&&((t3y+ty)<=0)))||((((t1y+ty)>=(1.95))&&((t1y+ty)<=(2.95)))||(((t3y+ty)>=1.95)&&(t3y+ty)<=2.95))))||
	((((t2x+tx)>=(-3.05))&&((t1x+tx)<(-2.95)))&&(((((t1y+ty)>=(3))&&((t1y+ty)<=(4)))||((t3y+ty)>=3))||((((t1y+ty)>=(1))&&((t1y+ty)<=(2)))||(((t3y+ty)>=1)&&((t3y+ty)<=2)))||((((t1y+ty)>=(-3))&&((t1y+ty)<=(-1)))||(((t3y+ty)>=(-3))&&((t3y+ty)<=(-1))))))||
	((t1x+tx)<=(-3.95))||
	
	//Configuração do toque nas paredes horizontais (de baixo para cima)
	(((t1y+ty)<=(-3.95))&&(((t2x+tx)>0)||((t1x+tx)<(-1))))||
	((((t1y+ty)<=(-2.95))&&((t1y+ty)>=(-3.05))||(((t3y+ty)>=(-3.05))&&((t3y+ty)<=(-2.95))))&&((((t2x+tx)<1)&&((t2x+tx)>(-1)))||(((t1x+tx)>(-1))&&((t1x+tx)<1))))||
	((((t1y+ty)<=(-1.95))&&((t1y+ty)>=(-2.05))||(((t3y+ty)>=(-2.05))&&((t3y+ty)<=(-1.95))))&&((((t2x+tx)<2)&&((t2x+tx)>1.05))||(((t1x+tx)>1.05)&&((t1x+tx)<2))))||
	((((t1y+ty)<=(-0.95))&&((t1y+ty)>=(-1.05))||(((t3y+ty)>=(-1.05))&&((t3y+ty)<=(-0.95))))&&(((((t2x+tx)<2.95)&&((t2x+tx)>2.05))||(((t1x+tx)>(2.05))&&((t1x+tx)<2.95)))||((((t2x+tx)<1.05)&&((t2x+tx>0.05)))||(((t1x+tx)>0.05)&&((t1x+tx)<1.05)))||(((((t2x+tx)<(-2.95))&&((t2x+tx)>(-4))))||(((t1x+tx)>(-4))&&((t1x+tx)<(-2.95))))))||
	((((t1y+ty)<=(0.05))&&((t1y+ty)>=(-0.05))||(((t3y+ty)>=(-0.05))&&((t3y+ty)<=(0.05))))&&(((((t2x+tx)<(2))&&((t2x+tx)>1))||(((t1x+tx)>(2))&&((t1x+tx)<1)))||((((t2x+tx)<(-2))&&((t2x+tx)>(-3)))||(((t1x+tx)>(-3))&&((t1x+tx)<(-2))))))||
	((((t1y+ty)<=(1.05))&&((t1y+ty)>=(0.95))||(((t3y+ty)>=(0.95))&&((t3y+ty)<=(1.05))))&&(((((t2x+tx)<(1))&&((t2x+tx)>(-2.95)))||(((t1x+tx)>(-2.95))&&((t1x+tx)<1)))||((((t2x+tx)<3)&&((t2x+tx)>2.05))||((t1x+tx)>2.05)&&((t1x+tx)<3))))||
	((((t1y+ty)<=(2.05))&&((t1y+ty)>=(1.95))||(((t3y+ty)>=(1.95))&&((t3y+ty)<=(2.05))))&&(((((t2x+tx)<(-3))&&((t2x+tx)>(-3.95)))||(((t1x+tx)>(-3.95))&&((t1x+tx)<(-3))))||((((t2x+tx)<(-1.05))&&((t2x+tx)>(-1.95)))||(((t1x+tx)>(-1.95))&&((t1x+tx)<(-1.05))))||((((t2x+tx)<(0.95))&&((t2x+tx)>0))||(((t1x+tx)>(0))&&((t1x+tx)<0.95)))))||
	((((t1y+ty)<=(3.05))&&((t1y+ty)>=(2.95))||(((t3y+ty)>=(2.95))&&((t3y+ty)<=(3.05))))&&(((((t2x+tx)<(-2))&&((t2x+tx)>(-2.95)))||(((t1x+tx)>(-2.95))&&((t1x+tx)<(-2))))||(((((t2x+tx)<(0))&&((t2x+tx)>(-1))))||(((t1x+tx)>(-1))&&((t1x+tx)<0)))||((((t2x+tx)<(2.05))&&((t2x+tx)>1))||(((t1x+tx)>(1))&&((t1x+tx)<2.05)))))||
	(((((t1y+ty)<=(4.05))&&((t1y+ty)>=(3.95)))||((t3y+ty)>=3.95))&&((((t2x+tx)>(-2.95))||((t1x+tx)>(-2.95)))))
	
	){
    	printf("Toque\n");
    	contador--;
    	if(contador==0) {
    		printf("\nPERDEU!!!\n");
    		exit(0);
		}
		janelas[1]=glutCreateWindow("Derrota");
		Prepara_tela();
		glutDisplayFunc(Derrota);
		glutMouseFunc(Mouse2);
    }
	
	if(((t3y+ty)>=3.35)&&(((t1x+tx)>=(-3.95)&&(t1x+tx)<(-3.05))||(((t2x+tx)>(-3.05))&&((t2x+tx)<(-3.95))))){
		printf("\nGANHOU!!!\n");
		contador=4;
		janelas[1]=glutCreateWindow("Vitoria");
		Prepara_tela();
		glutDisplayFunc(Vitoria);
		glutMouseFunc(Mouse2);
	}
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
		tx-=0.05;
	}
	if(key == GLUT_KEY_RIGHT)
	{
		tx+=0.05;		
	}
	if(key == GLUT_KEY_UP)
	{
		ty+=0.05;		
	}
	if(key == GLUT_KEY_DOWN)
	{
		ty-=0.05; 
	}
	glutPostRedisplay();
}

void Mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) {
    	if (state == GLUT_DOWN) {
    		srand(time(NULL));
            x1=rand()%2;
            x2=rand()%2;
            x3=rand()%2;
            glColor3f(x1,x2,x3);
            do {
            	srand(time(NULL));
            	x4=rand()%2;
            	x5=rand()%2;
            	x6=rand()%2;
            }while(x1==x4&&x2==x5&&x3==x6);
            glColor3f(x4,x5,x6);
            do {
			    srand(time(NULL));
            	x7=rand()%2;
            	x8=rand()%2;
            	x9=rand()%2;
            }while((x7==x1&&x8==x2&&x9==x3)||(x7==x4&&x8==x5&&x9==x6));
            glColor3f(x7,x8,x9);
        }
    }
    glutPostRedisplay();
}


int main(void) {
    glutInitWindowSize(400,400);
	janelas[0]=glutCreateWindow("Labirinto");
	glutSetWindow(janelas[0]);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutDisplayFunc(Desenha);
    glutReshapeFunc(AlteraTamanhoJanela);
	glutKeyboardFunc(Teclado);
	glutMouseFunc(Mouse);
	glutSpecialFunc(TeclasEspeciais);
    glutMainLoop();
}
