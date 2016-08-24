//hello.h  
#ifdef EXPORT_HELLO_DLL  
#define HELLO_API __declspec(dllexport)  
#else  
#define HELLO_API __declspec(dllimport)  
#endif  
#include <string>
extern "C"  
{  
    HELLO_API int IntAdd(int a , int b);  
	HELLO_API int IntDel(int a , int b); 
}  

