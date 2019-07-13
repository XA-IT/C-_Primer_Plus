# Linux 基础

tab 自动补全命令
### 4. Linux 常用命令
#### 4.1 文件处理
##### 命令格式与ls
- ls(list) [-选项] [参数]  
  - 如：`ls -la /usr` (long, all)  
  - 各个选项可以自由组合  
  - -a, -d(当前目录本身), -l, -i(i节点)，-h(human) 

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

##### 文件处理命令
- touch
  - 创建空文件
  - 不建议使用空格，要用则需要""包围
- cat
  - 显示文件内容
  - -n (显示行号) 
- tac
  - 反向列示
- more
  - 针对文件内容比较大的情况
  - space或f 翻页， Enter(换行), q或Q(退出)， b(返回前一页)
- less
  - `/关键词` 查找关键词
  - pgup向上翻页
- head
  - -n 显示前n行，默认为10行
- tail
  - -n 显示后n行

##### 链接命令
- ln -s [src] [dst]
  - link
  - -s (创建软链接)，-d (创建硬链接)
  - 软链接的特点：所有人都有rwx权限，可以对目录生成链接
  - 硬链接：同步更新，公用同一个i节点；不能跨分区

#### 4.2 权限管理
- 文件权限
  - r 读，查看
  - w 写，修改
  - x 执行
- 目录权限
  - r 列出内容ls 注意：即使拥有文件的r权限但若没有所在目录的r权限，则无法查看文件
  - w 创建删除目录中的文件touch/mkdir/rm/rmdir
  - x 进入目录cd
- chmod [{ugoa} {+-=} {rwx}] [文件或目录]
  - 使用数字表示 r4 w2 x1， ugo各一位，将三个操作权限相加，523：-r-x-w--wx；文件权限默认755，目录644
  - change mode
  - -R (递归修改所有子目录)
  - e.g chmod g+w,o-r xxxx
- chown [用户] [文件或目录]
  - change owner
- chgrp [grp] [ ]
  - change group
  - 缺省组为创建者的组
- umask
  - 设置权限掩码，利用掩码配置权限

#### 文件搜索
##### 文件搜索命令
- find [范围] [匹配条件]
  - find /etc -name init   
  - find / -size +204800 (以数据块为单位，相当于0.5KB)
  - **时间**：
    - -amin (访问时间access), -cmin (文件属性change), -mmin(文件内容modify)
    - find /etc -cmin -5 (etc目录5min内修改属性的文件)
  - -a (and), -o (or)
  - type -f -d -l (文件属性)
  - -exec 命令 {} \;