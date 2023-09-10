#pragma
#include"work.h"

class Manager:public Work
{
public:
	//构造函数
	Manager(int id, string name, int did);

	//展示个人信息
	virtual void showInfo();

	//获取岗位名称
	virtual string getDepName();
};