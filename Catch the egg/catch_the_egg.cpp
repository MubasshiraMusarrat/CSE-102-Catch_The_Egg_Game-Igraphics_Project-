# include "iGraphics.h"
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<mmsystem.h>

#define screenHeight 790
#define screenWidth 1500


int b,n=0;
char* bask[]= {"basket0.bmp","basket1.bmp","basket2.bmp","basket3.bmp","basket4.bmp","basket5.bmp","basket6.bmp",};
char* chicken1[]= {"chicken1.bmp", "chicken2.bmp", "chicken3.bmp"};
char* chicken2[]= {"whiteChicken1.bmp","whiteChicken2.bmp","whiteChicken3.bmp",};
char* whiteEgg[]= {"whiteEgg1.bmp", "whiteEgg2.bmp", "whiteEgg3.bmp"};
char* goldenEgg[]= {"goldenEgg1.bmp", "goldenEgg2.bmp", "goldenEgg3.bmp"};
char* blueEgg[]= {"blueEgg1.bmp", "blueEgg2.bmp", "blueEgg3.bmp"};
char* poop[]= {"poop1.bmp", "poop2.bmp", "poop3.bmp"};
char powerUps[7][3][30]= {"blueclock1.bmp", "blueclock2.bmp", "blueclock3.bmp",
                          "redBasket1.bmp", "redBasket2.bmp", "redBasket3.bmp",
                          "bomb1.bmp", "bomb2.bmp", "bomb3.bmp",
                          "redclock1.bmp", "redclock2.bmp", "redclock3.bmp",
                          "blueBasket1.bmp", "blueBasket2.bmp", "blueBasket3.bmp",
                          "grains1.bmp","grains2.bmp","grains3.bmp",
                          "grains_rotten1.bmp","grains_rotten2.bmp","grains_rotten3.bmp"
                         };

struct _parameter
{
    double x=0;
    int y=0;
} basket,hen1,hen2,hen3,egg,EGG,Egg,pic;

int Time=60;
int dT=0,egg_t=0,pict=0;
char s1[20]= {0},s2[20] = {0}, str[30]= {0};
int minutes=0,seconds=0;
int score=0;
char egg_mode=-1;
char powerup_mode[7]= {0},enable_mode[7]= {0};
char music=1, gameMode = -1, start=0, textBox=0,pause=0,flag1=0;
int life=300;

void Score();
void gameOver();
void HighScore();

void drawBasket()
{
    b=2;
    if(enable_mode[1] == 1 && b<5)
        b++;
    if(enable_mode[4] == 1 && b>0)
        b--;

    if(basket.y==0)
        iShowBMP2(basket.x,0,bask[b],0);

    if(basket.y==1)
        iShowBMP2(basket.x,screenHeight/8,bask[b+1],0);

    if(basket.y==2)
        iShowBMP2(basket.x,screenHeight/4,bask[b+2],0);
}
void drawChicken1()
{
    if(hen1.y== 0)
        iShowBMP2(hen1.x, screenHeight/2,chicken1[0], 0);
    if(hen1.y== 1)
        iShowBMP2(hen1.x,screenHeight*5/8, chicken1[1], 0);
    if(hen1.y== 2)
        iShowBMP2(hen1.x,screenHeight*3/4, chicken1[2], 0);
}

void drawChicken2()
{
    if(hen2.y== 0)
        iShowBMP2(hen2.x, screenHeight/2,chicken1[0], 0);
    if(hen2.y== 1)
        iShowBMP2(hen2.x,screenHeight*5/8, chicken1[1], 0);
    if(hen2.y== 2)
        iShowBMP2(hen2.x,screenHeight*3/4, chicken1[2], 0);
}

void drawChicken3()
{
    if(hen3.y== 0)
        iShowBMP2(hen3.x, screenHeight/2,chicken1[0], 0);
    if(hen3.y== 1)
        iShowBMP2(hen3.x,screenHeight*5/8, chicken1[1], 0);
    if(hen3.y== 2)
        iShowBMP2(hen3.x,screenHeight*3/4, chicken1[2], 0);
}

