#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

int solution(vector<int> &A){
    vector<int> value(20005,0);
    //计算每个元素的个数
    for(int x:A){
        value[x]++;
    }
    //对元素进行进位 因为  2^1+2^1=2^2
    //2^2+2^2=2^3  2^3+2^3=2^4
    for(int i=0;i<20000;i++){
        int up=value[i]/2;
        value[i]=value[i]%2;
        value[i+1]+=up;
    }
    int ret=0;
    for(int i=0;i<20005;i++){
        ret+=value[i];
    }
    for(int i=0;i<20005;i++){
        if(value[i])
        cout<<i<<":" <<value[i]<<endl;
    }
    return ret;
}
int solutiontest(vector<int> &A){
    vector<int> value(20005,0);
    for(int x:A){
        value[x]++;

    }
    for(int i=0;i<20000;i++){
        int up=value[i]>>1;
        value[i]=value[i]&1;
        value[i+1]+=up;
    }
    int ret=0;
    for(int i=0;i<20005;i++){
        ret+=value[i];
    }
    return ret;
}
int main(){
    int arr[]={2,2,2,2};
    vector<int> vec(arr,arr+4);
    vector<int> vec1;
    for(int i=0;i<1;i++){
        vec1.push_back(0);
    }
    cout<<solutiontest(vec1)<<endl;
    cout<<solution(vec1)<<endl;
}

