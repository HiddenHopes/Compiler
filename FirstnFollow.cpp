#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;

map<char, set<string> > g;
//char fst[100][100];
//char flw[100][100];
map<char, set<char> > fst;
map<char, set<char> > flw;
char start;

void input(){
    freopen("FirstnFollow.txt","r",stdin);
    char c, s[100];
    scanf("%c%*c%*c",&c);
    start = c;
    scanf("%s\n",s);
    g[c].insert(s);

    while(scanf("%c%*c%*c",&c)==1){
        scanf("%s\n",s);
        g[c].insert(s);
        //cout<<c<<"->";puts(s);
    }
}

set<char> First(char X){
    //cout<<"First("<<X<<") = "<<endl;
    if(isupper(X)==0) {
        set<char> v;
        v.insert(X);
        //cout<<" '"<<X<<"' "<<endl;
        return v;
    }
    if(g[X].find("e")!=g[X].end()) fst[X].insert('e');
    if(isupper(X))
      for(auto& i : g[X]){
        //cout<<"  string: "<<i<<endl;
        int p = 10;
        for(auto& j : i){
            //cout<<"    symbol: "<<j<<endl;
            set<char> y;
            if(isupper(j)) y = First(j);
            else {
                fst[X].insert(j); break;
            }

            if(y.find('e')!=y.end()) continue;
            else {
                //cout<<">First("<<y<<") = "<<endl;
                for(auto& k : y)
                    //cout<<k<<","<<endl,
                    fst[X].insert(k);
            }
            //return fst[X];
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
/*
void Follow(char X){
    for (auto& i : g) {
        for(auto& j : i.second){
            bool flag = 0;
            char ch;
            for(auto k : j){
                if(flag == 1){
                    for(auto& r: fst[k]){
                        flw[X].insert(r);
                    }
                    flag = 0;
                }
                if(k==X && flag == 0){
                    flag = 1;
                    //ch = k;
                }
            }
            if(flag == 1 && flw[i.first].size()==0) Follow(i.first);
            for(auto& k : flw[i.first]){
                flw[X].insert(k);
            }
        }
    }
}
*/
void findFollow(){
    flw.clear();
    flw[start].insert('$');
    for (auto& i : g) {
        for(auto& j : i.second){
            bool flag = 0;
            char ch;
            for(auto k : j){
                if(flag == 1){
                    for(auto& r: fst[k]){
                        flw[ch].insert(r);
                    }
                    flag = 0;
                }
                if(isupper(k)&&flag == 0){
                    flag = 1;
                    ch = k;
                }
            }
            /*if(flag == 1 && flw[i.first].size()==0) Follow(i.first);
            for(auto& k : flw[i.first]){
                flw[ch].insert(k);
            }*/
        }
    }
}

int main(){
    input();
    findFirst();
    findFollow();
    for(auto& i : fst){
        cout<<"First ( "<<i.first<<" ) :   { ";
        for(auto& j : i.second)
            cout<<j<<", ";
        cout<<"}"<<endl;
    }
    cout<<endl;
    for(auto& i : flw){
        cout<<"Follow ( "<<i.first<<" ) :   { ";
        for(auto& j : i.second)
            cout<<j<<", ";
        cout<<"}"<<endl;
    }
    return 0;
}
