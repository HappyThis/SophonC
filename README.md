# Sophon for windows
---
Sophon由Sdut507实验室开发小组开发，此版本仅为我个人对本项目做出的贡献(移除了队友的所做的功能)。
---
#### 简介
Sophon是基于C/S架构、采用Qt(c++)开发的远程控制系统，具有文件传输与查看、远程命令行、远程屏幕以及录像、远程抓包、远程任务管理器等功能
---
#### 特点
+ 采用IOCP实现高性能网络
+ 通过把wincap作为子进程的方式实现远程抓包
+ 实现了一个环形队列以缓冲上线主机发送的数据
+ 简单地实现了一个应用层协议以进行数据传输 采用Git做版本控制
+ 每一个功能都由GUI线程构造，构造时就把上线信息与实例通过信号槽的方式绑定(线程安全)，且都是一个可以通信的实例，当有信息发来时，IOCP会以信号的方式发送Server传输的信息给对应功能实例。
---
#### 编译&运行
因为本项目在windows平台开发，所以建议用vs直接打开工程文件。
+ Server端需要安装winpcap[https://www.winpcap.org/]
+ S/C端需要Qt的支持，两者都需要Qt的核心模块，GUI模块，其中Client还需要图表模块
+ S/C端与Qt编译器都需要编译为x86而不是64
---
#### 运行截图如下
![打开界面](https://github.com/HappyThis/SophonC/blob/master/screenshot/%E5%90%AF%E5%8A%A8.png)
![启动网络](https://github.com/HappyThis/SophonC/blob/master/screenshot/%E4%B8%8A%E7%BA%BF.png)
![上线](https://github.com/HappyThis/SophonC/blob/master/screenshot/%E4%B8%8A%E7%BA%BF.png)
![详细信息](https://github.com/HappyThis/SophonC/blob/master/screenshot/%E8%AF%A6%E7%BB%86%E4%BF%A1%E6%81%AF.png)
![文件浏览](https://github.com/HappyThis/SophonC/blob/master/screenshot/%E5%8F%AF%E4%BB%A5%E9%80%89%E6%8B%A9%E4%B8%8A%E7%BA%BF%E4%B8%BB%E6%9C%BA%E6%96%87%E4%BB%B6%E6%8E%A5%E6%94%B6%E5%9C%B0%E5%9D%80.png)
![协议占比](https://github.com/HappyThis/SophonC/blob/master/screenshot/%E5%8D%8F%E8%AE%AE%E5%8D%A0%E6%AF%94.png)
![网络IO](https://github.com/HappyThis/SophonC/blob/master/screenshot/IO%E5%88%86%E5%B8%83.png)
![协议统计](https://github.com/HappyThis/SophonC/blob/master/screenshot/%E7%BD%91%E7%BB%9C%E5%8D%8F%E8%AE%AE%E5%88%86%E6%9E%90.png)
![远程抓包](https://github.com/HappyThis/SophonC/blob/master/screenshot/%E8%BF%9C%E7%A8%8B%E6%8A%93%E5%8C%85.png)
![主流格式保存网络包](https://github.com/HappyThis/SophonC/blob/master/screenshot/%E5%8F%AF%E4%BB%A5%E5%B0%86%E6%8A%93%E6%8D%95%E7%9A%84%E6%95%B0%E6%8D%AE%E5%8C%85%E4%BF%9D%E5%AD%98%E4%B8%BA%E4%B8%BB%E6%B5%81%E6%A0%BC%E5%BC%8F.png)
![双击上线主机以进行文件输出](https://github.com/HappyThis/SophonC/blob/master/screenshot/%E5%8F%8C%E5%87%BB%E4%B8%8A%E7%BA%BF%E4%B8%BB%E6%9C%BA%E5%8A%A0%E5%85%A5%E6%96%87%E4%BB%B6%E4%BC%A0%E9%80%81%E9%98%9F%E5%88%97.png)
![加入文件发送队列](https://github.com/HappyThis/SophonC/blob/master/screenshot/%E5%B0%86%E6%96%87%E4%BB%B6%E5%8A%A0%E5%85%A5%E5%8F%91%E9%80%81%E9%98%9F%E5%88%97%E4%B9%8B%E5%90%8E%E5%8F%AF%E4%BB%A5%E5%8F%91%E9%80%81.png)
![发送成功](https://github.com/HappyThis/SophonC/blob/master/screenshot/%E5%8F%91%E9%80%81%E6%88%90%E5%8A%9F.png)
![远程命令行](https://github.com/HappyThis/SophonC/blob/master/screenshot/%E8%BF%9C%E7%A8%8B%E5%91%BD%E4%BB%A4%E8%A1%8C.png)
