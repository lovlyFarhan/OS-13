##linux關機的方法


###注意事件
>###查看系統使用狀態
用戶在線：who  
網絡聯機狀態：netstat -a  
後台執行的程序：ps -aux  
將數據同步寫入硬盤：sync  
關機命令：shutdown  
重啟、關機：reboot,halt,poweroff  

###linux的執行等級(run level)：init
run level 0:關機  
run level 1:單用戶形式，只root登錄進行維護  
run level 2:多用戶形式，不能使用Net File System(NFS)  
run level 3:純命令行模式  
run level 4:（沒有確定用途） 
run level 5:含有圖形界面模式  
run level 6:重啟  





