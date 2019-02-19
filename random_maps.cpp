#include<bits/stdc++.h>
using namespace std; 


/*
=================================================================================================
                                    STD CONVENTION HERE :-
=================================================================================================
                        IN REGION (0)  1< X <n-2   &   1< Y <n-2                W
                                                                            A       D
                                            0                                   S
                                        3       1
                                            2
------------------------------------------------------------------------------------------------
IN REGION (1)   X= 0   &   Y != 0,n-1       |           IN REGION (5) X = n-1   &   Y = 0
                        0                   |                               0
                    *       1               |                           1       *
                        2                   |                               *
--------------------------------------------|----------------------------------------------------
IN REGION (2) X= n-1   &   Y != 0,n-1       |           IN REGION (6) X = n-1   &   Y = n-1
                        0                   |                               *
                    1       *               |                           1       *
                        2                   |                               0
                                            |
--------------------------------------------|----------------------------------------------------
IN REGION (3)  X= 0   &   Y = n-1           |           IN REGION (7) X != 0,n-1  &  Y = 0   
                        *                   |                               0
                    *       1               |                           2       1
                        0                   |                               *
--------------------------------------------|----------------------------------------------------
IN REGION  (4)  X= 0   &   Y = 0            |           IN REGION (8) X != 0,n-1  &  Y = n-1
                        0                   |                               *
                    *       1               |                           2       1
                        *                   |                               0
====================================================================================================
====================================================================================================
*/

int prob(int p){
    int i=7;
    p=p*i;
    int k=rand()%p;

    //cout<<k/i<<" ";
    return (k/i);

}

char** maps(int n, int share){
    
    srand(time(0));
    char **map = new char*[n];
    for(int i=0;i<n;i++){
        map[i] = new char[n];
    }
    char previous_move = '\0';  // w a s d ;
    short int X,Y ;
    int move;
    X = rand()%n;
    Y = rand()%n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            map[i][j]='#';
        }
    }

    map[X][Y]='-';


    for(int i=0;i<(n*n)/share;i++){
        //  REGION (0) CODE
        if( X>0 && X<n-1 && Y>0 && Y<n-1 ){
            move = prob(4);
            if(previous_move == 'w' && move == 2)
                move += 1;
            else if(previous_move == 'd' && move == 3)
                move -= 3;
            else if(previous_move == 'a' && move == 1)
                move += 1;
            else if(previous_move == 's' && move == 0)   
                move += 1;
            else
                char imt;

            switch(move){
                case 0:
                    Y=Y+1; previous_move = 'w';
                    break;
                case 1:
                    X=X+1; previous_move = 'd';
                    break;
                case 2:
                    Y=Y-1; previous_move = 's';
                    break;
                case 3:
                    X=X-1; previous_move = 'a';
                    break;
            }
        }
        //  REGION (1) CODE
        else if (X==0  && Y>0 && Y<n-1) {
            move = prob(3);
            if(previous_move == 'w' && move == 2)
                move -= 2;
            else if(previous_move == 'a' && move == 1)
                move += 1;
            else if(previous_move == 's' && move == 0)   
                move += 1;
            else
                char imt;
            switch(move){
                case 0:
                    Y=Y+1; previous_move = 'w';
                    break;
                case 1:
                    X=X+1; previous_move = 'd';
                    break;
                case 2:
                    Y=Y-1; previous_move = 's';
                    break;
            }
        }
        //  REGION (2) CODE
        else if (X==(n-1)  && Y>0 && Y<n-1) {
            move = prob(3);

            if(previous_move == 'w' && move == 2)
                move -= 2;
            else if(previous_move == 'd' && move == 1)
                move += 1;
            else if(previous_move == 's' && move == 0)   
                move += 1;
            else
                char imt;

            switch(move){
                case 0:
                    Y=Y+1; previous_move = 'w';
                    break;
                case 1:
                    X=X-1; previous_move = 'a';
                    break;
                case 2:
                    Y=Y-1; previous_move = 's';
                    break;
            }
        }
        //  REGION (3) CODE
        else if (X==0  && Y==(n-1) ) {
            move = prob(2);
            
            if(previous_move == 'w' && move == 0)
                move += 1;
            else if(previous_move == 'a' && move == 1)
                move -= 1;
            else
                char imt;

            switch(move){
                case 0:
                    Y=Y-1; previous_move = 's';
                    break;
                case 1:
                    X=X+1; previous_move = 'd';
                    break;
            }
        }
        //  REGION (4) CODE
        else if (X==0  && Y==(0) ) {
            move = prob(2);
            
            
            if(previous_move == 's' && move == 0)
                move += 1;
            else if(previous_move == 'a' && move == 1)
                move -= 1;
            else
                char imt;
            
            switch(move){
                case 0:
                    Y=Y+1; previous_move = 'w';
                    break;
                case 1:
                    X=X+1; previous_move = 'd';
                    break;
            }
        }
        //  REGION (5) CODE
        else if (X==(n-1)  && Y==(0) ) {
            move = prob(2);
            
            if(previous_move == 's' && move == 0)
                move += 1;
            else if(previous_move == 'd' && move == 1)
                move -= 1;
            else
                char imt;
            
            switch(move){
                case 0:
                    Y=Y+1; previous_move = 'w';
                    break;
                case 1:
                    X=X-1; previous_move = 'a';
                    break;
            }
        }
        //  REGION (6) CODE
        else if (X==(n-1)  && Y==(n-1) ) {
            move = prob(2);
            
            if(previous_move == 'w' && move == 0)
                move += 1;
            else if(previous_move == 'd' && move == 1)
                move -= 1;
            else
                char imt;
        
            switch(move){
                case 0:
                    Y=Y-1; previous_move = 's';
                    break;
                case 1:
                    X=X-1; previous_move = 'a';
                    break;
            }
        }
        //  REGION (7) CODE
        else if (X > 0 && X<(n-1) && Y==0) {
            
            move = prob(3);

            
            if(previous_move == 's' && move == 0)
                move += 1;
            else if(previous_move == 'a' && move == 1)
                move += 1;
            else if(previous_move == 'd' && move == 2)   
                move -= 2;
            else
                char imt;
            

            switch(move){
                case 0:
                    Y=Y+1; previous_move = 'w';
                    break;
                case 1:
                    X=X+1; previous_move = 'd';
                    break;
                case 2:
                    X=X-1; previous_move = 'a';
                    break;
            }
        }
        //  REGION (8) CODE
        else if (X>0 && X<(n-1) && Y==(n-1)) {
            
            move = prob(3);

            
            if(previous_move == 'w' && move == 0)
                move += 1;
            else if(previous_move == 'a' && move == 1)
                move += 1;
            else if(previous_move == 'd' && move == 2)   
                move -= 2;
            else
                char imt;

            switch(move){
                case 0:
                    Y=Y-1; previous_move = 's';
                    break;
                case 1:
                    X=X+1; previous_move = 'd';
                    break;
                case 2:
                    X=X-1; previous_move = 'a';
                    break;
            }
        }
        else{
            cout<<"\n\n\t\tError sir\n\n";
        }

        map[X][Y]='-';
    }


    return (map);
}
int main(){
    //srand(time(0));
    int qwe;
    char **m;
    while(true){
    cin>>qwe;
    cout<<"===============================================================================================";
    cout<<endl<<endl;
    m=maps(10,qwe);
    for(int i=0;i<10;i++){
        cout<<"\t\t";
        for(int j=0;j<10;j++){
            cout<<m[i][j]<<"  ";
        }
        cout<<endl;
    }
    cout<<endl;
    
    cout<<"===============================================================================================";
    }
    return 0;
}
