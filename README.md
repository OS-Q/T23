# [Ymodem](https://github.com/OS-Q/T23)

[![sites](http://182.61.61.133/link/resources/OSQ.png)](http://www.OS-Q.com)

[Ymodem](https://github.com/OS-Q/T23)是[Xmodem](https://github.com/OS-Q/T24)的改进版协议，具有传输快速稳定的优点。它可以一次传输1024字节的信息块，同时还支持传输多个文件。平常所说的Ymodem协议是指的Ymodem-1K，除此还有Ymodem-g（没有CRC校验，不常用）。

YModem-1K用1024字节信息块传输取代标准的128字节传输，数据的发送回使用CRC校验，保证数据传输的正确性。它每传输一个信息块数据时，就会等待接收端回应ACK信号，接收到回应后，才会继续传输下一个信息块，保证数据已经全部接收。Ymodem用于
