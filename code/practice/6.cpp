#include<iostream>
using namespace std;

class Line{
    public:
        int getLength(void);
        Line(int len);
        Line(const Line &obj);
        ~Line();

    private:
        int *ptr;
};

Line::Line(int len){
    cout << "调用构造函数" << endl;
    //为指针分配内存
    ptr = new int;
    *ptr = len;
}

Line::Line(const Line &object){
    cout << "调用拷贝构造函数并为ptr分配内存" << endl;
    ptr = new int;
    *ptr = *object.ptr;
}

Line::~Line(void){
    cout << "释放内存" << endl;
    delete ptr;
}

int Line::getLength(void){
    return *ptr;
}
void display(Line obj){//这里在传递值时,使用了值拷贝,函数结束,会销毁内存
    cout << "line size: "<< obj.getLength()<<endl;
}
int main(){
    Line line(10);
    display(line);
    return 0;
}