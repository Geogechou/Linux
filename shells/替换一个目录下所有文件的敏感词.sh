# find在当前目录查找，查找正则模式匹配点(.)前面若干个字符，dot(.)后面有或者没有字符都可以。
# 结合xargs作为参数送给sed命令处理
# sed命令-i表示替换，不加选项是替换结果输出屏幕，不进行文件替换
 find  . -regex  '.+\..*' -print|xargs sed -i 's/mypassword/*******/g'
