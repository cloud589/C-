#include "egeLab.h"

//  设置 Drawpicture 函数，用来完成绘图功能
void Drawpicture(Circle* circle, Rectangles* rectangle, Triangle* triangle) {
	char buf[100];
	inputbox_getline("ikun画板", "欢迎您进入ikun画板，请根据菜单选择您想进行的操作：\n1.画圆\n2.画矩形\n3.画三角形", buf, 100); //弹出一个输入框，提示用户进行操作选择
	int choice = atoi(buf);  // 用整型变量 choice 来存储用户的选择

	//  完成用户选择的操作
	if (choice == 1) {
		circle->setCircle();
		circle->draw();
	}

	else if (choice == 2) {
		rectangle->setRectangle();
		rectangle->draw();
	}

	else if (choice == 3) {
		triangle->setTriangle();
		triangle->draw();
	}

	//  输入错误会提醒
	else {
		setcolor(RED);
		xyprintf(0, 0, "Error input!");
	}
}

//设置 Setgetline 函数。这个函数用来完成绘图板的基础功能
void Setgetline(Controller* environment) {
	char buf[100];
	inputbox_getline("ikun画板", "欢迎您进入ikun画板，请根据菜单选择您想进行的操作：\n1.清除屏幕\n2.作画\n3.退出", buf, 100); //弹出一个输入框，提示用户进行操作选择
	int choice = atoi(buf);
	Circle* circle = new Circle;
	Rectangles* rectangle = new Rectangles;
	Triangle* triangle = new Triangle;

	// 完成用户选择的操作
	if (choice == 1) {
		environment->Destroy();
		delete circle;
		delete rectangle;
		delete triangle;
		circle = nullptr;
		rectangle = nullptr;
		triangle = nullptr;
	}
	else if (choice == 2) { Drawpicture(circle, rectangle, triangle); }
	else if (choice == 3) { exit(0); }
	// 输入错误会提醒
	else {
		setcolor(RED);
		xyprintf(0, 0, "Error input!");
	}
}

int main() {
	Controller environment;
	//  初始化画板
	environment.Initialize();
	environment.Setlength();
	//  实现画板功能
	while (1) {
		Setgetline(&environment);
	}
	closegraph();
	return 0;
}