#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <windows.h>
#include <glut.h>
#define pi (2*acos(0.0))

float px=4.0,py=175.0;
int flag, df=0;

void output(int x, int y, char *string)
{
      int len,i;

           glRasterPos2f(x,y);
           len=(int) strlen(string);
           for (i = 0; i < len; i++)
			{
             glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,string[i]);
			}

}




int Circle(GLfloat x, GLfloat y, GLfloat z, GLfloat radius)
{


	GLfloat twicePi = 2.0f * 3.14;

	GLfloat circleVerticesX[363];
	GLfloat circleVerticesY[363];
	GLfloat circleVerticesZ[363];

	circleVerticesX[0] = x;
	circleVerticesY[0] = y;
	circleVerticesZ[0] = z;

	for (int i = 1; i < 363; i++)
	{
		circleVerticesX[i] = x + (radius * cos(i *  twicePi / 360));
		circleVerticesY[i] = y + (radius * sin(i * twicePi / 360));
		circleVerticesZ[i] = z;
	}

	GLfloat allCircleVertices[(363) * 3];

	for (int i = 0; i <363; i++)
	{
		allCircleVertices[i * 3] = circleVerticesX[i];
		allCircleVertices[(i * 3) + 1] = circleVerticesY[i];
		allCircleVertices[(i * 3) + 2] = circleVerticesZ[i];
	}

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, allCircleVertices);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 363);
	glDisableClientState(GL_VERTEX_ARRAY);
}





void Draw_Circle()
{
	glColor3f(1,0,0);
	Circle(px,py,0,3.0);
	glEnd();
}




void starting()
{
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1.0,0.0,0.0);
output(25,140,"WELCOME TO THE GAME");
output(50,100,"1.NEW GAME");
output(50,80,"2.INSTRUCTIONS");
output(50,60,"3.QUIT");
glFlush();
}




void win_mission()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glColor3f(1.0, 0.0, 0.0);
	output(35, 120, "CONGRATULATIONS");
	glColor3f(1.0, 0.0, 0.0);
	output(20, 100, "YOU HAVE PASSED THE MISSION");
	output(15, 70, "PRESS 1 TO GO TO THE NEXT LEVEL");
	output(15, 55, "PRESS 2 TO RESTART THE LEVEL");
	glFlush();
}





void win_final_mission()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glColor3f(1.0, 0.0, 0.0);
	output(35, 120, "CONGRATULATIONS");
	glColor3f(1.0, 0.0, 0.0);
	output(10, 100, "YOU HAVE PASSED ALL THE MISSIONS");

	glFlush();
}




void menu(int id)
{

}



void wall(GLfloat x1,GLfloat y1,GLfloat x2,GLfloat y2,GLfloat x3,GLfloat y3,GLfloat x4,GLfloat y4)
{

  glBegin(GL_POLYGON);
	/*glVertex3f(x1,y1,0);
	glVertex3f(x2,y2,0);
	glVertex3f(x3,y3,0);
	glVertex3f(x4,y4,0);*/
  glEnd();
  glBegin(GL_QUADS);
     glVertex3d( x1, y1, 0);
     glVertex3d( x2, y2, 0);
     glVertex3d( x3, y3, 0);
     glVertex3d( x4, y4, 0);

  glEnd();

}













void maze_1()
{
     glColor3f(1.0,1.0,0.0);
        //left wall
		wall(-4,0,0,0,0,170,-4,170);
		//wall(-4,60,0,60,0,0,-4,0);

		//rightwall
		wall(180,178,184,178,184,-4,180,-4);
		//upperwall
        wall(-4,178,-4,184,184,184,184,178);
		//bottom wall
		wall(180,0,180,-4,-4,-4,-4,0);
		//inner top wall
		wall(50,170,54,170,54,10,50,10);
         //inner first
		wall(-4,170,-4,166,172,166,172,170);
        //inner second
		wall(50,10,50,14,172,14,172,10);
		//Goal Wall
        glColor3f(0, 1, 0);
        wall(15,150, 25,150, 25,140, 15,140);





		glutPostRedisplay();
}











