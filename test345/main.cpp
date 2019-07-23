#include <iostream>

using namespace std;
int n = 1;
int i = 0;
int c = 0;
int t = 6;
int g = 0;
int av = 0;
int hz=0;
int b[9][10];
int m(int a){
    //cout<<"N: "<<n++;
    if (i==0){
        cout<<"\n";}
    cout <<a;
    hz++;
    //cout<<"/nt/n"<<
    if (hz==1000){ return 1;}
    if (i==n){c++;}
    if (a==1){i++; if (b[i][0]==0){if (i==6){b[i][0]=1;i=0; return m(n);}else if(b[i+1][5]==3){b[i][0]=1;b[i+1][5]=0;}else {return m(6);}}
        if (b[i][0]==1){if (i==6){b[i][0]=0;i=0; return m(n);}else if(b[i+1][7]==3){b[i][0]=3;b[i+1][7]=0;i=0;c--;return m(n);}else{return m(8);}}}
    if (a==2){i++; if (b[i][1]==0){if (i==6){b[i][1]=1;i=0; return m(n);}else if(b[i+1][6]==3){b[i][1]=1;b[i+1][6]=0;}else {return m(7);}}
        if (b[i][1]==1){if (i==6){b[i][1]=0;i=0; return m(n);}else if(b[i+1][8]==3){b[i][1]=3;b[i+1][9]=0;i=0;c--;return m(n);}else{return m(9);}}}
    if (a==3){i++; if (b[i][2]==0){if (i==6){b[i][2]=1;i=0; return m(n);}else if(b[i+1][3]==3){b[i][2]=1;b[i+1][3]=0;}else {return m(4);}}
        if (b[i][2]==1){if (i==6){b[i][2]=0;i=0; return m(n);}else if(b[i+1][7]==3){b[i][2]=3;b[i+1][7]=0;i=0;c--;return m(n);}else{return m(8);}}}
    if (a==4){i++; if (b[i][3]==0){if (i==6){b[i][3]=1;i=0; return m(n);}else if(b[i+1][9]==3){b[i][3]=1;b[i+1][9]=0;}else {return m(0);}}
        if (b[i][3]==1){if (i==6){b[i][3]=2;i=0; return m(n);}else if(b[i+1][2]==3){b[i][3]=2;b[i+1][2]=0;}else{return m(3);}}
        if (b[i][3]==2){if (i==6){b[i][3]=3;i=0; return m(n);}else if(b[i+1][8]==3){b[i][3]=3;b[i+1][8]=0;i=0;c--;return m(n);}else{return m(9);}}}
    //if (a==5) return 1;
    if (a==6){i++; if (b[i][5]==0){if (i==6){b[i][5]=1;i=0; return m(n);}else if(b[i+1][9]==3){b[i][5]=1;b[i+1][9]=0;}else {return m(0);}}
        if (b[i][5]==1){if (i==6){b[i][5]=2;i=0; return m(n);}else if(b[i+1][0]==3){b[i][5]=2;b[i+1][0]=0;}else{return m(1);}}
        if (b[i][5]==2){if (i==6){b[i][5]=3;i=0; return m(n);}else if(b[i+1][6]==3){;b[i][5]=3;b[i+1][6]=0;i=0;c--;return m(n);}else{return m(7);}}}
    if (a==7){i++; if (b[i][6]==0){if (i==6){b[i][6]=1;i=0; return m(n);}else if(b[i+1][1]==3){b[i][6]=1;b[i+1][1]=0;}else{return m(2);}}
        if (b[i][6]==1){if (i==6){b[i][6]=0;i=0; return m(n);}else if(b[i+1][5]==3){b[i][6]=3;b[i+1][5]=0;i=0;c--;return m(n);}else{return m(6);}}}
    if (a==8){i++; if (b[i][7]==0){if (i==6){cout<<"erfolg11";b[i][7]=1;i=0; return m(n);}else if(b[i+1][0]==3){b[i][7]=1;cout<<"erfolg";b[i+1][0]=0;}else {return m(1);}}
        if (b[i][7]==1){if (i==6){b[i][7]=0;i=0; return m(n);}else if(b[i+1][2]==3){b[i][7]=3;cout<<"erfolg";b[i+1][2]=0;i=0;c--;return m(n);}else{return m(3);}}}
    if (a==9){i++; if (b[i][8]==0){if (i==6){b[i][8]=1;i=0; return m(n);}else if(b[i+1][1]==3){b[i][8]=1;b[i+1][1]=0;}else {return m(2);}}
        if (b[i][8]==1){if (i==6){b[i][8]=0;i=0; return m(n);}else if(b[i+1][3]==3){b[i][8]=3;b[i+1][3]=0;i=0;c--;return m(n);c--;}else{return m(4);}}}
    if (a==0){i++; if (b[i][9]==0){if (i==6){b[i][9]=1;i=0; return m(n);}else if(b[i+1][3]==3){b[i][9]=1;b[i+1][3]=0;}else {return m(4);}}
        if (b[i][9]==1){if (i==6){b[i][9]=3;i=0; return m(n);}else if(b[i+1][5]==3){b[i][9]=3;b[i+1][5]=0;i=0;c--;return m(n);}else{return m(6);}}}

    return 0;
}

int main()
{
    for (int j=0;j<9;j++){
        for (int k=0; k<10;k++){
            b[j][k]=0;}
    }

    m(1);
    cout<<"\nC: "<<c<<"\n";
    cout<<"\n I: ";//<<i;
    for (int j=0;j<9;j++){
        cout<<endl;cout<<j<<": ";
        for (int k=0; k<10;k++){
            cout<<b[j][k];}}


    return 0;
}