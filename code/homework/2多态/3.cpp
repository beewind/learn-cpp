/*
3. 实现一个单例类
4. 练习各类注释的写法
*/

// 更多的c++单利模式
// https://www.cnblogs.com/zhxmdefj/p/14168495.html

#include<iostream>
using namespace std;
class Singleton {
    public:
        ~Singleton(){
            cout<<"析构函数调用"<<endl;
        };
        static Singleton* getInstance();
        static void deleteInstance();
        void show(){
            cout << s_ptr<<endl;
        }

    private:
        Singleton(){};
        static Singleton *s_ptr;
};
Singleton *Singleton::s_ptr = nullptr;

Singleton* Singleton::getInstance(){
    if (s_ptr==nullptr){
        s_ptr = new Singleton;
    }
    return s_ptr;
}
void Singleton::deleteInstance(){
    if (s_ptr!=nullptr){
        delete s_ptr;
    }
    return ;
}
int main(){
    Singleton *a = Singleton::getInstance();
    a->show();
    #if 1
    Singleton *b = Singleton::getInstance();
    b->show();
    #endif
    Singleton::getInstance()->show();
    return 0;
}
