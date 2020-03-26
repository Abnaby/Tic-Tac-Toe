#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
char matrixs[3][3]={'1','2','3','4','5','6','7','8','9'};
int active = 0  ;
struct Move {
    int row , col ;
};
Move bestMove ;
void **resetMatrix(char setMatrixs[3][3]){
    int bin=49;
    for (int i = 0; i < 3 ;i++ ){
        for (int j= 0 ; j < 3 ; j++){
            setMatrixs[i][j]={bin};
            bin++;
            }
        }
        return nullptr ;
    }
void draw(){
    // i ==> column
    // j ==> row
    for (int i =0;i<3;i++){
        for (int j =0 ; j<3;j++){
            cout <<" "<< matrixs[i][j]<<" ";
            cout <<"|";
        }
        cout<<endl;

    }
}
void player1 (char x){
    active = 1 ;
        for (int i =0;i<3;i++){
            for (int j =0 ; j<3;j++){
                    if (x == matrixs[i][j]){
                         matrixs [i][j] = 'X' ;}
                    else {}
                }
        }

    }
void player2 (char x){
    active = 2 ;
        for (int i =0;i<3;i++){
            for (int j =0 ; j<3;j++){
                    if (x == matrixs[i][j]){
                        matrixs [i][j] = 'O' ;
                        }
                    else {}
                }
        }
    }
char AI (int row , int col){
    active = 2 ;
    for (int i = 0 ; i <3 ; i++) {
        for (int j=0 ; j<3 ; j++) {
            if (i==row && j == col){
                return matrixs[i][j];
            }
        }
    }
    }
