#include "variable.h"
int flg=0;
int flg2=0;
int flg3=0;

position translation (position pp, position vecteur,int scale) {
	position pssa;

			pssa.x=pp.x+scale*vecteur.x;
			pssa.y=pp.y+scale*vecteur.y;
			pssa.z=pp.z+scale*vecteur.z;




return pssa;

}

void Animer()
{
	// rotation de la scene avant le debut de jeu (i.e:click space )->a activer apres


	float rayon = sqrt((pObs.x)*(pObs.x)+(pObs.z)*(pObs.z));

  if (r == 0)
{
    // pObs.x = rayon*sin(angle);
   //	 pObs.z= rayon*cos(angle);

      angle += 0.001;
if (angle > 360) angle = 0;

	        glutPostRedisplay();

}


/*else{
	 pObs.x = rayon*sin(angle);
   	 pObs.z=  rayon*cos(angle);
}*/
}


void GererClavier(unsigned char touche, int x, int y)
{

h=sqrt(pow(pObs.x-p.x,2)+pow(pObs.y-p.y,2)+pow(pObs.z-p.z,2));



switch (touche) {
		case 'd':
			if (direction != LEFT && flg==0) {
				direction = RIGHT;
				printf("ccccccccccccccccccccccccccccccccccc====================Dright===%d\n",flg);

	  				flg=1;
	  				flg2=3;

	  				 //glutPostRedisplay();
			}else if (direction!=UP && flg==1)
			{
				direction=DOWN;

				printf("ccccccccccccccccccccccccccccccccccc====================Ddown===%d\n",flg);
				flg=2;
				flg2=2;

			}else if (direction!=RIGHT && flg==2)
			{
				direction=LEFT;
				printf("ccccccccccccccccccccccccccccccccccc====================Dleft===%d\n",flg);
				flg=3;
				flg2=1;

			}
			else if (direction!=DOWN && flg==3)
			{
				direction=UP;
				printf("ccccccccccccccccccccccccccccccccccc====================Dup===%d\n",flg);
				flg=0;
				flg2=0;

			}





			break;
		case 'a':
			if (direction != RIGHT && flg2==0) {
				flg2=1;
				flg=3;
				direction = LEFT;

				 //eyex+= 4;
   				 //eyez+= 5;
	  		 		//glutPostRedisplay();
			  	printf("ccccccccccccccccccccccccccccccccccc====================Aleft===%d\n",flg2);


			}

			else if (direction!=UP && flg2==1 )
			{
				flg2=2;
				flg=2;
				direction=DOWN;
				printf("ccccccccccccccccccccccccccccccccccc====================Adown===%d\n",flg2);
			}else if (direction!=LEFT && flg2==2 )
			{   flg2=3;
				flg=1;
				direction=RIGHT;
				printf("ccccccccccccccccccccccccccccccccccc====================Aright===%d\n",flg2);
			}else if (direction!=DOWN && flg2==3 )
			{
				flg2=0;
				flg=0;

				direction=UP;
				printf("ccccccccccccccccccccccccccccccccccc====================Aup===%d\n",flg2);
			}






			break;
		/*case 'w':
			if (direction != DOWN) {
				direction = UP;


					glutPostRedisplay();

			}

			break;
		case 's':
			if (direction != UP) {
				direction = DOWN;

								angle = 0;

	  				glutPostRedisplay();

			}

			break;

/*
		case 'e':



			if (direction != DOWNLEFT) {
				direction = UPRIGHT;

				angle = +45;
	  				glutPostRedisplay();

			}


			break;



		case 'c':

			if (direction != UPLEFT) {
				direction = DOWNRIGHT;
				angle = -45;
	  				glutPostRedisplay();

			}


			break;



		case 'q':



			if (direction != DOWNRIGHT) {
				direction = UPLEFT;

				angle = -45;
	  				glutPostRedisplay();

			}


			break;



		case 'z':

			if (direction != UPRIGHT) {
				direction = DOWNLEFT;
				angle = +45;

			  				glutPostRedisplay();


			}


			break;*/
		  case 'h':
				r=1;
			pressed=1;
			pressed2=1;
			direction = UP;

	 			//pObs.x=-4.0;pObs.y=5.0;pObs.z=4.0;

			  				glutPostRedisplay();


			break;

		}






}

