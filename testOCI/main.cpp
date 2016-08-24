#include<iostream>
#include <stdio.h>
#include <time.h>
using namespace std;
#include "OtlDbTool.h"

int main()
{
	char * strConn = "forensicdev/123456@orcl";
	COtlDbTool dbtool;
	if(dbtool.Init(strConn)==0)
	{
		cout<<"Inited success"<<endl;
	}else
		cout<<"Inited Failed"<<endl;

	

	//dbtool.query();
	dbtool.query_count();
	dbtool.Fini();
	COtlDbTool dbtool2;
	if(dbtool2.Init(strConn)==0)
	{
		cout<<"Inited success"<<endl;
	}else
		cout<<"Inited Failed"<<endl;
	dbtool2.query_count();
	dbtool2.Fini();
	return 0;

}