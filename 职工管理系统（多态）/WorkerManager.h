#pragma once
#include"boss.h"
#include"manager.h"
#include"employee.h"
#include<fstream>

#define FILENAME "empfile.txt"

class WorkerManager
{
public:
	//构造函数
	WorkerManager();

	//展示菜单
	void show_Menu();

	//退出管理程序
	void exitSystem();

	//记录职工人数
	int empNum;

	//职工数组指针
	Work** empArray;

	//增加职工
	void add_Emp();

	//保存文件
	void save();

	//统计文件中的人数
	int get_empNum();

	//判断文件是否为空的标志
	bool FileIsEmpty;

	//初始化员工
	void init_Emp();
};
