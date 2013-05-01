#linux文件权限与目录配置

##用户与用户组
>/etc/passwd帐户相关

>/etc/shadow帐户密码

>/etc/group Linux的所有组名

##Linux文件属性
>文件权限|连接数|文件所有者|文件所属用户组|文件大小|文件最后被修改时间|文件名

##如何修改文件属性
>chmod|chown|chgrp

>r:4|w:2|x:1 读、写、执行

>注意：一个文件能否被删除，并不是由其本身的权限属性决定，而是由其所在目录的权限决定。

##文件的种类
>普通文件(纯文本文件|二进制文件|数据格式文件)、目录、链接文件、设备文件、套接字、管道。

>使用Ext2/Ext3文件系统时，针对文件的文件名长度限制为：

>单一文件（包括目录文件）的最大容许文件名为255个字符；包含完整路径的完整文件名最大长度字符为4096。

##Linux的文件目录配置
>###Filesystem Hierarchy Standard(FHS)
>/ (root,根目录)：与开机系统相关。整个系统最重要的目录。（不建议放在非常大的分区内）。根目录（/）所在分区越小越好，且应用程序所安装的软件最好不要与根目录放在同一个分区内。

>/usr/ (Unix software resource):软件资源放置的目录。

>bin :放置执行文件。在单用户维护模式下还能够被操作的命令。cat\chmod\chown\date\mv\mkdir\cp\bash等。

>/boot :放置开机相关的文件。如vmlinuz、/boot/grub等。

>/etc :配置文件。比较重要的有：/etc/inittab、/etc/init.d、/etc/modprobe.conf、/etc/X11、/etc/fstab、/etc/sysconfig、/etc/xined.d等。

>/home :用户主文件夹（Home Directory）。

>/lib :放置开机时以及在/bin和/sbin目录下的命令会调用的函数库。

>/media :放置可删除的设备。

>/mnt :暂时挂载某些额外的设备。

>/opt ：放置第三方软件的目录。

>/root :系统管理员的主文件夹。

>/sbin :放置设置系统环境命令的目录。如：fdisk、fsck、ifconfig、init、mkfs等。

>/srv (service):网路服务所需要取用的数据目录。如WWW服务需要的网页数据存放在/srv/www/目录下。

>/tmp :一般用户或者正在执行的程序暂时放置文件的地方。（任何人都能够访问）。



