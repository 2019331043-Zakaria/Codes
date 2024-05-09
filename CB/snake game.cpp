#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>
using namespace std;
enum edir{
    STOP,
    LEFT,
    RIGHT,
    UP,
    DOWN
};
class snake
{
private:
    int w, h;
    int fruitx,  fruity;
    int snakex, snakey;
    edir direction;
    bool gameover;
    int ntail;
    int score;
    int tailx[1000] = {0}, taily[1000] = {0};
public:
    snake(int width, int height){
        w = width;
        h = height;
        snakex = w/2;
        snakey = h/2;
        fruitx = 1 + (rand()%(w-1)) ;
        fruity = 1 + (rand()%(h-1)) ;
        gameover = 0;
        ntail = 0;
        score = 0;
    }
    void draw(){
        system("cls");
        for(int i=0; i<=h; i++){
            for(int j=0; j<=w; j++){
                if(!i or !j or i==h or j==w)putchar('\xFE'),putchar(' ');
                else if(i == fruity and j == fruitx)putchar('#'),putchar(' ');
                else if(i == snakey and j == snakex)putchar('O'),putchar(' ');
                else{
                    bool visited = 0;
                    for(int k = 0; k<ntail; k++){
                        if(tailx[k]==j and taily[k]==i)putchar('o'),putchar(' '),visited=1;
                    }
                    if(visited == 0)putchar(' '),putchar(' ');
                }
            }
            putchar('\n');
        }
        printf("Score : %d\n",score);
    }
    void input(){
        if(_kbhit()){
            switch(_getch()){
                case 'w':
                    if(direction != DOWN)direction = UP;
                    break;
                case 's':
                    if(direction != UP)direction = DOWN;
                    break;
                case 'a':
                    if(direction != RIGHT)direction = LEFT;
                    break;
                case 'd':
                    if(direction != LEFT)direction = RIGHT;
                    break;
                case 'x':
                    gameover = 1;
                    break;
            }
        }
    }
    void logic(){
        int prevx = tailx[0];
        int prevy = taily[0];
        tailx[0] = snakex;
        taily[0] = snakey;
        for(int i=1; i<ntail; i++){
            swap(prevx, tailx[i]);
            swap(prevy, taily[i]);
        }
        switch(direction){
            case UP:
                snakey--;
                break;
            case DOWN:
                snakey++;
                break;
            case LEFT:
                snakex--;
                break;
            case RIGHT:
                snakex++;
                break;
        }
        for(int i = 4; i<ntail; i++){
            if(tailx[i]==tailx[0] and taily[i]==taily[0])gameover=1;
        }
        if(snakex == 0 or snakey == 0 or snakex == w or snakey == h)gameover = 1;
        else if(snakex == fruitx and snakey == fruity){
            fruitx = 1 + (rand()%(w-1));
            fruity = 1 + (rand()%(h-1));
            ntail++;
            score += 10;
        }
    }
    void run(){
        while(!gameover){
            draw();
            input();
            logic();
            Sleep(10);
        }
        printf("Gameover!!!!");
    }
};
int main()
{
    snake s(20, 20);
    s.run();
    getch();
}
