#include "egeLab.h"

//  ���� Drawpicture ������������ɻ�ͼ����
void Drawpicture(Circle* circle, Rectangles* rectangle, Triangle* triangle) {
	char buf[100];
	inputbox_getline("ikun����", "��ӭ������ikun���壬����ݲ˵�ѡ��������еĲ�����\n1.��Բ\n2.������\n3.��������", buf, 100); //����һ���������ʾ�û����в���ѡ��
	int choice = atoi(buf);  // �����ͱ��� choice ���洢�û���ѡ��

	//  ����û�ѡ��Ĳ���
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

	//  ������������
	else {
		setcolor(RED);
		xyprintf(0, 0, "Error input!");
	}
}

//���� Setgetline �������������������ɻ�ͼ��Ļ�������
void Setgetline(Controller* environment) {
	char buf[100];
	inputbox_getline("ikun����", "��ӭ������ikun���壬����ݲ˵�ѡ��������еĲ�����\n1.�����Ļ\n2.����\n3.�˳�", buf, 100); //����һ���������ʾ�û����в���ѡ��
	int choice = atoi(buf);
	Circle* circle = new Circle;
	Rectangles* rectangle = new Rectangles;
	Triangle* triangle = new Triangle;

	// ����û�ѡ��Ĳ���
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
	// ������������
	else {
		setcolor(RED);
		xyprintf(0, 0, "Error input!");
	}
}

int main() {
	Controller environment;
	//  ��ʼ������
	environment.Initialize();
	environment.Setlength();
	//  ʵ�ֻ��幦��
	while (1) {
		Setgetline(&environment);
	}
	closegraph();
	return 0;
}