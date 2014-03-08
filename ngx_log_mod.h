#ifndef __NGX_LOG_MOD_H__
#define __NGX_LOG_MOD_H__
#include <ngx_config.h>
#include <ngx_core.h>
#include <string.h>

typedef enum NLOG_LEVEL{
	NL_NONE=-1,
	NL_ERROR =0,
	NL_WARN,
	NL_INFO,
	NL_DEBUG,
	NL_DEBUG2,
	NL_ALL
}NLOG_LEVEL;

extern NLOG_LEVEL g_NlogLevel;

typedef void (*NLogCb)(const char* log, int size);

extern void NWriteLog(const char* log, int size);
extern void NWriteDebugLog(const char* log, int size);

extern void NPrint(NLogCb LogCb,const char* LEVEL, const char* funcName, 
			const char* fileName, int line,  const char* format,  ...);
extern void NPrintBig(NLogCb LogCb,const char* LEVEL, const char* funcName, 
			const char* fileName, int line,  const char* format,  ...);

extern const char* NGetFileName(const char* fullname);

#define NLFILE NGetFileName(__FILE__)

#define NLOG_DEBUG(format, args...) \
		if(g_NlogLevel>=NL_DEBUG)NPrint(NWriteDebugLog,"DEBUG", __FUNCTION__, NLFILE, __LINE__, format, ##args)
#define NLOG_DEBUG2(format, args...) \
		if(g_NlogLevel>=NL_DEBUG2)NPrint(NWriteDebugLog,"DEBUG2", __FUNCTION__, NLFILE, __LINE__, format, ##args)
#define NLOG_DEBUG2_BIG(format, args...) \
		if(g_NlogLevel>=NL_DEBUG2)NPrintBig(NWriteDebugLog,"DEBUG2", __FUNCTION__, NLFILE, __LINE__, format, ##args)
#define NLOG_INFO(format, args...) \
		if(g_NlogLevel>=NL_INFO)NPrint(NWriteLog," INFO", __FUNCTION__, NLFILE, __LINE__, format, ##args)
#define NLOG_WARN(format, args...) \
		if(g_NlogLevel>=NL_WARN)NPrint(NWriteLog," WARN", __FUNCTION__, NLFILE, __LINE__, format, ##args)
#define NLOG_ERROR(format, args...) \
		if(g_NlogLevel>=NL_ERROR)NPrint(NWriteLog,"ERROR", __FUNCTION__, NLFILE, __LINE__, format, ##args)

#define NLOG(format, args...) NPrint(NWriteLog,"LOG", __FUNCTION__, NLFILE, __LINE__, format, ##args)

extern ngx_open_file_t* g_biz_logger;
extern ngx_open_file_t* g_biz_debuger;

#endif