void DrawCube(position ps,position ps2){
	glPushMatrix();
  glBegin(GL_QUADS);        // Draw The Cube Using quads
    glColor3f(0.0f,1.0f,0.0f);
    glVertex3f(ps.x, ps.y ,ps.z);
    glVertex3f(ps.x+1, ps.y,ps.z);
    glVertex3f(ps.x+1, ps.y, ps.z+1);
    glVertex3f( ps.x, ps.y, ps.z+1);
    glColor3f(1.0f,0.5f,0.0f);    // Color Orange
    glVertex3f( ps.x, ps.y ,ps.z);
    glVertex3f(ps.x,ps.y, ps.z+1);    // Top Left Of The Quad (Bottom)
    glVertex3f(ps.x,ps.y+1,ps.z+1);    // Bottom Left Of The Quad (Bottom)
    glVertex3f( ps.x,ps.y+1,ps.z);    // Bottom Right Of The Quad (Bottom)
    glColor3f(0.0f,0.5f,0.0f);    // Color Red
    glVertex3f( ps.x, ps.y, ps.z);    // Top Right Of The Quad (Front)
    glVertex3f(ps.x+1, ps.y, ps.z);    // Top Left Of The Quad (Front)
    glVertex3f(ps.x+1,ps.y+1, ps.z);    // Bottom Left Of The Quad (Front)
    glVertex3f( ps.x,ps.y+1, ps.z);    // Bottom Right Of The Quad (Front)
    glColor3f(1.0f,1.0f,0.0f);    // Color Yellow
    glVertex3f( ps2.x, ps2.y ,ps2.z);
    glVertex3f(ps2.x, ps2.y-1,ps2.z);
    glVertex3f(ps2.x-1, ps2.y-1, ps2.z);
    glVertex3f( ps2.x-1, ps2.y, ps2.z);
    glColor3f(0.0f,0.0f,1.0f);    // Color Blue
    glVertex3f( ps2.x, ps2.y ,ps2.z);
    glVertex3f(ps2.x, ps2.y-1,ps2.z);
    glVertex3f(ps2.x, ps2.y-1, ps2.z-1);
    glVertex3f( ps2.x, ps2.y, ps2.z-1);
    glColor3f(1.0f,0.0f,1.0f);    // Color Violet
    glVertex3f(ps2.x, ps2.y ,ps2.z);
    glVertex3f(ps2.x, ps2.y,ps2.z-1);
    glVertex3f(ps2.x-1, ps2.y, ps2.z-1);
    glVertex3f( ps2.x-1, ps2.y, ps2.z);
  	glEnd();
    glPopMatrix();
}

void print(int x, int y,int z, char *string)
{

glRasterPos2f(x,y);

int len = (int) strlen(string);

for (int i = 0; i < len; i++)
  {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,string[i]);
  }
};
void resetGame()
{
	//Reset snakeBody
		p.x=1.0;p.y=1.0;p.z=1.0;
		p2.x=2.0;p2.y=2.0;p2.z=2.0;

	int i = 0;
	for (i = 0; i < snakeLenght; i++)
	{
		snakeBody[i].x = p.x;
		snakeBody[i].z = p.z;
	}
	snakeLenght = 0;
	direction=UP;
flg=0;
flg2=0;
flg3=0;

Vvertical.x=0;
Vvertical.y=1;
Vvertical.z=0;

Vspeed.x=0;
Vspeed.y=0;
Vspeed.z=-1;

snake.x=1/2;
snake.y=1/2;
snake.z=1/2;
eyex=eyey=eyez=0;
pObs.x=-4.0;pObs.y=5.0;pObs.z=4.0;
cpt = 0;
}

void drawTree(float X,float Z){
        glPushMatrix();
        glTranslated(X,1,Z);
        glScalef(0.3,1,0.3);
        glColor3f(0.647059f,0.164706f, 0.164706f);
        glutSolidCube(taille_tree);
        glPopMatrix();

        glPushMatrix();
        glTranslated(X,2,Z);
				glScalef(0.3,0.3,0.3);
        glColor3f(0,0.5f,0);
        glutSolidSphere(2, 20, 20);
        glPopMatrix();
}
void drawTrees()
{

	for (int i = 0; i < 20; i++)
    {
    	    drawTree(tabZbi[i].x,tabZbi[i].z);
    }
}


