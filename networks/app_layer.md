## 应用层
### 概述
进行通信的单位为进程（process），通过socket收发消息，更安全的方法：SSL  
- 选择传输层协议，考虑的方面：  
    - 可靠数据传输    是否丢失容忍
    - 吞吐量   是否带宽敏感
    - 定时    对实时性的要求
    - 安全性  

重要的网络应用：    Web，文件传输 FTP，电子邮件 Email，目录服务，P2P  
互联网提供的运输服务
- TCP服务
  - 面向连接
  - 可靠的数据传送
- UDP服务
  - 通信前不进行握手
  - 无拥塞控制

### Web和HTTP
- 一种无状态协议，不记录用户状态信息；
- 可按 是否为非持续连接（non-persistent connection） 区分
- HTTP报文格式
  - HTTP请求报文
    - 请求行 request line 第一行 `GET /somedir/page.html HTTP/1.1`
      - *方法* 字段： GET, POST, HEAD, PUT, DELETE
      - *URL* 字段： 请求对象
      - HTTP版本 字段
    - 首部行 header line 后继于请求行的内容
      - Host: 
      - Connection: close   //表示非持续连接
      - User-agent: Mozilla/5.0
      - Accept-language: fr        //表示希望接收法语版本
    - 空行
    - 实体体 （entity body）
  - HTTP响应报文
    - 初始**状态行** status line 
      - 协议版本字段
      - 状态码 
        - 200    OK: 请求成功
        - 301    Moved permanently
        - 400    Bad request
        - 404    Not found
      - 状态信息
    - 首部行
    - 空行
    - 实体体

- cookie
  - 用于在无状态的HTTP之上建立web站点识别用户的功能

- web缓存 / 代理
  - 既是服务器又是客户
  - 通过使用cdn发挥更大作用

- 条件GET方法
  - 保证对象的新鲜度，由代理缓存器维护
  - 使用GET方法，并在首部行中包含`If-Modified-Since: `信息，由于报文中记录有修改时间，因此可以比较
  - 服务器返回`304 Not Modified` 信息，表明未修改

### FTP
- 两个并行的tcp连接： 控制连接和数据连接， 带外(out-of-band)传送
  - 控制连接贯穿会话始终，每传输一个文件打开一个数据连接
  - 需要记录用户在服务器的访问状态
- FTP的命令和回答
  - 以7bit ASCII格式在控制连接传输，常见命令：
    - USER username;
    - PASS password;
    - LIST;
    - RETR filename;
    - STOR filename;
  - 回答：
    - 331 Username OK, Password required
    - 125 Data connection already open; transfer starting
    - 425 Can't open data connection
    - 452 Error writing file

### 电子邮件
- 概况
  - 用户代理， 邮件服务器， 简单邮件传输协议SMTP
  - 用户发送后进入发送方邮件服务器的报文队列当中，若多次尝试仍不能转交给接收方服务器，则告知发送方
- SMTP
  - 使用TCP协议
  - 客户SMTP（运行在发件服务器） 在25号端口建立一个到服务器SMTP（收件服务器）的TCP连接
    - 持续连接，多个报文可用同一个TCP连接发送
- 与HTTP的对比
  - 传输对象不同，一个是Web服务器向Web用户传输，另一个是服务器之间的传输，但二者都使用持续连接
  - HTTP是一个拉协议PULL protocol，而SMTP是一个推协议PUSH protocol
  - SMTP要求所有报文内容使用7bit ASCⅡ编码
  - SMTP将所有报文对象放入一个报文之中，而HTTP则将每个对象单独封装
- 邮件报文格式
  - 典型的报文首部：
    ```
    From: alice@crepes.fr
    To: bob@hamburger.edu
    Subject: Searching for the meaning of life.

    ```
- 邮件访问协议，POP3，IMAP与HTTP
  - POP3: 特许（authorization），事务处理，更新
    - authorization：`user <username>` 和 `pass <password>`，
    - 事物处理： 下载并 删除or保留
      - 下载并删除：list, retr, dele操作
    - 更新：根据用户标记进行删除
    - 会话中不传递状态信息，仅在服务器端记录状态信息
  - IMAP: 可以更好地管理邮件内容，指定在远端存放的文件夹等

### DNS
- DNS提供的服务
  - 主机名到IP地址的转换
  - 主机别名的绑定
  - 邮件服务器别名
  - 负载分配(均衡)
- 工作原理
  - 输入值机名, 调用DNS客户端, 如函数`gethostbyname()`, DNS的请求与应答通过UDP数据报经端口53发送
  - DNS服务器是分布式的, 主要分为根DNS服务器, 顶级域TLD DNS服务器(顶级域名如com, org等的管理)和权威DNS服务器; 还有本地服务器,由ISP维护; 查询IP时是迭代查找的, 由本地DNS服务器向根服务器查询并逐层迭代请求
  - 为减少请求次数, 采用DNS缓存
- DNS记录与报文