#include "variable.h"

position translation (position pp, position vecteur,int scale) {
	position pssa;
	pssa.x=pp.x+scale*vecteur.x;
	pssa.y=pp.y+scale*vecteur.y;
	pssa.z=pp.z+scale*vecteur.z;
	return pssa;
}

void Animer(){
	// rotation de la scene avant le debut de jeu (i.e:click space )->a activer apres
	float rayon = sqrt((pObs.x)*(pObs.x)+(pObs.z)*(pObs.z));
	if (r == 0){
		pObs.x = rayon*sin(angle);
		pObs.z= rayon*cos(angle);
		angle += 0.001;
		if (angle > 360) angle = 0;
	        glutPostRedisplay();
}


/*else{
	 pObs.x = rayon*sin(angle);
   	 pObs.z=  rayon*cos(angle);
}*/
}


void GererClavier(unsigned char touche, int x, int y){

	switch (touche) {
		case 'q':
		exit(0);
		break;
		case 'd':
			if (direction != LEFT && flg==0) {
				direction = RIGHT;
				//printf("ccccccccccccccccccccccccccccccccccc====================Dright===%d\n",flg);
				flg=1;
				flg2=3;

			 	//glutPostRedisplay();
			}else if (direction!=UP && flg==1){
				direction=DOWN;
				//printf("ccccccccccccccccccccccccccccccccccc====================Ddown===%d\n",flg);
				flg=2;
				flg2=2;
			}else if (direction!=RIGHT && flg==2){
				direction=LEFT;
				//printf("ccccccccccccccccccccccccccccccccccc====================Dleft===%d\n",flg);
				flg=3;
				flg2=1;

			}else if (direction!=DOWN && flg==3){
				direction=UP;
				//printf("ccccccccccccccccccccccccccccccccccc====================Dup===%d\n",flg);
				flg=0;
				flg2=0;
			}
			if (flagNaviguer==1) {
				direction=0;
			}
			printf("pObsx %f pObsy %f pObsz %f \n",pObs.x,pObs.y,pObs.z);

			break;
		case 'a':
			if (direction != RIGHT && flg2==0) {
				flg2=1;
				flg=3;
				direction = LEFT;
				 //eyex+= 4;
   				 //eyez+= 5;
	  		 		//glutPostRedisplay();
			  	//printf("ccccccccccccccccccccccccccccccccccc====================Aleft===%d\n",flg2);
			}else if (direction!=UP && flg2==1 ){
				flg2=2;
				flg=2;
				direction=DOWN;
				//printf("ccccccccccccccccccccccccccccccccccc====================Adown===%d\n",flg2);
			}else if (direction!=LEFT && flg2==2 ){
				flg2=3;
				flg=1;
				direction=RIGHT;
				printf("ccccccccccccccccccccccccccccccccccc====================Aright===%d\n",flg2);
			}else if (direction!=DOWN && flg2==3 ){
				flg2=0;
				flg=0;
				direction=UP;
				//printf("ccccccccccccccccccccccccccccccccccc====================Aup===%d\n",flg2);
			}
			if (flagNaviguer==1) {
				direction=0;
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

	  				glutPostRedisplay();

			}

			break;
*/
	  case 'u':
			r=1;
			flagNaviguer=0;
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
		case 'p':
			flagNaviguer=1;
		break;
	}
}