void drawObst1(position ps){
    glPushMatrix();
    glColor3f(0.6470f,0.00, 0.16f);
  	glBegin(GL_QUADS);
    glVertex3f(ps.x, ps.y ,ps.z);
    glVertex3f(ps.x+1, ps.y,ps.z);
    glVertex3f(ps.x+1, ps.y, ps.z+1);
    glVertex3f( ps.x, ps.y, ps.z+1);
    glVertex3f( ps.x, ps.y ,ps.z);
    glVertex3f(ps.x,ps.y, ps.z+1);    // Top Left Of The Quad (Bottom)
    glVertex3f(ps.x,ps.y+1,ps.z+1);    // Bottom Left Of The Quad (Bottom)
    glVertex3f( ps.x,ps.y+1,ps.z);    // Bottom Right Of The Quad (Bottom)
    glVertex3f( ps.x, ps.y, ps.z);    // Top Right Of The Quad (Front)
    glVertex3f(ps.x+1, ps.y, ps.z);    // Top Left Of The Quad (Front)
    glVertex3f(ps.x+1,ps.y+1, ps.z);    // Bottom Left Of The Quad (Front)
    glVertex3f( ps.x,ps.y+1, ps.z);    // Bottom Right Of The Quad (Front)
    glVertex3f( ps.x+1, ps.y +1,ps.z+1);
    glVertex3f(ps.x+1, ps.y,ps.z+1);
    glVertex3f(ps.x, ps.y, ps.z+1);
    glVertex3f( ps.x,1+ ps.y, 1+ps.z);
    glVertex3f( 1+ps.x, ps.y+1 ,1+ps.z);
    glVertex3f(ps.x+1, ps.y,1+ps.z);
    glVertex3f(ps.x+1, ps.y, ps.z);
    glVertex3f( ps.x+1, ps.y+1, ps.z);
    glVertex3f(ps.x+1, ps.y+1 ,ps.z+1);
    glVertex3f(ps.x+1, ps.y+1,ps.z);
    glVertex3f(ps.x, ps.y+1, ps.z);
    glVertex3f( ps.x, ps.y+1, ps.z+1);
  	glEnd();
    glPopMatrix();
  }

	void drawSnake()
{

	int i = 0;

if (snakeLenght==0) {
	//body of the snake
			glPushMatrix();
			glTranslatef(snake.x,0.5,snake.z);
			//head of the snake
			glScalef(0.3, 0.3, 0.3);
			glColor3f(0.0,0,0.0);
			glutSolidCube(1);
			glPopMatrix();

	}

	glPushMatrix();
	glTranslatef(snake.x,0.5,snake.z);
	//head of the snake
	glScalef(0.3, 0.3, 0.3);
	glColor3f(0.0,0,0.0);
	glutSolidCube(1);
	glPopMatrix();
for (i = 1; i < snakeLenght; i++)
{
glPushMatrix();
glTranslatef(snakeBody[i].x, 0.5, snakeBody[i].z);
glScalef(0.3, 0.3, 0.3);
glColor3f(0, 0.5, 0);
glutWireCube(1);
glPopMatrix();

	}

	/*	printf("p.x %f\n",p.x);
		printf("p.z %f\n",p.z);
		printf("----\n");
		printf("p2.x %f\n",p2.x);
		printf("p2.z %f\n",p2.z);
		printf("----\n");
		printf("p3.x %f\n",p3.x);
		printf("p3.z %f\n",p3.z);
		printf("----\n");
		printf("p4.x %f\n",p4.x);
		printf("p4.z %f\n",p4.z);
*/



}
void moveSnakeBody(float oldSnakeX, float oldSnakeZ)
{
	float tempBodyPartX = 0;
	float tempBodyPartZ = 0;
	float currentX = oldSnakeX;
	float currentZ = oldSnakeZ;


	for (int i = 0; i < snakeLenght; i++) {
		tempBodyPartX = snakeBody[i].x;
		tempBodyPartZ = snakeBody[i].z;

		snakeBody[i].x = currentX;
		snakeBody[i].z = currentZ;

		currentX = tempBodyPartX;
		currentZ = tempBodyPartZ;

	}


/*	printf("snakeBody[0][0] %f snakeBody[0][0] %f\n",snakeBody[0][0],snakeBody[0][1] );
	printf("snakeBody[1][0] %f snakeBody[1][0] %f\n",snakeBody[1][0],snakeBody[1][1] );
	printf("snakeBody[2][0] %f snakeBody[2][0] %f\n",snakeBody[2][0],snakeBody[2][1] );*/

}



