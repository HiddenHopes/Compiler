#include<bits/stdc++.h>
using namespace std;
int isDecimal(char s[]){
    int length = strlen(s);
    int dotCount = 0;
    if(s[0]=='.') dotCount++;
    else if(s[0]=='+' || s[0]=='-'||isdigit(s[0]));
    else return 0;
    for(int i=1; i<length-2; i++){
        if(('0'<=s[i]&&s[i]<='9')||s[i]=='.');
        else return 0;
        if(s[i]=='.') dotCount++;
    }
    if(s[length-2]=='.')dotCount++;
    if(s[length-1]=='.')dotCount++;

    if(dotCount==0){
         if(isdigit(s[length-2])){
            if(isdigit(s[length-1]));
            else if(s[length-1]=='u'||s[length-1]=='U');
            else if(s[length-1]=='l' || s[length-1]=='L');
            else if(s[length-1]=='s' || s[length-1]=='S');
            else return 0;
        }
        else if(s[length-2]=='u' && s[length-1]=='l');
        else if(s[length-2]=='U' && s[length-1]=='L');
        else return 0;
    }
    else if(dotCount>1) return 0;
    return 1;
}

int isOctal(char s[]){
    int length = strlen(s);
    if(s[0]=='0');
    else return 0;
    for(int i=1; i<length; i++){
        if('0'<=s[i]&&s[i]<='7');
        else return 0;
    }
    return 1;
}

int isHexa(char s[]){
    int length = strlen(s);
    if(length>2 && s[0]=='0'&&(s[1]=='x'||s[1]=='X'));
    else return 0;
    for(int i=2; i<length; i++){
        if(('0'<=s[i]&&s[i]<='9') || ('a'<=s[i]&&s[i]<='f')|| ('A'<=s[i]&&s[i]<='F'));
        else return 0;
    }
    return 1;
}

int isNumeric(char s[]){
    int flag = 0;

    if(isDecimal(s)) flag = 1;
    else if(isOctal(s)) flag = 1;
    else if(isHexa(s)) flag = 1;

    return flag;
}

int main(){
    char s[1000];
    freopen("numeric.txt","r",stdin);
    while(gets(s)){
        printf("%s\t: \t",s);
        if(isNumeric(s)) printf("valid\n");
        else printf("invalid\n");
    }

    return 0;
}
