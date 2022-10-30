#include<iostream>
using namespace std;
class Box{
    private:
        double length;
        double breadth;
        double height;
    public:
        Box(double l= 2.0,double b=2.0,double h = 2.0){
            cout << "Constructor called."<<endl;
            length = l;
            breadth = b;
            height =h;
        }
        double Volume(){
            return length*breadth*height;
        }
        int compare(Box box){
            return this->Volume()> box.Volume();
        }
};
int main(){
    Box box1;
    Box box2;
    if (box1.compare(box2)){
        cout << "box1 big than box2" <<endl;
    }else{
        cout << "box2 smaller than or equal to box2 :"<< box1.Volume()<<endl;
    }
}