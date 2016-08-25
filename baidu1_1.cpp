#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<vector<int>> solve(int n){
    vector<vector<int>> ret;
    if(n<0) return ret;
    for(int i=n;i>1;i--){

        if(n%i==0){
            int mid=n/i;
            if(mid-i/2>0){
                vector<int> tmp;
                for(int j=mid-i/2;j<=mid+i/2;j++){
                    tmp.push_back(j);
                }
                ret.push_back(tmp);
                tmp.clear();
            }
        }else if(n%i!=0 && 2*n%i==0){

            int mid=n/i;
            if(mid-i/2+1>0){
                vector<int> tmp;
                for(int j=mid-i/2+1;j<=mid+i/2;j++){
                    tmp.push_back(j);
                }
                ret.push_back(tmp);
                tmp.clear();
            }
        }
    }
    return ret;
}
int main(){
    int n;cin>>n;
    vector<vector<int>> ret;
    ret=solve(n);
    if(ret.size()==0){
        cout<<"NONE"<<endl;
    }
    for(vector<int> x:ret){
        for(int y:x){
            cout<<y<<" ";
        }cout<<endl;
    }
 }
