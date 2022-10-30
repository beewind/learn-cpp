#include <iostream>
using namespace std;

class Box{
    public :
        double length;
        double breadth;
        double height;

        //函数声明
        double get(void);
        void set(double len,double bre,double hei);
};
//成员函数定义
double Box::get(void){
    return length*breadth*height;
}
void Box::set(double len,double bre,double hei){
    length = len;
    breadth =bre;
    height = hei;
}
int main(){
    Box Box1;
    Box Box2;
    double volume =0.0;

    //set box1
    Box1.height = 5.0;
    Box1.length = 6.0;
    Box1.breadth = 7.0;

    //set box2
    Box2.height = 10.0;
    Box2.length = 12;
    Box2.breadth = 13;

    volume = Box1.height * Box1.breadth *Box1.length;
    cout << volume << endl;

    Box2.set(10,8,12.0);
    volume = Box2.get();
    cout << volume << endl;
}