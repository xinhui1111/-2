#pragma once
#include"MyEllipticCurve.h"
#include"MyEcPoint.h"
#include"integer.h"
class ECParam
{
private:
	 MyEllipticCurve ellipticCurve;//基于的椭圆曲线
	 MyECPoint basePoint;//基点
	 Integer order;//基点的阶

	 ECParam(MyEllipticCurve ellipticCurve, MyECPoint basePoint, Integer order) {
		 try
		 {
			 if (ellipticCurve == *new MyEllipticCurve() || basePoint == *new MyECPoint() || order ==NULL) {
				 throw "参数不能为空";
			 }
		 }
		 catch (const char str[])
		 {
			 std::cout << "参数不能为空"<<endl;
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
		stringBuffer.append("椭圆曲线参数：" + '\n' + ellipticCurve.toString() + '\n');
		stringBuffer.append("基点：" + basePoint.toString() + '\n');
		stringBuffer.append("基点的阶：" + order.toString() + '\n');
		return stringBuffer.toString();
	}
};

