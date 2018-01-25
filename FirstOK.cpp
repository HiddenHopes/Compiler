#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;

map<char, set<string> > g;
map<char, set<char> > fst;
map<char, set<char> > flw;
char start;

void input(){
    freopen("FirstOK.txt","r",stdin);
    char c, s[100];
    scanf("%c%*c%*c",&c);
    start = c;
    scanf("%s\n",s);
    g[c].insert(s);

    while(scanf("%c%*c%*c",&c)==1){
        scanf("%s\n",s);
        g[c].insert(s);
    }
}

set<char> First(char X){
    if(isupper(X)==0) {
        set<char> v;
        v.insert(X);
        return v;
    }
    if(g[X].find("e")!=g[X].end()) fst[X].insert('e');
    if(isupper(X))
      for(auto& i : g[X]){
        int p = 10;
        for(auto& j : i){
            set<char> y;
            if(isupper(j)) y = First(j);
            else {
                fst[X].insert(j); break;
            }

            if(y.find('e')!=y.end()) continue;
            else {
                for(auto& k : y)
                    fst[X].insert(k);
            }
        }
    }
    return fst[X];
}

void findFirst(){
    fst.clear();
    First(start);
    for (auto& i : g) {
        First(i.first);
    }
}


int main(){
    input();
    findFirst();
    for(auto& i : fst){
        cout<<"First ( "<<i.first<<" ) :   { ";
        for(auto& j : i.second)
            cout<<j<<", ";
        cout<<"}"<<endl;
    }
    return 0;
}
