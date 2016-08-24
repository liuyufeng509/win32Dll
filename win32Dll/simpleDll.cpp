//hello.cpp  
#define EXPORT_HELLO_DLL  
#include "simpleDll.h"  
#include <iostream>
#include <windows.h>
#include <tlhelp32.h>
using namespace std;
#include "OtlDbTool.h"
HELLO_API int IntAdd(int a, int b)  
{  
	cout<<"IntAdd pid="<<GetCurrentProcessId()<<" threadID="<<GetCurrentThreadId()<<endl;
	cout<<"Add addr:"<<COtlDbTool::getInstance()<<endl;
	COtlDbTool::getInstance()->query_count();
	//Sleep(1000);
	/*char * strConn = "forensicdev/123456@orcl";
	if(!dbtool.GetInited())
	{
		if(dbtool.Init(strConn)==0)
		{
			cout<<"Inited success"<<endl;
		}else
			cout<<"Inited Failed"<<endl;
	}else
		cout<<"already inited"<<endl;
	*/
	//dbtool.query();
	//dbtool.query_count();
	//dbtool.Fini();
    return a+b; 
}  

HELLO_API int IntDel(int a , int b)
{
	cout<<"IntDel pid="<<GetCurrentProcessId()<<" threadID="<<GetCurrentThreadId()<<endl;
	cout<<"Del addr:"<<COtlDbTool::getInstance()<<endl;
	COtlDbTool::getInstance()->query(GetCurrentThreadId());
	//Sleep(1000);
	/*char * strConn = "forensicdev/123456@orcl";
	if(!dbtool.GetInited())
	{
		if(dbtool.Init(strConn)==0)
		{
			cout<<"Inited success"<<endl;
		}else
			cout<<"Inited Failed"<<endl;
	}else
		cout<<"already inited"<<endl;
	*/
	//dbtool.query();
	//dbtool.query_count();
	//dbtool.Fini();
    return a+b; 
}