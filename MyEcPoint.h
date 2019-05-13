#pragma once
//#include"Integer.h"
#include"MyEllipticCurve.h"
#include"Algorithm.h"
#include<sstream>
class MyECPoint
{
private:
	Integer x;
	Integer y;

	//椭圆曲线上的无穷点
	MyECPoint *INFINITY_=new MyECPoint();
public:
	MyECPoint() {
		this->x = NULL;
		this->y = NULL;
	}
	MyECPoint(Integer x,Integer y) {
		this->x = x;
		this->y = y;
	};
	~MyECPoint() {};

	//设置get和set方法
	Integer getX() {
		return x;
	}
	Integer getY() {
		return y;
	}
	void setX(Integer x) {
		this->x = x;
	}
	void setY(Integer y) {
		this->y = y;
	}
	


	//重载运算符==
	//equals函数判断两个坐标点是否为同一个点,
	bool operator==(MyECPoint obj) {
		if (this == &obj)return true;
		if (this == INFINITY_)return false;
		if (this->getX() == obj.getX()&&this->getY() == obj.getY())
			return true;
	}

	//加法运算
	 MyECPoint add(MyECPoint point, MyEllipticCurve ellipticCurve) {
		 if (point.equals(*INFINITY_))
			 return *this;
		 if (this->equals(*INFINITY_))
			 return point;
		 MyECPoint result = *new MyECPoint();
		 if (this->equals(point)) {//两点重合
			 //求切线斜率k=(3*x1*x1+a)*((2*y1)^-1)
			 Integer k = (((point.getX()*point.getX()*(*new Integer("3")) + (ellipticCurve.getA()))
				 *(point.getY()*(*new Integer("2")).InverseMod(ellipticCurve.getFp()))).Modulo(ellipticCurve.getFp()));
			 //求两点和的横坐标x3=k^2-2*x1
			 result.setX((((k*k) - (point.getX()))*(*new Integer("2"))).Modulo( ellipticCurve.getFp()));
			 //求两点和的纵坐标y3=k*(x1-x3)-y1
			 result.setY(((k*(point.getX() -(result.getX())))-(point.getY())).Modulo(ellipticCurve.getFp()));
		 }
		 else if (!this->getX()==(point.getX())) {//两点相异
			 //k=(y2-y1)/(x2-x1)
			 Integer k = (((point.getY() - this->getY())*
				 ((point.getX() - (this->getX())).InverseMod(ellipticCurve.getFp()))).Modulo(ellipticCurve.getFp()));
			 //x3=k^2-x1-x2
			 result.setX(((k*k)-(point.getX()-this->getX())).Modulo(ellipticCurve.getFp()));
			 //y3=k*(x1-x3)-y1
			 result.setY((k*(this->getX()-(result.getX()))-this->getY()).Modulo(ellipticCurve.getFp()));
		 }
		 else {
			 result = *INFINITY_;
		 }
		 return result;
	}

	 //数乘运算
	  MyECPoint multiply(Integer t, MyEllipticCurve ellipticCurve) {
		  MyECPoint point = *INFINITY_;
		  MyECPoint temp = *new MyECPoint(this->getX(),this->getY());
		  //计算t次，使用了快速积的方法，类似于快速幂
		  while (t>(*new Integer("0")) ) {
			  if (t%(*new Integer("2"))==(*new Integer("1"))) {
				  point = point.add(temp, ellipticCurve);
			  }
			  temp = temp.add(temp, ellipticCurve);
			  t = t/(*new Integer("2"));
		  }
		  return point;
	  }


	  MyECPoint subtract(MyECPoint point, MyEllipticCurve ellipticCurve) {
		 point.setY(point.getY()*(*new Integer("-1")));
		 return this->add(point, ellipticCurve);
	 }

	  string toString() {
		  return IntToString(x) + "," + IntToString(y);
	 }

	  string toHexString() {
		  stringbuf str1;
		  ostream os1(&str1);
		  os1 << hex << x;

		  stringbuf str2;
		  ostream os2(&str2);
		  os1 << hex << y;
		  
		  return str1.str() + "," + str2.str();
	 }
};

