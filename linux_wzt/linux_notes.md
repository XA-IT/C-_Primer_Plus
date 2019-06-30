# Linux 基础

tab 自动补全命令
### Linux 常用命令
#### 文件处理
##### ls
ls(list) [-选项] [参数]  
如：`ls -la /usr` (long, all)  
各个选项可以自由组合  
-a, -d(当前目录本身), -l, -i(id号)，-h(human) 

##### 目录处理命令
- mkdir 
  - make directories
  - 选项：-p(递归地创建)
- cd
  - change directory
  - ..(上一级目录),  .(当前目录)
- pwd 
  - print working dir
- rmdir
  - remove empty dir
- cp [ ] [(多个)src] [dst]
  - copy
  - -r (复制目录), -p (保持原文件属性)
- mv [src] [dst]
  - move
  - 在当前目录下直接移动 == 改名
- rm
  - remove
  - -r (删除目录), -f (强制)