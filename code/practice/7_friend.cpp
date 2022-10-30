#include<iostream>
using namespace std;
class Box{
    double width;
    friend void printWidth(Box box);
public:
    
    friend class BigBox;
    void setWidth(double wid);
};

class BigBox{
    public:
        void Print(int width,Box &box){
            //BigBox 是 Box的友元类,可以直接访问Box类的任何成员
            box.setWidth(width);
            cout << "Width of box: "<< box.width<<endl;
        }
};
// 成员函数定义
void Box::setWidth(double wid){
    width = wid;
};

//printWidth()不是任何类的成员函数
void printWidth(Box box)
{
    // printWidth()是Box的友元,它可以访问该类的任何成员.
    cout << "width of box: "<< box.width<<endl;
}

int main(){
    Box box;
    BigBox big;
    box.setWidth(10.0);
    printWidth(box);
    big.Print(20,box);
    return 0;
}
