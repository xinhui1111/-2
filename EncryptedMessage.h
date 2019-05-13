#pragma once
#include"MyEcPoint.h"
class EncryptedMessage
{
private:
	MyECPoint pa;
	 MyECPoint pb;
public:
	EncryptedMessage(MyECPoint pa, MyECPoint pb) {
		this->pa = pa;
		this->pb = pb;
	};
	 MyECPoint getPa() {
		return pa;
	}

	 MyECPoint getPb() {
		return pb;
	}

	 string toString() {
		return pa.toHexString() + " " + pb.toHexString();
	}

	~EncryptedMessage() {};
};

