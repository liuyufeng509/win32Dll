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

const int		MAX_DBCONNSTR_SIZE = 256;//���ݿ������ַ�������󳤶�
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
	COtlDbTool(void);
	~COtlDbTool(void);

	int Init(const char* strConn);
	int Fini();

	int query();
	int query_count();

private:


	otl_connect		m_pDbConnect;//���ݿ����Ӷ���
	char*			m_strDbConnect[MAX_DBCONNSTR_SIZE];

};
