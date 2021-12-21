//
//  main.cpp
//  Hard Battle Ship
//
//  Created by MinDl on 19.11.2021.
//

#include <iostream>
#include <cmath>
#include <string>
#include "Hard battle ship.h"
#include <time.h>
using namespace std;


int main(int argc, const char * argv[]){
    string again="again";
    while(again=="again")
        srand(time(NULL));
        int num_1=rand()%7; //If u want u can take there ur values
        int num_2=rand()%4; //If u want u can take there ur values
        int num_3=rand()%3; //If u want u can take there ur values
        int num_4=rand()%3; //If u want u can take there ur values
        int size_numbers=num_1+num_2+num_3+num_4;
        cout<<"Do u want play with:\n1)player\n2)bot\n::";
        cin>>again;
        if(again=="1"||again=="1)"||again=="player"){
            war_map player1;
            war_map player2;
            player1.show_map();
            int *numbers=new int[4]{0,0,0,0};
            int *a=new int(0);
            int *b=new int(0);
    //    Player1
            cout<<"Player1 turn\n";
            while(numbers[0]+numbers[1]+numbers[2]+numbers[3]<size_numbers){
                int num=0;
                string b1;
                cout<<"First coordinate(for example a0) or 'Gb' if u want go back one step or 'Cl' to clear all:";
                cin>>b1;
                if(b1=="Gb"||b1=="gb"||b1=="go back"||b1=="Go back"||b1=="GB"){
                    player1.clear();
                    cout<<endl;
                    player1.show_map();
                    if(*a==1){
                        numbers[0]--;
                        *a=0;
                    }
                    else if(*a==2){
                        numbers[1]--;
                        *a=0;
                    }
                    else if(*a==3){
                        numbers[2]--;
                        *a=0;
                    }
                    else if(*a==4){
                        numbers[3]--;
                        *a=0;
                    }
                }
                else if(b1=="Cl"||b1=="cl"||b1=="Clear all"||b1=="clear all"){
                    player1.clearAll();
                    for(int i=0;i<4;i++){
                        numbers[i]=0;
                    }
                    player1.show_map();
                }
                else{
                    char a1;
                    while(true){
                        cout<<"Number of cells:";
                        if(cin>>num){
                            break;
                        }
                        else{
                            cout<<"Wrong input"<<endl;
                            cin.clear();
                            cin.ignore(num<=0,'\n');
                        }
                    }
                    cout<<endl;
                    if(numbers[0]<num_1&&num==1){
                        a1=b1[0];
                        *b=b1[1]-48;
                        *a=conversation(a1);
                        *a=player1.set(num, *a, *b);
                        player1.show_map();
                        if(*a!=0){
                            numbers[0]++;
                        }
                    }
                    else if(numbers[1]<num_2&&num==2){
                        a1=b1[0];
                        *b=b1[1]-48;
                        *a=conversation(a1);
                        *a=player1.set(num, *a, *b);
                        player1.show_map();
                        if(*a!=0){
                            numbers[1]++;
                        }
                    }
                    else if(numbers[2]<num_3&&num==3){
                        a1=b1[0];
                        *b=b1[1]-48;
                        *a=conversation(a1);
                        *a=player1.set(num, *a, *b);
                        player1.show_map();
                        if(*a!=0){
                            numbers[2]++;
                        }
                    }
                    else if(numbers[3]<num_4&&num==4){
                        a1=b1[0];
                        *b=b1[1]-48;
                        *a=conversation(a1);
                        *a=player1.set(num, *a, *b);
                        player1.show_map();
                        if(*a!=0){
                            numbers[3]++;
                        }
                    }
                    else{
                        cout<<"U already use this ship\n";
                    }
                }
            }
        //Player2
            for(int i=0;i<4;i++){
                numbers[i]=0;
            }
            cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nPlayer2 tern\n";
            player2.show_map();
            while(numbers[0]+numbers[1]+numbers[2]+numbers[3]<size_numbers){
                int num=0;
                string b1;
                cout<<"First coordinate(for example a0) or 'Gb' if u want go back one step or 'Cl' to clear all:";
                cin>>b1;
                if(b1=="Gb"||b1=="gb"||b1=="go back"||b1=="Go back"||b1=="GB"){
                    player2.clear();
                    cout<<endl;
                    player2.show_map();
                    if(*a==1){
                        numbers[0]--;
                        *a=0;
                    }
                    else if(*a==2){
                        numbers[1]--;
                        *a=0;
                    }
                    else if(*a==3){
                        numbers[2]--;
                        *a=0;
                    }
                    else if(*a==4){
                        numbers[3]--;
                        *a=0;
                    }
                }
                else if(b1=="Cl"||b1=="cl"||b1=="Clear all"||b1=="clear all"){
                    player2.clearAll();
                    for(int i=0;i<4;i++){
                        numbers[i]=0;
                    }
                    player2.show_map();
                }
                else{
                    char a1;
                    while(true){
                        cout<<"Number of cells:";
                        if(cin>>num){
                            break;
                        }
                        else{
                            cout<<"Wrong input"<<endl;
                            cin.clear();
                            cin.ignore(num<=0,'\n');
                        }
                    }
                    cout<<endl;
                    if(numbers[0]<num_1&&num==1){
                        a1=b1[0];
                        *b=b1[1]-48;
                        *a=conversation(a1);
                        *a=player2.set(num, *a, *b);
                        player2.show_map();
                        if(*a!=0){
                            numbers[0]++;
                        }
                    }
                    else if(numbers[1]<num_2&&num==2){
                        a1=b1[0];
                        *b=b1[1]-48;
                        *a=conversation(a1);
                        *a=player2.set(num, *a, *b);
                        player2.show_map();
                        if(*a!=0){
                            numbers[1]++;
                        }
                    }
                    else if(numbers[2]<num_3&&num==3){
                        a1=b1[0];
                        *b=b1[1]-48;
                        *a=conversation(a1);
                        *a=player2.set(num, *a, *b);
                        player2.show_map();
                        if(*a!=0){
                            numbers[2]++;
                        }
                    }
                    else if(numbers[3]<num_4&&num==4){
                        a1=b1[0];
                        *b=b1[1]-48;
                        *a=conversation(a1);
                        *a=player2.set(num, *a, *b);
                        player2.show_map();
                        if(*a!=0){
                            numbers[3]++;
                        }
                    }
                    else{
                        cout<<"U already use this ship\n";
                    }
                }
            }
            delete [] numbers;
    //    Play
            bool count=true;
            string some;
            string player;
            int count_fire1=0;
            int count_fire2=0;
            while(count){
                cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                bool count1=true;
                bool count2=true;
                while(count1){
                    player1.show_warMap();
                    cout<<"Player1 turn\n";
                    char a1;
                    string b1;
                    cout<<"Coordinates to fire:";
                    cin>>b1;
                    a1=b1[0];
                    *b=b1[1]-48;
                    *a=conversation(a1);
                    *a=player2.fire(*a, *b,player1);
                    if(*a==3){
                        count_fire1++;
                    }
                    else if(*a==2){
                        player1.show_warMap();
                        count1=false;
                    }
                    if(count_fire1==(num_1+num_2*2+num_3*3+num_4*4)){
                        player="Player1";
                        count=false;
                        count1=false;
                        count2=false;
                    }
                }
                cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                cout>>"You missed, Next player turn\nWrite something to continue";
                cin>>some;
                while(count2){
                    player2.show_warMap();
                    cout<<"Player2 turn\n";
                    char a1;
                    string b1;
                    cout<<"Coordinates to fire:";
                    cin>>b1;
                    a1=b1[0];
                    *b=b1[1]-48;
                    *a=conversation(a1);
                    *b=player1.fire(*a, *b,player2);
                    if(*b==3){
                        count_fire2++;
                    }
                    else if(*b==2){
                        player2.show_warMap();
                        count2=false;
                    }
                    if(count_fire2==(num_1+num_2*2+num_3*3+num_4*4)){
                        player="Player2";
                        count=false;
                        count2=false;
                    }
                }
            }
            cout<<"Player1\n";
            player1.show_warMap();
            cout<<"Player2\n";
            player2.show_warMap();
            cout<<player<<" Win!!!!\n\n";
            delete a;
            delete b;
        }
        else if(again=="2"||again=="2)"||again=="bot"){
            war_map player1;
            war_map player2;
            player1.show_map();
            int *numbers=new int[4]{0,0,0,0};
            int *a=new int(0);
            int *b=new int(0);
    //    Player1
            cout<<"Player1 turn\n";
            while(numbers[0]+numbers[1]+numbers[2]+numbers[3]<size_numbers){
                int num=0;
                string b1;
                cout<<"First coordinate(for example a0) or 'Gb' if u want go back one step or 'Cl' to clear all:";
                cin>>b1;
                if(b1=="Gb"||b1=="gb"||b1=="go back"||b1=="Go back"||b1=="GB"){
                    player1.clear();
                    cout<<endl;
                    player1.show_map();
                    if(*a==1){
                        numbers[0]--;
                        *a=0;
                    }
                    else if(*a==2){
                        numbers[1]--;
                        *a=0;
                    }
                    else if(*a==3){
                        numbers[2]--;
                        *a=0;
                    }
                    else if(*a==4){
                        numbers[3]--;
                        *a=0;
                    }
                }
                else if(b1=="Cl"||b1=="cl"||b1=="Clear all"||b1=="clear all"){
                    player1.clearAll();
                    for(int i=0;i<4;i++){
                        numbers[i]=0;
                    }
                    player1.show_map();
                }
                else{
                    char a1;
                    while(true){
                        cout<<"Number of cells:";
                        if(cin>>num){
                            break;
                        }
                        else{
                            cout<<"Wrong input"<<endl;
                            cin.clear();
                            cin.ignore(num<=0,'\n');
                        }
                    }
                    cout<<endl;
                    if(numbers[0]<num_1&&num==1){
                        a1=b1[0];
                        *b=b1[1]-48;
                        *a=conversation(a1);
                        *a=player1.set(num, *a, *b);
                        player1.show_map();
                        if(*a!=0){
                            numbers[0]++;
                        }
                    }
                    else if(numbers[1]<num_2&&num==2){
                        a1=b1[0];
                        *b=b1[1]-48;
                        *a=conversation(a1);
                        *a=player1.set(num, *a, *b);
                        player1.show_map();
                        if(*a!=0){
                            numbers[1]++;
                        }
                    }
                    else if(numbers[2]<num_3&&num==3){
                        a1=b1[0];
                        *b=b1[1]-48;
                        *a=conversation(a1);
                        *a=player1.set(num, *a, *b);
                        player1.show_map();
                        if(*a!=0){
                            numbers[2]++;
                        }
                    }
                    else if(numbers[3]<num_4&&num==4){
                        a1=b1[0];
                        *b=b1[1]-48;
                        *a=conversation(a1);
                        *a=player1.set(num, *a, *b);
                        player1.show_map();
                        if(*a!=0){
                            numbers[3]++;
                        }
                    }
                    else{
                        cout<<"U already use this ship\n";
                    }
                }
            }
        //Bot
            delete [] numbers;
            numbers = new int[4]{0,0,0,0};
            while(numbers[0]+numbers[1]+numbers[2]+numbers[3]<size_numbers){
                int num =4;
                int const size_map=10;
                if(numbers[3]==num_4){
                    num=3;
                }
                if(numbers[2]==num_3){
                    num=2;
                }
                if(numbers[1]==num_2){
                    num=1;
                }
                if(numbers[0]<num_1&&num==1){
                    *b=rand()%size_map;
                    *a=rand()%size_map;
                    *a=player2.setbot(num, *a, *b);
                    if(*a==1){
                        numbers[0]++;
                    }
                }
                else if(numbers[1]<num_2&&num==2){
                    *b=rand()%size_map;
                    *a=rand()%size_map;
                    *a=player2.setbot(num, *a, *b);
                    if(*a==2){
                        numbers[1]++;
                    }
                }
                else if(numbers[2]<num_3&&num==3){
                    *b=rand()%size_map;
                    *a=rand()%size_map;
                    *a=player2.setbot(num, *a, *b);
                    if(*a==3){
                        numbers[2]++;
                    }
                }
                else if(numbers[3]<num_4&&num==4){
                    *b=rand()%size_map;
                    *a=rand()%size_map;
                    *a=player2.setbot(num, *a, *b);
                    if(*a==4){
                        numbers[3]++;
                    }
                }
                *a=0;
            }
            delete [] numbers;
    //    Play
            bool count=true;
            string player;
            int count_fire1=0;
            int count_fire2=0;
//            Fire
            while(count){
                int const size_map=10;
//                Player1 fire
                bool count1=true;
                bool count2=true;
                while(count1){
                    player1.show_warMap();
                    cout<<"Player1 turn\n";
                    char a1;
                    string b1;
                    cout<<"Coordinates to fire:";
                    cin>>b1;
                    a1=b1[0];
                    *b=b1[1]-48;
                    *a=conversation(a1);
                    *a=player2.fire(*a, *b,player1);
                    if(*a==3){
                        count_fire1++;
                    }
                    else if(*a==2){
                        player1.show_warMap();
                        count1=false;
                    }
                    if(count_fire1==(num_1+num_2*2+num_3*3+num_4*4)){
                        player="Player1";
                        count=false;
                        count1=false;
                        count2=false;
                    }
                }
//                Bot fire
                while(count2){
                    *b=rand()%size_map;
                    *a=rand()%size_map;
                    *b=player1.bot_mind(*a, *b, player2);
                    if(*b==3){
                        count_fire2++;
                    }
                    else if(*b==2){
                        count2=false;
                    }
                    if(count_fire2==(num_1+num_2*2+num_3*3+num_4*4)){
                        player="Player2";
                        count=false;
                        count2=false;
                    }
                }
            }
            cout<<"Player1\n";
            player1.show_warMap();
            cout<<"Player2\n";
            player2.show_warMap();
            cout<<player<<" Win!!!!\n\n";
            delete a;
            delete b;
        }
        cout<<"Do u want play again?(Write 'again'):";
        cin>>again;
        cout<<endl;
    }
}
