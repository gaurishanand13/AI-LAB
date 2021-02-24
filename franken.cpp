#include <iostream>
#include <vector>
#include<string>
#include<map>
#include<set>
#include<stdio.h> 
#include<ctype.h> 
using namespace std;


vector<char> find_first(map<char , vector<string> >& u_map , char ch){
    vector<char> ans;
    if((ch>='a' && ch<='z') || ch == '$'){
        ans.push_back(ch);
        return ans;
    }
    if(u_map.count(ch)==0){
        return ans;
    }
    vector<string> curr = u_map[ch];
    for(int i=0;i<curr.size();i++){
        bool flag = true;
        for(int j=2;j<curr[i].size();i++){
            vector<char> smallans = find_first(u_map , curr[i][j]);
            if(smallans.size() == 0){
                continue;
            }
            else{
                if(smallans.size() == 1 && smallans[0] == '$'){
                    continue;
                }
                flag = false;
                for(int k=0;k<smallans.size();k++){
                    ans.push_back(smallans[k]);
                }
                break;
            }
        }
        if(flag){
            ans.push_back('$');
        }
    }    
    return ans;
}

int main()
{
    int x;
    cout<<"Number of Lines : ";
    cin >> x;

    map<char , vector<string> > u_map;
    set<char> firstChar;
    for(int i=0;i<x;i++){
        string req;
        cin >> req;
        u_map[req[0]].push_back(req);
        for(int j=0;j<req.size();j++){
            if(req[j]>='A' && req[j]<='Z'){
                firstChar.insert(req[j]);
            }
        }
    }

    char choice = 'x';
    cout<<"OUTOUT ------------------>"<<endl;
    for(auto it:firstChar){
        char ch = it;
        vector<char> ans = find_first(u_map , ch);
        cout<<"FIRST("<<ch<<") = {";
        for(int i=0;i<ans.size();i++){
            if(i == ans.size()-1){
                cout<<ans[i];
            }
            else{
                cout<<ans[i]<<",";
            }
        }
        cout<<"}\n";
    }
}