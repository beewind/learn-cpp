#include<iostream>
using namespace std;
class People{
    public:
        string getName(){
            return name;
        }
        string getDish(){
            return dish;
        }
        string getSport(){
            return sport;
        }
        People(string n,string d,string s){
            name = n;
            dish = d;
            sport = s;
        }
        virtual void welcome(){
            cout <<"我是"<<name<<",喜欢"<<dish<<","<<sport<<endl;
        }
    private:
    string name;
    string dish;
    string sport;
};
void say(People* p){
    p->welcome();
}
class Chinese : public People{
    public:
        //TODO 父类初始化为什么不能写在函数体内?
        Chinese(string n,string d,string s):People(n,d,s){}
        void welcome(){
            cout << "你是中国人-"<<getName()<<",喜欢"<<getDish()
            <<","<<getSport()<<endl;
        }

};

class American : public People{
    public:
        American(string n,string d,string s):People(n,d,s){}
        void welcome(){
            cout << "你是美国人-"<<getName()<<",喜欢"<<getDish()
            <<","<<getSport()<<endl;
        }

};
int main(){
    Chinese w("王小强","四川菜","太极拳");
    American a("约翰","批萨","橄榄球");
    say(&w);
    say(&a);
}