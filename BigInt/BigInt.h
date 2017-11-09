#pragma once

#include <string>

using namespace std;

class BigInt
{
private:
	string m_value;

public:
	BigInt();
	BigInt(string strNum);
	~BigInt();

	//get, set
	string getValue(){ return m_value; }
	void setValue(string str) 
	{
		m_value = str; 
		printf("string length : %d\n", m_value.length());
	}

	//연산자
	friend const BigInt operator+(const BigInt& bigA, const BigInt& bigB);
	friend const BigInt operator-(const BigInt& bigA, const BigInt& bigB);
	friend const BigInt operator*(const BigInt& bigA, const BigInt& bigB);
	friend const BigInt operator/(const BigInt& bigA, const BigInt& bigB);

	//출력
	void show() const;

private:
	bool isABig(const string* strA, const string* strB); // string a, b가 들어오면 a가 b보다 큰지 판별
	string stringAdd(const string& strA, const string strB); // 덧셈 연산
	void resultZero(string& strZero); // 123 - 123 = 000, 123 * 0 = 000 이렇게 나오는데 000을 0으로 변환 또는 002의 결과값을 2로 변환
};
