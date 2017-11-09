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

	//������
	friend const BigInt operator+(const BigInt& bigA, const BigInt& bigB);
	friend const BigInt operator-(const BigInt& bigA, const BigInt& bigB);
	friend const BigInt operator*(const BigInt& bigA, const BigInt& bigB);
	friend const BigInt operator/(const BigInt& bigA, const BigInt& bigB);

	//���
	void show() const;

private:
	bool isABig(const string* strA, const string* strB); // string a, b�� ������ a�� b���� ū�� �Ǻ�
	string stringAdd(const string& strA, const string strB); // ���� ����
	void resultZero(string& strZero); // 123 - 123 = 000, 123 * 0 = 000 �̷��� �����µ� 000�� 0���� ��ȯ �Ǵ� 002�� ������� 2�� ��ȯ
};
