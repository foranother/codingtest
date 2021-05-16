#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

class Parenthesis
{
public:
	//type�� ���� ��ȣ�� true, ���� ��ȣ�� false�� ǥ���ϱ� ���� ����
	//index�� �ش� ��ȣ�� �ε���
	bool type;
	int index;

	//������, �ε����� Ÿ�� �ٷ� ����
	Parenthesis(int index, bool type)
	{
		this->index = index;
		this->type = type;
	}

	//������, char������ �޾� ������ȣ�� true�� ����, ������ȣ�� false�� ����
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

//���� ¦�� ã�� ���� ���� ��ȣ�鸸 ����
//���� ��ȣ�� ������ ž�� ����� ���� ��ȣ�� ������ ����
//ž ���� ������ �̷���� ->���ú����� ����
bool isValidParentheses(const vector<Parenthesis>& parentheses)
{
	stack<Parenthesis> st;

	for (int i = 0; i < parentheses.size(); i++)
	{
		//���ʺ��� �������� ��ȣ�� ���ʷ� ��ȸ�Ѵ�.
		//���� �����̹Ƿ� ��� ���� ���� ����
		Parenthesis p = parentheses[i];

		if (p.type == true)
		{
			//���� ��ȣ��� ¦�� ã�� ������ ���ÿ� �����Ѵ�.
			st.push(p);
		}
		else if (p.type == false)
		{
			//���� ��ȣ p�� ���Ͽ�
			if (st.size() > 0)
			{
				//���� �������� �߰��� ���� ��ȣ�� ¦�� ���� �� �����Ƿ� �����Ѵ�.
				st.pop();
			}
			else
			{
				//¦�� ���� �� �ִ� ���� ��ȣ�� ���ٸ� �ùٸ��� ���� ��ȣ ���ڿ��̹Ƿ� false �����Ѵ�.
				return false;
			}
		}
	}

	if (st.size() > 0)
	{
		//���� ���ÿ� ¦�� ã�� ���� ���� ��ȣ�� ���������� �ǹ��ϹǷ�
		//false�� �����Ѵ�.
		return false;
	}
	return true;
}

void process(int caseIndex)
{
	//string ���ڿ��� str ���� ����
	string str;
	cin >> str;

	//�迭���·� ����ϱ� ���� ���� ����
	//����Ÿ���� Ŭ������ ��밡��
	vector<Parenthesis> parentheses;

	//���ʹ� (front~back) ��� ��ġ�� ���� ���� ����(���� �迭�� ���)
	//������ ž ��ġ�� ���Ҹ� ���� ����

	//str(caseIndex)�� ���̸�ŭ �����Է�
	for (int i = 0; i < str.length(); ++i)
	{
		//push_back�Լ��� ���� �����Է¹޴´�.
		//i�� index, str[i]�� ������ȣ, ������ȣ�� ���� bool�� ����
		parentheses.push_back(Parenthesis(i, str[i]));
	}

	//VPS���� �ƴ����� Ȯ���ϴ� isValid ����
	bool isValid = isValidParentheses(parentheses);


	//isValid�� true�̸� YES ��� �ƴϸ� NO ���
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
	//case ���� �Է�
	int caseSize;
	cin >> caseSize;

	//�� �Է¹��� ���̽����� VPS���� �ƴ��� Ȯ���ϴ� �ݺ���
	for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1)
	{
		process(caseIndex);
	}
}