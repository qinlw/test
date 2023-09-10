#include "boss.h"

//构造函数
Boss::Boss(int id, string name, int did)
{
	this->w_id = id;
	this->w_name = name;
	this->w_did = did;
}

//显示个人信息
void Boss::showInfo()
{
	cout << "职工编号：" << w_id
		<< "\t职工姓名：" << w_name
		<< "\t职工部门编号：" << w_did << endl;
}

//获取岗位名称
string Boss::getDepName()
{
	return string("总裁");
}
