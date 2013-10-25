##LINUX目錄配置

>*[Filesystem Hierarchy Standard(FHS)](http://www.pathname.com/fhs)*  
/:root  
/usr:UNIX Software resource  
/var:variable 與系統運作過程相關  

###/(root根目錄)
/bin:放置可執行文件的目錄。放置在單用戶維護模式下依舊能夠使用的命令。  
/boot:放置開機會使用到的文件（包括linux內核文件以及開機菜單與開機所需的配置文件等）。Linux Kernel常用的文件名為vmlinuz。  
/dev:任何設備（接口設備等）都會以文件的形式存儲在該目錄中。  
/etc:系統主要的配置文件（如用戶帳號的密碼文件、各種服務的起始文件等），一般用戶可以查閱，但是只有root用戶可以修改。*不能將可執行文件放置在該目錄中*。
>*幾個重要的文件*  
/etc/init.d:所有服務的默認啟動腳本放置目錄。  
/etc/xinetd.d:super deamon管理的各項服務的配置文件目錄。  
/etc/X11:與X Window 相關的各種配置文件。  
  
/home:系統默認的用戶主文件夾。    
/lib:放置在開機時會遇到的函數庫，以及在/bin和/sbin目錄下命令需調用的函數庫。  
/media:放置可刪除的設備文件。  
/mnt:暫時掛載外接設備。  
/opt:第三方軟件的安裝目錄。  
/root:系統管理員的主文件夾。  
/sbin:放置開機過程中所需要的命令，如開機、修復、還原系統等操作所需要的命令。  
/srv:服務啟動後，存儲的該服務所需的數據目錄。如WWW、FTP等服務。  
/tmp:一般用戶或者是正在執行的程序臨時放置文件的目錄。  
/lost+found:使用標準ext2/ext3文件系統才會產生的目錄，目的在於當文件系統發生錯誤時，會將丟失的片段存儲在這個目錄中。  
/proc:一個虛擬文件系統(Virtual Filesystem)。放置的數據都是在內存當中（如系統內核、進程PROCESS、外部設備的狀態以及網絡狀態等）。  
/sys:與/proc類似。主要記錄與內核相關的信息。  

###/usr(UNIX Software Resource)
/usr/X11R6:為X Window系統重要數據放置的目錄。  
/usr/bin:絕大部分的用戶可以使用的命令。  
/usr/include:C/C++等程序語言的頭文件(header)和包含文件(include)的放置處。  
/usr/lib:各種應用軟件的函數庫、目標文件(OBJECT FILE)以及不被一般用戶慣用的執行文件或腳本。  
/usr/local:系統管理員在本機自行安裝自己下載的軟件所放置的目錄。  
/usr/sbin:非系統正常運行所需要的系統命令（如某些網路服務器軟件的服務，命令）。  
/usr/share:放置共享文件的目錄。   
>/usr/share/man:在線幫助文件  
/usr/share/doc:軟件雜項的文件說明  
/usr/share/zoneinfo:與時區相關的時區文件  

/usr/src:一般源碼的放置位置。內核源碼放置位置：/usr/src/linux。  

###/var
>主要針對常態性變動的文件，包括緩存(CACHE)、登錄文件(LOG FILE)以及某些軟件運行時產生的文件，包括程序文件(LOCK FILE,RUN FILE)，或者如MYSQL數據庫文件等。 

/var/cache:應用程序執行過程中產生的緩存文件。  
/var/lib:程序本身執行過程中，需要使用到的數據文件放置的目錄（如MYSQL的數據庫/var/lib/mysql、rpm數據庫/var/lib/rpm等）。  
/var/lock:某些設備或文件資源一次只能被一個應用程序所使用，如果多個程序同時使用就會出現一些意外錯誤，為了防止錯誤的出現，則要求對該設備（或資源文件）進行上鎖(LOCK)，以確保設備（資源文件）只能夠被一個應用軟件所使用。    
/var/log:登錄文件放置的目錄。  
/var/mail:放置個人電子郵箱的目錄。  
/var/run:某些程序或者服務啟動後，會將其PID 放置在此目錄中。  
/var/spool:放置一些隊列數據。  


12时50分22秒 2013年10月21日 Edit BY [Ivan Lyon](i@iliyang.cn)


























