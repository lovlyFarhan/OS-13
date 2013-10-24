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

    [solome@app ~]$ bzip2 [-cdkzv#] filename
    [solome@app ~]$ bzcat filename.bz2
    PARAMS:
        -c  :  同gzip
        -d  :  -
        -k  :  保留原文件（不會刪除原始文件）
        -z  :  -
        -v  :  -
        -[1,9]  :  -
    [solome@app ~]$ bzip2 -zk filename
    [solome@app ~]$ bzcat filename.bz2
    [solome@app ~]$ bzip2 -d filename.bz2

####打包命令
>*tar*:將多個目錄或文件打包成一個大文件。  
    
    [solome@app ~]$ tar -jcv -f filename.tar.bz2 ./file1 ./file2 ... #壓縮
    [solome@app ~]$ tar -jtv -f ./filename.tar.bz2                   #查詢
    [solome@app ~]$ tar -jxv -f ./filename.tar.bz2 -C directory_name #解壓
    PARAMS:
        -c  :  新建打包文件
        -t  :  查看打包文件中的文件信息
        -x  :  解包（解壓）功能
        -j  :  通過bzip2進行壓縮、解壓操作
        -z  :  通過gzip進行壓縮、解壓操作
        -v  :  壓縮、解壓過程中顯示文件的處理狀態
        -f  :  -f filename 被處理的打包文件名
        -C  :  -C directory_name 在特定目錄進行解壓縮操作
    

