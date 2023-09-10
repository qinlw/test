#include"WorkerManager.h"

int main()
{
	WorkerManager wm;

	int choice;

	while (true)
	{
		wm.show_Menu(); //展示菜单
		
		cin >> choice;
		switch (choice)
		{
		case 0:		//退出管理程序
			wm.exitSystem();
			break;
		case 1:		//增加职工信息
			wm.add_Emp();
			break;
		case 2:		//显示职工信息
			break;
		case 3:		//删除离职职工
			break;
		case 4:		//修改职工信息
			break;
		case 5:		//查找职工信息
			break;
		case 6:		//按照编号排序
			break;
		case 7:		//清空所有文档
			break;
		default:
			system("cls");
			break;
		}
	}

	return 0;
}

//github到此一游
