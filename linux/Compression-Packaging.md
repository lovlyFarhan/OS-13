###壓縮與打包

####常見的壓縮文件擴展名:
    *.Z
    *.gz
    *.bz2
    *.tar
    *.tar.gz
    *.tar.bz2

####壓縮命令：
*compress*:一款古老的壓縮命令，在centOS6.4中可以`man compress`查看命令的說明文檔，但是系統中並未提供該命令。（不常用，不做備份）。  
*gzip/zcat*:
    [solome@app ~]$ gzip [-cdtv#] filename
    [solome@app ~]$ zcat filename.gz       #讀取壓縮文件中的內容
    PARAMS:
    -c  :  將壓縮的數據輸出到屏幕（通過數據流重定向處理）
    -d  :  解壓被壓縮的文件
    -t  :  檢驗壓縮文件的一致性，查看文件有無錯誤
    -v  :  顯示原文件/壓縮後文件壓縮比等信息
    -[1,9]  :  壓縮等級，一般默認為6
    EXAMPLE:
    [solome@app ~]$ gzip -v filename
	[solome@app ~]$ zcat filename.gz
	[solome@app ~]$ gzip -d filename.gz

*bzip2/bzcat*:

####打包命令
>tar

