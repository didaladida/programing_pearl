#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include <algorithm>  // for std::find
#include <iostream>   // for std::cout
#include <cstring>
#include<unordered_map>
#include<sstream>
using namespace std;
int main(){
    ifstream in1("dict.txt");
    unordered_map<string,string> w2w;
    stringstream ss;
    if(in1.is_open()){
        string tmp;
        while(in1.good()){
            getline(in1,tmp);
            ss<<tmp;
            string s1,s2;
            ss>>s1>>s2;
            ss.clear();
            w2w[s1]=s2;
        }
    }
    std::ifstream t("text.txt");
    std::stringstream buffer;

    buffer << t.rdbuf();
    string tmp;
    while(buffer>>tmp){
        if(w2w.find(tmp)!=w2w.end()){
            cout<<w2w[tmp]<<" ";
        }
        else cout<<tmp<<" ";
    }


}
