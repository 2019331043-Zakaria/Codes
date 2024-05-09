#include<iostream>
#include<stdio.h>
#include<vector>
#include<fstream>
#include<time.h>
#include<stdlib.h>
#include <conio.h>

using namespace std;

int N_Player; ///total number of players.


class Player{
public:
    string name;
    int current_position;
    int total_number_of_moves;

    Player(){
        current_position=0;
        total_number_of_moves=0;
    }


}player[10];

class Square{
public:
    int position_number;
    int special_move;
    int move_to_position;

    Square(){
        position_number=0;
        special_move=0;
        move_to_position=0;
    }

};

class Board{
public:
    Square square[48];

    Board()
    {
        for(int i=0;i<=47;i++){
            square[i].position_number=i;
            square[i].special_move=0;
            square[i].move_to_position=0;
        }
        string x;
        int y,z;
        ifstream box;
        box.open("SnakeLadder.txt");
        while(!box.eof()){
            box>>x>>y>>z;
            square[y].move_to_position=z ;
            if(x=="S") {square[y].special_move =1; }
            else {square[y].special_move=2; }
        }
        box.close();
    }
    void print(){
        for(int i=0;i<=47;i++){cout<<square[i].position_number<<" "<<square[i].special_move<<" "<<square[i].move_to_position<<endl; }
    }


}board;




class ScoreBoard{

public:
    vector<pair< string,pair<int,int>>>PrevScore; ///stores name , match played, total winnings.

    ScoreBoard(){
        ifstream Scores;
        Scores.open("GameScore.txt");
        bool flag=0;
        string names;
        int play,win;
        char trash;
        while(!Scores.eof()){
            if (!flag){getline(Scores,names); flag=1;}
            else{
                play=-1;
                Scores>>names>>play>>win;
                if(play !=-1 )PrevScore.push_back({names,{play,win}});
            }
        }
        Scores.close();

    }

}score_board;


class GamePlay{
public:
    bool endgame;
    int winning_player;
    GamePlay(){endgame=0;winning_player=-1;}

    void getinfo(){
        cout<<"Type the total number of players: "<<endl;
        cin>>N_Player;

        cout<<"Type the names one by one : "<<endl;

        for(int i=0;i<N_Player;i++){
            string x;
            cin>>x;
            player[i].name=x;
        }
    }
    void print(){
        for(int i=0;i<N_Player;i++) cout<<"player "<<i+1<<" is at "<<player[i].current_position<<endl;
        int arr[8]={47,36,35,29,23,12,11,0};
        bool flag=1;

        cout<<"-----------------------------------------------------------------------"<<endl;
        for(int i=0;i<8;i++){
            for(int j=0;j<7;j++){
                if(i==7 && j==0){
                    cout<<"|Start   ";
                    continue;
                }
                if(j==6){
                    if(i==0){cout<<"|Player:Position|"<<endl;}
                    else{
                        if(i<=N_Player){
                            cout<<"|Player"<<i<<":";
                            if(player[i-1].current_position/10==0) cout<<player[i-1].current_position<<"      |"<<endl;
                            else cout<<player[i-1].current_position<<"     |"<<endl;
                        }
                        else{
                            cout<<"|               |\n";
                        }
                    }
                }
                else{
                    int x;

                    if(flag==1 || i==3){
                        x=arr[i]-j;
                    }
                    else{
                        x=arr[i]+j;
                    }
                    if(board.square[x].special_move==0){
                        if(x/10!=0) cout<<"|"<<x<<"      ";
                        else cout<<"|"<<x<<"       ";
                    }
                    else if(board.square[x].special_move==1){
                        if(x/10==0 && board.square[x].move_to_position/10==0 ){cout<<"|"<<x<<"(S,"<<board.square[x].move_to_position<<")  ";}
                        else if(x/10!=0 && board.square[x].move_to_position/10==0 || x/10==0 && board.square[x].move_to_position/10!=0) {
                            cout<<"|"<<x<<"(S,"<<board.square[x].move_to_position<<") ";
                        }
                        else{cout<<"|"<<x<<"(S,"<<board.square[x].move_to_position<<")";}
                    }

                    else{
                        if(x/10==0 && board.square[x].move_to_position/10==0 ){cout<<"|"<<x<<"(L,"<<board.square[x].move_to_position<<")  ";}
                        else if(x/10!=0 && board.square[x].move_to_position/10==0 || x/10==0 && board.square[x].move_to_position/10!=0) {
                            cout<<"|"<<x<<"(L,"<<board.square[x].move_to_position<<") ";
                        }
                        else{cout<<"|"<<x<<"(L,"<<board.square[x].move_to_position<<")";}
                    }
                }
            }
            flag^=1;


            cout<<"|        |        |        |        |        |        |               |"<<endl;
            cout<<"|        |        |        |        |        |        |               |"<<endl;
            cout<<"-----------------------------------------------------------------------"<<endl;
        }


    }

    void draw(int i){
        system("CLS");
        char prev='x';
        print();
        cout<<"player "<<i+1<<"'s turn"<<endl<<flush;
        cout<<"Press R and Enter to roll the dice"<<endl;
        while(1){
            char r;
            cin>>r;
            if(r=='R') break;
        }
        srand (time(NULL));
        int value=(rand()%3)+1;

        cout<<"player "<<i+1<<" drew "<<value<<endl<<flush;


        if(player[i].current_position==0){
            if(value==1){
                player[i].current_position=1;
                player[i].total_number_of_moves++;
            }
        }
        else{
            if( (player[i].current_position + value) <= 47 ){
                player[i].current_position+=value;
                if( board.square[ player[i].current_position ].special_move!=0 ){
                    if(board.square[ player[i].current_position ].special_move==1) cout<<"OOPS!!! PLAYER "<<i+1<<" IS BITTEN BY A SNAKE!!!"<<endl;
                    else cout<<"CONGRATS!!! PLAYER "<<i+1<<" HAS STEPPED ON A LADDER"<<endl;
                    player[i].current_position=board.square[ player[i].current_position ].move_to_position;
                }
                if(player[i].current_position==47){
                    endgame=1;
                    winning_player=i;
                }
            }
            player[i].total_number_of_moves++;
        }
        cout<<"Press Enter Again"<<endl;
        getch();



    }

};




int main()
{
    ///board.print();


    GamePlay game;
    game.getinfo();


    while(!game.endgame){
        for(int i=0;i<N_Player && !game.endgame;i++){
            game.draw(i);
        }
    }

    ///cout<<game.winning_player + 1<<endl;

    vector<bool>flag(N_Player,0);
    ofstream Scores;
    Scores.open("GameScore.txt");
    Scores<<"PlayerName Number_Playing Number_Winning"<<endl;
    for(int i=0;i<score_board.PrevScore.size();i++){
        for(int j=0;j<N_Player;j++){
            if(player[j].name==score_board.PrevScore[i].first){
                flag[j]=1;
                score_board.PrevScore[i].second.first++;
                if(game.winning_player==j) score_board.PrevScore[i].second.second++;
                break;
            }
        }
        Scores<<score_board.PrevScore[i].first<<" "<<score_board.PrevScore[i].second.first<<" "<<score_board.PrevScore[i].second.second<<endl;
    }
    for(int i=0;i<N_Player;i++){
        if(flag[i]==0){
            Scores<<player[i].name<<" "<<1<<" ";
            if(game.winning_player==i ) Scores<<1<<endl;
            else Scores<<0<<endl;
        }
    }

    Scores.close();

    cout<<"THE WINNER IS PLAYER "<<game.winning_player+1<<endl;






	return 0;
}
