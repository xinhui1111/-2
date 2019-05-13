#pragma once
#include"integer.h"
#include"MyECPoint.h"
using namespace CryptoPP;
class MyECKeyPair
{private:
	 const Integer* privateKey;
	 const MyECPoint* publicKey;

	 MyECKeyPair() {
		privateKey = new Integer("0");
		publicKey = new MyECPoint();
	}

	 MyECKeyPair(Integer privateKey, MyECPoint publicKey) {
		this->privateKey = &privateKey;
		this->publicKey = &publicKey;
	}

	 Integer getPrivateKey() {
		return *privateKey;
	}

	 MyECPoint getPublicKey() {
		return *publicKey;
	}
};

