#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include <algorithm>  // for std::find
#include <iostream>   // for std::cout
#include <cstring>
#include<sstream>
using namespace std;

class Seg{
public:
    int s,e;
    Seg(int a,int b):s(a),e(b){};
};
bool cmp(Seg a,Seg b){
    return a.s<b.s;
}
int main()
{
   stringstream  ss;
   vector<Seg> segs;
   ifstream in("input.txt");
   string tmpString;
   if(in.is_open()){
        int a,b;
        while(in.good())
        {
            getline(in, tmpString);
            ss<<tmpString;
            ss>>a>>b;
            ss.clear();
            segs.push_back(Seg(min(a,b),max(a,b)));
        }
        in.close();
    }
    sort(segs.begin(),segs.end(),cmp);
    int ret=0;
    int last=-1;
    for(Seg x:segs){
        cout<<x.s<<"||"<<x.e<<endl;
        if(x.s<last){
            ret=max(ret,last-x.s+1);
        }
        last=max(last,x.e);
    }
    cout<<ret<<endl;
}
