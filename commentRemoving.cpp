#include<stdio.h>
#include<string.h>
char s[10000];
void commentRemove(){
    freopen("commentRemoving.txt","r",stdin);
    int sflag = 0;    // single comment flag mane single comment paile sflag 1 kore dite hobe.
    int dflag = 0;    /*double comment flag mane double comment paile dflag 1 kore dite hobe*/
    while(gets(s)){   // gets() diye s[] e proti loop e ekta kore line input nibe
        int length = strlen(s); // s[] liner character songkha
        for(int i=1; i<length; i++){
            if(sflag) break;  // sflag 1 hole mane '//' thakle ey line aar print korar dorkar nai. tai break kore porer line input nibe.

            if(s[i-1] == '/' && s[i] == '/') sflag = 1; // por por duita character '//' hole sflag 1 kore dite hobe
            else if(s[i-1] == '/' && s[i] == '*') dflag = 1; /* por por duita character '/*' hole dflag 1 kore dite hobe*/

            if(sflag==0 && dflag==0)printf("%c",s[i-1]); // sflag aar dflag konotai jodi 1 na hoi tahole print hobe.

            if(s[i-1] == '*' && s[i] == '/') {dflag = 0;i++;} // por por duita character '*/' hole dflag abar 0 kore dite hobe.
        }
        if(sflag==0 && dflag==0)printf("%c",s[length-1]); // sflag aar dflag konotai jodi 1 na hoi, tahole last er character print hobe
        printf("\n"); // newline print hobe
        sflag = 0;  // proti line er kaaj seshe sflag sob somoi 0 kore dite hobe karon eta single line comment. porer liner jonno er daam nai.
    }
}
int main(){
    commentRemove();
    return 0;
}
