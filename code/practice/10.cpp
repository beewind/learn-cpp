#include<iostream>
using namespace std;

void print(int i){
    cout <<"int :"<<i<<endl;
}
void print(double f){
    cout <<"double :"<<f<<endl;
}
int main(){
    print(1);
    print(1.0);
    return 0;
}