void maze_2()
{
      //goal_circle(3, 3);

        glColor3f(0.0,1.0,0.0);
        Draw_Circle();
        glColor3f(1.0,1.0,0.0);
		/*wall(-4,70,0,70,0,170,-4,170);
		wall(-4,60,0,60,0,0,-4,0);
        wall(-4,178,-4,184,184,184,184,178);
        wall(-4,178,-4,184,184,184,184,178);
		wall(180,178,184,178,184,-4,180,-4);
		wall(180,0,180,-4,-4,-4,-4,0);
		wall(170,0,170,-4,-4,-4,-4,0);
		*/
		//Main Side Wall
		wall(0,0, 4,0, 4,120, 0,120);
		wall(0,0, 140,0, 140,4, 0,4);
		wall(140,0, 144,0, 144,120, 140,120);
		wall(144,120, 0,120, 0,116, 144,116);

		//please try to numbering the wall from left to right

        //left horizontal wall
		wall(12,15, 14,15, 14,120, 12,120);
		// next horizontal wall
		wall(30,0, 32,0, 32,105, 30,105);
		//third horizontal wall
		wall(50,15, 52,15, 52,105, 50,105);
		//fourth horizontal wall
		wall(70,0, 72,0, 72,40, 70,40);
		//Fifth horizontal wall
		wall(70,120, 72,120, 72,60, 70,60);
		//sixth horizontal line
		wall(90,0, 92,0, 92,35, 90,35);


		//All vertical line are here
		// vertical line are form up to down
		wall(144,90, 144,92, 90,92, 90,90);
		// 2nd vertical line
		wall(144,70, 144,72, 90,72, 90,70);
		//3rd vertical line
		wall(144,50, 144,52, 90,52, 90,50);

        //Goal Wall
        glColor3f(0, 1, 0);
        wall(140,4, 140,14, 130,14, 130,4);



		glutPostRedisplay();
}



void maze_3()
{
    //goal_circle(3, 3);

        glColor3f(0.0,1.0,0.0);
        Draw_Circle();
        glColor3f(1.0,1.0,0.0);

		//Main Side Wall
		wall(0,0, 4,0, 4,150, 0,150);
		wall(0,0, 150,0, 150,4, 0,4);
		wall(150,0, 154,0, 154,150, 150,150);
		wall(154,150, 0,150, 0,146, 154,146);

		//please try to numbering the wall from left to right

        //All horizontal wall
		wall(12,150, 14,150, 14,100, 12,100);
		wall(25,130, 27,130, 27,80, 25,80);
		wall(60,130, 62,130, 62,80, 60,80);
		wall(80,150, 82,150, 82,100, 80,100);
		wall(100,130, 102,130, 102,80, 100,80);
		wall(20,20, 22,20, 22,62, 20,62);
		wall(45,0, 47,0, 47,45, 45,45);
		wall(60,43, 62,43, 62,20, 60,20);
		wall(90,0, 92,0, 92,30, 90,30);

		//All vertical line are here
		wall(0,80, 0,82, 35,82, 35,80);
		wall(50,80, 50,82, 80,82, 80,80);
		wall(40,130, 40,132, 62,132, 62,130);
		wall(100,130, 100,132, 130,132, 130,130);
		wall(150,115, 150,117, 115,117, 115,115);
        wall(100,100, 100,102, 130,102, 130,100);
		wall(100,80, 100,82, 154,82, 154,80);
		wall(20,60, 20,62, 130,62, 130,60);
		wall(154,45, 154,43, 60,43, 60,45);
		wall(154,25, 154,27, 110,27, 110,25);


        //Goal Wall
        glColor3f(0, 1, 0);
        wall(140,4, 140,14, 130,14, 130,4);
}









