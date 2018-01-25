#include<bits/stdc++.h>
using namespace std;


map<char, set<string> > g;
char start;

void input(){
    freopen("leftRecursion.txt","r",stdin);
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


int main(){
    input();
    leftRecursion();
    return 0;
}
