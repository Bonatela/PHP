#include "glut.h"
#include <stdlib.h>


// Vari�veis para controles de navega��o
GLfloat angle, fAspect;
GLfloat rotX, rotY, rotX_ini, rotY_ini;
GLfloat obsX, obsY, obsZ, obsX_ini, obsY_ini, obsZ_ini;
int x_ini,y_ini,bot;

// Luz selecionada
int luz = 0;

// Posi��o de cada luz
GLfloat posLuz[3][4] = {
	{  10, 30,  10, 1 },
	{  10, 30,  10, 1 },
	{  10, 30,  10, 1 }
};

// Dire��o de cada luz
GLfloat dirLuz[3][3] = {
	{ 0,-1,0 },
	{ 0,-1,0 },
	{ 0,-1,0 }
};

// Cor difusa de cada luz //RGB
GLfloat luzDifusa[3][4] = {
	{ 1,0,0,1 },
	{ 0,1,0,1 },
	{ 0,0,1,1 }
};

// Cor especular de cada luz //RGB
GLfloat luzEspecular[3][4] = {
	{ 1,0,0,1 },
	{ 0,1,0,1 },
	{ 0,0,1,1 }
};





//___________________________________________________________________
// Fun��o respons�vel pela especifica��o dos par�metros de ilumina�ao
void DefineIluminacao (void)
{
    int i;
	GLfloat luzAmbiente[4]={0.2,0.2,0.2,1.0};
	// Capacidade de brilho do material
	GLfloat especularidade[4]={0.5,0.5,0.5,1.0};
	GLint especMaterial = 90;

	// Define a reflet�ncia do material
	glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);
	// Define a concentra��o do brilho
	glMateriali(GL_FRONT,GL_SHININESS,especMaterial);
	// Ativa o uso da luz ambiente
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

	// Define os par�metros das fontes de luz
	for(i=0;i<3;++i)
	{
		glLightfv(GL_LIGHT0+i, GL_AMBIENT, luzAmbiente);
		glLightfv(GL_LIGHT0+i, GL_DIFFUSE, luzDifusa[i] );
		glLightfv(GL_LIGHT0+i, GL_SPECULAR, luzEspecular[i] );
		glLightfv(GL_LIGHT0+i, GL_POSITION, posLuz[i] );
		glLightfv(GL_LIGHT0+i, GL_SPOT_DIRECTION,dirLuz[i]);
		glLightf(GL_LIGHT0 +i, GL_SPOT_CUTOFF,40.0);
		glLightf(GL_LIGHT0 +i, GL_SPOT_EXPONENT,10.0);
	}
}



#define TAM 40
#define D 2
// Fun��o para desenhar um "campo" no ambiente
void DesenhaChao(void)
{

	// Flags para determinar a cor de cada quadrado
	//bool flagx,flagz;
	int flagx,flagz;
	float x, z;
	// Define a normal apontando para cima
	glNormal3f(0,1,0);

	glBegin(GL_QUADS);
	  flagx = 0;
	  // X varia de -TAM a TAM, de D em D
	  for(x=-TAM;x<TAM;x+=D)
	  {
		// Flagx determina a cor inicial
		if(flagx) flagz = 0;
		else flagz = 1;

		// Z varia de -TAM a TAM, de D em D
		for(z=-TAM;z<TAM;z+=D)
		{
			// Escolhe cor
			if(flagz) glColor3f(0.0,0.5,0.0);
			else glColor3f(0,0.5,0);
			// E desenha o quadrado
			glVertex3f(x,0,z);
			glVertex3f(x+D,0,z);
			glVertex3f(x+D,0,z+D);
			glVertex3f(x,0,z+D);
			// Alterna cor
			flagz=!flagz;
		}
		// A cada coluna, alterna cor inicial
		flagx=!flagx;
	}
	glEnd();
}




