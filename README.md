ngx_log_mod nginx 独立日志模块
===================================  
  输出日志到独立的日志文件，由于对nginx日志格式不喜欢，加上nginx日志不带有文件及行号等信息，开发了这个模块。主要用于在开发系统时，业务系统相关的日志独立输出到不同的文件，其中DEBUG日志与ERROR(包含INFO,WARN)是分开存储的。

配置项：
-----------------------------------  
bizlog [on|off];
======
		on 打开日志输出，off关闭日志输出，默认为off.

log_level [0|1|2|3|4|5]
log_level [error|warn|info|debug|debug2|all]
======
		0: error 输出错误级别的日志，使用NLOG_ERRROR 输出。
		1: warn  输出警告级别(包含错误日志)的日志，使用NLOG_WARN输出。
		2: info  输出提示级别(包含警告日志)的日志，使用NLOG_INFO输出。
		3: debug 输出调试级别(包含提示日志)的日志，使用NLOG_DEBUG输出。
		4: debug2 调试2级别的日志，使用NLOG_DEBUG2输出。
		5: all  输出所有以上的所有日志。

logfile 日志文件名。
======
		所有error,warn,info级别的日志都输出在该文件中。

debugfile 调试日志文件名。
======
		所有debug,debug2级别的日志都输出在该文件中。

	