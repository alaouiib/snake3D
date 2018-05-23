#include "variable.h"
int flg=0;
int flg2=0;
int flg3=0;
int flg4;
float f,g;

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
		case 'w':
			if (direction != DOWN) {
				direction = UP;


					glutPostRedisplay();

			}

			break;
		case 's':
			if (direction != UP) {
				direction = DOWN;

	  				glutPostRedisplay();

			}

			break;


		  case 'u':
				r=1;
			pressed=1;
			pressed2=1;
			switchCam=0;
			if (flg4==-1) {
				direction = UP;
				flg4=1;
			}



			  				glutPostRedisplay();


			break;


		case 'i':
		 switchCam=1;
		r=1;
		pressed=1;
		pressed2=1;
		if (flg4==-1) {
			direction = UP;
			flg4=1;
		}

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
	snakeLenght = 0;
	direction=0;
flg=0;
flg2=0;
flg3=0;
flg4=-1;
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
cpt = 0;
if (switchCam==0) {
	pObs.x=-8.0;pObs.y=18.0;pObs.z=8.0;
}
}

void drawTree(float X,float Z){
        glPushMatrix();
        glTranslated(X,0.5,Z);
        glScalef(0.3,1,0.3);
        glColor3f(0.647059f,0.164706f, 0.164706f);
        glutSolidCube(taille_tree);
        glPopMatrix();

        glPushMatrix();
        glTranslated(X,1,Z);
				glScalef(0.3,0.3,0.3);
        glColor3f(0,0.5f,0);
        glutSolidSphere(2, 20, 20);
        glPopMatrix();
}
void drawTrees(){

	for (int i = 0; i < 29; i++)
    {
    	    drawTree(tabPosArbres[i].x,tabPosArbres[i].z);
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

	void drawSnake(){

	int i = 0;

if (snakeLenght==0) {

			glPushMatrix();
			glTranslatef(snake.x,0.5,snake.z);
			//head of the snake
			glScalef(0.3, 0.3, 0.3);
			glColor3f(0.0,0.5,0.0);
			glutSolidCube(1);

				glPopMatrix();

	}

//body
else {
	for (i = 0; i < snakeLenght; i++)
{

glPushMatrix();
glTranslatef(snakeBody[i].x,0.5, snakeBody[i].z);
glScalef(0.3, 0.3, 0.3);
glColor3f(0, 0.5, 0);
glutSolidCube(1);
glPopMatrix();

	}

}

}
void moveSnakeBody(float oldSnakeX, float oldSnakeY,float oldSnakeZ)
{
	float tempBodyPartX = 0;
	float tempBodyPartY = 0;
	float tempBodyPartZ = 0;

	float currentX = oldSnakeX;
	float currentY = oldSnakeY;
	float currentZ = oldSnakeZ;


	for (int i = 0; i < snakeLenght; i++) {
		tempBodyPartX = snakeBody[i].x;
		tempBodyPartY = snakeBody[i].y;
		tempBodyPartZ = snakeBody[i].z;

		snakeBody[i].x = currentX;
		snakeBody[i].y = currentY;
		snakeBody[i].z = currentZ;

		currentX = tempBodyPartX;
		currentY = tempBodyPartY;
		currentZ = tempBodyPartZ;

	}

}

void moveSnakePos()
{

//ici traitement si le snake est arrive aux extremites de l'univers->newGame()

			int flag;
			float fraction=0.1f;
			if (direction == RIGHT) {
				angle_camera=90;

					p.x+=.015;
					p2.x+=.015;
					if (cpt>=3) {
						p.x+=.01;
						p2.x+=.01;
					}
					 	if (cpt>=10) {
							p.x+=.02;
							p2.x+=.02;
						}

					Vspeed.x=1;
					Vspeed.y=0;
					Vspeed.z=0;

				glutPostRedisplay();

	}
			else if (direction == LEFT) {
angle_camera=-90;
					p.x-=.015;
					p2.x-=.051;
					if (cpt>=3) {
						p.x-=.01;
						p2.x-=.01;
					}
		 	if (cpt>=10) {
				p.x-=.02;
				p2.x-=.02;
			}
					Vspeed.x=-1;
					Vspeed.y=0;
					Vspeed.z=0;

					glutPostRedisplay();

	}
			else if (direction == UP) {
angle_camera=-180;
					p.z-=.015;
					p2.z-=.015	;
					if (cpt>=3) {
						p.z-=.01;
						p2.z-=.01;
					}
				 if (cpt>=10) {
						p.z-=.02;
						p2.z-=.02;
					}
					Vspeed.x=0;
					Vspeed.y=0;
					Vspeed.z=-1;

					glutPostRedisplay();



	}
			else if (direction == DOWN) {
				angle_camera=0;
					p.z+=.01;
					p2.z+=.01;
					if (cpt>=3) {

						p.z+=.01;
						p2.z+=.01;
					}
					 if (cpt>=10) {

						p.z+=.02;
						p2.z+=.02;
					}
					Vspeed.x=0;
					Vspeed.y=0;
					Vspeed.z=1;

				glutPostRedisplay();



	}



}


void rsem(position ps){

	glPushMatrix();
    glTranslatef(ps.x,0.5,ps.z);
		glColor3f(1.0,0.5,0);
  	glScalef(0.3, 0.3, 0.3);
		glutSolidCube(1);
	glPopMatrix();

		glPushMatrix();
	glTranslatef(ps.x,1.0,ps.z);
	glScalef(0.3, 0.3, 0.3);
  glColor3f(0,0.5,0);
	glutSolidSphere(2, 20,20);
	glPopMatrix();

}

void drawSnowMan() {
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
else if(p.x<=-(longe-1) ||p.z>=longe ||p2.x>=longe||p2.z<=-(longe-1) )
	{
 	sprintf(str, "%d", cpt);
 	strncpy(string,gameover	,100);
  strcat(string, str);

  glPushMatrix();
	glColor3f(1.5,1,0);
	glTranslated(cx-2,cy+3,cz-2);
 	print(0,0,0,string);
	glPopMatrix();

//printf("zan9aaaaaaaaaaaaaaaaaaaaaa zan9aaaaaaaaaaaaaaaaaaaaaa\n" );


 resetGame();
}

else if (cpt>=7)
		{
			for ( int i = 120; i <=snakeLenght; i++)
				{

		if (fabs(p.x-snakeBody[i].x)<=0.25&&fabs(p.z-snakeBody[i].z)<=0.25)
			{


	printf("ksida ksida ksida ksida m3a le %d em ksida ksida ksida ksida m3a le %d eme\n",i,i);
	sprintf(str, "%d", cpt);
 	strncpy(string,gameover	,100);
  strcat(string, str);
  glPushMatrix();
	glColor3f(1.5,1,0);
	glTranslated(cx,cy+3,cz);
 	print(0,0,0,string);
	glPopMatrix();
  resetGame();

			}

		}
					for (int i = 0; i <29; i++)
					{
				if ( fabs(snake.x-tabPosArbres[i].x)<=0.25 && fabs(snake.z-tabPosArbres[i].z)<=0.25)
	{
	sprintf(str, "%d", cpt);
 	strncpy(string,gameover	,100);
  strcat(string, str);
  glPushMatrix();
	glColor3f(1.5,1.0,0.0);
 	glTranslated(cx,cy+3,cz);
 	print(0,0,0,string);
	glPopMatrix();

			printf("-----collision with tree-------snake.x %f tabPosArbres.x %f-------1- \n",snake.x,tabPosArbres[i].x);

 resetGame();

					}
				}


			}
			else {

				sprintf(str, "%d", cpt);
				strncpy(string,gameover	,100);
				strcat(string, str);

					for (int i = 0; i<29; i++)
					{
				if ( fabs(snake.x-tabPosArbres[i].x)<=0.25 && fabs(snake.z-tabPosArbres[i].z)<=0.25)
					{


						printf("-----collision with tree-------snake.x %f tabPosArbres.x %f,-------%d- \n",snake.x,tabPosArbres[i].x,i);

		sprintf(str, "%d", cpt);
	 	strncpy(string,gameover	,100);
    strcat(string, str);
 		glPushMatrix();
		glColor3f(1.5,1,0);
	 	glTranslated(cx,cy+3,cz);
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
    gluPerspective(70 ,(float)width/(float)height,1,100);//fovy,aspect=width/height,near,far

	//printf("snake x %f snake y %f snake z %f\n",snake.x,snake.y,snake.z );

  snake.x=(p2.x+p.x)/2;
	snake.y=(p2.y+p.y)/2;
	snake.z=(p2.z+p.z)/2;
	if (switchCam==1) {
		pObs=translation(snake,Vspeed,-8);
		pObs=translation(pObs,Vvertical,3);
		cx=snake.x;cy=snake.y;cz=snake.z;

	 }
	 else if (switchCam==0) {
		 pObs.x=0.0;pObs.y=10.0;pObs.z=20.0;
		 cx=0.0;cy=0.0;cz=0.0;

	 }

   	gluLookAt(pObs.x,pObs.y,pObs.z,cx,cy,cz,0,1,0);

   	glPushMatrix();
    plan(longe);
    drawTrees(); // dessiner les arbres en les considerant commes des obstacles
   	moveSnakeBody(snake.x,snake.y,snake.z);
   	moveSnakePos();
		glPopMatrix();

   	drawSnake();

		glPushMatrix();
	    glTranslatef(p3.x,0.5,p3.z);
			glColor3f(0.5,0.58,0.65);
	  	glScalef(0.3, 0.3, 0.3);
	    glutWireCube(1);
		glPopMatrix();

	for (int i = 0; i < 29; i++)
	{
	rsem(tabPosArbres[i]);
	}




if (pressed==1)
{
	//text du score
    glPushMatrix();
    sprintf(str, "%d", cpt);
  	strncpy(string,car,100);
    strcat(string, str);
    glTranslated(snake.x,snake.y+4,snake.z);
 	  print(0,0,0,string);

	  glPopMatrix();

}


if (pressed2==0)
{

  	strncpy(string,string3,100);
		glColor3f(1.5,0.0,1.5);
		glPushMatrix();

		glTranslated(-2.0,8.0,0.0);
		//glRotatef(angle,0.0,1.0,0.0);
		print(0,0,0,string);
		glPopMatrix();

	//text du score
 	strncpy(string,string1,100);
		glColor3f(1.5,0.0,0.5);
		glPushMatrix();

		glTranslated(-2.0,6.0,0.0);
    //glRotatef(angle,0.0,1.0,0.0);
 	print(0,0,0,string);
	glPopMatrix();

	strncpy(string,string2,100);
		glColor3f(1.5,0.0,0.5);
		glPushMatrix();

		glTranslatef(-2.0,5.0,0.0);
//glRotatef(angle,0.0,1.0,0.0);

 	print(0,0,0,string);
	glPopMatrix();

}
// f=(float)(rand()%(Xmax-(-1*Xmax))+(-1*Xmax));
// g=(float)(rand()%(Xmax-(-1*Xmax))+(-1*Xmax));
f+=0.01;
if (f>=longe) {
f=0;
}
glPushMatrix();
glTranslatef(f,0.0,0.0);
glRotatef(angle,0.0,1.0,0.0);
angle+=0.1;
drawSnowMan();
glutPostRedisplay();
glPopMatrix();

glPushMatrix();
drawSnowMan();
glPopMatrix();

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
		t20.x=-9.0;t20.y=0.0;t20.z=8.0;
		t21.x=-2.0;t21.y=0.0;t21.z=-3.0;
		t22.x=-3.5;t22.y=0.0;t22.z=1.0;
		t23.x=-5.0;t23.y=0.0;t23.z=-3.0;
		t24.x=-6.5;t24.y=0.0;t24.z=6.0;
		t25.x=-8.0;t25.y=0.0;t25.z=-3.0;
		t26.x=-9.5;t26.y=0.0;t26.z=9.0;
		t27.x=-11.0;t27.y=0.0;t27.z=-3.0;
		t28.x=-12.5;t28.y=0.0;t28.z=-2.0;
		t29.x=-15.0;t29.y=0.0;t29.z=-5.0;



    	taille_tree=1;

		tabPosArbres[0]=t1;tabPosArbres[1]=t2;tabPosArbres[2]=t3;tabPosArbres[3]=t4;tabPosArbres[4]=t5;tabPosArbres[5]=t6;
		tabPosArbres[6]=t7;tabPosArbres[7]=t8;tabPosArbres[8]=t9;tabPosArbres[9]=t10;tabPosArbres[10]=t11;tabPosArbres[11]=t12;tabPosArbres[12]=t13;tabPosArbres[13]=t14;tabPosArbres[14]=t15;tabPosArbres[15]=t16;tabPosArbres[16]=t17;
		tabPosArbres[17]=t18;tabPosArbres[18]=t19;tabPosArbres[19]=t20;tabPosArbres[20]=t21;tabPosArbres[21]=t22;tabPosArbres[22]=t23;tabPosArbres[23]=t24;tabPosArbres[24]=t25;tabPosArbres[25]=t26;tabPosArbres[26]=t27;tabPosArbres[27]=t28;
		tabPosArbres[28]=t29;


Vspeed.x=0;
Vspeed.y=0;
Vspeed.z=-1;

Vvertical.x=0;
Vvertical.y=1;
Vvertical.z=0;
flg4=-1;

	glutInitWindowPosition(200, 200);
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH);
	glutCreateWindow("Snake 3D");
	glEnable(GL_DEPTH_TEST);
			pObs.x=0.0;pObs.y=15.0;pObs.z=15.0;

			/**offset.x+=h*sin(angle_camera);
			offset.z+=h*cos(angle_camera);*/
	glutDisplayFunc(Affichage);

	glutKeyboardFunc(GererClavier);
	glutIdleFunc(Animer);

	glutMainLoop();

	return 0;

}
