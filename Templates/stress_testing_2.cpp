#include<bits/stdc++.h>
using namespace std;


struct testcase{
    int a,n,d;
};
int random_number(int a,int b){
    return a+(rand()%b);
}
testcase generate_test_case(){
    testcase randomTest;
    randomTest.a=random_number(1,1000000);
    randomTest.n=random_number(1,1000000);
    randomTest.d=random_number(-100000,1000000);
    return randomTest;
}
int brute_force(testcase T){

}
int optimized_solution(testcase T){

}
void debugger(){
    testcase random=generate_test_case();
  int ans1=brute_force(random);
  int ans2=optimized_solution(random);
  if(ans1!=ans2){
      cout<<random.a;
    //   exit();
  }
}
int main(int argc,char* argv[]){
  
  int t=1;
  while(true){
      debugger();
  }

}