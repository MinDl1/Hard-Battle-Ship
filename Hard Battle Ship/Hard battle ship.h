//
//  main.cpp
//  Hard Battle Ship
//
//  Created by MinDl on 19.11.2021.
//

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int conversation(char a){
    int b;
    if(a=='a'||a=='0')b=0;
    else if(a=='b'||a=='1')b=1;
    else if(a=='c'||a=='2')b=2;
    else if(a=='d'||a=='3')b=3;
    else if(a=='e'||a=='4')b=4;
    else if(a=='f'||a=='5')b=5;
    else if(a=='g'||a=='6')b=6;
    else if(a=='h'||a=='7')b=7;
    else if(a=='i'||a=='8')b=8;
    else if(a=='j'||a=='9')b=9;
    else{
        b=0;
        cout<<"Erorr\n";
    }
    return b;
}

int const sizearr=12;
int Temp[sizearr][sizearr];

struct war_map{
private:
    int map[sizearr][sizearr];
    int warMap[sizearr][sizearr];
public:
    war_map(){
        for(int i=0;i<sizearr;i++){
            for(int j=0;j<sizearr;j++){
                warMap[i][j]=Temp[i][j]=map[i][j]=0;
            }
        }
    }
//    Show_map
    void show_map(){
        int const sizelet=10;
        char letters[sizelet]={'a','b','c','d','e','f','g','h','i','j'};
        cout<<"  | "<<'0'<<" | "<<'1'<<" | "<<'2'<<" | "<<'3'<<" | "<<'4'<<" | "<<'5'<<" | "<<'6'<<" | "<<'7'<<" | "<<'8'<<" | "<<"9 |\n-------------------------------------------\n";
        for(int i=1;i<sizearr-1;i++){
            cout<<letters[i-1]<<" ";
            for(int j=1;j<sizearr-1;j++){
                if(map[i][j]==0){
                    cout<<"|   ";
                }
                else if(map[i][j]==1){
                    cout<<"| # ";
                }
                else if(map[i][j]==2){
                    cout<<"| * ";
                }
                else if(map[i][j]==3){
                    cout<<"| @ ";
                }
                else{
                    cout<<"Error";
                }
            }
            cout<<"|\n-------------------------------------------"<<endl;
        }
        cout<<endl;
        cout<<"' '-void\n'*'-shot into the void\n'#'-your ship\n'@'-enemy has shot at your ship\n\n";
    }
//    WarMap
    void show_warMap(){
        cout<<"Your map:\n\n";
        show_map();
        int const sizelet=10;
        char letters[sizelet]={'a','b','c','d','e','f','g','h','i','j'};
        cout<<"Your map enemy:\n\n";
        cout<<"  | "<<'0'<<" | "<<'1'<<" | "<<'2'<<" | "<<'3'<<" | "<<'4'<<" | "<<'5'<<" | "<<'6'<<" | "<<'7'<<" | "<<'8'<<" | "<<"9 |\n-------------------------------------------\n";
        for(int i=1;i<sizearr-1;i++){
            cout<<letters[i-1]<<" ";
            for(int j=1;j<sizearr-1;j++){
                if(warMap[i][j]==0){
                    cout<<"|   ";
                }
                else if(warMap[i][j]==1){
                    cout<<"| # ";
                }
                else if(warMap[i][j]==2){
                    cout<<"| * ";
                }
                else if(warMap[i][j]==3){
                    cout<<"| @ ";
                }
                else{
                    cout<<"Error";
                }
            }
            cout<<"|\n-------------------------------------------"<<endl;
        }
        cout<<endl;
    }
//    Fire
    int fire(int a,int b,war_map & obj){
        a+=1;
        b+=1;
        int temp=map[a][b];
        map[a][b]+=2;
        if(map[a][b]==2){
            obj.warMap[a][b]=map[a][b];
            return 2;
        }
        else if(map[a][b]==3){
            obj.warMap[a][b]=map[a][b];
            return 3;
        }
        else if(map[a][b]>3){
            map[a][b]=temp;
            cout<<"Error\n";
            return 0;
        }
        return 0;
    }
//    Clear All
    void clearAll(){
        for(int i=0;i<sizearr;i++){
            for(int j=0;j<sizearr;j++){
                map[i][j]=0;
            }
        }
    }
//    clear one
    void clear(){
        for(int i=0;i<sizearr;i++){
            for(int j=0;j<sizearr;j++){
                map[i][j]=Temp[i][j];
            }
        }
    }
//    Set
    int set(int num,int a,int b){
        for(int i=0;i<sizearr;i++){
            for(int j=0;j<sizearr;j++){
                Temp[i][j]=map[i][j];
            }
        }
        a+=1;
        b+=1;
        if(a>sizearr-2||b>sizearr-2||a<1||b<1){
            cout<<"Error: Wrong location\n\n";
            return 0;
        }
        else if(map[a+1][b+1]!=0||map[a+1][b]!=0||map[a][b+1]!=0||map[a-1][b-1]!=0||map[a-1][b]!=0||map[a][b-1]!=0||map[a+1][b-1]!=0||map[a-1][b+1]!=0){
            cout<<"Error: Near ship\n\n";
            return 0;
        }
        else if(map[a][b]>=1){
            cout<<"Error: Wrong location\n\n";
            return 0;
        }
        else if(num==1){
            map[a][b]+=1;
            return 1;
        }
        string str;
        int a1,b1;
        char a2;
        cout<<"Enter how u want place:";
        cin>>str;
        cout<<endl;
        a2=str[0];
        b1=str[1]-48;
        a1=conversation(a2);
        b1+=1;
        a1+=1;
        if(num==2){
            if(a>9&&b1==b){
                cout<<"Error: Wrong location\n\n";
                return 0;
            }
            else if(b>9&&a1==a){
                cout<<"Error: Wrong location\n\n";
                return 0;
            }
            else if(abs(a1-a)<abs(b1-b)){
                if(map[a+1][b+2]==1||map[a][b+2]==1||map[a-1][b+2]==1){
                    cout<<"Error: Near ship\n\n";
                    return 0;
                }
                map[a][b]+=1;
                map[a][b+1]+=1;
                return 2;
            }
            else if(abs(a1-a)>abs(b1-b)){
                if(map[a+2][b]==1||map[a+2][b+1]==1||map[a+2][b-1]==1){
                    cout<<"Error: Near ship\n\n";
                    return 0;
                }
                map[a][b]+=1;
                map[a+1][b]+=1;
                return 2;
            }
            else{
                cout<<"Error\n\n";
                return 0;
            }
        }
        else if(num==3){
            if(a>8&&b1==b){
                cout<<"Error: Wrong location\n\n";
                return 0;
            }
            else if(b>8&&a1==a){
                cout<<"Error: Wrong location\n\n";
                return 0;
            }
            else if(abs(a1-a)<abs(b1-b)){
                if(map[a+1][b+2]==1||map[a][b+2]==1||map[a-1][b+2]==1||map[a+1][b+3]==1||map[a][b+3]==1||map[a-1][b+3]==1){
                    cout<<"Error: Near ship\n\n";
                    return 0;
                }
                map[a][b]+=1;
                map[a][b+1]+=1;
                map[a][b+2]+=1;
                return 3;
            }
            else if(abs(a1-a)>abs(b1-b)){
                if(map[a+2][b]==1||map[a+2][b+1]==1||map[a+2][b-1]==1||map[a+3][b]==1||map[a+3][b+1]==1||map[a+3][b-1]==1){
                    cout<<"Error: Near ship\n\n";
                    return 0;
                }
                map[a][b]+=1;
                map[a+1][b]+=1;
                map[a+2][b]+=1;
                return 3;
            }
            else{
                cout<<"Error: Wrong location\n\n";
                return 0;
            }
        }
        else if(num==4){
            if(a>7&&b1==b){
                cout<<"Error: Wrong location\n\n";
                return 0;
            }
            else if(b>7&&a1==a){
                cout<<"Error: Wrong location\n\n";
                return 0;
            }
            else if(abs(a1-a)<abs(b1-b)){
                if(map[a+1][b+2]==1||map[a][b+2]==1||map[a-1][b+2]==1||map[a+1][b+3]==1||map[a][b+3]==1||map[a-1][b+3]==1||map[a+1][b+4]==1||map[a][b+4]==1||map[a-1][b+4]==1){
                    cout<<"Error: Near ship\n\n";
                    return 0;
                }
                map[a][b]+=1;
                map[a][b+1]+=1;
                map[a][b+2]+=1;
                map[a][b+3]+=1;
                return 4;
            }
            else if(abs(a1-a)>abs(b1-b)){
                if(map[a+2][b]==1||map[a+2][b+1]==1||map[a+2][b-1]==1||map[a+3][b]==1||map[a+3][b+1]==1||map[a+3][b-1]==1||map[a+4][b]==1||map[a+4][b+1]==1||map[a+4][b-1]==1){
                    cout<<"Error: Near ship\n\n";
                    return 0;
                }
                map[a][b]+=1;
                map[a+1][b]+=1;
                map[a+2][b]+=1;
                map[a+3][b]+=1;
                return 4;
            }
            else{
                cout<<"Error: Wrong location\n\n";
                return 0;
            }
        }
        else{
            return 0;
        }
    }
//    Set Bot coordinatse
    int setbot(int num,int a,int b){
        a+=1;
        b+=1;
        int a1,b1;
        int const size_map=10;
        b1=rand()%size_map;
        a1=rand()%size_map;
        b1+=1;
        a1+=1;
        if(a>sizearr-2||b>sizearr-2||a<1||b<1){
            return 0;
        }
        else if(map[a+1][b+1]!=0||map[a+1][b]!=0||map[a][b+1]!=0||map[a-1][b-1]!=0||map[a-1][b]!=0||map[a][b-1]!=0||map[a+1][b-1]!=0||map[a-1][b+1]!=0){
            return 0;
        }
        else if(map[a][b]>=1){
            return 0;
        }
        else if(num==1){
            map[a][b]+=1;
            return 1;
        }
        else if(a1>sizearr-2||b1>sizearr-2||a1<1||b1<1){
            return 0;
        }
        else if(num==2){
            if(a>8&&abs(a1-a)>abs(b1-b)){
                return 0;
            }
            else if(b>8&&abs(a1-a)<abs(b1-b)){
                return 0;
            }
            else if(abs(a1-a)<abs(b1-b)){
                if(map[a+1][b+2]==1||map[a][b+2]==1||map[a-1][b+2]==1){
                    return 0;
                }
                map[a][b]+=1;
                map[a][b+1]+=1;
                return 2;
            }
            else if(abs(a1-a)>abs(b1-b)){
                if(map[a+2][b]==1||map[a+2][b+1]==1||map[a+2][b-1]==1){
                    return 0;
                }
                map[a][b]+=1;
                map[a+1][b]+=1;
                return 2;
            }
            else{
                return 0;
            }
        }
        else if(num==3){
            if(a>7&&abs(a1-a)>abs(b1-b)){
                return 0;
            }
            else if(b>7&&abs(a1-a)<abs(b1-b)){
                return 0;
            }
            else if(abs(a1-a)<abs(b1-b)){
                if(map[a+1][b+2]==1||map[a][b+2]==1||map[a-1][b+2]==1||map[a+1][b+3]==1||map[a][b+3]==1||map[a-1][b+3]==1){
                    return 0;
                }
                map[a][b]+=1;
                map[a][b+1]+=1;
                map[a][b+2]+=1;
                return 3;
            }
            else if(abs(a1-a)>abs(b1-b)){
                if(map[a+2][b]==1||map[a+2][b+1]==1||map[a+2][b-1]==1||map[a+3][b]==1||map[a+3][b+1]==1||map[a+3][b-1]==1){
                    return 0;
                }
                map[a][b]+=1;
                map[a+1][b]+=1;
                map[a+2][b]+=1;
                return 3;
            }
            else{
                return 0;
            }
        }
        else if(num==4){
            if(a>6&&abs(a1-a)>abs(b1-b)){
                return 0;
            }
            else if(b>6&&abs(a1-a)<abs(b1-b)){
                return 0;
            }
            else if(abs(a1-a)<abs(b1-b)){
                if(map[a+1][b+2]==1||map[a][b+2]==1||map[a-1][b+2]==1||map[a+1][b+3]==1||map[a][b+3]==1||map[a-1][b+3]==1||map[a+1][b+4]==1||map[a][b+4]==1||map[a-1][b+4]==1){
                    return 0;
                }
                map[a][b]+=1;
                map[a][b+1]+=1;
                map[a][b+2]+=1;
                map[a][b+3]+=1;
                return 4;
            }
            else if(abs(a1-a)>abs(b1-b)){
                if(map[a+2][b]==1||map[a+2][b+1]==1||map[a+2][b-1]==1||map[a+3][b]==1||map[a+3][b+1]==1||map[a+3][b-1]==1||map[a+4][b]==1||map[a+4][b+1]==1||map[a+4][b-1]==1){
                    return 0;
                }
                map[a][b]+=1;
                map[a+1][b]+=1;
                map[a+2][b]+=1;
                map[a+3][b]+=1;
                return 4;
            }
            else{
                return 0;
            }
        }
        else{
            return 0;
        }
    }
};
