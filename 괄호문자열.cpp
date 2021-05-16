#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

class Parenthesis
{
public:
	//type은 열린 괄호면 true, 닫힌 괄호면 false를 표현하기 위한 변수
	//index는 해당 괄호의 인덱스
	bool type;
	int index;

	//생성자, 인덱스와 타입 바로 받음
	Parenthesis(int index, bool type)
	{
		this->index = index;
		this->type = type;
	}

	//생성자, char형으로 받아 열린괄호면 true로 저장, 닫힌괄호면 false로 저장
	Parenthesis(int index, char c)
	{
		this->index = index;
		if (c == '(')
		{
			this->type = true;
		}
		else
		{
			this->type = false;
		}
	}
};

//현재 짝을 찾지 못한 열린 괄호들만 저장
//닫힌 괄호가 나오면 탑에 저장된 열린 괄호를 삭제해 나감
//탑 원소 삭제만 이루어짐 ->스택변수로 선언
bool isValidParentheses(const vector<Parenthesis>& parentheses)
{
	stack<Parenthesis> st;

	for (int i = 0; i < parentheses.size(); i++)
	{
		//왼쪽부터 오른쪽의 괄호를 차례로 조회한다.
		//벡터 변수이므로 모든 원소 접근 가능
		Parenthesis p = parentheses[i];

		if (p.type == true)
		{
			//열린 괄호라면 짝을 찾을 때까지 스택에 보관한다.
			st.push(p);
		}
		else if (p.type == false)
		{
			//닫힌 괄호 p에 대하여
			if (st.size() > 0)
			{
				//가장 마지막에 추가된 열린 괄호와 짝을 맞출 수 있으므로 제거한다.
				st.pop();
			}
			else
			{
				//짝을 맞출 수 있는 열린 괄호가 없다면 올바르지 않은 괄호 문자열이므로 false 리턴한다.
				return false;
			}
		}
	}

	if (st.size() > 0)
	{
		//아직 스택에 짝을 찾지 못한 열린 괄호가 남아있음을 의미하므로
		//false를 리턴한다.
		return false;
	}
	return true;
}

void process(int caseIndex)
{
	//string 문자열로 str 변수 선언
	string str;
	cin >> str;

	//배열형태로 사용하기 위한 벡터 선언
	//변수타입은 클래스로 사용가능
	vector<Parenthesis> parentheses;

	//벡터는 (front~back) 모든 위치의 원소 접근 가능(동적 배열로 사용)
	//스택은 탑 위치의 원소만 접근 가능

	//str(caseIndex)의 길이만큼 내용입력
	for (int i = 0; i < str.length(); ++i)
	{
		//push_back함수를 통해 내용입력받는다.
		//i는 index, str[i]는 열린괄호, 닫힌괄호에 따라 bool값 저장
		parentheses.push_back(Parenthesis(i, str[i]));
	}

	//VPS인지 아닌지를 확인하는 isValid 선언
	bool isValid = isValidParentheses(parentheses);


	//isValid가 true이면 YES 출력 아니면 NO 출력
	if (isValid)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
}

int main()
{
	//case 갯수 입력
	int caseSize;
	cin >> caseSize;

	//각 입력받은 케이스마다 VPS인지 아닌지 확인하는 반복문
	for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1)
	{
		process(caseIndex);
	}
}