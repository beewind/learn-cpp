#include<iostream>
using namespace std;

class Printer{
    public:
        virtual void print(){
            cout<<"this is Printer"<<endl;
        }
};

class DotMatrixPrinter:public Printer{
    public:
        void print(){
            cout<<"this is DotMatrixPrinter"<<endl;
        }
};

class InkpetPrinter:public Printer{
    public:
        void print(){
            cout<<"this is InkpetPrinter"<<endl;
        }
};

class LaserPrinter:public Printer{
    public:
        void print(){
            cout<<"this is LaserPrinter"<<endl;
        }
};
class Test{
    public:
        void test(Printer **p,int n){
            for (int i = 0;i<n;i++){
               p[i]->print();
            }
            
        }
};
int main(){
        Test t;
        Printer* p[]={new DotMatrixPrinter,new InkpetPrinter,
            new LaserPrinter,};

        t.test(p,sizeof(p)/sizeof(Printer));
}