#include "stdafx.h"
#include "BigInt.h"


BigInt::BigInt()
{
}

BigInt::~BigInt()
{
}

BigInt::BigInt(string strNum)
	: m_value(strNum)
{
	printf("** %d 자리수 입니다. \n", m_value.length());
}

const BigInt operator+(const BigInt & bigA, const BigInt & bigB)
{
	BigInt result;
	
	result.m_value = result.stringAdd(bigA.m_value, bigB.m_value);

	return result;
}

const BigInt operator-(const BigInt & bigA, const BigInt & bigB)
{
	BigInt result;
	string strSum = "0";
	string::const_iterator aConstIter;
	string::const_iterator bConstIter;
	string::const_iterator aBeginIter;
	string::const_iterator bBeginIter;
	string::iterator strTmpIter;

	bool isMinus = false; // 1 - 100 = -99 인 경우 true

	if (result.isABig(&bigA.m_value, &bigB.m_value)) // 100 - 1, 1 - 100 을 구분
	{
		aConstIter = bigA.m_value.end();
		bConstIter = bigB.m_value.end();

		aBeginIter = bigA.m_value.begin();
		bBeginIter = bigB.m_value.begin();
	}
	else
	{
		isMinus = true;
		aConstIter = bigB.m_value.end();
		bConstIter = bigA.m_value.end();

		aBeginIter = bigB.m_value.begin();
		bBeginIter = bigA.m_value.begin();
	}

	int nSub, nA, nB, nLower = 0;

	nA = *(--aConstIter) - '0';
	nB = *(--bConstIter) - '0';

	while (true)
	{
		nSub = ((nA - nLower) >= nB) ? (nA - nLower) - nB : (10 + (nA - nLower)) - nB;

		if (nA >= nB) nLower = 0;
		else nLower = 1;

		strTmpIter = strSum.begin();
		*strTmpIter = (char)(nSub % 10) + '0';
		strSum = (char)'0' + strSum;

		if (aConstIter == aBeginIter && bConstIter == bBeginIter)
		{
			result.resultZero(strSum);

			if (isMinus)
			{
				strSum = '-' + strSum;
			}

			break;
		}

		nA = (aConstIter != aBeginIter) ? *(--aConstIter) - '0' : 0;
		nB = (bConstIter != bBeginIter) ? *(--bConstIter) - '0' : 0;
	}

	result.m_value = strSum;

	return result;
}

const BigInt operator*(const BigInt & bigA, const BigInt & bigB)
{
	BigInt result;
	string::const_iterator aConstIter;
	string::const_iterator bConstIter;
	string::iterator strTmpIter;

	int nA, nB, nMul, nUpper = 0;

	aConstIter = bigA.m_value.end();
	bConstIter = bigB.m_value.end();

	nA = *(--aConstIter) - '0';
	nB = *(--bConstIter) - '0';

	string strTotal = "0";
	string strZero = "";

	while (true)
	{
		string strMul = "0";
		while (true)
		{
			strTmpIter = strMul.begin();
			
			nMul = (nB * nA) + nUpper;
			*strTmpIter = (char)(nMul % 10) + '0';
			nUpper = nMul / 10;

			strMul = (char)'0' + strMul;

			if (bConstIter == bigB.m_value.begin())
			{
				strTmpIter = strMul.begin();
				if (nUpper > 0) *strTmpIter = (char)(nUpper + '0');
				else strMul.erase(strTmpIter);

				break;
			}

			nB = *(--bConstIter) - '0';
		}

		strMul += strZero;

		strTotal = result.stringAdd(strTotal, strMul);

		if (aConstIter == bigA.m_value.begin())
		{
			strTmpIter = strTotal.begin();
			if (nUpper > 0) *strTmpIter = (char)(nUpper + '0');

			break;
		}

		// 초기화
		bConstIter = bigB.m_value.end();

		nA = *(--aConstIter) - '0';
		nB = *(--bConstIter) - '0';

		nUpper = 0;
		
		// 자리수가 올라가면서 곱하면 뒤에 0이 하나씩 붙음
		strZero += '0';
	}

	result.resultZero(strTotal);
	result.m_value = strTotal;

	return result;
}


const BigInt operator/(const BigInt & bigA, const BigInt & bigB)
{
	BigInt result;
	
	
	return result;
}

bool BigInt::isABig(const string * strA, const string * strB)
{
	if (strA->length() > strB->length())
	{
		return true;
	}
	else if (strA->length() < strB->length())
	{
		return false;
	}
	else // 같다면
	{
		string::const_iterator aConstIter;
		string::const_iterator bConstIter;

		aConstIter = strA->begin();
		bConstIter = strB->begin();

		while (true)
		{
			if (*aConstIter > *bConstIter) return true;
			else if (*aConstIter < *bConstIter) return false;
			else if (*aConstIter == *bConstIter)
			{
				aConstIter++;
				bConstIter++;

				if (aConstIter == strA->end() && bConstIter == strB->end())
				{
					return true;
				}
			}
		}
	}
}

string BigInt::stringAdd(const string & strA, const string strB)
{
	string strSum = "0";
	string::const_iterator aConstIter;
	string::const_iterator bConstIter;
	string::iterator strTmpIter;

	aConstIter = strA.end();
	bConstIter = strB.end();

	int nSum, nA, nB, nUpper = 0;

	nA = *(--aConstIter) - '0'; //ascii code 에서 '0' == 48, '1' == 49, 49 - 48 = 1
	nB = *(--bConstIter) - '0';

	while (true)
	{
		nSum = nA + nB + nUpper;

		strTmpIter = strSum.begin();
		*strTmpIter = (char)(nSum % 10) + '0';
		nUpper = nSum / 10;

		strSum = (char)('0') + strSum;

		if (aConstIter == strA.begin() && bConstIter == strB.begin())
		{
			strTmpIter = strSum.begin();
			if (nUpper > 0)
			{
				*strTmpIter = '1';
			}
			else
			{
				strSum.erase(strTmpIter);
			}

			break;
		}

		nA = (aConstIter != strA.begin()) ? *(--aConstIter) - '0' : 0;
		nB = (bConstIter != strB.begin()) ? *(--bConstIter) - '0' : 0;
	}

	return strSum;
}

void BigInt::resultZero(string & strZero)
{
	string strTmpZero;
	string::iterator strTmpIter;
	strTmpIter = strZero.begin();

	while (true) // 연산이 끝나고 나면 결과가 001로 나온다, 앞에 00을 제거해준다. 출력은 1
	{
		if (strZero.length() == 1) break;

		if (*strTmpIter == '0') strZero.erase(strTmpIter);
		else
		{
			break;
		}
	}
}

void BigInt::show() const
{
	printf("result : %s\n\n", m_value.c_str());
}