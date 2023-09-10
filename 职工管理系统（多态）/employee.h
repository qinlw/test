#pragma
#include"work.h"

class Employee:public Work
{
public:
	//构造函数
	Employee(int id, string name, int did);

	//显示个人信息
	virtual void showInfo();

	//获取岗位名称
	virtual string getDepName();
};