#include<bits/stdc++.h>
using namespace std;

//rand return value from 0 to RAND_MAX
int rand(int a,int b){
    return a+rand()%(b-a+1);
}
int main(int argc,char* argv[]){
    srand(atoi(argv[1]));//atoi converts an array of char to int
    int n=rand(2,5000);
    printf("%d\n",n);
    set<int>used;
    for(int i=0;i<n;i++){
        int x;
        do{
            x=rand(1,5000);

        }while(used.count(x));
        printf("%d ",x);
        used.insert(x);

    }
    puts("");

}