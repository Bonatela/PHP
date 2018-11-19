#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <mmsystem.h>

#include "glut.h"




GLUquadricObj *circulo;


// Variaveis para controles de navegação
GLfloat angle, fAspect;
GLfloat rotX, rotY, rotX_ini, rotY_ini;
GLfloat obsX, obsY, obsZ, obsX_ini, obsY_ini, obsZ_ini;

int x_ini,y_ini,bot;
int bate = 0;
int fogo=0;
float move = 0, angulo = 0;
int placarPlayer1 = 0, placarPlayer2 = 0;



// Luz selecionada
int luz = 0;
typedef struct XY {
        float x;
        float y;
} PontoXY;


PontoXY  player1, player2,bola;



// Posi??o de cada luz
GLfloat posLuz[3][4] = {
	{  10, 30,  10, 1 },
	{  10, 30,  10, 1 },
	{  10, 30,  10, 1 }
};



// Dire??o de cada luz
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




//Iluminação
void DefineIluminacao (void)
{
        int i;

        GLfloat luzAmbiente[4]={0.2,0.2,0.2,1.0};

    /// Capacidade de brilho do material
        GLfloat especularidade[4]={0.5,0.5,0.5,1.0};
        GLint especMaterial = 90;

	/// Define a reflet?ncia do material
        glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);

	/// Define a concentra??o do brilho
        glMateriali(GL_FRONT,GL_SHININESS,especMaterial);
	/// Ativa o uso da luz ambiente
    ///	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

	/// Define os par?metros das fontes de luz
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



//Player 1
void Player1(void)
{

	///Player 1
	glPushMatrix(); glColor3f(0,1,1); 	glTranslatef(player1.x + -15,8,player1.y + 0); glScalef(1,2,1); glutSolidCube(1); 	glPopMatrix();

	glPushMatrix(); glColor3f(0,0,0); 	glTranslatef(player1.x + -15,5,player1.y + 0); glScalef(1,4,2); glutSolidCube(1); 	glPopMatrix();

	glPushMatrix(); glColor3f(0,0,0); 	glTranslatef(player1.x + -15,3,player1.y + 1); glScalef(1,4,1); glutSolidCube(1); 	glPopMatrix();

	glPushMatrix(); glColor3f(0,0,0); 	glTranslatef(player1.x + -15,3,player1.y + -1);  glScalef(1,4,1); glutSolidCube(1); 	glPopMatrix();

    glPushMatrix(); glColor3f(0,0,0); 	glTranslatef(player1.x + -14,7,player1.y + 1); glScalef(-3,-1,1); glutSolidCube(1); 	glPopMatrix();

	glPushMatrix(); glColor3f(0,0,0); 	glTranslatef(player1.x + -14,7,player1.y +-1);  glScalef(-3,-1,1);  glutSolidCube(1); 	glPopMatrix();

} //Chave Funcao Player 1


//Player 2
void Player2(void)
{

	///Player 2
	glPushMatrix(); glColor3f(1,0,0); 	glTranslatef(player2.x + 15,8,player2.y + 0);	glScalef(1,2,1); glutSolidCube(1); 	glPopMatrix();

	glPushMatrix(); glColor3f(0,0,0); 	glTranslatef(player2.x + 15,5,player2.y + 0); glScalef(1,4,2); glutSolidCube(1); 	glPopMatrix();

	glPushMatrix(); glColor3f(0,0,0); 	glTranslatef(player2.x + 15,3,player2.y + 1); glScalef(1,4,1); glutSolidCube(1); 	glPopMatrix();

	glPushMatrix(); glColor3f(0,0,0); 	glTranslatef(player2.x + 15,3,player2.y + -1); 	glScalef(1,4,1); glutSolidCube(1); 	glPopMatrix();

    glPushMatrix(); glColor3f(0,0,0); 	glTranslatef(player2.x + 14,7,player2.y + 1); glScalef(-3,-1,1); glutSolidCube(1); 	glPopMatrix();

	glPushMatrix(); glColor3f(0,0,0); 	glTranslatef(player2.x + 14,7,player2.y + -1); 	glScalef(-3,-1,1);  glutSolidCube(1); 	glPopMatrix();

} //Chave Funcao Player 2




//Desenha Bola
void DesenhaEsfera(void){

     glPushMatrix();

    //glRotatef(ang,1.1,-2.1,-1.1);

  	 glTranslatef(bola.x + 0,2.5,bola.y + 0);

     ///cor da bola - > Branca
     glColor3f(1,1,1);

     glutSolidSphere(1.5,10,100);

     glPopMatrix();
     glFlush();

}





