### 用find命令和awk命令组合来统计代码数
find /c/Users/geoge/Documents/Github/lanzhangben -name '*.java' -exec wc -l {} \;>>txt
cat txt | awk `{sum+=$0;} END{print sum;}`