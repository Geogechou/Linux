#include <stdio.h>
#include <regex.h>
int main() {
    const char* pattern="(CN)([0-9]+)(.*)";
    char *str="CN86US01";
    regex_t reg;
    //编译正则表达式
    regcomp(&reg,pattern,REG_EXTENDED);
    regmatch_t pmatch[10];
    //nmatch为要匹配的数目,是要匹配的group,例如上式有3个group(CN),group([0-9]+),(.*),然后算group(0)一共是4
    //pmatch传一个regmatch_t数组, eflags一般为0(具体查看man regexec中有写详细的参数)
    int status=regexec(&reg,str,4,pmatch,0);
    //表示匹配成功
    if(status==0){
        //浏览所有匹配到的group
        for(size_t i=0;i<reg.re_nsub+1;i++) {
            //rm_so是字符串匹配的起始位置,rm_eo是字符串匹配的终止位置
            for (int j = pmatch[i].rm_so; j < pmatch[i].rm_eo; j++){
                printf("%c", str[j]);
            }
            printf("\n");
        }
    }
    //释放正则表达式
    regfree(&reg);
    return 0;
}