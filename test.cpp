// test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
// stringbuf example
#include <string>       // std::string
#include <iostream>     // std::cout, std::ostream, std::hex
#include <sstream>      // std::stringbuf
using namespace std;


#include<vector>
vector<string> split(const string& src, string separate_character)
{
	vector<string> strs;

	int separate_characterLen = separate_character.size();//分割字符串的长度,这样就可以支持如“,,”多字符串的分隔符
	int lastPosition = 0, index = -1;
	while (-1 != (index = src.find(separate_character, lastPosition)))
	{
		strs.push_back(src.substr(lastPosition, index - lastPosition));
		lastPosition = index + separate_characterLen;
	}
	string lastString = src.substr(lastPosition);//截取最后一个分隔符后的内容
	if (!lastString.empty())
		strs.push_back(lastString);//如果最后一个分隔符后还有内容就入队
	return strs;
};

int main() {
	string str = "sdd cj dd";
	vector<string>receive;
	receive=split(str, " ");
	for (auto& it : receive)
		cout << it << endl;
	return 0;
}
