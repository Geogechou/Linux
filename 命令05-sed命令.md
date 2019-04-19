
```shell
sed -i 's/https:\/\/www.sonydafa.com\/wechatApp/http:\/\/localhost:8080\/wechatApp_war_exploded/g' index.js
# sed的一条替换文本的命令
# -i表示替换文本并保存，默认是输出到屏幕上的
# s表示是替换操作
# 格式是s/pattern-to-find/replacement-pattern/
# g表示全局替换
# index.js是作用的文件名
# 正则表达式中需要用转义字符
# 该命令实现将https://www.sonydafa.com/wechatApp替换为http://localhost:8080/wechatApp_war_exploded
```