void ball_movement_1(int key,int x,int y)
{
  switch (key)
  {
	case GLUT_KEY_UP:
		//flag=0;
	    if(py<175)
		if(py<=180 && py>=-10)
        if(!((px>=0 && px<=175) && (py>=163 && py<=165)))
            if(!((px>=50 && px<=175) && (py>=5 && py<=10)))
          py=py+4;
		glutPostRedisplay();
		break;

	case GLUT_KEY_DOWN:
      //flag=0;
	    if(py>5)
	    if(py<=180 && py>=-10)
        if(!((px>=0 && px<=175) && (py>=175 && py<=180)))
        if(!((px>=50 && px<=175) && (py>=15 && py<=20)))

		 py=py-4;
		glutPostRedisplay();
		break;

	case GLUT_KEY_LEFT:
		//flag=0;
	    if(px>0)
	    if(((px>=8 && px<=180) ))
        if(!((px>=0 && px<=177) && (py>=166 && py<=170)))
        if(!((px>=54&&px<=56) && (py>=10&& py<=170)))
        if(!((px>=55 && px<=180) && (py>=10 && py<=15)))
		px=px-4;
		glutPostRedisplay();
		break;

	case GLUT_KEY_RIGHT:
		//flag=0;
	    if(px<175)
	    if(px>=0 && px<=174)
        if(!((px>=47&&px<=50) && (py>=10&& py<=170)))
		px=px+4;
		glutPostRedisplay();
		break;
  }
}







void ball_movement_2(int key,int x,int y)


{
  switch (key)
  {
	case GLUT_KEY_UP:
		flag=0;
	    if(py<110)
        if(!((px>=11 && px<=16) && (py>=8 && py<=115)))

        if(!((px>=48 && px<=53) && (py>=10 && py<=105)))

        if(!((px>=65 && px<=75) && (py>=55 && py<=120)))
        //if(!((px>=71 && px<=76) && (py>=0 && py<=45)))
        //if(!((px>=86 && px<=89) && (py>=0 && py<=35)))
        if(!((px>=90 && px<=144) && (py>=85 && py<=90)))
        if(!((px>=90 && px<=144) && (py>=65 && py<=70)))
        if(!((px>=90 && px<=144) && (py>=45 && py<=50)))

        py=py+4;
		glutPostRedisplay();
		break;

	case GLUT_KEY_DOWN:
      flag=0;
	    if(py>10)
        if(!((px>=28 && px<=33) && (py>=0 && py<=110)))
        if(!((px>=48 && px<=53) && (py>=15 && py<=112)))

        //if(!((px>=71 && px<=79) && (py>=55 && py<=120)))
        if(!((px>=65&& px<=75) && (py>=0 && py<=48)))
        if(!((px>=90 && px<=95) && (py>=0 && py<=42)))
        if(!((px>=90 && px<=144) && (py>=93 && py<=98)))
        if(!((px>=90 && px<=144) && (py>=73 && py<=78)))
        if(!((px>=90 && px<=144) && (py>=53 && py<=58)))

        py=py-5;
		glutPostRedisplay();
		break;

	case GLUT_KEY_LEFT:
		flag=0;
	    if(px>8)
        if(!((px>=13 && px<=18) && (py>=15 && py<=120)))
        if(!((px>=35 && px<=40) && (py>=0 && py<=105)))
        if(!((px>=55 && px<=60) && (py>=15 && py<=105)))
        if(!((px>=74 && px<=79) && (py>=60 && py<=120)))
        if(!((px>=74 && px<=79) && (py>=0 && py<=40)))
        if(!((px>=94 && px<=99) && (py>=0 && py<=35)))
        //if(!((px>=90 && px<=144) && (py>=85 && py<=90)))
        //if(!((px>=90 && px<=144) && (py>=65 && py<=70)))
        //if(!((px>=90 && px<=144) && (py>=45 && py<=50)))
		px=px-5;
		glutPostRedisplay();
		break;

	case GLUT_KEY_RIGHT:
		flag=0;
	    if(px<134)
        if(!((px>=8 && px<=11) && (py>=15 && py<=120)))
        if(!((px>=23 && px<=28) && (py>=0 && py<=105)))
        if(!((px>=43 && px<=47) && (py>=15 && py<=105)))

        if(!((px>=66 && px<=69) && (py>=60 && py<=120)))
        if(!((px>=66 && px<=69) && (py>=0 && py<=40)))
        if(!((px>=86 && px<=89) && (py>=0 && py<=35)))
        if(!((px>=84 && px<=144) && (py>=87 && py<=93)))
        if(!((px>=84 && px<=144) && (py>=67 && py<=73)))
        if(!((px>=84 && px<=144) && (py>=47 && py<=53)))

        px=px+4;
		glutPostRedisplay();
		break;
  }
}






