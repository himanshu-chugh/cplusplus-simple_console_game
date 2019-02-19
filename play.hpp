#include<iostream>
using namespace std;


// 1 for valid , 0 for invalid & -1 for wrong key

int check_move(char **map ,int grid_size ,char move, int current_x,int current_y){
    if(move == 'w'){
        if(map[current_x][current_y+1] == '-' && ((current_y+1)<(grid_size-1)))
        return 1;
        else
        {
            return 0;
        }
        
    }
    else if(move == 's'){
        if(map[current_x][current_y-1] == '-' && (current_y-1>=0))
        return 1;
        else
        {
            return 0;
        }
        
    }
    else if(move == 'a'){
        if(map[current_x-1][current_y] == '-'  && (current_x-1>=0))
        return 1;
        else
        {
            return 0;
        }
        
    }
    else if(move == 'd'){
        if(map[current_x+1][current_y] == '-' && ((current_x+1)<(grid_size-1)))
        return 1;
        else
        {
            return 0;
        }
        
    }
    else {
        return -1;
    }

}


//  PLZ USE  "check_move()" BEFORE USING MAKE "make_mark()"
void make_mark(char **map, char move,int current_x,int current_y){
    if( move == 'w'){
        map[current_x][current_y+1]='$';
    }
    else if( move == 's'){
        map[current_x][current_y-1]='$';
    }
    else if( move == 'a'){
        map[current_x-1][current_y]='$';
    }
    else{
        map[current_x+1][current_y]='$';
    }
}
