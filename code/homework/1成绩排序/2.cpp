#include<string>
#include<iostream>
#include<array>
using namespace std;
struct Student{
    string name ;
    int grade;
}students[7] ={
    {"一一",11},{"十二",12},{"一",1},{"十四",14},
    {"十五",15},{"二一",21},{"四一",41}
};
void quick_sort(int left,int right){
        if (left >= right){
            return ;
        }
        struct Student v = students[left];
        int l = left;
        int r = right;
        while(l < r){
            while( l< r && students[r].grade > v.grade){
                r--;
            }
            if (l<r){
                students[l++]=students[r];
            }
            while (l<r && students[l].grade<v.grade)
            {
                l++;
            }
            if (l<r){
                students[r--]=students[l];
            }
            
        } 
        students[l]=v;
        quick_sort(left,l-1);
        quick_sort(l+1,right);
    }
void sort_stu(){
    quick_sort(0,6);
}
int main(){
    sort_stu();
    for (auto &&i : students)
    {
        cout<<i.name<<":"<<i.grade<<endl;
    }
    
}