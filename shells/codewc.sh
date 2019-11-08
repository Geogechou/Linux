### 输入要统计代码的后缀名，输出当前目录下所有该后缀的文件的行数
### 例如 bash codewc "sh",统计所有sh为结尾的代码的行数
find . -name "*.$1" -exec wc -l {} \;|awk '{sum+=$0;} END{printf("%d行\n",sum);}'
