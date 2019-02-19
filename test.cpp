#include"random_maps_generator.hpp"
#include"play.hpp"
#include<conio.h>

int main(){
    
    char **c;
    c=maps(10,1);
    for(int i=0;i<10;i++){
        cout<<"\t\t\t";
        for(int j=0;j<10;j++){
            cout<<c[i][j]<<"  ";
            //c[i][j]='q';
        }
        cout<<endl;
    }
    cout<<"============================================================\n";
    for(int i=0;i<10;i++){
        cout<<"\t\t\t";
        for(int j=0;j<10;j++){
            cout<<c[i][j]<<"  ";
            //c[i][j]='q';
        }
        cout<<endl;
    }
    
   char ch;
   int i;
   int x,y;
   cin>>x>>y;
   while(1){
   	   
    ch = getch();
    cout<<"\t\t"<<ch<<"\n";
    i = check_move(c,10,ch,x,y);
    cout<<"status :"<<i<<"\n";

}
    return 0;
}
