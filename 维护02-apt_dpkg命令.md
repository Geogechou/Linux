## 系统维护 

### apt命令

### 清除无效的安装包

```shell
sudo apt-get autoremove --purge
```
### 卸載未能正確安裝的包

```shell
sudo apt-get -f install
```
### 更新軟件源列表

```shell
apt-get update
```
### 根據軟件原更新軟件

```
apt-get upgrade
```

## dpkg 命令
debian package
### 安裝
```
dpkg -i xxx.deb
```
### 卸載
```
dpkg -r xxx
```
