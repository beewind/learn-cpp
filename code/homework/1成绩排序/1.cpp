/* 成绩排序
1.使用字符串数组和实数数组分别存储学生的名字和成绩，并通过对学生成绩的排序，按照名次输出学生的名字
2.使用结构体struct 完成同样的功能  
*/
#include<array>
#include<iostream>
using namespace std;
array<string,9> names = {"十三","十二","十一","六","三","三四","五五","三一","一一"};
array <int,9> grade = {13,12,11,6,3,34,55,31,11};

void mycopy(int i,int j){
    names[i]=names[j];
    grade[i]=grade[j];
}

void sort_stu_in(int left,int right){
    if (left >= right){
        return ;
    }
    int v = grade[left];
    string v_name = names[left];
    int l= left;
    int r= right;
    while(l<r){
        while(l<r&&grade[r]>v){
            r--;
        }
        if (l<r){
            mycopy(l,r);
            l++;
        }
        while(l<r&&grade[l]<v){
            l++;
        }
        if(l<r){
            mycopy(r,l);
            r--;
        }

    }
    names[l]=v_name;
    grade[l]=v;
    sort_stu_in(left,l-1);
    sort_stu_in(l+1,right);
}

void sort_stu(){
    sort_stu_in(0,grade.size()-1);
}
int main(){
    sort_stu();
    for (int i=0;i<grade.size();i++){
        cout<<names[i]<<":"<<grade[i]<<endl;
    }
    
}
