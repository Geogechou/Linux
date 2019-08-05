#include <stdio.h>

int main() {
    FILE* stream;
    stream=fopen(R"(C:\Users\geoge\Desktop\c1.txt)","a+");
    fprintf(stream,"hello file,你好 文件,再见吧");
    fclose(stream);
    return 0;
}