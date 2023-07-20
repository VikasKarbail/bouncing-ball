/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <GLUT/glut.h>
#include<math.h>
#include<stdbool.h>
#define PI 3.14159265f
#include<stdio.h>

GLfloat ballRadius = 0.2,xradius=0.2,xxradius=1.0,xxxradius=0.5;
GLfloat ballX = 0.0f;
GLfloat ballY = 0.0f;
GLfloat ballXMax,ballXMin,ballYMax,ballYMin;
GLfloat xSpeed = 0.02f;
GLfloat ySpeed = 0.007f;
int refreshMills = 30;
int refreshend = 60000;
GLfloat angle=0.0;
int xa,ya;
int flag=0,flag1=0,flag2=0,flagl=0,flagd=0;
int score = 0,score1=0,score2=0,endTimer,timer,i;
void *currentfont;
GLfloat  x, y;
GLdouble clipAreaXLeft,clipAreaXRight,clipAreaYBottom,clipAreaYTop;
void balldisp()	;
void scoredisp();
void end();

void drawstring(float x,float y,float z,char *string)
{
 char *c;
 glRasterPos3f(x,y,z);
 for(c=string;*c!='\0';c++)
 {
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*c);
 }
}
void frontscreen(void)
{

	 glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLE_FAN);
	for(angle=0; angle<360; angle+=1)
	{
    		y =(cos(angle*PI/180)*xradius);
    		x =(sin(angle*PI/180)*xradius);
    		glVertex2f(x,y);
	}

	glEnd();
 xradius=xradius+0.005;
  glColor3f( 1.0,1.0,0.0 );
 glBegin(GL_TRIANGLE_FAN);
	for(angle=0; angle<360.0; angle+=1)
	{
    		y =(sin(angle*PI/180)*xxradius);
    		x =(cos(angle*PI/180)*xxradius);
    		glVertex2f(x,y);
	}

	glEnd();
 xxradius=xxradius-0.005;
 glColor3f(0.0,0.0,0.0);
 drawstring(-0.42,0.9,0.0,"CGV MINI PROJECT");
glColor3f(1.0,0.0,0.0);
 drawstring(-0.3,0.6,0.0,"VISUALIZERS");
glColor3f( 0.5,0.0,1.0 );
 drawstring(-0.4,0.4,0.0,"BOUNCING BALL");
 glColor3f( 0.0,0.0,0.0 );
 drawstring(-0.9,-0.0,0.0,"BY:");
 glColor3f( 0.0,0.0,0.0 );
 drawstring(-0.9,-0.1,0.0,"Vikas K.R.");
drawstring(-0.9,-0.2,0.0,"Suhas O");
 drawstring(0.45,-0.0,0.0,"GUIDE : ");
drawstring(0.25,-0.15,0.0,"Prof. NavyaShree");
glColor3f( 0.0,0.0,1.5 );
 drawstring(-0.4,-0.7,0.0,"Press i for Instructions");
glColor3ub( rand()%250, rand()%250, rand()%200 );
 drawstring(-0.4,-0.9,0.0,"Press ENTER to Start");
 drawstring(-0.2,-0.55,0.0,"Academic Year");
 glColor3f( 0.0,1.0,0.4 );

 glutSwapBuffers();
}

void level2()
{
	glClear(GL_COLOR_BUFFER_BIT);
		drawstring(-0.175,0.0,0.0,"LEVEL 2 ");
		drawstring(-0.4,-0.25,0.0,"Press c to Continue...");
		glutSwapBuffers();
}

void finalsc()
{
	int z,j=0,k=0,y,a=0,b=0, w,d=0,e=0;
	z=score;
	y=score1;
	w=score2;
	glColor3f(1.0,1.0,0.0);
	glLoadIdentity();
    drawstring(-1.0,1.0,0.0,"FINAL SCORE : ");
	while(z > 9)
        {
            k = z % 10;

             glRasterPos2f (-0.20,1.0);
             glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,48+k);
	       z /= 10;
           glRasterPos2f(-0.25,1.0);
       }
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,48+z);
	drawstring(-1.0,0.9,0.0,"LEVEL 1 : ");
	while(w > 9)
        {
            e = w % 10;

             glRasterPos2f (-0.20,0.9);
             glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,48+e);
	       w /= 10;
           glRasterPos2f(-0.25,0.9);
       }
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,48+w);
	drawstring(-1.0,0.8,0.0,"LEVEL 2 : ");

	while(y > 9)
        {
            b = y % 10;

             glRasterPos2f (-0.20,0.8);
             glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,48+b);
	       y /= 10;
           glRasterPos2f(-0.25,0.8);
       }
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,48+y);
}