void moveSnakePos()
{

//ici traitement si le snake est arrive aux extremites de l'univers->newGame()

			int flag;
			float fraction=0.1f;
			if (direction == RIGHT) {

					p.x+=.05;
					p2.x+=.05;
					Vspeed.x=1;
					Vspeed.y=0;
					Vspeed.z=0;

				glutPostRedisplay();

	}
			else if (direction == LEFT) {

					p.x-=.05;
					p2.x-=.05;

					Vspeed.x=-1;
					Vspeed.y=0;
					Vspeed.z=0;

					glutPostRedisplay();

	}
			else if (direction == UP) {

					p.z-=.05;
					p2.z-=.05;

					Vspeed.x=0;
					Vspeed.y=0;
					Vspeed.z=-1;


					glutPostRedisplay();



	}
			else if (direction == DOWN) {

					p.z+=.05;
					p2.z+=.05;
					Vspeed.x=0;
					Vspeed.y=0;
					Vspeed.z=1;

				glutPostRedisplay();


	}



}


void rsem(position p){

	glPushMatrix();
    glTranslatef(p.x,0.5,p.z);
		glColor3f(1.0,0.5,0);

  	glScalef(0.3, 0.3, 0.3);
		glutSolidCube(1);
		glPopMatrix();

		glPushMatrix();

	glTranslatef(p.x,1.0,p.z);
	glScalef(0.3, 0.3, 0.3);

  glColor3f(0,0.5,0);
	glutSolidSphere(2, 20,20);
	glPopMatrix();

}
void drawSnowMan() {
glScalef(0.3,0.3,0.3);
	glColor3f(1.0f, 1.0f, 1.0f);

// Draw Body
	glTranslatef(0.0f ,0.75f, 0.0f);
	glutSolidSphere(0.75f,20,20);

// Draw Head
	glTranslatef(0.0f, 1.0f, 0.0f);
	glutSolidSphere(0.25f,20,20);

// Draw Eyes
	glPushMatrix();
	glColor3f(0.0f,0.0f,0.0f);
	glTranslatef(0.05f, 0.10f, 0.18f);
	glutSolidSphere(0.05f,10,10);
	glTranslatef(-0.1f, 0.0f, 0.0f);
	glutSolidSphere(0.05f,10,10);
	glPopMatrix();

// Draw Nose
	glColor3f(1.0f, 0.5f , 0.5f);
	glutSolidCone(0.08f,0.5f,10,2);
}
void plan(float longe)
{

     glBegin(GL_POLYGON);
        glColor3f(0.747059f,0.864706f, 0.164706f);

         glVertex3f(longe,0,(longe));
        glVertex3f(-longe,0,(longe));
        glVertex3f(-longe,0,-1*(longe));
        glVertex3f(longe ,0,-1*(longe));
      glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.747059f,0.464706f, 0.164706f);
        glVertex3f(longe, -longe,longe);
        glVertex3f(-longe,-longe,longe);
        glVertex3f(-longe, 0,longe);
        glVertex3f(longe , 0,longe);


   glEnd();
   glBegin(GL_POLYGON);
        glColor3f(0.747059f,0.364706f, 0.164706f);
        glVertex3f(-longe,-longe,-longe);
		glVertex3f(-longe,-longe,longe);
        glVertex3f(-longe,0,longe);
        glVertex3f(-longe,0,-longe);

   glEnd();
  glBegin(GL_POLYGON);
        glColor3f(0.747059f,0.164706f, 0.164706f);
        glVertex3f(longe,-longe,longe);
        glVertex3f(longe,-longe,-longe);
        glVertex3f(longe,0,-longe);
        glVertex3f(longe,0,longe);

   glEnd();
   glBegin(GL_POLYGON);
        glColor3f(0.747059f,0.264706f, 0.164706f);
        glVertex3f(-longe,-longe,-longe);
		glVertex3f(longe,-longe,-longe);
        glVertex3f(longe,0,-longe);
        glVertex3f(-longe,0,-longe);

   glEnd();

  //collision
		if ((fabs(p3.x-snake.x)<=0.25 && fabs(p3.z-snake.z)<=0.25)||(fabs(p4.x-snake.x)<=0.25 && fabs(p4.z-snake.z)<=0.25)) //
   	{
   		//generer nouveaux positions pour la bouff
			cpt++;
   		snakeLenght+=30;
   		p3.x=(float)(rand()%(Xmax-(-1*Xmax))+(-1*Xmax));
   		p3.z=(float)(rand()%(Xmax-(-1*Xmax))+(-1*Xmax));
			p4.x=p3.x+1;
   		p4.z=p3.z+1;

}
else if(p.z<=-(longe-2) ||p.z>=longe ||p2.x>=longe||p2.x<=-(longe-2) )
	{
 sprintf(str, "%d", cpt);
 	strncpy(string,gameover	,100);
    strcat(string, str);

  glPushMatrix();
	glColor3f(1.5,1,0);
 	glTranslated(snake.x,snake.y,snake.z);
 	print(0,0,0,string);
	glPopMatrix();
printf("zan9aaaaaaaaaaaaaaaaaaaaaa zan9aaaaaaaaaaaaaaaaaaaaaa\n" );
 resetGame();
}

