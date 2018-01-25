/** identifier valid kina ta check korar program
jemon:

 int a,b,sum, 9sum, int;

 ekhane a,b,sum valid. eivabe identifier lekha jai.
 kintu 9sum,int invalid, karon surute 9 ekta numeric value aar int ekta keyword

 **/
#include<bits/stdc++.h>
using namespace std;

int isIdentifier(char s[]){
    char keyword[][10]={"auto","break","case","char","const","continue","default","double",
                        "else","enum","extern","float","for","goto","if","int", "do", "long",
                        "register","return","short","signed","sizeof","static", "struct",
                        "switch","typedef","union","unsigned","void","volatile","while"};
    printf("%s ",s); // ey printf() txt file er input gula print kore
    int flag = 1;  //prothomei flag er maan 1 kore rakhte hobe, mane ey porjonto dhorchi j eta valid identifier

    for(int i=0; i<32; i++){
        if(strcmp(s,keyword[i])==0)   //keyword kina check korbe
            flag=0;                   // keyword hole flag = 1 hobe, mane invalid identifier
    }

    if(isalpha(s[0]) || s[0]=='_') ;   // first character alphabet othoba underscore hole kichu korte hobe na
    else  flag=0;                       // jodi ta na hoi tahole flag = 1 hobe, mane invalid identifier

    int length = strlen(s);
    for(int j=0; j<length; j++){
        if(isalnum(s[j])!=0 || s[j]=='_');  //prottekta character alphabet/numeric/underscore hole kichu korte hobe na
        else flag=0;                        // jodi ta na hoi, tahole flag = 1 hobe, mane invalid identifier
    }

    return flag;
}
int main(){
    freopen("identifier.txt","r", stdin);
    char s[1000];
    while(gets(s)){    // ekta ekta kore line s[] e input nibe
        if(isIdentifier(s)) printf("valid\n");
        else printf("invalid\n");
    }
return 0;
}
