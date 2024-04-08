#ifndef EGELAB_H
#define EGELAB_H

#include "graphics.h"
#include <iostream>
#include <string>
#include <array>

//  ���� Controller �ࡣ����ཫ�����ʼ��ͼ�λ��������ٻ���������ͼ�δ��ڵĳߴ�
class Controller {
private:
	std::string environment;

public:
	Controller() = default;  // Ĭ�Ϲ��캯������ִ���κ��������

	Controller(std::string environment) : environment{ environment } {}  // �������Ĺ��캯������ʼ��shape��Ա����

	virtual ~Controller() = default;  // ������������ȷ�����������������ʱ�ܹ���ȷ�ͷ���Դ

	void Initialize() { setinitmode(0, 500, 50); }  // ���� Initialize �������ú���������ʼ������

	void Destroy() { cleardevice(); }  //  ���� Destroy �������ú����������ͼ������

	void Setlength() { initgraph(640, 480); }  //  ���� Setlength �������ú���������ʼ����ͼ����

	std::string getInfo() { return environment; }  // ��ȡ��״��Ϣ�ĺ���

	void setInfo(std::string environment) { this->environment = environment; }  // ������״��Ϣ�ĺ���
};

// ���� Point ������������ʾһ����Ķ�ά���ꡣ
class Point : public Controller {
private:
	int x;
	int y;

public:
	Point(int x, int y) : x{ x }, y{ y } {}

	Point() : Point(0, 0) {}  // Ĭ�Ϲ��캯���������x��y�����ʼ��Ϊ0

	int getX() { return x; }

	int getY() { return y; }

	void setX(int x) { this->x = x; }

	void setY(int y) { this->y = y; }
};

// ���� Color ������������ʾ��ͼ�λ����п���ʹ�õ���ɫ��
class Color{
private:
	std::string color;

public:
	Color(std::string color) : color{color} {}

	Color() = default;

	// ������ɫΪ��ɫ�ĺ���
	void R() {
		setfillcolor(RED);  // ���������ɫΪ��ɫ
	}

	// ������ɫΪ��ɫ�ĺ���
	void G() { setfillcolor(GREEN); }

	// ������ɫΪ��ɫ�ĺ���
	void B() { setfillcolor(BLUE); }

	std::string getInfo() { return color; }

	void setInfo(std::string  color) { this->color = color; }
};

//  ���� Shape ����
class Shape {
protected:
	std::string shape;
	static int count;

public:
	Shape() = default;

	Shape(std::string shape) : shape(shape) { count++; }

	virtual ~Shape() { count--; }

	virtual void draw() = 0;  // ���麯�������ڻ�����״����Ҫ����������ʵ��

	std::string getInfo() { return shape; }  // ��ȡ��״��Ϣ�ĺ���

	void setInfo(std::string shape) { this->shape = shape; }  // ������״��Ϣ�ĺ���

	void setShape_Color() { setcolor(WHITE); }
};
int Shape::count = 0;

//���� Circle ������������ɻ���Բ�εĲ���
class Circle : public Shape {
private:
	int x;
	int y;
	int radius;

public:
	Color* color = new Color;

	Circle(int x, int y, int radius) : x{ x }, y{ y }, radius{ radius } {}

	Circle() : Circle(0, 0, 0) { count++; }

	Circle(Circle& other) : x(other.x), y(other.y), radius(other.radius) {}

	~Circle() override {
		delete color;
		color = nullptr;
		count--;
		char cot[100];
		sprintf(cot, "%d", count);
		xyprintf(0, 0, cot);
	}

	int getX() { return x; }

	int getY() { return y; }

	int getRadius() { return radius; }

	static int getCount() { return count; }

	//  ���� setCircle ������������ȡ�û������Բ�������Ϣ
	void setCircle() {
		char buf[100];
		inputbox_getline("ikun����", "������Բ��x����", buf, 100);
		this->x = atoi(buf);  //ʹ��atoi()�������ַ���ת��Ϊ���ͱ���
		inputbox_getline("ikun����", "������Բ��y����", buf, 100);
		this->y = atoi(buf);
		inputbox_getline("ikun����", "������뾶", buf, 100);
		this->radius = atoi(buf);
	}

	//  ��д���� Controller �е�draw����
	void draw() override {
		Shape::setShape_Color();  //  ���� setShape_Color ������ʹԲ�������ʰ�ɫ
		circle(x, y, radius);  // ����һ��Բ��Բ��Ϊ(x, y)���뾶Ϊradius
		getch();
	}
};