void anima(int valor){

   glutPostRedisplay();
   glutTimerFunc(9,anima,move);
}






#define TAM 40
#define D 2

// Fun para desenhar um "chao" no ambiente
// Desenha Para Desenhar Campo
void DesenhaChao(void)
{

	   glPushMatrix();

	// linhas da quadra
		glPushMatrix();
		glColor3f(1,1,1);
		glTranslatef(0,0.1,0);
        glScalef(92,2,70);
        glutWireCube(1);
        glPopMatrix();

    // quadra
        glPushMatrix();
		glColor3f(0,0.5,0);
        glScalef(98,2,74);
        glutSolidCube(1);
        glPopMatrix();

    // quadra externa
        glPushMatrix();
       	glColor3f(1,1,1);
       	glTranslatef(0,-0.8,0);
       	glScalef(100,1.99,75);
       	glutSolidCube(1);
        glPopMatrix();

    // Area esquerda
        glPushMatrix();
		glColor3f(1,1,1);
		glTranslatef(-38.5,0.1,0);
        glScalef(15,2,35);
        glutWireCube(1);
        glPopMatrix();

        glPushMatrix();
		glColor3f(1,1,1);
		glTranslatef(-42.5,0.1,0);
        glScalef(7,2,25);
        glutWireCube(1);
        glPopMatrix();

        glPushMatrix();
        glColor3f(1.0f, 1.0f, 1.0f);
        glTranslatef(-35, 1.3, 0.0f);
        glScalef(4,4,4);
        glRotatef(90,1,0,0);
        gluDisk(circulo, 0.0, 0.18, 100,100);
        glPopMatrix();

    // Area direita
        glPushMatrix();
		glColor3f(1,1,1);
		glTranslatef(38.5,0.1,0);
        glScalef(15,2,35);
        glutWireCube(1);
        glPopMatrix();

        glPushMatrix();
		glColor3f(1,1,1);
		glTranslatef(42.5,0.1,0);
        glScalef(7,2,25);
        glutWireCube(1);
        glPopMatrix();

        glPushMatrix();
        glColor3f(1.0f, 1.0f, 1.0f);
        glTranslatef(35, 1.3, 0.0f);
        glScalef(4,4,4);
        glRotatef(90,1,0,0);
        gluDisk(circulo, 0.0, 0.18, 100,100);
        glPopMatrix();

    //Linha central
        glBegin(GL_LINES);
        glPushMatrix();
	    glLineWidth(3);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(0.0, 1.2,35.0);
        glVertex3f(0.0, 1.2,-35.0);
        glEnd();
        glPopMatrix();

    // Circulo central
        glPushMatrix();
        glColor3f(1.0f, 1.0f, 1.0f);
        glTranslatef(0, 1.3, 0.0f);
        glScalef(4,4,4);
        glRotatef(90,1,0,0);
        gluDisk(circulo, 2.9, 3.0, 100,100);
        gluDisk(circulo, 0.0, 0.18, 100,100);
        glPopMatrix();


}





//Goleiras do Campo
void goleira(void)
{

/// Goleira 1

	int i;

    ///Suporte da rede
        glPushMatrix();
        glColor3f(0.5,0.5,0.5);
        glScalef(1,12,1);
        glTranslatef(46.5,0.5,10);
        glutSolidCube(1);
        glPopMatrix();

    ///Suporte da rede
        glPushMatrix();
        glColor3f(0.5,0.5,0.5);
        glScalef(1,12,1);
        glTranslatef(46.5,0.5,-10);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glColor3f(0.5,0.5,0.5);
        glScalef(1,1,12);
        glTranslatef(46.5,12.5,0);
        glutSolidCube(1.7);
        glPopMatrix();

    ///rede
        for(i=13;i>0;i--){
            glPushMatrix();
            glColor3f(1,1,1);
            glScalef(0.1,8,i);
            glTranslatef(470,0.8,0);
            glutWireCube(1.5);

    glPopMatrix();


	}

/*----------------------------------*/


	int x;

    ///Suporte da rede
        glPushMatrix();
        glColor3f(0.5,0.5,0.5);
        glScalef(1,12,1);
        glTranslatef(-46.5,0.5,10);
        glutSolidCube(1);
        glPopMatrix();

    ///Suporte da rede
        glPushMatrix();
        glColor3f(0.5,0.5,0.5);
        glScalef(1,12,1);
        glTranslatef(-46.5,0.5,-10);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glColor3f(0.5,0.5,0.5);
        glScalef(1,1,12);
        glTranslatef(-46.5,12.5,0);
        glutSolidCube(1.7);
        glPopMatrix();


    ///rede
        for(x=13;x>0;x--){
            glPushMatrix();
            glColor3f(1,1,1);
            glScalef(0.1,8,x);
            glTranslatef(-470,0.8,0);
            glutWireCube(1.5);
            glPopMatrix();
	}


} //chave da funcao