void end()
{
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1.0,1.0,0.0);
glBegin(GL_TRIANGLE_FAN);
	for(angle=0; angle<360; angle+=1)
	{
    		y =0.3+(cos(angle*PI/180)*xxxradius);
    		x =(sin(angle*PI/180)*xxxradius);
    		glVertex2f(x,y);
	}
 glEnd();
 glColor3f(0.0,0.0,0.0);
 glPointSize(15.0);
 glBegin(GL_POINTS);
 glVertex2f(-0.2,0.5);
 glVertex2f(0.2,0.5);
 glEnd();
 glLineWidth(10.0);
 glBegin(GL_LINES);
 glVertex2f(0.0,0.2);
 glVertex2f(0.0,0.4);
 glEnd();
 glBegin(GL_LINES);
 glVertex2f(-0.2,0.0);
 glVertex2f(0.0,0.1);
  glVertex2f(0.0,0.1);
   glVertex2f(0.2,0.0);
 glEnd();
 glColor3f(1.0,0.0,0.0);
 drawstring(-0.3,-0.7,0.0,"GAME OVER");
 finalsc();
 glutSwapBuffers();

}
void instr()
{

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f( 0.5,0.0,1.0 );
	 drawstring(-0.25,0.85,0.0,"Instructions");
	  glColor3f(1.0,1.0,0.0);
	 drawstring(-0.9,0.55,0.0,"1. The Player needs to click on the ball in order");
	 drawstring(-0.8,0.45,0.0,"to score. ");
	 drawstring(-0.9,0.35,0.0,"2. Per click score will be incremented by 1. ");
	 drawstring(-0.9,0.25,0.0,"3. And the speed of the ball will increase ");
	 drawstring(-0.9,0.15,0.0,"4. To Quit at any stage press q ");
	 drawstring(-0.9,0.05,0.0,"5. Timer of 10 secs for two levels");
	 glColor3ub( rand()%250, rand()%250, rand()%200 );
     drawstring(-0.6,-0.9,0.0,"PRESS ENTER TO START");
	glutSwapBuffers();
}


void display()
{
	 glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	balldisp();
	scoredisp();

	glutSwapBuffers();

	endTimer+=refreshMills;

	timer=endTimer/1000;

}


void mydisplay(void)
{   if(flag==0&&flag1==0&&flagd==0)
    frontscreen ();

    if(flag1==1&&flag==0)
        instr();


   if(flag==1&&flagd==0)
   {
   display();==

	}
   if(score>=10&&flag1==0)
   {
   level2();
   endTimer=0;
   flagd=1;
   //level1sc=score;
}

      if(endTimer>=10000&&flag==1)
      {

   end();
   flagd=1;
}
   else if(endTimer>=20000&&flag1==1)
   {
   end();
          flagd=1;
}
}
void mykey( unsigned char key, int x, int y )
{
  switch(key)
 {

    case 13:  if(flag==0)
               flag=1;
              //flag1=0;
              //ySpeed=ySpeed+0.01;

              break;
    case 'i': if(flag==0)
 	              flag1=1;
 	            break;
    case 'c':if(flagl==0)
	          {
	         flag1=1;
	        	flagd=0;

	        //score=0;
   ySpeed=ySpeed+0.05;}

			break;
	case 'q' :
	case 'Q' : exit(0);
	          break;

 }

}

