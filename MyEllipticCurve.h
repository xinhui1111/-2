#pragma once
#include"Integer.h"
#include<iostream>
class MyEllipticCurve
{
private:
	Integer fp;
	Integer a;
	Integer b;
public:
	MyEllipticCurve() {
		fp = NULL;
		a = NULL;
		b = NULL;
	}
	 MyEllipticCurve(Integer fp, Integer a, Integer b) {
		 try
		 {
			 if (fp == NULL || a == NULL || b == NULL) {
				 throw"��������Ϊ��";
			 }
			 this->fp = fp;
			 this->a = a;
			 this->b = b;
		 }
		 catch (...)
		 {
			 std::cout << "��������Ϊ��";
		 }
	}
	~MyEllipticCurve() {};

	 Integer getFp() {
		return fp;
	}

	 Integer getA() {
		return a;
	}

	 Integer getB() {
		return b;
	}

	 string toString() {
		string stringBuffer = "";
		stringBuffer.append("������Fp:" + IntToString(fp) + '\n');
		stringBuffer.append("����a:" + IntToString(a) + '\n');
		stringBuffer.append("����b:" + IntToString(b) + '\n');
		return stringBuffer;
	}

	 bool operator==(MyEllipticCurve a1) {
		 if (this->a == a1.a&&this->b == a1.b&&this->fp == a1.fp)
			 return true;
		 else
			 return false;
	 }
};

