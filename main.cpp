#include"random_maps_generator.hpp"
#include"play.hpp"
#include<conio.h>


int main(){
    



    char **global_game_map;
    int n=10,s=1;
    global_game_map = maps(n,s);
    int status;

    
    cout<<"\n\t\t MOVES ARE VERY SIMPLE YOU JUST HAVE TO USE 'W,A,S,D' \n\n"; 
    for(int i=n-1;i>=0;i--){
        cout<<"\t\t\t";
        for(int j=0;j<n;j++){
            cout<<global_game_map[j][i]<<"  ";
        }
        cout<<endl;
    }

    cout<<"\n\t\tEnter intitial coordinates taking this game in 1st quadrant : \n";
    int x,y;
    int flag = 0;
    do{
        cin>>x>>y;
        if((x>=0 && x<n && y>=0 && y<n )){
            if(global_game_map[x][y] == '-'){
                    global_game_map[x][y] = '$';
                    cout<<global_game_map[x][y]<<" "<<global_game_map[x][y]<<"\n";
                    cout<<"Done something\n";
                    flag = 1;
            }
            else
            {   cout<<global_game_map[x][y]<<"\n";
                cout<<"\n\t\tENTER ANY '-' COORDINATES\n";
            }
        }
    }while(flag==0);
    cout<<"\nfinally out from do while!!!\n";

    char main_move;

    while(true){
        system("cls"); 
        
        for(int i=n-1;i>=0;i--){
        cout<<"\t\t\t";
        for(int j=0;j<n;j++){
            cout<<global_game_map[j][i]<<"  ";
        }
        cout<<endl;
    }
    
    
    cout<<endl<<endl<<endl;
    cout<<"\t\tMAKE MOVE : ";
    
    main_move = getch();
    cout<<main_move<<"\n";


    status = check_move(global_game_map,n,main_move,x,y);
    cout<<status;
    if(status == 1){
        cout<<"yes";
        make_mark(global_game_map,main_move,x,y);
        cout<<"haa!!";
        if(main_move == 'w'){
            y=y+1;
        }
        if(main_move == 'a'){
            x=x-1;
        }
        if(main_move == 's'){
            y=y-1;
        }
        if(main_move == 'd'){
            x=x+1;
        }
        
    }
    else if(status == -1){
        cout<<"INVALID MOVE TRY AGAIN";
        continue;
    }
    else{
        cout<<"out";
        break;
    }
    }
    return 0;
}