int whoWinner (){
      int cntrx = 0 ,cntry =0  ;
      int horzx = 0 ,horzy = 0 ;
      int verx = 0  ,very = 0 ;
      int i , j ;
    for (i = 0 ; i < 3 ; i++){
        for (j = 0 ; j < 3 ;j++) {
            if (active == 1){
                //diagonal check
                if ((i==j ||(i + j) ==2 ) && (matrixs[i][j]=='X')){
                    cntrx ++ ;
                    }
                //horizontal check
                 if (matrixs[i][j]=='X'){
                    horzx++ ;
                    if (horzx == 2 && (i!=j && (i + j) ==2 )) {
                        cntrx = cntrx-1;
                    }else{}
                    }
                 //vertical check
                 if (matrixs[j][i]=='X'){
                        verx++ ;
                    if (verx == 2 && (i!=j && (i + j) ==2 )) {
                        cntrx = cntrx-1;
                    }
                        }
                if (cntrx==3||horzx ==3 ||verx ==3){
                    return 1 ;
                }
                    }
            else if (active == 2) {
                //diagonal check
                if ((i==j ||(i + j) ==2 ) && (matrixs[i][j]=='O')){
                    cntry ++ ;
                    }
                //horizontal check
                 if (matrixs[i][j]=='O'){
                    horzy++ ;
                    if (horzx == 2 && (i!=j && (i + j) ==2 )) {
                        cntry = cntry-1;
                    }
                    }
                 //vertical check
                 if (matrixs[j][i]=='O'){very++ ;
                    if (horzy == 2 && (i!=j && (i + j) ==2 )) {
                        cntry = cntry-1;
                    }
                 }
                if (cntry==3||horzy ==3 ||very ==3){
                    return -1 ;
                }

                }

        }
                horzx = 0 ;
                verx = 0 ;
                horzy = 0 ;
                very = 0 ;
            }
return 0 ;
}
bool chackValidChoice(char x){
    for (int i=0 ; i<3 ; i++){
        for (int j = 0 ;j<3 ;j++){
            if ((matrixs[i][j] == x &&  matrixs[i][j] != 'X' && matrixs[i][j] != 'O')){
                return true;
            }
        }

    }
    return false ;
}
char AI_Easy_Level(){
         srand(time(NULL)); //initialize randomizer
                            //time(NULL) to change the random number every time
         char random = matrixs[rand()%3][rand()%3] ;
         return random ;
}
char AI_Medium_Level(){
/*
      int cntrx = 0 ;
      int horzx = 0 ;
      int verx = 0 ;
    for (int i = 0 ; i < 3 ; i++) {
        for (int j = 0 ; j <3 ; j++){
            //diagonal check
            if (active == 1){
                //diagonal check
                if ((i==j ||(i + j) ==2 ) && (matrixs[i][j]=='X')){
                    cntrx ++ ;
                    }
                //horizontal check
                 if (matrixs[i][j]=='X'){
                    horzx++ ;
                    if (horzx == 2 && (i==j ||(i + j) ==2 )) {
                        cntrx = cntrx-1;
                    }
                    }
                 //vertical check
                 if (matrixs[j][i]=='X'){verx++ ;}
                if(i==j || (i+j==2)){
                    if(matrixs[]){
                            return matrixs[i][j] ;
                    }
                }
                if(horzx == 2 && matrixs[i][j] != 'X'){
                    return matrixs[i][j] ;
                }
                if(verx == 2 && matrixs[j][i] != 'X'){
                    return matrixs[j][i] ;
                }
            }

        }
                horzx = 0 ;
                verx = 0 ;
            }

*/
//diagonals Check
//Attack First
        if ((matrixs[2][2] == 'O' && matrixs[1][1] == 'O') ||
            (matrixs[0][1] == 'O' && matrixs[0][2] == 'O') ||
             (matrixs[1][0] == 'O' && matrixs[2][0] == 'O')
                ){
                    if (matrixs[0][0] == 'X'){goto Defending;}
                    else {return matrixs[0][0];}
        }else if ((matrixs[0][0] == 'O' && matrixs[0][2] == 'O')||
                  (matrixs[1][1] == 'O' && matrixs[2][1] == 'O')){
                    if (matrixs[0][1] == 'X'){goto Defending;}
                    else {return matrixs[0][1];}
        }else if ((matrixs[1][1] == 'O' && matrixs[2][0] == 'O') ||
                   (matrixs[0][0] == 'O' && matrixs[0][1] == 'O')||
                   (matrixs[1][2] == 'O' && matrixs[2][2] == 'O')){
                    if (matrixs[0][2] == 'X'){goto Defending;}
                    else {return matrixs[0][2];}
        }else if ((matrixs[1][1] == 'O' && matrixs[1][2] == 'O') ||
                  (matrixs[0][0] == 'O' && matrixs[2][0] == 'O')){
                    if (matrixs[1][0] == 'X'){goto Defending;}
                    else {return matrixs[1][0];}
        }else if (((matrixs[0][0] == 'O' && matrixs[2][2] == 'O') ||
                    (matrixs[2][0] == 'O' && matrixs[0][2] == 'O')||
                    (matrixs[1][0] == 'O' && matrixs[1][2] == 'O')||
                    (matrixs[0][1] == 'O' && matrixs[2][1] == 'O'))){
                    if (matrixs[1][1] == 'X'){goto Defending;}
                    else {return matrixs[1][1];}
        }else if ((matrixs[1][0] == 'O' && matrixs[1][1] == 'O')||
                  (matrixs[0][2] == 'O' && matrixs[2][2] == 'O')){
                    if (matrixs[1][2] == 'X'){goto Defending;}
                    else {return matrixs[1][2];}
        }else if ((matrixs[0][2] == 'O' && matrixs[1][1] == 'O') ||
                  (matrixs[2][1] == 'O' && matrixs[2][2] == 'O')||
                  (matrixs[0][0] == 'O' && matrixs[1][0] == 'O')){

                    if (matrixs[2][0] == 'X'){goto Defending;}
                    else {return matrixs[2][0];}
        }else if ((matrixs[2][0] == 'O' && matrixs[2][2] == 'O')||
                  (matrixs[0][1] == 'O' && matrixs[1][1] == 'O')){
                    if (matrixs[2][1] == 'X'){goto Defending;}
                    else {return matrixs[2][1];}
        }else if ((matrixs[0][0] == 'O' && matrixs[1][1] == 'O' )||
                  (matrixs[2][0] == 'O' && matrixs[2][1] == 'O')||
                  (matrixs[0][2] == 'O' && matrixs[1][2] == 'O')){
                    if (matrixs[2][2] == 'X'){goto Defending;}
                    else {return matrixs[2][2];}
        }

//defending
       Defending:if ((matrixs[2][2] == 'X' && matrixs[1][1] == 'X') ||
            (matrixs[0][1] == 'X' && matrixs[0][2] == 'X') ||
             (matrixs[1][0] == 'X' && matrixs[2][0] == 'X')
                ){
                    if (matrixs[0][0] == 'O'){return AI_Easy_Level();}
                    else {return matrixs[0][0];}
        }else if ((matrixs[0][0] == 'X' && matrixs[0][2] == 'X')||
                  (matrixs[1][1] == 'X' && matrixs[2][1] == 'X')){
                    if (matrixs[0][1] == 'O'){return AI_Easy_Level();}
                    else {return matrixs[0][1];}
        }else if ((matrixs[1][1] == 'X' && matrixs[2][0] == 'X') ||
                   (matrixs[0][0] == 'X' && matrixs[0][1] == 'X')||
                   (matrixs[1][2] == 'X' && matrixs[2][2] == 'X')){
                    if (matrixs[0][2] == 'O'){return AI_Easy_Level();}
                    else {return matrixs[0][2];}
        }else if ((matrixs[1][1] == 'X' && matrixs[1][2] == 'X') ||
                  (matrixs[0][0] == 'X' && matrixs[2][0] == 'X')){
                    if (matrixs[1][0] == 'O'){return AI_Easy_Level();}
                    else {return matrixs[1][0];}
        }else if (((matrixs[0][0] == 'X' && matrixs[2][2] == 'X') ||
                    (matrixs[2][0] == 'X' && matrixs[0][2] == 'X')||
                    (matrixs[1][0] == 'X' && matrixs[1][2] == 'X')||
                    (matrixs[0][1] == 'X' && matrixs[2][1] == 'X'))){
                    if (matrixs[1][1] == 'O'){return AI_Easy_Level();}
                    else {return matrixs[1][1];}
        }else if ((matrixs[1][0] == 'X' && matrixs[1][1] == 'X')||
                  (matrixs[0][2] == 'X' && matrixs[2][2] == 'X')){
                    if (matrixs[1][2] == 'O'){return AI_Easy_Level();}
                    else {return matrixs[1][2];}
        }else if ((matrixs[0][2] == 'X' && matrixs[1][1] == 'X') ||
                  (matrixs[2][1] == 'X' && matrixs[2][2] == 'X')||
                  (matrixs[0][0] == 'X' && matrixs[1][0] == 'X')){

                    if (matrixs[2][0] == 'O'){return AI_Easy_Level();}
                    else {return matrixs[2][0];}
        }else if ((matrixs[2][0] == 'X' && matrixs[2][2] == 'X')||
                  (matrixs[0][1] == 'X' && matrixs[1][1] == 'X')){
                    if (matrixs[2][1] == 'O'){return AI_Easy_Level();}
                    else {return matrixs[2][1];}
        }else if ((matrixs[0][0] == 'X' && matrixs[1][1] == 'X' )||
                  (matrixs[2][0] == 'X' && matrixs[2][1] == 'X')||
                  (matrixs[0][2] == 'X' && matrixs[1][2] == 'X')){
                    if (matrixs[2][2] == 'O'){return AI_Easy_Level();}
                    else {return matrixs[2][2];}
        }

        return AI_Easy_Level() ;
    }
