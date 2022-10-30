#include<iostream>
using namespace std;

class Box{
    public:
        Box(double l,double b,double h){
            length = l;
            breadth = b;
            height = h;
        }
        // 定义为成员变量
        Box operator+(const Box& b){
            Box box(1,1,1);
            box.length = this->length + b.length;
            box.height = this->height+b.height;
            box.breadth = this->breadth + b.breadth;
            return box;
        }
        friend Box operator-(const Box&,const Box&);
        friend void display(Box& box);

    private:
        double length;
        double breadth;
        double height;
};

// 定义为非成员变量
Box operator-(const Box& a,const Box& b){
    Box box(1,1,1);
    box.breadth = a.breadth-b.breadth;
    box.height = a.height-b.height;
    box.length = a.length - b.length;
    return box;
}
void display(Box& box){
    cout<<box.breadth<<endl;
}
int main(){
    Box box1(1.0,1,1);
    Box box2(2,2,2);
    Box box3 = box2+box1;
    display(box3);
    Box box4 = box2-box1;
    display(box4);
    
    return 0;

}