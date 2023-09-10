#pragma once
#include<iostream>
#include<string>
using namespace std;

class Work
{
public:
	//显示个人信息
	virtual void showInfo() = 0;

	//获取岗位名称
	virtual string getDepName() = 0;

	int w_id;
	string w_name;
	int w_did;
};