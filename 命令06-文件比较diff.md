## 文件比较

1. 采用MD5算法，根据文件内容生成16字节的Hash值，比较hash值是否相同。

   `md5sum visit.html`

   md5失误率:2^-128

2. 使用SHA-1算法的命令，生成20字节的Hash值

   `sha1sum visit.html`

### diff   比较不同

```shell
# 比较hello.c和hello1.c两个文件的不同之处
# u0的意思是，仅打印0行相同的，即只打印不同的
# u后不带数字，默认是打印3行相同，再打印不同的
diff -u0 hello.c hello1.c
```

### file命令

查看文件类型, `file hello.c`
