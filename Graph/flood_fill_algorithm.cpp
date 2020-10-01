#include<iostream>
#include<list>
using namespace std;

int R,C;
void printmat(char input[][50]){
   
   for(int i=0;i<R;i++){
      for(int j=0;j<C;j++){
         cout<<input[i][j];
      }
      cout<<endl;
   }
}


// W,N,E,S
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};


//ch is the character to be replaced
//color is the character to be added

void floodfill(char mat[][50],int i, int j,char ch,char color){  //DFS
      //Base case
	  if(i<0||j<0 || i>=R || j>=C){ 
         return;
	  }
      
      //Figure boundary condition
      if(mat[i][j]!=ch){
          return;
      }

      //Recursion call
      mat[i][j] = color;

      for(int k=0;k<4;k++){ //all four direction
         floodfill(mat,i+dx[k],j+dy[k],ch,color);
      }

}


int main(){
 
	cin >> R >> C;

	char input[15][50];

	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			cin>>input[i][j];
		}
	}

	floodfill(input,8,13,'.','r'); //initiate at (8,13)
	printmat(input);
	return 0;
}


/***** input ********
15 30
..............................
............#####.............
............#...#.............
.....########...#######.......
....###....######.....###.....
...##...................##....
..##.....................#....
..##....................##....
..###..................##.....
....###...............###.....
......###............###......
........###........###........
..........##########..........
..............................
............A.P.P.L.E.........

******************/