else if (snakeLenght>=150)
		{

			for ( int i = 90; i <=snakeLenght; i++)

				{

		if ((p.x==snakeBody[i].x)&&(p.z==snakeBody[i].z))
			{
	printf("ksida ksida ksida ksida m3a le %d em ksida ksida ksida ksida m3a le %d eme\n",i,i);
	sprintf(str, "%d", cpt);
 	strncpy(string,gameover	,100);
  strcat(string, str);


  glPushMatrix();
	glColor3f(1.5,1,0);
 	glTranslated(snake.x,snake.y+1,snake.z);
 	print(0,0,0,string);
	glPopMatrix();


 resetGame();

			}

		}
					for (int i = 0; i <20; i++)
					{
				if ( fabs(snake.x-tabZbi[i].x)<=0.3 && fabs(snake.z-tabZbi[i].z)<=0.3)
	{
	sprintf(str, "%d", cpt);
 	strncpy(string,gameover	,100);
  strcat(string, str);


  glPushMatrix();
	glColor3f(1.5,1.0,0.0);
 	glTranslated(snake.x,snake.y+2,snake.z);
 	print(0,0,0,string);
	glPopMatrix();

				printf("-----dkholt f chjra-------snake.x %f tabZbi.x %f-------1- \n",snake.x,tabZbi[i].x);

 //resetGame();
				/*printf("p.x  %f p.z %f\n",p.x,p.z );
				printf("le %d eme",i );*/
					}
				}


			}/*else if(sqrt((p.x-t2.x)*(p.x-t2.x)+(p.y-t2.y)*(p.y-t2.y)+(p.z-t2.z)*(p.z-t2.z))<=0.3)*/
			else {
					for (int i = 0; i <20; i++)
					{
				if ( fabs(snake.x-tabZbi[i].x)<=0.3 && fabs(snake.z-tabZbi[i].z)<=0.3)
					{

	printf("-----dkholt f chjra-------snake.x %f tabZbi.x %f-------2- \n",snake.x,tabZbi[i].x);
			/*printf("p.x  %f p.z %f\n",p.x,p.z );
				printf("le %d eme",i );*
		sprintf(str, "%d", cpt);
	 	strncpy(string,gameover	,100);
    strcat(string, str);
*/

  glPushMatrix();
	glColor3f(1.5,1,0);
 	glTranslated(snake.x,snake.y+2,snake.z);
 	print(0,0,0,string);
	glPopMatrix();


 resetGame();
					}
				}
		}


}


void Affichage() {


    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
    gluPerspective(60 ,(float)width/(float)height,1,100);//fovy,aspect=width/height,near,far

	//printf("snake x %f snake y %f snake z %f\n",snake.x,snake.y,snake.z );

  snake.x=(p2.x+p.x)/2;
	snake.y=(p2.y+p.y)/2;
	snake.z=(p2.z+p.z)/2;

	pObs=translation(snake,Vspeed,-8);
	pObs=translation(pObs,Vvertical,3);
   	gluLookAt(pObs.x,pObs.y,pObs.z,snake.x,snake.y+2,snake.z,0,1,0);

   	glPushMatrix();

    plan(longe);
		for(int i =-2;i < 2; i++)
		for(int j=-2; j < 2; j++) {
		glPushMatrix();
		glTranslatef(i*4,0,j* 8);
		drawSnowMan();
		glPopMatrix();
		}
  //drawTrees(); //ca marche pas bien quand on veut gerer les collisions

   	moveSnakeBody(snake.x,snake.z);
   	moveSnakePos();
		glPopMatrix();

   	drawSnake();

 	glPushMatrix();
    glTranslatef(p3.x,0.5,p3.z);
		glColor3f(0.5,0.5,0);
  	glScalef(0.3, 0.3, 0.3);
    glutSolidCube(1);
	glPopMatrix();

		for (int i = 0; i < 20; i++)
		{
	 	rsem(tabZbi[i]);
		}



if (pressed==1)
{
	//text du score
glPushMatrix();

    sprintf(str, "%d", cpt);
  	strncpy(string,car,100);
    strcat(string, str);
    glPushMatrix();

    glTranslated(snake.x+5,snake.y+3,snake.z-5);
 	print(0,0,0,string);

	glPopMatrix();

glPopMatrix();
}


if (pressed2==0)
{
	//text du score
 	strncpy(string,string1,100);
    glPushMatrix();

    glTranslated(snake.x,snake.y+2,snake.z);
    //glRotatef(angle,0.0,1.0,0.0);

 	print(0,0,0,string);
	glPopMatrix();


}

	//lma3lam
   glColor4ub(0, 0, 255, 255);
        glBegin(GL_LINE_STRIP);
        glVertex3i(0,0,0);
        glVertex3i(2,0,0);
        glEnd();
        glColor4ub(0, 255, 255, 255);
        glBegin(GL_LINE_STRIP);
        glVertex3i(0,0,0);
        glVertex3i(0,2,0);
        glEnd();
        glColor4ub(0, 155, 255, 255);
        glBegin(GL_LINE_STRIP);
        glVertex3i(0,0,0);
        glVertex3i(0,0,2);
        glEnd();
	glFlush();
}



