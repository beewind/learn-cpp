#include<iostream>
using namespace std;

struct Student{
    char *name;
    int age;
};
int main(){
    struct Student st1 = {name:"eugene",age:18};
    cout<<st1.name<<":"<<st1.age<<endl;
}