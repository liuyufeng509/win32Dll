#include "OtlDbTool.h"


COtlDbTool::COtlDbTool(void)
{
	memset(m_strDbConnect,0,MAX_DBCONNSTR_SIZE);
}


COtlDbTool::~COtlDbTool(void)
{
}

int COtlDbTool::Init(const char* strConn)
{
	int nRes = 0;

	if(strConn!=NULL && strlen(strConn)>0)
	{
		strncpy_s((char*)m_strDbConnect,MAX_DBCONNSTR_SIZE,strConn,strlen(strConn));
	}
	else
	{
		nRes = -1;
		return nRes;
	}

	otl_connect::otl_initialize(); // initialize OCI environment

	try
	{
		m_pDbConnect.rlogon((const char*)m_strDbConnect);
		cout<<"connected"<<endl;
	}
	catch(otl_exception& p)
	{
        cerr<<p.msg<<endl; // print out error message
        cerr<<p.stm_text<<endl; // print out SQL that caused the error
        cerr<<p.var_info<<endl; // print out the variable that caused

		nRes = -1;
	}

	return nRes;
}

int COtlDbTool::Fini()
{
	int nRes = 0;

	m_pDbConnect.logoff();
	otl_connect::otl_terminate();
	cout<<"Fini"<<endl;
	return nRes;
}

int COtlDbTool::query()
{
	int nRes = 0;
	vector<View1Data> datas;

	try
	{
		otl_stream i ( 1 , // buffer size
                  "select * from model_view1", // SELECT statement
                  m_pDbConnect // connect object
		);
		View1Data data;
		cout<<"start to read"<<endl;
		int k=0;
	  while ( !i.eof() )
	  {//循环取出每一行
		  i>>data.case_id;
		  i>>data.final_result;
		 /* otl_lob_stream lob1;
		  i>>lob1;
		  int n=0;
		  while(!lob1.eof()){
			  ++n;
			  lob1>>data.meterials_abstract;
		  }
		  lob1.close();
		  */
		  i>>data.new_content;
		  
		 /* i>>lob1;
		  n=0;
		   while(!lob1.eof()){
			  ++n;
			  lob1>>data.proof;
		  }
		  lob1.close();*/
		  datas.push_back(data);
		  k++;
		  cout<<"read the "<<k<<" recorde"<<endl;
	  }
	}catch(otl_exception& p)
	{
		cerr<<p.msg<<endl; // print out error message
		cerr<<p.stm_text<<endl; // print out SQL that caused the error
		cerr<<p.var_info<<endl; // print out the variable that caused

		nRes = -1;
	}

	cout<<"遍历结果"<<endl;

	for(int j=0; j<datas.size(); j++)
	{
		cout<<"**********************************"<<endl;
		cout<<"case_id:"<<datas[j].case_id<<endl;
		cout<<"final_result:"<<datas[j].final_result<<endl;
		//cout<<"meterials_abstract:"/*<<datas[j].meterials_abstract[0]<<datas[j].meterials_abstract[datas[j].meterials_abstract.len()-1]<<", len="*/<<datas[j].meterials_abstract.len()<<endl;
		cout<<"new_content:"<<datas[j].new_content<<endl;
		//cout<<"proof:"<<datas[j].proof.len()<<endl;
	}

	return nRes;
	
}


int COtlDbTool::query_count()
{
	int nRes = 0;
	vector<View1Data> datas;
	int count = 0;
	try
	{
		otl_stream i ( 1 , // buffer size
                  "select count(*) from model_view", // SELECT statement
                  m_pDbConnect // connect object
		);
		View1Data data;
		cout<<"start to read"<<endl;
		int k=0;
	  while ( !i.eof() )
	  {//循环取出每一行
		  i>>count;
	  }
	}catch(otl_exception& p)
	{
		cerr<<p.msg<<endl; // print out error message
		cerr<<p.stm_text<<endl; // print out SQL that caused the error
		cerr<<p.var_info<<endl; // print out the variable that caused

		nRes = -1;
	}

	cout<<"count="<<count<<endl;

	return nRes;
	
}
