#pragma once
#include "otlv4.h"
#include<iostream>
#include <stdio.h>
#include <time.h>
#include <string>
#include <vector>

using namespace std;
#define OTL_ORA11G_R2
#define OTL_ORA_UTF8

const int		MAX_DBCONNSTR_SIZE = 256;//数据库连接字符串的最大长度
struct View1Data
{
	View1Data():case_id(0), final_result(0)
	{
		meterials_abstract.set_len(20000);
		proof.set_len(20000);
		memset(new_content, 0, sizeof(new_content));
	}
	int case_id;
	int final_result;
	otl_long_string meterials_abstract;
	char  new_content[4001];
	otl_long_string proof;
};

class  COtlDbTool
{
public:
	
	~COtlDbTool(void);

	 static COtlDbTool * getInstance()
    {
        if(m_pInstance == NULL)
        {
            m_pInstance = new COtlDbTool();
			m_pInstance->Init("forensicdev/123456@orcl");
        }
        return m_pInstance;
    }
	int Fini();

	int query(int tid);
	int query_count();

	bool GetInited(){return isInited;}

private:
	static COtlDbTool * m_pInstance;
	COtlDbTool(void);
	int Init(const char* strConn);
	otl_connect		m_pDbConnect;//数据库连接对象
	char*			m_strDbConnect[MAX_DBCONNSTR_SIZE];

	bool isInited;
};