void drawEgg()
{
    if(egg_t == 0 || egg_t == 2 || egg_t == 4 || egg_t == 6)
    {
        if(hen1.y == 0)
            iShowBMP2(egg.x,(screenHeight/2)-egg.y, whiteEgg[0], 0);
        if(hen1.y == 1)
            iShowBMP2(egg.x, (screenHeight*5/8)- egg.y, whiteEgg[1], 0);
        if(hen1.y == 2)
            iShowBMP2(egg.x, (screenHeight*3/4)- egg.y, whiteEgg[2], 0);
        if(egg_mode==1)
        {
            score += 5;
            egg_mode = -1;
        }
        if(egg_mode==0)
        {
            score -= 1;
            if(life>0)
                life--;
            egg_mode = -1;
        }
    }
    if(egg_t == 1)
    {
        if(hen1.y == 0)
            iShowBMP2(egg.x,(screenHeight/2)-egg.y, goldenEgg[0], 0);
        if(hen1.y == 1)
            iShowBMP2(egg.x, (screenHeight*5/8)- egg.y, goldenEgg[1], 0);
        if(hen1.y == 2)
            iShowBMP2(egg.x, (screenHeight*3/4)- egg.y, goldenEgg[2], 0);
        if(egg_mode==1)
        {
            score += 20;
            egg_mode = -1;
        }
        if(egg_mode==0)
        {
            score -= 5;
            if(life>=3)
                life-=3;
            egg_mode = -1;
        }
    }
    if(egg_t == 3)
    {
        if(hen1.y == 0)
            iShowBMP2(egg.x,(screenHeight/2)-egg.y, blueEgg[0], 0);
        if(hen1.y == 1)
            iShowBMP2(egg.x, (screenHeight*5/8)- egg.y, blueEgg[1], 0);
        if(hen1.y == 2)
            iShowBMP2(egg.x, (screenHeight*3/4)- egg.y, blueEgg[2], 0);
        if(egg_mode==1)
        {
            score += 10;
            egg_mode = -1;
        }
        if(egg_mode==0)
        {
            score -= 3;
            if(life>=2)
                life-=2;
            egg_mode = -1;
        }
    }
    if(egg_t == 5)
    {
        if(hen1.y == 0)
            iShowBMP2(egg.x,(screenHeight/2)-egg.y, poop[0], 0);
        if(hen1.y == 1)
            iShowBMP2(egg.x, (screenHeight*5/8)- egg.y, poop[1], 0);
        if(hen1.y == 2)
            iShowBMP2(egg.x, (screenHeight*3/4)- egg.y, poop[2], 0);
        if(egg_mode==1)
        {
            score-=2;
            egg_mode=-1;
        }
    }
}

void drawEGG()
{
    if(egg_t == 0 || egg_t == 1 || egg_t == 5 || egg_t == 6)
    {
        if(hen2.y == 0)
            iShowBMP2(EGG.x,(screenHeight/2)-egg.y, whiteEgg[0], 0);
        if(hen2.y == 1)
            iShowBMP2(EGG.x, (screenHeight*5/8)- egg.y, whiteEgg[1], 0);
        if(hen2.y == 2)
            iShowBMP2(EGG.x, (screenHeight*3/4)- egg.y, whiteEgg[2], 0);
        if(egg_mode==1)
        {
            score += 5;
            egg_mode = -1;
        }
        if(egg_mode==0)
        {
            score -= 1;
            if(life>0)
                life--;
            egg_mode = -1;
        }
    }
    if(egg_t == 2)
    {
        if(hen2.y == 0)
            iShowBMP2(EGG.x,(screenHeight/2)-egg.y, goldenEgg[0], 0);
        if(hen2.y == 1)
            iShowBMP2(EGG.x, (screenHeight*5/8)- egg.y, goldenEgg[1], 0);
        if(hen2.y == 2)
            iShowBMP2(EGG.x, (screenHeight*3/4)- egg.y, goldenEgg[2], 0);
        if(egg_mode==1)
        {
            score += 20;
            egg_mode = -1;
        }
        if(egg_mode==0)
        {
            score -= 5;
            if(life>=3)
                life-=3;
            egg_mode = -1;
        }
    }
    if(egg_t == 4)
    {
        if(hen2.y == 0)
            iShowBMP2(EGG.x,(screenHeight/2)-egg.y, blueEgg[0], 0);
        if(hen2.y == 1)
            iShowBMP2(EGG.x, (screenHeight*5/8)- egg.y, blueEgg[1], 0);
        if(hen2.y == 2)
            iShowBMP2(EGG.x, (screenHeight*3/4)- egg.y, blueEgg[2], 0);
        if(egg_mode==1)
        {
            score += 10;
            egg_mode = -1;
        }
        if(egg_mode==0)
        {
            score -= 3;
            if(life>=2)
                life-=2;
            egg_mode = -1;
        }
    }
    if(egg_t == 3)
    {
        if(hen2.y == 0)
            iShowBMP2(EGG.x,(screenHeight/2)-egg.y, poop[0], 0);
        if(hen2.y == 1)
            iShowBMP2(EGG.x, (screenHeight*5/8)- egg.y, poop[1], 0);
        if(hen2.y == 2)
            iShowBMP2(EGG.x, (screenHeight*3/4)- egg.y, poop[2], 0);
        if(egg_mode==1)
        {
            score-=2;
            egg_mode=-1;
        }
    }
}

