#include <cstdio>
#include <vector>

using namespace std;

class TicketTable
{
public:
	vector<bool> used;
	int length;

	TicketTable(int length)
	{
		this->length = length;
		//ó���� �� ����ֱ� ������ false�� �ʱ�ȭ
		this->used.assign(length, false);
	}

	//������� ȸ�� ��ȣ�� ���޹ް� �� ���� ��ȣ�� ����ϴ� �޼ҵ�
	int findEmptyIndexByUserId(int userId)
	{
		//���̸�ŭ ���� ������ ������ ���� ����
		int index = userId % length;
		//���� ����ִ� ������ ����ؼ� 1�� ���ذ��� ã�� ����ִ� ���� ����
		while (this->isEmpty(index) == true)
		{
			//% length�� �ϴ� ������ �ִ밪�� �Ѿ�� �ٽ� 1���� ���ư��� ����
			index = (index + 1) % length;
		}
		//���� �� ��ȯ
		return index;
	}

	//�ش� ���� ��ȣ�� �̹� ��� ������ ���θ� ��ȯ�ϴ� �޼ҵ�
	bool isEmpty(int ticketIndex)
	{
		return this->used[ticketIndex];
	}

	//Ƽ�� ��� ���θ� �����ϱ� ���� �޼ҵ�
	void setUsed(int index, bool status)
	{
		this->used[index] = status;
	}
};

vector<int> getTicketNumbers(int n, int m, const vector<int>& ids)
{
	//tickest�̶�� ���� ���� ����
	vector<int> tickets;
	//Ŭ���� ���
	TicketTable table = TicketTable(n);

	//����ڸ�ŭ �ݺ���
	for (int i = 0; i < m; i++)
	{
		int userId = ids[i];
		int ticketIndex = table.findEmptyIndexByUserId(userId);

		//push_back�� ���� �ε����� tickets�� ��� �߰�
		tickets.push_back(ticketIndex);
		//�߰��� �ߴٸ� setUsed �Լ��� ���� true�� �� ����
		table.setUsed(ticketIndex, true);
	}

	return tickets;
}

int main()
{
	//n�� ��ü Ƽ���� ��, m�� ��û ���� ��
	int n, m;

	//n, m �Է�
	scanf("%d%d", &n, &m);

	//���ͺ����� ����
	vector<int> ids(m);
	//���� ����ŭ �� �Է¹޴´�.
	for (int i = 0; i < m; ++i)
	{
		scanf("%d", &ids[i]);
	}

	vector<int> tickets = getTicketNumbers(n, m, ids);
	//Ƽ�ϻ����ŭ �ݺ����� �����Ͽ� ������ ��� ���� ����Ǿ��ִ����� ���� ���
	for (int i = 0; i < tickets.size(); ++i)
	{
		printf("%d\n", tickets[i]);
	}
}