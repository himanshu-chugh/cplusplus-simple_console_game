#include<bits/stdc++.h>
using namespace std;
void display(int n,char **arr){
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}
bool check(int x,int y,int n,char **arr){
	if(x>=0 && y>=0 && x<n && y<n)
	{
		if(arr[x][y]=='#')
			return true;
	}
	return false;
}
void board_gen(int x,int y,int n,char **arr){
	static int a[4]={1,2,3,4};
	random_shuffle(a,a+4);
	int counter=0;
	arr[x][y]='-';
	for(int i=0;i<4;i++)
	{
		if(a[i]==1)
		{
			if(check(x,y-1,n,arr))
			{
				arr[x][y-1]='-';
				board_gen(x,y-1,n,arr);
				break;
			}
			else
				counter++;
		}
		else if(a[i]==2)
		{
			if(check(x,y+1,n,arr))
			{
				arr[x][y+1]='-';
				board_gen(x,y+1,n,arr);
				break;
			}
			else
				counter++;
		}
		else if(a[i]==3)
		{
			if(check(x+1,y,n,arr))
			{
				arr[x+1][y]='-';
				board_gen(x+1,y,n,arr);
				break;
			}
			else
				counter++;
		}
		else
		{
			if(check(x-1,y,n,arr))
			{
				arr[x-1][y]='-';
				board_gen(x-1,y,n,arr);
				break;
			}
			else
				counter++;
		}	
	}
}
char** maps(int n){
	srand(time(0));
   	char **map = new char*[n];
    for(int i=0;i<n;i++)
        map[i] = new char[n];
    for(int i=0;i<n;i++)
    	for(int j=0;j<n;j++)
    		map[i][j] ='#';
    int x=rand()%n;
    int y=rand()%n;
    board_gen(x,y,n,map);
    //display(n,map);
    return map;
    
}