void drawegg()
{
    if(egg_t == 2 || egg_t == 3 || egg_t == 4 || egg_t == 5)
    {
        if(hen3.y == 0)
            iShowBMP2(Egg.x,(screenHeight/2)-egg.y, whiteEgg[0], 0);
        if(hen3.y == 1)
            iShowBMP2(Egg.x, (screenHeight*5/8)- egg.y, whiteEgg[1], 0);
        if(hen3.y == 2)
            iShowBMP2(Egg.x, (screenHeight*3/4)- egg.y, whiteEgg[2], 0);
        if(egg_mode==1)
        {
            score += 5;
            egg_mode = -1;
        }
        if(egg_mode==0)
        {
            score -= 1;
            if(life>0)
                life--;
            egg_mode = -1;
        }
    }
    if(egg_t == 0)
    {
        if(hen3.y == 0)
            iShowBMP2(Egg.x,(screenHeight/2)-egg.y, goldenEgg[0], 0);
        if(hen3.y == 1)
            iShowBMP2(Egg.x, (screenHeight*5/8)- egg.y, goldenEgg[1], 0);
        if(hen3.y == 2)
            iShowBMP2(Egg.x, (screenHeight*3/4)- egg.y, goldenEgg[2], 0);
        if(egg_mode==1)
        {
            score += 20;
            egg_mode = -1;
        }
        if(egg_mode==0)
        {
            score -= 5;
            if(life>=3)
                life-=3;
            egg_mode = -1;
        }
    }
    if(egg_t == 1)
    {
        if(hen3.y == 0)
            iShowBMP2(Egg.x,(screenHeight/2)-egg.y, blueEgg[0], 0);
        if(hen3.y == 1)
            iShowBMP2(Egg.x, (screenHeight*5/8)- egg.y, blueEgg[1], 0);
        if(hen3.y == 2)
            iShowBMP2(Egg.x, (screenHeight*3/4)- egg.y, blueEgg[2], 0);
        if(egg_mode==1)
        {
            score += 10;
            egg_mode = -1;
        }
        if(egg_mode==0)
        {
            score -= 3;
            if(life>=2)
                life-=2;
            egg_mode = -1;
        }
    }
    if(egg_t == 6)
    {
        if(hen3.y == 0)
            iShowBMP2(Egg.x,(screenHeight/2)-egg.y, poop[0], 0);
        if(hen3.y == 1)
            iShowBMP2(Egg.x, (screenHeight*5/8)- egg.y, poop[1], 0);
        if(hen3.y == 2)
            iShowBMP2(Egg.x, (screenHeight*3/4)- egg.y, poop[2], 0);
        if(egg_mode==1)
        {
            score-=2;
            egg_mode=-1;
        }
    }
}

