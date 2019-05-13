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

	//��Բ�����ϵ������
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

	//����get��set����
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
	


	//���������==
	//equals�����ж�����������Ƿ�Ϊͬһ����,
	bool operator==(MyECPoint obj) {
		if (this == &obj)return true;
		if (this == INFINITY_)return false;
		if (this->getX() == obj.getX()&&this->getY() == obj.getY())
			return true;
	}

	//�ӷ�����
	 MyECPoint add(MyECPoint point, MyEllipticCurve ellipticCurve) {
		 if (point.equals(*INFINITY_))
			 return *this;
		 if (this->equals(*INFINITY_))
			 return point;
		 MyECPoint result = *new MyECPoint();
		 if (this->equals(point)) {//�����غ�
			 //������б��k=(3*x1*x1+a)*((2*y1)^-1)
			 Integer k = (((point.getX()*point.getX()*(*new Integer("3")) + (ellipticCurve.getA()))
				 *(point.getY()*(*new Integer("2")).InverseMod(ellipticCurve.getFp()))).Modulo(ellipticCurve.getFp()));
			 //������͵ĺ�����x3=k^2-2*x1
			 result.setX((((k*k) - (point.getX()))*(*new Integer("2"))).Modulo( ellipticCurve.getFp()));
			 //������͵�������y3=k*(x1-x3)-y1
			 result.setY(((k*(point.getX() -(result.getX())))-(point.getY())).Modulo(ellipticCurve.getFp()));
		 }
		 else if (!this->getX()==(point.getX())) {//��������
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

	 //��������
	  MyECPoint multiply(Integer t, MyEllipticCurve ellipticCurve) {
		  MyECPoint point = *INFINITY_;
		  MyECPoint temp = *new MyECPoint(this->getX(),this->getY());
		  //����t�Σ�ʹ���˿��ٻ��ķ����������ڿ�����
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

