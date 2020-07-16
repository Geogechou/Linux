## 查找文件 find which whereis locate

### locate 

locate查找文件速度很快，但是不是實時查找，結果可能不精確。查找原理是查找一個數據庫

例子

```
$: locate vim
# 顯示出所有包含vim字符的文件
```

注：該命令需要手動安裝`sudo apt-get install mlocate`

### find

find命令實時向硬盤查找

### which

which命令查找命令是否存在，以及存放的位置

例子

```
$: which vim
# 顯示/usr/bin/vim
```

### whereis

whereis用來搜索程序名以及man文件及源碼文件

```
$:whereis vim
# 輸出：
# vim: /usr/bin/vim /usr/bin/vim.basic /usr/bin/vim.tiny 
# /etc/vim /usr/share/vim /usr/share/man/man1/vim.1.gz

```