void drawPowerups()
{
    int i;
    if(dT == 30 || dT == 90 || dT == 150)
        powerup_mode[0] = 1;
    else if(dT == 35 || dT == 75 || dT == 110)
        powerup_mode[1] = 1;
    else if(dT == 45 || dT == 135 || dT == 170)
        powerup_mode[2] = 1;
    else if(dT == 50 || dT == 105 || dT == 155)
        powerup_mode[3] = 1;
    else if(dT == 55 || dT == 130 || dT == 160)
        powerup_mode[4] = 1;
    else if(dT == 40 || dT == 80 || dT==120)
        powerup_mode[5] = 1;
    else if(dT == 60 ||dT ==90 || dT==125)
        powerup_mode[6] =1;

    for(i=0; i<7; i++)
    {
        if( powerup_mode[i] == 1)
        {
            if(pict==0)
                iShowBMP2(pic.x,screenHeight-pic.y, powerUps[i][0], 0);
            if(pict==1)
                iShowBMP2(pic.x,screenHeight-pic.y, powerUps[i][1], 0);
            if(pict==2)
                iShowBMP2(pic.x,screenHeight-pic.y, powerUps[i][2], 0);

            if(pic.y<(screenHeight-pict*(screenHeight/8)) && pic.y> (screenHeight-pict*(screenHeight/8))-170)
            {
                if(pic.x > basket.x && pic.x < (basket.x +110+b*25))
                    enable_mode[i] = 1;
            }
            if(pic.y >=(screenHeight- pict*(screenHeight/8)))
            {
                pic.y=0;
                powerup_mode[i]=0;
            }
        }
    }
    if(enable_mode[2] == 1)
    {
        dT=Time;
        enable_mode[2]=0;
    }

}

void Life()
{
    iSetColor(255, 255, 255);
    iRectangle(200, screenHeight-70,301, 30);
    if(life>200)
        glColor4ub(0, 255, 0, .5*255);
    else if (life>100 && life<= 200)
        glColor4ub(255, 242, 0, .5*255);
    else if( life >=0 && life <=100)
        glColor4ub(255, 0, 0, .5*255);
    iFilledRectangle(201, screenHeight-69, life, 28);

}

void iDraw()
{
    //place your drawing codes here
    iClear();
    if(gameMode == -1)
    {
        n=0;
        dT=0;
        Time=60;
        seconds=0;
        minutes=0;
        score=0;
        life=300;
        for(int i=0; i<30; i++)
            str[i]=0;
        for(int i=0; i<7; i++)
            enable_mode[i]=0;
        iShowBMP(0, 0, "menu.bmp");

        if (music == 0)
        {
            iSetColor(0,0,0);
            iFilledRectangle(675,150,115,15);
        }
    }

    if(gameMode == 0)
    {
        sndPlaySound(0,0 );
        iShowBMP(0, 0, "bg2.bmp");
    }

    if(gameMode == 0  && start == 1)
    {
        iShowBMP(0, 0, "bg.bmp");
        iSetColor(128, 84, 0);
        iFilledRectangle(0,screenHeight/2+15,screenWidth, 4.5);
        iFilledRectangle(0,screenHeight*5/8+15,screenWidth, 3);
        iFilledRectangle(0,screenHeight*3/4+15,screenWidth, 1.5);

        drawBasket();
        drawChicken1();
        drawEgg();
        drawPowerups();

        if(dT>=60)
        {
            drawChicken2();
            drawEGG();
        }

        if(dT>=120)
        {
            drawChicken3();
            drawegg();
        }

        iSetColor(255, 255, 255);
        iText(screenWidth-100,screenHeight-50,s1, GLUT_BITMAP_TIMES_ROMAN_24);
        if(Time-dT<=10)
        {
            iSetColor(255, 0, 0);
            iText(screenWidth-100,screenHeight-50,s1, GLUT_BITMAP_TIMES_ROMAN_24);
        }

        sprintf(s2, "Score: %d",score);
        iSetColor(255, 255, 255);
        iText(50, screenHeight-50, s2, GLUT_BITMAP_TIMES_ROMAN_24);

        Life();

        if(pause == 1)
            iShowBMP(0, 0, "pause.bmp");
        if(dT == Time || life<=0)
            gameOver();
    }
    if(gameMode==2)
    {
        iShowBMP(0, 0, "highScore.bmp");
        HighScore();
    }
    if(gameMode==3)
        iShowBMP(0, 0,"instruction.bmp");
}
void iMouseMove(int mx, int my)
{
    //place your codes here

}

