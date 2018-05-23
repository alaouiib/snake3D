
#include "GL/glut.h"
#define PIXEL_X 50
#define PIXEL_Y 50
#include<stdio.h>
#include<string.h>
#include<stdarg.h>
#include<math.h>
#include<time.h>
#include<unistd.h>

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define UPRIGHT 5
#define DOWNRIGHT 6
#define UPLEFT 7
#define DOWNLEFT 8




float angle;
int snakeLenght=0;
float rayon ;
static float angle_camera = 0;
int r=0;
int flag=0;
struct position{
   float x;
   float y;
   float z;
};

typedef struct position position;
position snakeBody[2000];
position p,p2,p3,p4,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25,t26,t27,t28,t29,snake,Vspeed,Vvertical,pObs,pipito;
position pxz,pxz1;
int width=1000;
int height=700;
GLbyte  direction ;

char car[100] =  "Score:";
char gameover[100] =  "game over (Rejouer? click sur 'W')ton score est: ";
char string1[100]="pour commencer en mode 2D-> taper 'u' ";
char string2[100]="pour commencer en mode 3D-> taper 'i'";
char string3[100]="selectionner le mode de jeu: ";

char str[80];
char string[1000];
int cpt=0;
float h;
float eyex,eyey,eyez;
int switchCam=-1;

GLint sides =10;
GLint rings =10;
float taille_tree;
float longe=17.0;
position tabPosArbres[20];
float X,Z,P;
int pressed=0;
int pressed2=0;
   		int Xmax =8;
      float cx,cy,cz;
