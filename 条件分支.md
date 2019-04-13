## 条件分支

### 条件分支的语法

```shell
if  condition
	then list
elif condition
	then list
else 
	list
fi
```

```shell
# log current date to errLog
# rewrite errFile content to errLog and remove errFile
# if errFile not exist,then write error log to errLog

file=errLog
date>>$file
if [ -w errFile ]
then
	cat errFile>>$file
	rm errFile
	echo "remove errFile"
else	
	echo "This File can not be writed"
	echo "No Error File Or No write right">>$file
fi
```



### case分支结构

* 语法

  ```shell
  case word in
  pattern1) list1;;
  pattern2) list2;;
  ....
  esac
  ```