//  ���� Rectangles ������������ɻ��ƾ��εĲ���
class Rectangles : public Shape {
private:
	int left;
	int top;
	int right;
	int bottom;
	bool filled;

public:
	Color* color = new Color;

	Rectangles(int left, int top, int right, int bottom, bool filled = true) : left{ left }, top{ top }, right{ right }, bottom{ bottom }, filled{ filled } {}

	Rectangles() : Rectangles(0, 0, 0, 0) { count++; }

	Rectangles(Rectangles& other) : left(other.left), top(other.top), right(other.right), bottom(other.bottom), filled(other.filled) {}

	~Rectangles() override {
		delete color;
		color = nullptr;
		count--;
		char cot[100];
		sprintf(cot, "%d", count);
		xyprintf(0, 15, cot);
	}

	int getLeft() { return left; }

	int gettop() { return top; }

	int getRight() { return right; }

	int getBottom() { return bottom; }

	static int getCount() { return count; }

	bool isFilled() const { return filled; } // ��ȡ�Ƿ����Ĳ���ֵ

	void setFilled(bool filled) { this->filled = filled; } // �����Ƿ����Ĳ���ֵ

	//  ���� setRectangle ������������ȡ�û�����ľ��ε������Ϣ
	void setRectangle() {
		char buf[100];
		inputbox_getline("ikun����", "�����������x����", buf, 100);
		this->left = atoi(buf);
		inputbox_getline("ikun����", "����������ϲ�y����", buf, 100);
		this->top = atoi(buf);
		inputbox_getline("ikun����", "����������Ҳ�x����", buf, 100);
		this->right = atoi(buf);
		inputbox_getline("ikun����", "����������²�y����", buf, 100);
		this->bottom = atoi(buf);
	}

	//  ��д���� Controller �е� draw ����
	void draw() override{
		Shape::setShape_Color();
		color->G();  // ���������������ɫΪ��ɫ
		bar(left, top, right, bottom); //������x���꣬ �ϲ�y���꣬ �Ҳ�x���꣬�²�y����
		getch();
	}
};

//���� Triangle ������������ɻ��������εĲ���
class Triangle : public Shape {
private:
	std::array<int, 6> pt;
	bool filled;

public:
	Color* color = new Color;

	Triangle(std::array<int, 6> pt, bool filled = true) : pt(pt) , filled(filled){}

	Triangle() : Triangle(std::array<int, 6>{0, 0, 0, 0, 0, 0}) { count++; }

	Triangle(Triangle& other) : pt(other.pt), filled(other.filled) {}

	~Triangle() override {
		delete color;
		color = nullptr;
		count--;
		char cot[100];
		sprintf(cot, "%d", count);
		xyprintf(0, 30, cot);
	}

	std::array<int, 6> getPt() { return pt; }

	static int getCount() { return count; }

	bool isFilled() const { return filled; }

	void setFilled(bool filled) { this->filled = filled; }

	//  ���� setTriangle ������������ȡ�û�����������ε������Ϣ
	void setTriangle() {
		char buf[100];
		for (int i = 0; i < 6; i += 2) {
			inputbox_getline("ikun����", "���������ε�x���꣺", buf, 100);
			//ʹ�� if ����ж��û��Ƿ�������ȷ
			if (atoi(buf) == 0) {
				xyprintf(0, 0, "��������������������꣡\n");
				i -= 2; // ������벻��ȷ�������˴�ѭ��
				continue;
			}
			this->pt[i] = atoi(buf);
			inputbox_getline("ikun����", "���������ε�y���꣺", buf, 100);
			//ʹ�� if ����ж��û��Ƿ�������ȷ
			if (atoi(buf) == 0) {
				xyprintf(0, 0, "��������������������꣡\n");
				i -= 2; // ������벻��ȷ�������˴�ѭ��
				continue;
			}
			this->pt[i + 1] = atoi(buf);
		}
	}

	//  ��д���� Controller �е� draw ����
	void draw() override{
		Shape::setShape_Color();
		color->B();  // ���������������ɫΪ��ɫ
		int* position;
		position = pt.data();  // �� pt ����� data �������ص�ָ�븳ֵ�� position
		fillpoly(3, position);
		getch();
	}
};

#endif // !EGELAB_H