## ubuntu下用锐捷认证&SSR

1. 下载mentohust

   [下载地址]()

   ![Ubuntu选择deb](https://github.com/georgezhou314/imageRepo/raw/master/linux/ruijiedownload.png)

   2. 安装 

   3. 运行

      ```shell
      # -u表示用户名 -p表示密码 -d1表示DHCP动态选择IP地址 v表示版本号,scu为6.82 
      # &表示后台运行，否则窗口关闭认证就退出了
      sudo mentohust -u20161414xxxx -p123456 -d1 -v6.82 &
      ```

   4. 出现的问题

      >0.提示“不允许使用的客户端类型”：学校禁用了xrgsu，使用-v参数指定版本号
      >
      >1.提示“客户端版本过低
      >
      >复制相关文件（"8021x.exe"和"W32N55.dll"）到/etc/mentohust/
      >
      >8021x.exe和W32n55.dll文件在Windows的锐捷认证软件(四川大学认证客户端)下有相关文件

## Ubuntu下用SSR

1. 下载electron-ssr

   [下载地址](https://github.com/qingshuisiyuan/electron-ssr-backup/releases)

   选择deb版本就可以

2. 下载打开填写IP,端口等参数就ok