int main(int argc, char * argv[]) {
	glutInit( & argc, argv);
	glutInitWindowSize(width,height);

	snake.x=1/2;
	snake.y=1/2;
	snake.z=1/2;


	  p3.x=2.0;p3.y=1.0;p3.z=2;
		p4.x=3.0;p4.y=2.0;p4.z=3;
		t1.x=-5;t1.y=0.0;t1.z=-5.0;
		t2.x=-4;t2.y=0.0;t2.z=-4.0;
		t3.x=-8.0;t3.y=0.0;t3.z=8.0;
		t4.x=-8.0;t4.y=0.0;t4.z=7.0;
		t5.x=-6.0;t5.y=0.0;t5.z=-3.0;
		t6.x=-1.0;t6.y=0.0;t6.z=-9.0;
		t7.x=5.0;t7.y=0.0;t7.z=-9.0;
		t8.x=11.0;t8.y=0;t8.z=-3.0;
		t9.x=9.0;t9.y=0.0;t9.z=4.0;
		t10.x=13.0;t10.y=0.0;t10.z=-3.0;
		t11.x=12.0;t11.y=0.0;t11.z=10.0;
		t12.x=4;t12.y=0.0;t12.z=4.0;
		t13.x=1.0;t13.y=0.0;t13.z=10.0;
		t14.x=-8.0;t14.y=0.0;t14.z=-7.0;
		t15.x=-2.0;t15.y=0.0;t15.z=10.0;
		t16.x=2.0;t16.y=0.0;t16.z=10.0;
		t17.x=-5.0;t17.y=0.0;t17.z=-9.0;
		t18.x=-10.0;t18.y=0.0;t18.z=-3.0;
		t19.x=-9.0;t19.y=0.0;t19.z=4.0;
		t20.x=-9.0;t20.y=0.0;t20.z=-3.0;


    	taille_tree=1;

		tabZbi[0]=t1;tabZbi[1]=t2;tabZbi[2]=t3;tabZbi[3]=t4;tabZbi[4]=t5;tabZbi[5]=t6;
		tabZbi[6]=t7;tabZbi[7]=t8;tabZbi[8]=t9;tabZbi[9]=t10;tabZbi[10]=t11;


Vspeed.x=0;
Vspeed.y=0;
Vspeed.z=-1;

Vvertical.x=0;
Vvertical.y=1;
Vvertical.z=0;
	//X=(float)(rand()%(Ymax-(-1*Ymax))+(-1*Ymax));



		//offset.x=pObs.x-( p2.x/2);
		//offset.y=pObs.y-( p2.y/2);
	///	offset.z=pObs.z- p2.z;

	glutInitWindowPosition(200, 200);
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH);
	glutCreateWindow("Snake 3D");
	glEnable(GL_DEPTH_TEST);
			pObs.x=-25.0;pObs.y=8.0;pObs.z=25.0;


			/**offset.x+=h*sin(angle_camera);
			offset.z+=h*cos(angle_camera);*/
	glutDisplayFunc(Affichage);

	glutKeyboardFunc(GererClavier);
	glutIdleFunc(Animer);

	glutMainLoop();

	return 0;

}
