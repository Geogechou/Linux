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
### 清除跟踪所有的.idea文件
```
git rm --cached -rf .idea
```