// Fun�ao callback de redesenho da janela de visualiza��o
void Desenha(void)
{
     int i;
	// Limpa a janela de visualiza��o com a cor
	// de fundo definida previamente
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Chama a fun��o que especifica os par�metros de ilumina��o
	DefineIluminacao();

	// Desabilita a ilumina��o para desenhar as esferas
	glDisable(GL_LIGHTING);
	for(i=0;i<3;++i)
	{
		// Desenha "esferas" nas posi��es das fontes de luz
		glPushMatrix();
		glTranslatef(posLuz[i][0],posLuz[i][1],posLuz[i][2]);
		glColor3f(luzDifusa[i][1],luzDifusa[i][1],luzDifusa[i][1]);
		glutSolidSphere(1,5,5);
		glPopMatrix();
	}
	// Habilita ilumina��o novamente
	glEnable(GL_LIGHTING);

	// Altera a cor do desenho para branco
	glColor3f(1,1,1);

	// Desenha o teapot e o ch�o
	glPushMatrix();
	glTranslatef(0,7.5,0);
	glutSolidTeapot(10);
    glTranslatef(10,-7.5,0);
	glutSolidTorus(5,10,10,10);
	glPopMatrix();
	DesenhaChao();

	// Executa os comandos OpenGL
	glutSwapBuffers();
}



// Fun��o usada para especificar a posi��o do observador virtual
void PosicionaObservador(void)
{
	// Especifica sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);
	// Inicializa sistema de coordenadas do modelo
	glLoadIdentity();
	// Posiciona e orienta o observador
	glTranslatef(-obsX,-obsY,-obsZ);
	glRotatef(rotX,1,0,0);
	glRotatef(rotY,0,1,0);
}


// Fun��o usada para especificar o volume de visualiza��o
void EspecificaParametrosVisualizacao(void)
{
	// Especifica sistema de coordenadas de proje��o
	glMatrixMode(GL_PROJECTION);
	// Inicializa sistema de coordenadas de proje��o
	glLoadIdentity();

	// Especifica a proje��o perspectiva(angulo,aspecto,zMin,zMax)
	gluPerspective(angle,fAspect,0.5,1500);

	PosicionaObservador();
}



// Fun��o callback chamada para gerenciar eventos de teclas normais (ESC)
void Teclado (unsigned char tecla, int x, int y)
{
	if(tecla==27) // ESC ?
		exit(0);
	if(tecla>='0' && tecla<='2') luz = tecla - '0';
}


// Fun��o callback para tratar eventos de teclas especiais
void TeclasEspeciais (int tecla, int x, int y)
{
	switch (tecla)
	{
		case GLUT_KEY_LEFT:			posLuz[luz][0] -=2;
									break;
		case GLUT_KEY_RIGHT:		posLuz[luz][0] +=2;
									break;
		case GLUT_KEY_UP:			posLuz[luz][1] +=2;
									break;
		case GLUT_KEY_DOWN:			posLuz[luz][1] -=2;
									break;
		case GLUT_KEY_PAGE_UP:		posLuz[luz][2] -=2;
									break;
		case GLUT_KEY_PAGE_DOWN:	posLuz[luz][2] +=2;
									break;
		case GLUT_KEY_HOME:			if(angle>=10)  angle -=5;
									break;
		case GLUT_KEY_END:			if(angle<=150) angle +=5;
									break;
	}
	PosicionaObservador();
	glutPostRedisplay();
}



// Fun�o callback para eventos de bot�es do mouse
void GerenciaMouse(int button, int state, int x, int y)
{
	if(state==GLUT_DOWN)
	{
		// Salva os par�metros atuais
		x_ini = x;
		y_ini = y;
		obsX_ini = obsX;
		obsY_ini = obsY;
		obsZ_ini = obsZ;
		rotX_ini = rotX;
		rotY_ini = rotY;
		bot = button;
	}
	else bot = -1;
}





