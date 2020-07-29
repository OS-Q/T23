# [Ymodem升级终端](https://github.com/OS-Q/W41)

[![sites](http://182.61.61.133/link/resources/OSQ.png)](http://www.OS-Q.com)

* Q[4] - M[12] - W[52] - D[365] - H[24] - N[60] - S[60]

### [workspace描述](https://github.com/OS-Q/W41/wiki)

[Ymodem升级终端](https://github.com/OS-Q/W41) 用于支持设备通过串口和Ymodem协议进行IAP升级


Ymodem是Xmodem的改进版协议，具有传输快速稳定的优点。它可以一次传输1024字节的信息块，同时还支持传输多个文件。

平常所说的Ymodem协议是指的Ymodem-1K，除此还有Ymodem-g（没有CRC校验，不常用）。

YModem-1K用1024字节信息块传输取代标准的128字节传输，数据的发送回使用CRC校验，保证数据传输的正确性。它每传输一个信息块数据时，就会等待接收端回应ACK信号，接收到回应后，才会继续传输下一个信息块，保证数据已经全部接收。

### [收录资源](https://github.com/OS-Q/)

* [文档](docs/)
* [工程](project/)
* [工具](software/)

### [OS-Q = Open Solutions | Open Source | Operating System ](http://www.OS-Q.com/W41)