void balldisp()
{
	glTranslatef(ballX,ballY,0.0f);
	glBegin(GL_TRIANGLE_FAN);
	if(score>=10)
   {
   glColor3f(0,0,1);
   //level1sc=score;
   }
   else
   {

     glColor3f(1,0,0);
   }
	glVertex2f(0.0f,0.0f);
	int numSegments = 100;
	int i;
	for(i=0;i<=numSegments;i++)
	{
		angle = i*2.0f*PI/numSegments;
		glVertex2f(cos(angle)*ballRadius,sin(angle)*ballRadius);
	}

	glEnd();

	ballX += xSpeed;
	ballY += ySpeed;

	if(ballX > ballXMax)
	{   xa=ballX;
		ballX = ballXMax;
		xSpeed = -xSpeed;

	}
	else if(ballX < ballXMin)
	{   xa=ballX;
		ballX = ballXMin;
		xSpeed = -xSpeed;

	}
	if(ballY > ballYMax)
	{   ya=ballY;
		ballY = ballYMax;
		ySpeed = -ySpeed;

	}
	else if(ballY < ballYMin)
	{   ya=ballY;
		ballY = ballYMin;
		ySpeed = -ySpeed;

	}


}




void scoredisp()
{
	int z,j=0,k=0,i,s=0;
	z=score;
	glColor3f(1.0,1.0,0.0);
	glLoadIdentity();
	glRasterPos2f(0.28,1 );
	drawstring(0.38,1,0.0,"TIME : ");

	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,48+timer);
	if(score>=10)
       drawstring(-0.25,1,0,"LEVEL 2");
    else
       drawstring(-0.25,1,0,"LEVEL 1");
    drawstring(-1,1,0.0,"SCORE : ");

	while(z > 9)
        {
            k = z % 10;
             glRasterPos2f (-0.58,1);
             glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,48+k);
           z /= 10;
           glRasterPos2f(-0.62,1);
       }
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,48+z);
}

bool isMouseOverBall(float worldClickX, float worldClickY, float ballX, float ballY)
{
    float distance = sqrt(pow(worldClickX - ballX, 2.0f) + pow(worldClickY - ballY, 2.0f));
    return distance < ballRadius;
}

void windowToWorld(int windowX, int windowY, double *worldX, double *worldY)
{
    int x = windowX - 500 / 2;
    int y = windowY - 500 / 2;

    *worldX = (float)x / 250.0f;
    *worldY = -(float)y / 250.0f;
}

void onMouse(int button, int state, int x, int y)
{
	GLdouble worldClickX, worldClickY;
    windowToWorld(x, y, &worldClickX, &worldClickY);
    bool clicked = isMouseOverBall(ballX, ballY, worldClickX, worldClickY);
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
   {
  	 if(clicked)
    {
    	score=score+1;

   if(score>10)
    {
    	score1=score1+1;
    	score2=10;
    }
    else
    {
    	score2=score;
    }
    }

   }



}

void reshape(GLsizei width,GLsizei height)
{
	if(height ==0) height = 1;
	GLfloat aspect = (GLfloat)width / (GLfloat)height;
	glViewport(0,0,width,height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
    if(width >=height)
	{
		clipAreaXLeft = -1.0 * aspect;
		clipAreaXRight = 1.0 * aspect;
		clipAreaYBottom = -1.0;
		clipAreaYTop = 1.0;
	}
	else
	{
		clipAreaXLeft = -1.0;
		clipAreaXRight = 1.0 ;
		clipAreaYBottom = -1.0 / aspect;
		clipAreaYTop = 1.0/ aspect;
	}
	gluOrtho2D(clipAreaXLeft,clipAreaXRight,clipAreaYBottom,clipAreaYTop+0.10);
	ballXMin = clipAreaXLeft + ballRadius;
	ballXMax =  clipAreaXRight - ballRadius;
	ballYMin =  clipAreaYBottom + ballRadius;
	ballYMax =  clipAreaYTop - ballRadius;
}

void Timer(int value)
{
	glutPostRedisplay();
	glutTimerFunc(refreshMills,Timer,5);
}

int main(int argc,char* argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Bouncing Ball");
	glutMouseFunc(onMouse);
    glutDisplayFunc(mydisplay);
	glutKeyboardFunc(mykey);
	glutReshapeFunc(reshape);
	glutTimerFunc(0,Timer,0);
	glutMainLoop();
}
