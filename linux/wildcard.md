#unix like系統通配符於特殊符號
##常用的通配符
>*代表0到無窮多個任意字符。  
?代表一定有一個任意字符。  
[]代表一定有一個在[]字符集中的字符。  
[-]字符集是編碼順序，在這連續編碼字符集中一定存在一個字符。  
[^]除字符集中的之外的任意一個字符。  

##bash環境中的一些特殊符號
>#註釋符號，其後內容不會被解釋。  
\轉義符號，將“特殊符號或者通配符”還原成一般字符。  
|管道命令的分隔符。  
;連續命令執行的分隔符。  
~主目錄。  
$變量前導符。  
&放在命令之後，使命令在後台執行。  
!邏輯意義上的“非”。  
/目錄分隔號。  
>,>>數據流重定向之輸出導向。  
<,<<數據流重定向之輸入導向。  
''單引號，裡面的內容以純字符串對待。  
""雙引號，具備變量置換等功能。  
``裡面的內容均以命令處理。  
()在中間為子shell的起始於結束。  
{}在中間為命令塊的組合。  