// Fun��o callback para eventos de movimento do mouse
#define SENS_ROT	5.0
#define SENS_OBS	10.0
#define SENS_TRANSL	10.0
void GerenciaMovim(int x, int y)
{
	// Bot�o esquerdo ?
	if(bot==GLUT_LEFT_BUTTON)
	{
		// Calcula diferen�as
		int deltax = x_ini - x;
		int deltay = y_ini - y;
		// E modifica �ngulos
		rotY = rotY_ini - deltax/SENS_ROT;
		rotX = rotX_ini - deltay/SENS_ROT;
	}
	// Bot�o direito ?
	else if(bot==GLUT_RIGHT_BUTTON)
	{
		// Calcula diferen�a
		int deltaz = y_ini - y;
		// E modifica dist�ncia do observador
		obsZ = obsZ_ini + deltaz/SENS_OBS;
	}
	// Bot�o do meio ?
	else if(bot==GLUT_MIDDLE_BUTTON)
	{
		// Calcula diferen�as
		int deltax = x_ini - x;
		int deltay = y_ini - y;
		// E modifica posi��es
		obsX = obsX_ini + deltax/SENS_TRANSL;
		obsY = obsY_ini - deltay/SENS_TRANSL;
	}
	PosicionaObservador();
	glutPostRedisplay();
}


// Fun��o callback chamada quando o tamanho da janela � alterado
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
	// Para previnir uma divis�o por zero
	if ( h == 0 ) h = 1;

	// Especifica as dimens�es da viewport
	glViewport(0, 0, w, h);

	// Calcula a corre��o de aspecto
	fAspect = (GLfloat)w/(GLfloat)h;

	EspecificaParametrosVisualizacao();
}


// Fun��o respons�vel por inicializar par�metros e vari�veis
void Inicializa (void)
{
	// Define a cor de fundo da janela de visualiza��o como branca
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	// Habilita a defini��o da cor do material a partir da cor corrente
	glEnable(GL_COLOR_MATERIAL);
	//Habilita o uso de ilumina��o
	glEnable(GL_LIGHTING);
	// Habilita as fontes de luz
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);
	// Habilita o depth-buffering
	glEnable(GL_DEPTH_TEST);

	// Habilita o modelo de coloriza��o de Gouraud
	glShadeModel(GL_SMOOTH);

	// Inicializa a vari�vel que especifica o �ngulo da proje��o
	// perspectiva
	angle=45;

	// Inicializa as vari�veis usadas para alterar a posi��o do
	// observador virtual
	rotX = 30;
	rotY = 0;
	obsX = obsY = 0;
	obsZ = 100;
}



// Programa Principal
int main (int argc, char** argv)
{


        glutInit (&argc, argv);
	// Define o modo de opera��o da GLUT
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	// Especifica a posi��o inicial da janela GLUT
	glutInitWindowPosition(5,5);

	// Especifica o tamanho inicial em pixels da janela GLUT
	glutInitWindowSize(1024,768);

	// Cria a janela passando como argumento o t�tulo da mesma
	glutCreateWindow("Desenho de um teapot iluminado por spots");

	// Registra a fun��o callback de redesenho da janela de visualiza��o
	glutDisplayFunc(Desenha);

	// Registra a fun��o callback de redimensionamento da janela de visualiza��o
	glutReshapeFunc(AlteraTamanhoJanela);

	// Registra a fun��o callback para tratamento das teclas normais
	glutKeyboardFunc (Teclado);

	// Registra a fun��o callback para tratamento das teclas especiais
	glutSpecialFunc (TeclasEspeciais);

	// Registra a fun��o callback para eventos de bot�es do mouse
	glutMouseFunc(GerenciaMouse);

	// Registra a fun��o callback para eventos de movimento do mouse
	glutMotionFunc(GerenciaMovim);

	// Chama a fun��o respons�vel por fazer as inicializa��es
	Inicializa();

	// Inicia o processamento e aguarda intera��o do usu�rio
	glutMainLoop();

	return 0;
}
