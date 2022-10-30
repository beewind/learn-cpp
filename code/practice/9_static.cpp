#include<iostream>
using namespace std;

class Box{
    public:
        static int objection;
        Box(double l=2.0,double b=2.0,double h=2.0){
            cout << "constructor called." <<endl;
            length = l;
            breadth = b;
            height = h;
            objection++;
        }
        double Volume(){
            return length*breadth*height;
        }
        Box(const Box &obj){
            cout <<"拷贝构造函数调用:" <<obj.objection <<endl;
        }
    private:
        double length;
        double breadth;
        double height;
        
        
};
void display(Box box){
    cout << box.Volume()<<endl;
}

int Box::objection=0;

int main(void){
    Box box1(3.3,1.2,1.5);
    cout <<"Total objects: "<< Box::objection<<endl;
    Box box2(8.5,6.0,2.0);
    cout <<"Total objects: "<< Box::objection<<endl;
    display(box1);
    cout <<"Total objects: "<< Box::objection<<endl;
    return 0;
}