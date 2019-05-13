#pragma once
#include"MyEllipticCurve.h"
#include"MyEcPoint.h"
#include"integer.h"
class ECParam
{
private:
	 MyEllipticCurve ellipticCurve;//���ڵ���Բ����
	 MyECPoint basePoint;//����
	 Integer order;//����Ľ�

	 ECParam(MyEllipticCurve ellipticCurve, MyECPoint basePoint, Integer order) {
		 try
		 {
			 if (ellipticCurve == *new MyEllipticCurve() || basePoint == *new MyECPoint() || order ==NULL) {
				 throw "��������Ϊ��";
			 }
		 }
		 catch (const char str[])
		 {
			 std::cout << "��������Ϊ��"<<endl;
		 }
		
		this->ellipticCurve = *ellipticCurve;
		this->basePoint = *basePoint;
		this->order = *order;
	}

	 MyEllipticCurve getEllipticCurve() {
		return ellipticCurve;
	}

	 MyECPoint getBasePoint() {
		return basePoint;
	}

	 Integer getOrder() {
		return order;
	}

	public String toString() {
		StringBuffer stringBuffer = new StringBuffer();
		stringBuffer.append("��Բ���߲�����" + '\n' + ellipticCurve.toString() + '\n');
		stringBuffer.append("���㣺" + basePoint.toString() + '\n');
		stringBuffer.append("����Ľף�" + order.toString() + '\n');
		return stringBuffer.toString();
	}
};

