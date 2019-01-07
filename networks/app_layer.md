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
- 是否为非持续连接（non-persistent connection）
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
  - HTTP相应报文