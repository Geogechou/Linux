## Git的使用
* `git branch branch1`
表示创建branch1分支  
* `git checkout branch1` 
由当前分支切换到branch1分支  
* `git push origin branch1:branch1` 
 表示从本地branc1推送到远程branch1  
* `git branch -d branch1` 
 表示删除本地分支branch1  
* `git push origin --delete branch1` 
表示删除远程分支branch1  
* `git branch -a` 
显示本地分支和远程分支
<<<<<<< HEAD
### 只clone近几次的提交
```
# 仅跟踪近3次commit，体积明显要小很多
git clone xxx.git --depth 3
```
### 抛弃全部提交历史，重建
```
rm -rf .git
git init
git add -A
git commit -m "核平"
git remote add origin '*.git'
git push origin master --force

```
### 清除跟踪所有的.idea文件
```
git rm --cached -rf .idea
```
=======

>从GitHub拉去出一个仓库并在本地新增文件
>1. `git remote rm origin`   
>2. `git remote add origin git@github.com:Geogechou/Java.git`   
>3. `git clone git@github.com:Geogechou/Java.git`   
>4. `git push origin master`     

>>>>>>> f5ad8c3c734fb8b5d4d1eb5192673120508aeeb1