void ball_movement_3(int key,int x,int y)
{
  switch (key)
  {
	case GLUT_KEY_UP:
		flag=0;
	    if(py<140)
        if(!((px>=10 && px<=15) && (py>=95 && py<=150)))
        //if(!((px>=40 && px<=65) && (py>=125 && py<=130)))
        if(!((px>=79 && px<=84) && (py>=94 && py<=150)))
        if(!((px>=19 && px<=24) && (py>=15 && py<=62)))
        if(!((px>=59 && px<=63) && (py>=15 && py<=43)))
        if(!((px>=110 && px<=150) && (py>=20 && py<=25)))
        if(!((px>=50 && px<=80) && (py>=75 && py<=80)))
        if(!((px>=20 && px<=130) && (py>=55 && py<=60)))
        if(!((px>=60 && px<=154) && (py>=35 && py<=40)))
        if(!((px>=100 && px<=154) && (py>=75 && py<=80)))
        if(!((px>=100 && px<=130) && (py>=95 && py<=100)))
        if(!((px>=115 && px<=150) && (py>=110 && py<=115)))
        if(!((px>=100 && px<=130) && (py>=125 && py<=130)))
        if(!((px>=40 && px<=62) && (py>=125 && py<=130)))
        if(!((px>=0 && px<=35) && (py>=75 && py<=80)))

        py=py+5;
		glutPostRedisplay();
		break;

	case GLUT_KEY_DOWN:
      flag=0;
	    if(py>10)
        if(!((px>=24 && px<=28) && (py>=85 && py<=138)))
        //if(!((px>=40 && px<=65) && (py>=80 && py<=138)))
        if(!((px>=89 && px<=92) && (py>=0 && py<=38)))
        if(!((px>=59 && px<=64) && (py>=20 && py<=43)))
        if(!((px>=110 && px<=150) && (py>=30 && py<=35)))
        if(!((px>=50 && px<=80) && (py>=85 && py<=90)))
        if(!((px>=20 && px<=130) && (py>=65 && py<=70)))
        if(!((px>=60 && px<=154) && (py>=48 && py<=53)))
        if(!((px>=100 && px<=154) && (py>=85 && py<=90)))
        if(!((px>=100 && px<=130) && (py>=105 && py<=110)))
        if(!((px>=115 && px<=150) && (py>=120 && py<=125)))
        if(!((px>=100 && px<=130) && (py>=135 && py<=140)))
        if(!((px>=40 && px<=62) && (py>=135 && py<=140)))
        if(!((px>=0 && px<=35) && (py>=85 && py<=90)))
        //if(!((px>=15 && px<=20) && (py>=20 && py<=62)))

        py=py-5;
		glutPostRedisplay();
		break;

	case GLUT_KEY_LEFT:
		flag=0;
	    if(px>8)
       if(!((px>=15 && px<=20) && (py>=100 && py<=150)))
        if(!((px>=27 && px<=35) && (py>=80 && py<=130)))
        if(!((px>=65 && px<=70) && (py>=80 && py<=130)))
        if(!((px>=85 && px<=90) && (py>=100 && py<=150)))
        if(!((px>=105 && px<=110) && (py>=80 && py<=130)))
        if(!((px>=25 && px<=30) && (py>=20 && py<=62)))
        if(!((px>=48 && px<=53) && (py>=0 && py<=45)))
        if(!((px>=65 && px<=70) && (py>=20 && py<=43)))
        if(!((px>=95 && px<=100) && (py>=0 && py<=30)))
        if(!((px>=40 && px<=85) && (py>=79 && py<=84)))
        if(!((px>=20 && px<=135) && (py>=59 && py<=64)))
        if(!((px>=100 && px<=135) && (py>=99 && py<=104)))
        if(!((px>=100 && px<=135) && (py>=129 && py<=134)))
        if(!((px>=0 && px<=40) && (py>=79 && py<=84)))
		px=px-4;
		glutPostRedisplay();
		break;

	case GLUT_KEY_RIGHT:
		flag=0;
	    if(px<144)
        if(!((px>=5 && px<=10) && (py>=100 && py<=150)))
        if(!((px>=20 && px<=25) && (py>=80 && py<=130)))
        if(!((px>=55 && px<=60) && (py>=80 && py<=130)))
        if(!((px>=75 && px<=80) && (py>=100 && py<=150)))
        if(!((px>=95 && px<=100) && (py>=80 && py<=130)))
        if(!((px>=15 && px<=20) && (py>=20 && py<=62)))
        if(!((px>=37 && px<=42) && (py>=0 && py<=45)))
        if(!((px>=55 && px<=60) && (py>=20 && py<=43)))
        if(!((px>=85 && px<=90) && (py>=0 && py<=30)))
        if(!((px>=103 && px<=150) && (py>=24 && py<=28)))
        if(!((px>=45 && px<=85) && (py>=79 && py<=84)))
        if(!((px>=95 && px<=154) && (py>=79 && py<=84)))
        if(!((px>=110 && px<=150) && (py>=116 && py<=120)))
        if(!((px>=35 && px<=62) && (py>=129 && py<=134)))

        px=px+4;
		glutPostRedisplay();
		break;
  }
}




