## 文本处理命令

* grep/egrep/fgrep：在文件中查找字符串(筛选)
* sed：流编辑(加工)
* awk：逐行扫描进行文本处理的一门语言(筛选与加工)

## grep (global regular expression print)

1. 语法

   grep [OPTIONS]  PATTERN [FILE...]

2. 选项

   -n，显示每行前面显示行号

   * 例子

     `grep -n echo *.sh`，查找*.sh文件中的echo字符，并打印行号

   -v，显示所有不包括模式的行

    * 例子

      `grep -n 'a=.*' while-demo.sh`，模式用单引号包括起来。

   -i，忽略字母大小写

3. 举例

   grep常用来过滤输出

   * `ls -l | grep '\.sh'`, 找出所有的shell文件（）
   * `grep -E '[0-9]+' hello.c`, 使用扩展的正则表达式，需要加上选项-E

## sed(流编辑和正则表达式替换)
* sed命令默认输出到屏幕，所以当要做彻底的文件替换用-i选项

* 替换文本中匹配的模式

  `sed -e 's/a/b/g' while-demo.sh`, 将while-demo.sh文件中的所有a替换为b，-E是使用扩展正则表达式

* 用()来进行分组管理

  time文件内容是*12-03-2019*,现在替换为*2019-03-12*, 将第一个分组匹配的放在新的文件的第三个位置,*\1,\2,\3*，表示的是第几个分组

* 举个栗子

      `sed -E 's/([0-9]{2})-([0-9]{2})-([0-9]{4})/\3\.\2\.\1/g' time`

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


## awk(行列筛选及文本加工)

awk选自三个发明人的名字

`awk '程序' 文件名列表`

程序: 条件{命令}

awk自动对每行文本进行条件判断，满足条件执行动作(内置循环), 变量NR就是行号

条件：与C语言类似的条件算符和逻辑表达式，正则表达式的模式匹配 */regexpr/*, 包含该模式的行，如果不指定条件就默认都满足。

* 举个栗子

* `ps -ef | awk '/guest/{printf("%s",$2);}'`, $2表示第二列，意思是正则表达式匹配*guest*模式，匹配之后执行的动作是*printf("%s",$2);*   , 就是把第二列打印出来。

* `awk '{printf("%d: %s\n",NR,$0);}' hello.c` , 由于没有指定匹配条件，所以默认每行都匹配，NR表示行号，$0表示整行
* `date | awk '{printf("%s",$3);}'` , 打印date日期的第三列
* `ls -l | awk '$5>500 {printf("%s\n",$0)}'`  , 选择尺寸大于500kb的进行整行输出。
