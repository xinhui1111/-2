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
				 throw"参数不能为空";
			 }
			 this->fp = fp;
			 this->a = a;
			 this->b = b;
		 }
		 catch (...)
		 {
			 std::cout << "参数不能为空";
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
		stringBuffer.append("有限域Fp:" + IntToString(fp) + '\n');
		stringBuffer.append("参数a:" + IntToString(a) + '\n');
		stringBuffer.append("参数b:" + IntToString(b) + '\n');
		return stringBuffer;
	}

	 bool operator==(MyEllipticCurve a1) {
		 if (this->a == a1.a&&this->b == a1.b&&this->fp == a1.fp)
			 return true;
		 else
			 return false;
	 }
};