void processSpecialKeys(int key, int xx, int yy)
{
	float fraction = 0.1f;
	switch (key) {
		case GLUT_KEY_LEFT :
			angle -= 0.05f;
			lx = sin(angle);
			lz = -cos(angle);
		break;
		case GLUT_KEY_RIGHT :
			angle += 0.05f;
			lx = sin(angle);
			lz = -cos(angle);
		break;
		case GLUT_KEY_UP :
			x += lx * fraction;
			z += lz * fraction;
		break;
		case GLUT_KEY_DOWN :
			x -= lx * fraction;
			z -= lz * fraction;
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

void print(int x, int y,int z, char *string){
	glRasterPos2f(x,y);
	int len = (int) strlen(string);
	for (int i = 0; i < len; i++){
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,string[i]);
  }
}
void resetGame(){
	//Reset snakeBody
	p.x=1.0;p.y=1.0;p.z=1.0;
	p2.x=2.0;p2.y=2.0;p2.z=2.0;
//reset la nourriture
  p3.x=2.0;p3.y=1.0;p3.z=2;
	p4.x=3.0;p4.y=2.0;p4.z=3;
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
	//pressed2=0;
	pressed=0;
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
	for (int i = 0; i < 14; i++){
  	drawTree(tabPosArbres[i].x,tabPosArbres[i].z);
  }
}


// void drawObst1(position ps){
//   glPushMatrix();
//   glColor3f(0.6470f,0.00, 0.16f);
// 	glBegin(GL_QUADS);
//   glVertex3f(ps.x, ps.y ,ps.z);
//   glVertex3f(ps.x+1, ps.y,ps.z);
//   glVertex3f(ps.x+1, ps.y, ps.z+1);
//   glVertex3f( ps.x, ps.y, ps.z+1);
//   glVertex3f( ps.x, ps.y ,ps.z);
//   glVertex3f(ps.x,ps.y, ps.z+1);    // Top Left Of The Quad (Bottom)
//   glVertex3f(ps.x,ps.y+1,ps.z+1);    // Bottom Left Of The Quad (Bottom)
//   glVertex3f( ps.x,ps.y+1,ps.z);    // Bottom Right Of The Quad (Bottom)
//   glVertex3f( ps.x, ps.y, ps.z);    // Top Right Of The Quad (Front)
//   glVertex3f(ps.x+1, ps.y, ps.z);    // Top Left Of The Quad (Front)
//   glVertex3f(ps.x+1,ps.y+1, ps.z);    // Bottom Left Of The Quad (Front)
//   glVertex3f( ps.x,ps.y+1, ps.z);    // Bottom Right Of The Quad (Front)
//   glVertex3f( ps.x+1, ps.y +1,ps.z+1);
//   glVertex3f(ps.x+1, ps.y,ps.z+1);
//   glVertex3f(ps.x, ps.y, ps.z+1);
//   glVertex3f( ps.x,1+ ps.y, 1+ps.z);
//   glVertex3f( 1+ps.x, ps.y+1 ,1+ps.z);
//   glVertex3f(ps.x+1, ps.y,1+ps.z);
//   glVertex3f(ps.x+1, ps.y, ps.z);
//   glVertex3f( ps.x+1, ps.y+1, ps.z);
//   glVertex3f(ps.x+1, ps.y+1 ,ps.z+1);
//   glVertex3f(ps.x+1, ps.y+1,ps.z);
//   glVertex3f(ps.x, ps.y+1, ps.z);
//   glVertex3f(ps.x, ps.y+1, ps.z+1);
// 	glEnd();
//   glPopMatrix();
// }
void drawSnake(){
	int i = 0;
	//head of the snake
  glPushMatrix();
	glTranslatef(snake.x,0.5,snake.z);
	glScalef(0.3, 0.3, 0.3);
	glColor3f(0.0,1.5,0.0);
	glutSolidCube(1);
	glPopMatrix();
//body
	for (i = 0; i < snakeLenght; i++){
		glPushMatrix();
		glTranslatef(snakeBody[i].x,0.5, snakeBody[i].z);
		glScalef(0.3, 0.3, 0.3);
		glColor3f(0.0,1.5,0.0);
		glutSolidCube(1);
		glPopMatrix();
	}
}
void moveSnakeBody(float oldSnakeX, float oldSnakeY,float oldSnakeZ){
	float tempBodyPartX = 0;
	float tempBodyPartY = 0;
	float tempBodyPartZ = 0;
	float currentX = oldSnakeX;
	float currentY = oldSnakeY;
	float currentZ = oldSnakeZ;

	for (int i =0; i < snakeLenght; i++) {
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

void moveSnakePos(){
//ici traitement si le snake est arrive aux extremites de l'univers->newGame()
	int flag;
	float fraction=0.1f;
	if (direction == RIGHT) {
		cc=1;
		p.x+=.01;
		p2.x+=.01;
		if (cpt>=5) {
			p.x+=.01;
			p2.x+=.01;
		}
	 	if (cpt>=10) {
			p.x+=.01;
			p2.x+=.01;
		}
		Vspeed.x=1;
		Vspeed.y=0;
		Vspeed.z=0;
		glutPostRedisplay();
	}else if (direction == LEFT) {
		cc=1;
		p.x-=.01;
		p2.x-=.01;
		if (cpt>=5) {
			p.x-=.01;
			p2.x-=.01;
		}
	 	if (cpt>=10) {
			p.x-=.01;
			p2.x-=.01;
		}
		Vspeed.x=-1;
		Vspeed.y=0;
		Vspeed.z=0;
		glutPostRedisplay();

	}else if (direction == UP) {
		cc=0;
		p.z-=.01;
		p2.z-=.01;
		if (cpt>=5) {
			p.z-=.01;
			p2.z-=.01;
		}
	 	if (cpt>=10) {
			p.z-=.01;
			p2.z-=.01;
		}
		Vspeed.x=0;
		Vspeed.y=0;
		Vspeed.z=-1;
		glutPostRedisplay();
		// printf("pObsx %f pObsy %f pObsz %f \n",pObs.x,pObs.y,pObs.z);


	}else if (direction == DOWN) {
   	cc=0;
		p.z+=.01;
		p2.z+=.01;
		if (cpt>=5) {
		p.z+=.01;
		p2.z+=.01;
		}
	 	if (cpt>=10) {
		p.z+=.01;
		p2.z+=.01;
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
	//glutSolidSphere(2, 20,20);
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
void plan(float longe){
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
  //collision//
	if ((fabs(snake.x-p3.x)<=0.25 && fabs(snake.z-p3.z)<=0.25)||(fabs(snake.x-p4.x)<0.01 && fabs(snake.z-p4.z)<0.01)){
		// printf("---fabs(snake.x-p3.x):%f -----fabs(snake.z-p3.z): %f-------------------->>>>p3\n",fabs(snake.x-p3.x),fabs(snake.z-p3.z) );
		// printf("---fabs(snake.x-p4.x):%f -----fabs(snake.z-p4.z): %f-------------------->>>>p4\n",fabs(snake.x-p4.x),fabs(snake.z-p4.z) );
		//generer nouveaux positions pour la bouff
		cpt++;
		if (cpt>=5) {
			snakeLenght+=5;
		}else if (cpt>=15) {
			snakeLenght+=2;
		}else{
			snakeLenght+=10;
		}
		p3.x=(float)(rand()%(Xmax-(-1*Xmax))+(-1*Xmax));
		p3.z=(float)(rand()%(Xmax-(-1*Xmax))+(-1*Xmax));
		p4.x=p3.x+1;
		p4.z=p3.z+1;
	}else if(p.x<=-(longe-1) ||p.z>=longe ||p2.x>=longe||p2.z<=-(longe-1) ){
 		sprintf(str, "%d", cpt);
 		strncpy(string,gameover	,100);
  	strcat(string, str);
  	glPushMatrix();
		glColor3f(0,0,1.5);
		glTranslated(cx,cy+4,cz);
 		print(0,0,0,string);
		glPopMatrix();
		glPushMatrix();
		glColor3f(0,0,1.5);
		glTranslated(cx,cy+3,cz+28);
 		print(0,0,0,rejouer);
		glPopMatrix();
		//printf("zan9aaaaaaaaaaaaaaaaaaaaaa zan9aaaaaaaaaaaaaaaaaaaaaa\n" );
		resetGame();
	}else if (cpt>=7){
		for ( int i = 150; i <=snakeLenght; i++){
			if (fabs(p.x-snakeBody[i].x)<=0.25&&fabs(p.z-snakeBody[i].z)<=0.25){
				printf("ksida ksida ksida ksida m3a le %d em ksida ksida ksida ksida m3a le %d eme\n",i,i);
				sprintf(str, "%d", cpt);
 				strncpy(string,gameover	,100);
  			strcat(string, str);
  			glPushMatrix();
				glColor3f(0,0,1.5);
				glTranslated(cx,cy+3,cz);
 				print(0,0,0,string);
				glPopMatrix();
  			resetGame();
			}
		}
		for (int i = 0; i <29; i++){
			if ( fabs(snake.x-tabPosArbres[i].x)<=0.25 && fabs(snake.z-tabPosArbres[i].z)<=0.25){
				sprintf(str, "%d", cpt);
			 	strncpy(string,gameover	,100);
			  strcat(string, str);
			  glPushMatrix();
				glColor3f(0,0,1.5);
			 	glTranslated(cx,cy+3,cz);
			 	print(0,0,0,string);
				glPopMatrix();
				// printf("-----collision with tree-------snake.x %f tabPosArbres.x %f-------1- \n",snake.x,tabPosArbres[i].x);
 				resetGame();
			}
		}
	}else {
				//
				// sprintf(str, "%d", cpt);
				// strncpy(string,gameover	,100);
				// strcat(string, str);
				for (int i = 0; i<29; i++){
					if ( fabs(snake.x-tabPosArbres[i].x)<=0.25 && fabs(snake.z-tabPosArbres[i].z)<=0.25){
						// printf("-----collision with tree-------snake.x %f tabPosArbres.x %f,-------%d- \n",snake.x,tabPosArbres[i].x,i);
						sprintf(str, "%d", cpt);
	 					strncpy(string,gameover	,100);
    				strcat(string, str);
 						glPushMatrix();
						glColor3f(0,0,1.5);
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
  gluPerspective(68 ,(float)width/(float)height,1,100);//fovy,aspect=width/height,near,far
	//printf("snake x %f snake y %f snake z %f\n",snake.x,snake.y,snake.z );
  snake.x=(p2.x+p.x)/2;
	snake.y=(p2.y+p.y)/2;
	snake.z=(p2.z+p.z)/2;
	if (switchCam==1) {//3D
		pObs=translation(snake,Vspeed,-8);
		pObs=translation(pObs,Vvertical,3);
		cx=snake.x;cy=snake.y;cz=snake.z;
	 }else if (switchCam==0) {//2D
		 pObs.x=0.0;pObs.y=25.0;pObs.z=1.0;
		 cx=0.0;cy=0.0;cz=0.0;
	 }
	 if (flagNaviguer==1) {
		 // Reset transformations
		 // Set the camera
		 gluLookAt(x,1.3f,z,x+lx,1.0f, z+lz,0.0f, 1.0f, 0.0f);
		}else if(flagNaviguer==0){
		
   		gluLookAt(pObs.x,pObs.y,pObs.z,cx,cy,cz,0,1,0);
		}
   	glPushMatrix();
    plan(longe);
    drawTrees(); // dessiner les arbres en les considerant commes des obstacles
		moveSnakeBody(snake.x,snake.y,snake.z);
   	moveSnakePos();
		glPopMatrix();
		glPushMatrix();
		glPopMatrix();
   	drawSnake();
		glPushMatrix();
	   /* glTranslatef(p3.x,0.5,p3.z);
			glRotatef(angle_camera,0,1,0);
			angle_camera+=0.01;
			glColor3f(0.5,0.7,0.65);
	  	glScalef(0.3, 0.3, 0.3);
			glutSolidCube(1);*/
		glPopMatrix();
		glPushMatrix();
		glColor3f(0.547059f,0.064706f, 0.464706f);
		glTranslated(p3.x,0.5,p3.z);
		glScalef(0.3, 0.3, 0.3);
		glRotatef(angle_camera,0.0,1.0,0.0);
		angle_camera+=0.01;
		glutSolidTorus(innerRaidus,outterRaidus,sides,rings);
		glPopMatrix();
		for (int i = 0; i < 14; i++){
			rsem(tabPosArbres[i]);
		}
		for (int i = 15; i < 29; i++){
			glPushMatrix();
			glColor3f(0.0,0.064706f, 0.464706f);
			glTranslated(tabPosArbres[i].x,0.5,tabPosArbres[i].z);
			glScalef(0.3, 0.3, 0.3);
			glRotatef(angle_camera,0.0,1.0,0.0);
			angle_camera+=0.01;
			glutWireTorus(innerRaidus,outterRaidus,sides,rings);
			glPopMatrix();
		}
		if (pressed==1){
			//text du score
	    glPushMatrix();
			glColor3f(0.0,0.0,2.0);
	    sprintf(str, "%d", cpt);
	  	strncpy(string,car,100);
	    strcat(string, str);
			if (switchCam==0) {
				glTranslated(0.0,10.0,-9.0);
				print(0,0,0,string);
			}else if(switchCam==1){
				glTranslated(snake.x,snake.y+4,snake.z);
				print(0,0,0,string);
			}
	  	glPopMatrix();
		}
		if (pressed2==0 && flagNaviguer==0){
	  	strncpy(string,string3,100);
			glColor3f(0.0,0.0,1.5);
			glPushMatrix();
			glTranslated(0.0,11.0,0.0);
			print(0,0,0,string);
			glPopMatrix();
	//text du score
 			strncpy(string,string1,100);
			glColor3f(1,1,1);
			glPushMatrix();
			glTranslated(0.0,9.0,0.0);
		 	print(0,0,0,string);
			glPopMatrix();
			strncpy(string,string2,100);
			glColor3f(1,1,1);
			glPushMatrix();
			glTranslatef(0.0,7.5,0.0);
	 	 	print(0,0,0,string);
  		glPopMatrix();
			strncpy(string,string4,100);
			glColor3f(1,1,1);
			glPushMatrix();
			glTranslatef(0.0,6.0,0.0);
	 		print(0,0,0,string);
			glPopMatrix();
			glPopMatrix();
			strncpy(string,string5,100);
			glColor3f(5,0,0);
			glPushMatrix();
			glTranslatef(0.0,4.5,0.0);
			print(0,0,0,string);
			glPopMatrix();

		}

/*
glPushMatrix();
glTranslatef(0.0,0.0,f);
glRotatef(angle,0.0,1.0,0.0);
angle_camera+=0.1;
drawSnowMan();
glutPostRedisplay();
glPopMatrix();*/

	glPushMatrix();
//drawSnowMan();
	glPopMatrix();
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
	pObs.x=-15.0;pObs.y=15.0;pObs.z=25.0;
  flagNaviguer=0;
			/**offset.x+=h*sin(angle_camera);
			offset.z+=h*cos(angle_camera);*/
	glutDisplayFunc(Affichage);
	glutKeyboardFunc(GererClavier);
	glutSpecialFunc(processSpecialKeys);
	glutIdleFunc(Animer);
	glutMainLoop();

	return 0;

}