void iPassiveMouseMove(int mx, int my)
{
    if(mx>=basket.x && (basket.x+150)<screenWidth)
        basket.x+=125;

    if(basket.x>=mx && basket.x>0)
        basket.x-=125;

    if(my>= (basket.y*(screenHeight/8)) && basket.y < 2)
        basket.y ++;

    if(my <= (basket.y*(screenHeight/8)) && basket.y >0)
        basket.y--;

}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        //place your codes here
    {
        if(gameMode == -1)
        {
            for (int i=0; i<4 ; i++)
            {
                if(mx >= 170 && mx <= 570 && my >= 100+i*160  && my <= 220+i*160)
                {
                    gameMode= 3-i;
                    if(gameMode == 0)
                        start = 0;
                }
            }
            if(gameMode==1)
            {
                FILE *fp=NULL;
                fp=fopen("gameData.txt","r");
                while(!feof(fp))
                {
                    fscanf(fp, "%d %d %d %d %d %d", &score, & Time, &dT, &seconds, &minutes, &life);
                }
                fclose(fp);
                start=1;
                gameMode=0;
            }
            if(mx >= 660 && mx <= 800 && my >= 100 && my <= 220)
            {
                music = !music;
                if(music == 0)
                    sndPlaySound(0, 0);
                else if (music == 1)
                    sndPlaySound("bgMusic.wav", SND_ASYNC|SND_LOOP);
            }
            if(mx>= screenWidth-150 && mx<= screenWidth-50 && my>=screenHeight-150 && my<=screenHeight-50)
                exit(0);
        }
        if(gameMode == 0 && start == 0)
        {
            for(int i=0; i<3; i++)
            {
                if(mx >= 550 && mx <= 880 && my >= 120+i*150 && my <= 220+i*165)
                {
                    Time=(3-i)*60;
                    start=1;
                }
            }
        }
    }


    //if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)

    //place your codes here

}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{

    if(key == 'p' || key == 'P')
    {
        iPauseTimer(0);
        iPauseTimer(1);
        iPauseTimer(2);
        iPauseTimer(3);
        iPauseTimer(4);
        pause=1;
    }
    if(key == 'r' || key == 'R')
    {
        iResumeTimer(0);
        iResumeTimer(1);
        iResumeTimer(2);
        iResumeTimer(3);
        iResumeTimer(4);
        pause=0;
    }
    if(textBox == 1)
    {
        if(key == '\r')
        {
            FILE *fp = NULL;
            fp = fopen("Input.txt", "a");
            fprintf(fp, "%s %d", str, score);
            fclose(fp);

            start=0;
            gameMode = 2;
            music = 1;
            sndPlaySound("bgMusic.wav", SND_ASYNC|SND_LOOP);
            textBox=0;
        }
        else
        {
            str[n]= key;
            n++;
        }

    }
    //place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

    if(key == GLUT_KEY_LEFT)
    {
        if(basket.x>0)
            basket.x-=125;
    }
    if(key == GLUT_KEY_RIGHT)
    {
        if((basket.x+150)<screenWidth)
            basket.x+=125;
    }

    if(key == GLUT_KEY_UP)
    {
        if(basket.y >= 0 && basket.y < 2)
            basket.y ++;
    }
    if(key == GLUT_KEY_DOWN)
    {
        if(basket.y <= 2 && basket.y > 0)
            basket.y --;
    }
    if(key == GLUT_KEY_END)
    {
        if(gameMode == -1)
            exit(0);
        if(gameMode == 0)
        {
            if(dT<Time)
            {
                FILE *fp;
                fp=fopen("gameData.txt","w");
                fprintf(fp,"%d %d %d %d %d %d",score, Time, dT, seconds, minutes,life);
                fclose(fp);
            }
        }
        gameMode = -1;
    }

    //place your codes for other keys here
}
void henMove()
{
    hen1.x=(rand()%(screenWidth-150)+1);
    hen2.x=(rand()%(screenWidth-150)+1);
    hen3.x=(rand()%(screenWidth-150)+1);

    egg.x=hen1.x+70;
    EGG.x=hen2.x+70;
    Egg.x=hen3.x+70;

    hen1.y=rand()%3;
    hen2.y=rand()%3;
    hen3.y=rand()%3;

    egg_t=rand()%7;
}