// Janela de Visualizaçao
void Desenha(void)
{
     int i;

	// Limpa a janela de visualiza??o com a cor
	// de fundo definida previamente
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Chama a fun??o que especifica os par?metros de ilumina??o
	DefineIluminacao();

	// Desabilita a ilumina??o para desenhar as esferas
	glDisable(GL_LIGHTING);
	for(i=0;i<3;++i)
	{
		// Desenha "esferas" nas posi??es das fontes de luz
		glPushMatrix();
		glTranslatef(posLuz[i][0],posLuz[i][1],posLuz[i][2]);
		glColor3f(luzDifusa[i][0],luzDifusa[i][1],luzDifusa[i][2]);
	//	glutSolidSphere(1,5,5);
		glPopMatrix();
	}

	// Habilita ilumina??o novamente
	glEnable(GL_LIGHTING);

	// Altera a cor do desenho para branco
	glColor3f(1,1,1);
	DesenhaChao();
	Player1();
	Player2();
    goleira();
    DesenhaEsfera();

	// Executa os comandos OpenGL
	glutSwapBuffers();
}






// Funcao Teclado + Player 1 & Player 2 + Bola
void Teclado (unsigned char tecla, int x, int y)
{/*
	if(tecla==27) // ESC ?
		exit(0);
	if(tecla>='0' && tecla<='2') luz = tecla - '0';
	   glutPostRedisplay();


   if (tecla=='l')
       fogo = !fogo;
       glutPostRedisplay();
*/




///Player 1

    if(tecla == 's'){
        if(player1.y < (45 - 0.80)){

            if(player1.y == -0.8f){ player1.y = 0;  }else { player1.y  = player1.y + 0.8;}

            }
    }



    if(tecla == 'd'){
        if(player1.x <= 60){player1.x = player1.x + 0.8f;}
    }


    if(tecla == 'd'){
        if(player1.x <= 60 && bola.x <= (player1.x -13)&& bola.y >= (player1.y -1) && bola.y <= (player1.y + 1)){player1.x = player1.x + 0.8f;bola.x +=2.0f;}
    }


    if(tecla == 'a'){
         if(player1.x >= -25){player1.x = player1.x - 0.8f;}
    }


    /*
    if(tecla == 'a'){
       if(player1.x >= -25 && bola.x <=player1.x  && bola.y >= (player1.y -1) && bola.y <= (player1.y + 1)){
        player1.x = player1.x - 0.8f;
        bola.x = bola.x - 2.0f;
       }
    }
    */



    if(tecla == 'w'){
        if(player1.y > (-25 + 0.8)){

            if(player1.y == 0.8f){ player1.y = 0;  }else { player1.y  = player1.y - 0.8;}
        }
    }






///Player 2


    if(tecla == 'u'){
        if(player2.y > (-25 + 0.80)){if(player2.y == 0.8f){ player2.y = 0;  }else { player2.y  = player2.y - 0.8;}}
    }



    if(tecla == 'k'){
        if(player2.x <= 30 ){

            player2.x = player2.x + 0.8f;
        }
    }


    if(tecla == 'h'){
        if(player2.x >= -55 ){

            player2.x = player2.x - 0.8f;
        }
    }


    if(tecla == 'j'){
        if(player2.y < (45 - 0.8)){

            if(player2.y == -0.8){ player2.y = 0;  }else { player2.y  = player2.y + 0.8;}
        }
    }




///começa jogo

    if (tecla == 't')
         move = 0;

    glutPostRedisplay();
}





// Fun??o usada para especificar a posi??o do observador virtual
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






// Fun??o usada para especificar o volume de visualiza??o
void EspecificaParametrosVisualizacao(void)
{
	// Especifica sistema de coordenadas de proje??o
	glMatrixMode(GL_PROJECTION);
	// Inicializa sistema de coordenadas de proje??o
	glLoadIdentity();

	// Especifica a proje??o perspectiva(angulo,aspecto,zMin,zMax)
	gluPerspective(angle,fAspect,0.5,1500);

	PosicionaObservador();
}





