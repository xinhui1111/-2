#pragma once
#include"pch.h"
#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1
#include "md5.h"
using namespace CryptoPP;
#pragma comment(lib, "cryptlib.lib") 
#include"hex.h"
#include"files.h"
#include"filters.h"
#include"integer.h"
using namespace std;

#include"EncryptedMessage.h"

//#include"EncryptedMessage.h"


#include "integer.h"
#include"base64.h"
using namespace CryptoPP;
#pragma comment(lib, "cryptlib.lib")

class Algorithm_ {


private:
	static Integer x; static Integer y;
public:


	Algorithm_() {

	}

	~Algorithm_() {

	}
	static Integer getX() {
		return x;
	}

	static Integer getY() {
		return y;
	}











	//ʹ��MD5�õ�����ϢժҪ�ķǸ���������ʽ
	static Integer msgDigestByMD5(const string msg) {
		string dest = "";
		HexEncoder encoder(new StringSink(dest));

		//std::string msg = "Yoda said, Do or do not. There is no try.";
		std::string digest;

		Weak::MD5 hash;
		hash.Update((const byte*)msg.data(), msg.size());
		digest.resize(hash.DigestSize());
		hash.Final((byte*)&digest[0]);

		StringSource(digest, true, new Redirector(encoder));
		return *new Integer(dest.data());
	}


	//ʮ������ת������������
	static string HexToBinInt(string hexstr) {
		string del_zero(string str);
		string scatter(char hex_str);
		string result = "";
		int len = hexstr.length();
		int len_BinInt = len * 4;
		string bin = "";
		for (int i = 0; i < len; ++i) {
			bin = scatter(hexstr[i]);
			result.append(bin);
		}
		return del_zero(result);
	}


	//������������תʮ������
	static string BinIntToHex(string bigstr) {
		string del_zero(string str);
		int integer(string str);
		stringstream ss;
		string str = "";

		int len = bigstr.length();
		int* result = new int[len / 4 + 1];
		int seg = len / 4;//�ֳɵĶ���
		if (len % 4 == 0) {
			for (int i = 0; i < seg; ++i) {
				string sub = bigstr.substr(i * 4, 4);
				result[i] = integer(sub);
				ss << result[i];
			}
		}
		else {//���Ҫ��ǰ���0�����
			//1���ж���Ҫ�Ӽ���0,add_numΪ��Ҫ�ӵĸ���
			int yu = len % 4;
			int add_num = 4 - yu;
			//2����0������ַ�����
			for (int j = 0; j < add_num; j++) {
				bigstr.insert(0, 1, '0');
			}
			bigstr;
			//3���Ѿ����������ֶΣ���ǰ���������һ��
			//��Ҫ�����ж��ַ��Ƿ����10������10��ҪתΪ�ַ�A��B
			for (int i = 0; i < seg + 1; ++i) {
				string sub = bigstr.substr(i * 4, 4);
				result[i] = integer(sub);
				if (result[i] >= 10) {
					char result_char = (char)(result[i] - 10 + 'A');
					ss << result_char;
				}
				else {
					ss << result[i];
				}
			}
		}
		return del_zero(ss.str());
	}

	//���ĸ������ַ����ϵ�һ�������ַ�����ȥ
	//ע�⣺str�ĳ���Ϊ4
	static int integer(string str) {
		int number[4];
		int len = str.length();
		for (int i = 0; i < len; i++) {
			number[i] = str.at(i) - '0';
		}
		int integer = int(number[0] * pow(2, 3) + number[1] * pow(2, 2) + number[2] * pow(2, 1) + number[3]);
		return integer;
	}

	//����ʮ������ת��Ϊ������
	static string scatter(char hex_str) {
		stringstream result;
		if (hex_str == 'A')
			return "1010";
		else if (hex_str == 'B')
			return "1011";
		else if (hex_str == 'c')
			return "1100";
		else if (hex_str == 'D')
			return "1101";
		else if (hex_str == 'E')
			return "1110";
		else if (hex_str == 'F')
			return "1111";
		else {
			int receive_num = hex_str - '0';
			int yu = 0, shang = 1;
			for (int i = 0; i < 4; ++i) {
				shang = receive_num / 2;
				yu = receive_num % 2;
				result << yu;
				receive_num = shang;
			}
			string _result = result.str();
			string c(_result.rbegin(), _result.rend());
			return c;
		}
	}


	//���ַ���ǰ���0ȥ��
	static string del_zero(string str) {
		int len = str.length();
		bool flag = 0;
		stringstream result;
		for (int i = 0; i < len; ++i) {
			if ('0' != str[i] || flag == 1)
			{
				result << str[i];
				flag = 1;
			}
			else
				continue;
		}
		return result.str();
	}

	//�ָ��������ת��������Ϣ���
	//���ַ���s����delim�ķָ���ʽ���зָ�������浽ret������
	void split(std::string& s, std::string& delim, std::vector<std::string> ret)
	{
		size_t last = 0;
		size_t index = s.find_first_of(delim, last);
		while (index != string::npos)
		{
			ret.push_back(s.substr(last, index - last));
			last = index + 1;
			index = s.find_first_of(delim, last);
		}
		if (index - last > 0)
		{
			ret.push_back(s.substr(last, index - last));
		}
	}

	vector<string> split(const string& src, string separate_character)
	{
		vector<string> strs;

		int separate_characterLen = separate_character.size();//�ָ��ַ����ĳ���,�����Ϳ���֧���硰,,�����ַ����ķָ���
		int lastPosition = 0, index = -1;
		while (-1 != (index = src.find(separate_character, lastPosition)))
		{
			strs.push_back(src.substr(lastPosition, index - lastPosition));
			lastPosition = index + separate_characterLen;
		}
		string lastString = src.substr(lastPosition);//��ȡ���һ���ָ����������
		if (!lastString.empty())
			strs.push_back(lastString);//������һ���ָ����������ݾ����
		return strs;
	}


	//��ʮ�������ַ���ת��Ϊ������Ϣ��
	static EncryptedMessage* hexStr2EncryptedMessage(string s) {

	}

	//�ַ���ת��Ϊ��Ӧ�ֽ����飬����û�о����ӽ���
	byte* CharToByte(string str) {

		byte* receive = new byte[str.length()];
		for (int i = 0; i < str.length(); i++) {
			receive[i] = str[i];
		}
		return receive;
	}


	//���ַ�������ȡ�ֽ�����
	string toByteArray(string str) {
		byte* decoded = CharToByte(str);
		string encoded;
		StringSource ss(decoded, sizeof(byte)*str.length(), true,
			new Base64Encoder(
				new StringSink(encoded)
			) // Base64Encoder
		); // StringSource
		return encoded;
	}

	//���ֽ�������ַ�����ת��Ϊʵ�ʵ��ַ���
	string byteToString(string byteArray) {
		string decoded;

		StringSource ss(byteArray, true,
			new Base64Decoder(
				new StringSink(decoded)
			) // Base64Decoder
		); // StringSource
		return decoded;
	}

	//ģ��java��biginteger��toByteArray
	static byte* toByteArray(Integer Integer_) {
		byte* by = new byte[Integer_.ByteCount()];
		byte* temp = by;
		for (int i = 0; i < Integer_.ByteCount(); ++i)
		{
			*temp++ = Integer_.GetByte(i);
		}
		return by;
	}
	
};

Integer Algorithm_::x = *new Integer("0");
Integer Algorithm_::y = *new Integer("0");