int main(){
//    int mac = INFINITY ;
    forx:cout << "Select How many players? \n1 or 2 \n" ;
    int Single_or_multi ; cin >> Single_or_multi ;
    if (Single_or_multi == 1){
            diffculty :cout << "Difficulty \n 1- Easy \n 2- Medium\n";
            int difficult , i =0 ; cin >>difficult ;
            if(difficult != 2 && difficult !=1) {
                        cout << "Input Not valid \n";
                        goto diffculty ;
                    }
            draw() ;
            if (difficult == 1) {
                    while (1){
            //            draw() ;
                        i++;
                        cout << "Player X Enter number from matrix = " << endl ;
                        enters : char x ; cin >> x;
                        if (chackValidChoice(x)== false) {
                            cout << "Enter number Not choice \n" ;
                            goto enters ;
                        }else {player1(x);}
                        if ( whoWinner() != 0) {
                            if (whoWinner() == 1 ){
                                cout << "You Winner !" << endl ;
                                draw() ;
                                break ;
                                }
                            }
                        draw() ;
                        if (i==4){goto check ;}
                        //Computer Playing
                        rechoice:char y = AI_Easy_Level();
                        if (chackValidChoice(y)== false) {goto rechoice ;}else {player2(y) ;}
                        if ( whoWinner() != 0) {
                            if (whoWinner() == -1 ){
                                cout << "Computer is the winner !" << endl ;
                                draw() ;
                                break ;}
                        else {}
                            }
                        cout << "Computer Choice : "<< y <<endl;

                        draw();
                     if (i==4){goto check ;}


                            }
                    }
            else if (difficult == 2 ) {
                    while (1){
                        i++;
                        cout << "Player X Enter number from matrix = " << endl ;
                        enterM : char x ; cin >> x;
                        if (chackValidChoice(x)== false) {
                            cout << "Enter number Not choice \n" ;
                            goto enterM ;
                        }else {player1(x);}
                        if ( whoWinner() != 0) {
                            if (whoWinner() == 1 ){
                                cout << "You Winner !" << endl ;
                                draw() ;
                                break ;}
                            }
                        draw() ;
                        if (i==4){goto check ;}
                        //Computer Playing
                        rechoiceAns:char y = AI_Medium_Level();
                        if (chackValidChoice(y)== false) {goto rechoiceAns ;}else {player2(y) ;}
                        cout << "Computer Choice : "<< y <<endl;
                        if ( whoWinner() != 0) {
                            if (whoWinner() == -1 ){
                                cout << "Computer is the winner !" << endl ;
                                draw() ;
                                break ;}
                        else {}
                            }
                            draw() ;
                     if (i==4){goto check ;}


                            }

                    }
        goto check ;
    }
    else if (Single_or_multi == 2) {
    draw();
    for (int i = 0 ; i < 9 ; i++){
        cout << "Player X Enter number from matrix = " << endl ;
        enterx : char x ; cin >> x;
        if (chackValidChoice(x)== false) {
            cout << "Enter number Not choice \n" ;
            goto enterx ;
        }else {
        player1(x);
        }
        if ( whoWinner() != 0) {
            if (whoWinner() == 1 ){
                cout << "The Winner is player one" << endl ;
                draw() ;
                break ;
            }
       }
    draw() ;
    if (i==4){
        goto check ;
     }        cout << "Player O Enter number from matrix = " << endl ;
        entery:
        char y ; cin >> y;
        if (chackValidChoice(y)== false) {
            cout << "Enter number Not choice \n" ;
            goto entery ;
        }else {
        player2(y) ;
        }
        if ( whoWinner() != 0) {
            if (whoWinner() == -1 ){
                cout << "The Winner is player two 'O'" << endl ;
                draw() ;
                break ;
            }
        else {
        }
    }
        draw() ;
     if (i==4){
        goto check ;
     }
   }
   check:if (whoWinner()== 1 || whoWinner() ==-1 ){
    cout << "Choose One of it \n 1- Restart Game \n 2- Exit \n"; }
   else {cout << "No Winner Choose One of it \n 1- Restart Game \n 2- Exit \n"; }
   choose:int choise=0; cin >>choise ;
    if (choise == 1){
        resetMatrix(matrixs);
        goto forx ;
    }
    else if (choise == 2){
        goto Exit ;
    }
    else {
       cout << "Wrong Choice Please Enter valid choice \n";
       goto choose;
        }
    }
    else {
        cout << "Wrong Choice Please Enter valid choice \n";
    goto forx ;
}

   Exit:return 0;
}