// Fun??o callback para tratar eventos de teclas especiais
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
	glutPostRedisplay();
}





// Fun??o callback para eventos de bot?es do mouse
void GerenciaMouse(int button, int state, int x, int y)
{
	if(state==GLUT_DOWN)
	{
		// Salva os par?metros atuais
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






// Mouse
#define SENS_ROT	5.0
#define SENS_OBS	10.0
#define SENS_TRANSL	10.0
void GerenciaMovim(int x, int y)
{
	// Bot?o esquerdo ?
	if(bot==GLUT_LEFT_BUTTON)
	{
		// Calcula diferen?as
		int deltax = x_ini - x;
		int deltay = y_ini - y;
		// E modifica ?ngulos
		rotY = rotY_ini - deltax/SENS_ROT;
		rotX = rotX_ini - deltay/SENS_ROT;
	}
	// Bot?o direito ?
	else if(bot==GLUT_RIGHT_BUTTON)
	{
		// Calcula diferen?a
		int deltaz = y_ini - y;
		// E modifica dist?ncia do observador
		obsZ = obsZ_ini + deltaz/SENS_OBS;
	}
	// Bot?o do meio ?
	else if(bot==GLUT_MIDDLE_BUTTON)
	{
		/// Calcula diferen?as
		int deltax = x_ini - x;
		int deltay = y_ini - y;
		/// E modifica posi??es
		obsX = obsX_ini + deltax/SENS_TRANSL;
		obsY = obsY_ini - deltay/SENS_TRANSL;
	}
	PosicionaObservador();
	glutPostRedisplay();
}







// Função callback chamada quando o tamanho da janela alterado
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
	/// Para previnir uma divisao por zero
	if ( h == 0 ) h = 1;

	/// Especifica as dimens?es da viewport
	glViewport(0, 0, w, h);

	/// Calcula a corre??o de aspecto
	fAspect = (GLfloat)w/(GLfloat)h;

	EspecificaParametrosVisualizacao();
}





// Fun??o respons?vel por inicializar par?metros e vari?veis
void Inicializa (void)
{
	/// Define a cor de fundo da janela de visualiza??o como branca
	glClearColor(0.0f, 0.0f, 1.0f, 0.0f);

	/// Habilita a defini??o da cor do material a partir da cor corrente
	glEnable(GL_COLOR_MATERIAL);
	///Habilita o uso de ilumina??o
	glEnable(GL_LIGHTING);
	/// Habilita as fontes de luz
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);
	/// Habilita o depth-buffering
	glEnable(GL_DEPTH_TEST);

	/// Habilita o modelo de coloriza??o de Gouraud
	glShadeModel(GL_SMOOTH);

	/// Inicializa a vari?vel que especifica o ?ngulo da proje??o
	/// perspectiva
	angle=45;

	/// Inicializa as vari?veis usadas para alterar a posi??o do
	/// observador virtual
	rotX = 30;
	rotY = 0;
	obsX = obsY = 0;
	obsZ = 100;
}





// {Main}
int main (int argc, char** argv)
{

    glutInit (&argc, argv);

        /// Define o modo de opera??o da GLUT
            glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

        /// Especifica a posi??o inicial da janela GLUT
            glutInitWindowPosition(5,5);

        /// Especifica o tamanho inicial em pixels da janela GLUT
            glutInitWindowSize(800,600);

        /// Cria a janela passando como argumento o t?tulo da mesma
            glutCreateWindow("FiFao");
            glutTimerFunc(100,anima,move);

            circulo = gluNewQuadric();

        /// Registra a fun??o callback de redesenho da janela de visualiza??o
            glutDisplayFunc(Desenha);

        /// Registra a fun??o callback de redimensionamento da janela de visualiza??o
            glutReshapeFunc(AlteraTamanhoJanela);

        /// Registra a fun??o callback para tratamento das teclas normais
            glutKeyboardFunc (Teclado);

        /// Registra a fun??o callback para tratamento das teclas especiais
            glutSpecialFunc (TeclasEspeciais);

        /// Registra a fun??o callback para eventos de bot?es do mouse
            glutMouseFunc(GerenciaMouse);

        /// Registra a fun??o callback para eventos de movimento do mouse
            glutMotionFunc(GerenciaMovim);

        /// Chama a fun??o respons?vel por fazer as inicializa??es
            Inicializa();

        /// Inicia o processamento e aguarda intera??o do usu?rio
            glutMainLoop();

    return 0;

} //Main


