#include<bits/stdc++.h>
using namespace std;
vector<string> Keyword;
vector<string> Constant;
vector<string> Identifier;
vector<string> String;
vector<string> Symbol;
vector<string> Operator;

int isKeyword(char s[]){
    char keyword[][10]={"auto","break","case","char","const","continue","default","double",
                        "else","enum","extern","float","for","goto","if","int", "do", "long",
                        "register","return","short","signed","sizeof","static", "struct",
                        "switch","typedef","union","unsigned","void","volatile","while"};
    int flag = 0;  //prothomei flag er maan 0 kore rakhte hobe, mane ey porjonto dhorchi j eta valid identifier

    for(int i=0; i<32; i++){
        if(strcmp(s,keyword[i])==0)   //keyword kina check korbe
            flag=1;                   // keyword hole flag = 1 hobe, mane invalid identifier
    }
    return flag;
}

int isString(char s[]){
    if(s[0]=='"'){
        char t[1000];
        char c;
        int i=0;
        while(scanf("%c",&c)==1){
            t[i]=c;
            i++;
            if(c=='"') break;
        }
        strcat(s,t);
        return 1;
    }
    else return 0;
}


int isIdentifier(char s[]){
    int flag = 1;  //prothomei flag er maan 0 kore rakhte hobe, mane ey porjonto dhorchi j eta valid identifier

    if(isalpha(s[0]) || s[0]=='_') ;   // first character alphabet othoba underscore hole kichu korte hobe na
    else  flag=0;                       // jodi ta na hoi tahole flag = 1 hobe, mane invalid identifier

    int l = strlen(s);
    for(int j=0; j<l; j++){
        if(isalnum(s[j])!=0 || s[j]=='_');  //prottekta character alphabet/numeric/underscore hole kichu korte hobe na
        else flag=0;                        // jodi ta na hoi, tahole flag = 1 hobe, mane invalid identifier
    }

    return flag;
}


int isDecimal(char s[]){
    int length = strlen(s);
    int dotCount = 0;
    if(s[0]=='.') dotCount++;
    if(s[0]=='+' || s[0]=='-'||isdigit(s[0]));
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
int isConstant(char s[]){
    if(isNumeric(s)) return 1;
    else return 0;
}

int isOperator(char s[]){
    char operators[][3]={"+","-","*","/","%","=","<",">","<=",">=","==","!=","&&","||","!","&","|", "^", "~",">>","<<","->"};
    int flag = 0;  //prothomei flag er maan 0 kore rakhte hobe, mane ey porjonto dhorchi j eta operator na

    for(int i=0; i<32; i++){
        if(strcmp(s,operators[i])==0)   //operator kina check korbe
            flag=1;                   // operator hole flag = 1 hobe, mane invalid identifier
    }
    return flag;
}

int isSymbol(char s[]){
    char symbols[][3]={",",";","(",")","{","}","[","]","#"};
    int flag = 0;  //prothomei flag er maan 0 kore rakhte hobe, mane ey porjonto dhorchi j eta operator na

    for(int i=0; i<32; i++){
        if(strcmp(s,symbols[i])==0)   //operator kina check korbe
            flag=1;                   // operator hole flag = 1 hobe, mane invalid identifier
    }
    return flag;
}


int main(){
    freopen("tokenize.txt","r", stdin);
    char s[1000];

    while(scanf("%s",s)==1){    // ekta ekta kore line s[] e input nibe
        if(isKeyword(s)) Keyword.push_back(s);
        else if(isString(s)) String.push_back(s);
        else if(isIdentifier(s)) Identifier.push_back(s);
        else if(isConstant(s)) Constant.push_back(s);
        else if(isOperator(s)) Operator.push_back(s);
        else if(isSymbol(s)) Symbol.push_back(s);
    }


    printf("Keywords: \n");
    for(int i=0; i<Keyword.size(); i++)     cout<<Keyword[i]<<" "; printf("\n\n");
    printf("Strings: \n");
    for(int i=0; i<String.size(); i++)     cout<<String[i]<<" "; printf("\n\n");
    printf("Identifiers: \n");
    for(int i=0; i<Identifier.size(); i++)  cout<<Identifier[i]<<" "; printf("\n\n");
    printf("Constants: \n");
    for(int i=0; i<Constant.size(); i++)    cout<<Constant[i]<<" "; printf("\n\n");
    printf("Operators: \n");
    for(int i=0; i<Operator.size(); i++)    cout<<Operator[i]<<" "; printf("\n\n");
    printf("Symbols: \n");
    for(int i=0; i<Symbol.size(); i++)      cout<<Symbol[i]<<" "; printf("\n\n");
return 0;
}
