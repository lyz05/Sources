#include<iostream>
#include<vector>
using namespace std;
 
int main()
{
    vector<int> v(3);
    v[0]=2;
    v[1]=7;
    v[2]=9;
    
    //在最前面的元素前插入8
    v.insert(v.begin(),8);
    
    //在第二个元素前插入新元素1
    v.insert(v.begin()+2,1);
    
    //在末尾插入新元素1
    v.insert(v.end(),3);     
    
    for(vector<int>::iterator it=v.begin();it!=v.end();it++)
    cout<<*it<<endl;
    
    return 0;   
}