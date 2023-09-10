#include "employee.h"

//构造函数
Employee::Employee(int id, string name, int did)
{
	this->w_id = id;
	this->w_name = name;
	this->w_did = did;
}

//显示个人信息
void Employee::showInfo()
{
	cout << "职工编号：" << w_id
		<< "\t职工姓名：" << w_name
		<< "\t职工部门编号：" << w_did << endl;
}

//获取岗位名称
string Employee::getDepName()
{
	return string("员工");
}