void eggMove()
{
    if((dT>=80 && dT<= 85 ) || (dT>=100 && dT<=110) || (dT>= 140 && dT<=150) || (dT>=160 && dT<165))
    {
        egg.x=egg.x+sqrt(egg.y);
        EGG.x=EGG.x+sqrt(egg.y);
    }
    egg.y += 25;
    if(egg.y>(screenHeight/2)-20)
        egg.y=0;

    pic.y += 25;
}

void timer()
{
    if(gameMode == 0 && start == 1)
    {
        if(dT < Time)
        {
            dT++;
            seconds++;
            if(seconds>60)
            {
                seconds = 1;
                minutes++;
            }
            sprintf(s1,"%02d:%02d",(Time/60)-1-minutes,60-seconds);
        }
    }
}

void Score()
{
    if(gameMode==0 && start==1)
    {
        if(dT<Time)
        {
            if(egg.y>screenHeight/2-170 && egg.y<screenHeight/2 )
            {
                if((egg.x>basket.x && egg.x< (basket.x +110+b*25))||(EGG.x>basket.x && EGG.x< (basket.x +110+b*25)))
                {
                    egg_mode=1;
                }
                else
                {
                    egg_mode=0;
                }
            }
            if(enable_mode[0] == 1 && dT>10)
            {
                seconds -= 10;
                Time += 10;
            }
            enable_mode[0] =0;
            if(enable_mode[3] == 1 && Time-dT>10)
            {
                seconds += 10;
                Time -= 10;
            }
            enable_mode[3] =0;
            if(enable_mode[5] ==1)
            {
                if(life<=200)
                    life += 100;
                else if(life>200)
                    life=300;
            }
            enable_mode[5] =0;
            if(enable_mode[6] ==1 && Time-dT>10)
            {
                seconds +=10;
                Time -=10;
                if(life>=100)
                    life -=100;
                else if(life<100)
                    life=0;
            }
            enable_mode[6] =0;
        }
    }

}

void picMove()
{
    pic.x=(rand()%(screenWidth-150)+1);
    pict=rand()%3;
}

void gameOver()
{
    textBox =1;
    iShowBMP(0, 0, "game_over.bmp");
    iSetColor(0, 0, 0);
    iRectangle(400, 250, 700,100);
    glColor4ub(0, 0, 255, .7*255);
    iText(410, 280, str,GLUT_BITMAP_TIMES_ROMAN_24);
    iText(410, 200, s2,GLUT_BITMAP_TIMES_ROMAN_24);
}

void HighScore()
{
    FILE *fp;
    int scr_list[10], cnt= 0, i;
    char name_list[10][20];
    char tmp[20];

    if ( (fp = fopen("Input.txt", "r+")) == NULL )
    {
        printf("File not found. \n \n");
        exit(1);
    }
    else
    {
        while (!feof(fp))
        {
            fscanf(fp, "%s", name_list[cnt]);
            fscanf(fp, "%d", &scr_list[cnt]);
            cnt++;
        }
    }
    if(dT == Time)
    {
        if ( score > scr_list[cnt - 1])
        {
            for (i = cnt -1; i >= 0; i--)
            {
                if (score < scr_list[i])
                    break;
            }
            for(int j=cnt-2; j>i; j--)
            {
                strcpy(name_list[j+1], name_list[j]);
                scr_list[j+1]=scr_list[j];
            }

            strcpy(name_list[i+1],str);
            scr_list[i+1]=score;
        }
    }
    fclose(fp);

    for(i=0; i<cnt; i++)
        tmp[i]=0;
    for(i=0; i<10; i++)
    {
        iSetColor(255, 255, 255);
        iText(500,screenHeight-200-50*i,name_list[i],GLUT_BITMAP_TIMES_ROMAN_24);
        itoa(scr_list[i],tmp,10);
        iText(900,screenHeight-200-50*i,tmp,GLUT_BITMAP_TIMES_ROMAN_24);
    }

}

int main()
{
    //place your own initialization codes here.


    iSetTimer(1000,timer);
    iSetTimer(1000,henMove);
    iSetTimer(50,eggMove);
    iSetTimer(3000,picMove);
    iSetTimer(screenHeight/2,Score);

    if(music==1 && gameMode==-1)
        sndPlaySound("bgMusic.wav", SND_ASYNC|SND_LOOP);


    iInitialize(screenWidth,screenHeight, "Catch the egg!");

    return 0;
}

