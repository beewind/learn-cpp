#include<iostream>

using namespace std;

template <typename T> 
T getSelf(T t){
    return t;
}

template<typename K> K doubleK(K k){
    return k+k;
}

int main(){
    int i = 2;
    int a = getSelf(i);
    cout << a<<endl;

    double j = 5.5;
    double b = doubleK(j);
    cout << b <<endl;
}