void maze_ball()
{
glClear(GL_COLOR_BUFFER_BIT);
if(df==0)
starting();
else if(df==1)
     {
        //flag=1;
        glColor3f(0.0,1.0,0.0);
        Draw_Circle();
        glColor3f(1.0,0.0,0.0);
        output(-60,175,"LEVEL ONE");
        maze_1();
        glutSpecialFunc(ball_movement_1);

        if(((px>=15 && px<=25) && (py>=140 && py<=150)))
         {
           df=2;
           px=8;
           py=108;
           win_mission();
         }


       }


  else if(df==3)
   {

    glColor3f(0.0,1.0,0.0);
    Draw_Circle();
    glColor3f(1.0,0.0,0.0);
    output(-60,175,"LEVEL TWO");
    maze_2();
    glutSpecialFunc(ball_movement_2);
     if(((px>=130 && px<=140) && (py>=4 && py<=14)))
     {  df=4;
        px=8.0;
        py=150.0;
        win_mission();

     }
   }


   else if(df==5)
    {
    glColor3f(0.0,1.0,0.0);
    Draw_Circle();
    glColor3f(1.0,0.0,0.0);
    output(-60,175,"LEVEL THREE");
    maze_3();
    glutSpecialFunc(ball_movement_3);
    if(((px>=130 && px<=140) && (py>=4 && py<=14)))
     {
       win_final_mission();

     }

    }
  glFlush();


}








void keyboard_control(unsigned char key,int x,int y)
{

if(df==0 && key=='1')
   {
     df=1;
	 glutPostRedisplay();
   }
if(df==2 && key=='1')
   {
    df=3;
    glutPostRedisplay();
   }
 if(df==2 && key=='2')
    {
    px=4.0;
    py=175.0;
    df=1;
    glutPostRedisplay();
   }
  if(df==4 && key=='1' )
  {
      df=5;
      glutPostRedisplay();

  }
   if(df==4 && key=='2' )
  {

      px=8;
      py=108;
      df=3;
      glutPostRedisplay();

  }

}







void display()
{

maze_ball();

}




void Two_D(int w, int h)
{
  glViewport(0,0,w,h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  if(w<=h)
  gluOrtho2D(45.0,135.0,-2.0*(GLfloat)h/(GLfloat)w,180.0*(GLfloat)h/(GLfloat)w);
  else
  gluOrtho2D(-45.0*(GLfloat)w/(GLfloat)h,135.0*(GLfloat)w/(GLfloat)h,-2.0,180.0);
  glMatrixMode(GL_MODELVIEW);
  glutPostRedisplay();
 }


int main(int argc,char **argv)
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowSize(1000,700);
  glutCreateWindow("Maze ball");
  glutReshapeFunc(Two_D);
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard_control);

  glutCreateMenu(menu);





  glutAttachMenu(GLUT_RIGHT_BUTTON);

  glutMainLoop();
  return 0;
}




