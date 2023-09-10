#include "WorkerManager.h"

WorkerManager::WorkerManager()
{
	//文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;

		//初始化属性
		//初始化职工个数
		this->empNum = 0;
		//初始化数组指针
		this->empArray = NULL;
		//初始化文件是否为空的标志
		this->FileIsEmpty = true;

		ifs.close();
		return;
	}

	//2.文件存在， 数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件存在， 数据为空" << endl;

		//初始化属性
		//初始化职工个数
		this->empNum = 0;
		//初始化数组指针
		this->empArray = NULL;
		//初始化文件是否为空
		this->FileIsEmpty = true;

		ifs.close();
		return;
	}

	//统计职工人数
	int num = this->get_empNum();
	cout << "当前职工人数为：" << num << "人" << endl;
	this->empNum = num;

	//开辟内存空间
	this->empArray = new Work * [this->empNum];
	//将文件中的数据存到数组中
	this->init_Emp();
}

//展示菜单
void WorkerManager::show_Menu()
{
	cout << "********************************************" << endl;
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

//退出管理程序
void WorkerManager::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

//增加职工
void WorkerManager::add_Emp()
{
	cout << "请输入要增加的职工人数：" << endl;
	int addNum;
	cin >> addNum;

	if (addNum > 0)
	{
		//开辟新空间
		int newsize = empNum + addNum;
		Work** newSpace = new Work * [newsize];

		//将原来的空间拷贝至新空间
		if (this->empArray != NULL)
		{
			for (int i(0); i < empNum; i++)
			{
				newSpace[i] = this->empArray[i];
			}
		}

		//批量添加新数据
		for (int i(1); i <= addNum; i++)
		{
			int id;
			string name;
			int did;

			cout << "请输入第" << i << "个职工的编号：" << endl;
			cin >> id;

			cout << "请输入第" << i << "个职工的姓名：" << endl;
			cin >> name;

			cout << "请选择第" << i << "个职工的部门编号：" << endl;
			cout << "1.总裁" << endl;
			cout << "2.经理" << endl;
			cout << "3.员工" << endl;
			cin >> did;

			Work* worker = NULL;
			switch (did)
			{
			case 1:
				worker = new Boss(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Employee(id, name, 3);
				break;
			default:
				break;
			}

			newSpace[this->empNum + i -1] = worker;
		}

		//释放原有空间
		delete[] this->empArray;

		//更新数组指针指向
		this->empArray = newSpace;

		//更新职工人数
		this->empNum = newsize;

		//添加成功提示
		cout << "已成功添加" << addNum << "名职工" << endl;	

		//保存文件
		this->save();
	}
	else
	{
		cout << "输入有误" << endl;
	}

	system("pause");
	system("cls");
}

//保存文件
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	
	for (int i(0); i < empNum; i++)
	{
		ofs << empArray[i]->w_id << " "
			<< empArray[i]->w_name << " "
			<< empArray[i]->w_did << endl;
	}

	ofs.close();
}

//统计文件中的人数
int WorkerManager::get_empNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int num(0);
	int id;
	string name;
	int did;

	while (ifs >> id && ifs >> name && ifs >> did)
	{
		num++;
	}

	return num;
}

//初始化员工
void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int index(0);

	int id;
	string name;
	int did;

	while (ifs >> id && ifs >> name && ifs >> did)
	{
		Work* work = NULL;

		switch (did)
		{
		case 1:
			work = new Boss(id, name, did);
			break;
		case 2:
			work = new Manager(id, name, did);
			break;
		case 3:
			work = new Employee(id, name, did);
			break;
		default:
			break;
		}

		this->empArray[index] = work;
		index++;
	}

	ifs.close();
}
