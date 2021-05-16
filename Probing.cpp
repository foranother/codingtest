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
		//처음엔 다 비어있기 때문에 false로 초기화
		this->used.assign(length, false);
	}

	//사용자의 회원 번호로 지급받게 될 행운권 번호를 계산하는 메소드
	int findEmptyIndexByUserId(int userId)
	{
		//길이만큼 값을 나누어 나머지 값을 저장
		int index = userId % length;
		//값이 비어있는 곳까지 계속해서 1을 더해가며 찾고 비어있는 곳에 저장
		while (this->isEmpty(index) == true)
		{
			//% length를 하는 이유는 최대값을 넘어가면 다시 1부터 돌아가기 위함
			index = (index + 1) % length;
		}
		//구한 값 반환
		return index;
	}

	//해당 행운권 번호가 이미 사용 중인지 여부를 반환하는 메소드
	bool isEmpty(int ticketIndex)
	{
		return this->used[ticketIndex];
	}

	//티켓 사용 여부를 갱신하기 위한 메소드
	void setUsed(int index, bool status)
	{
		this->used[index] = status;
	}
};

vector<int> getTicketNumbers(int n, int m, const vector<int>& ids)
{
	//tickest이라는 벡터 변수 선언
	vector<int> tickets;
	//클래스 사용
	TicketTable table = TicketTable(n);

	//사용자만큼 반복문
	for (int i = 0; i < m; i++)
	{
		int userId = ids[i];
		int ticketIndex = table.findEmptyIndexByUserId(userId);

		//push_back을 통해 인덱스를 tickets에 계속 추가
		tickets.push_back(ticketIndex);
		//추가를 했다면 setUsed 함수를 통해 true로 값 변경
		table.setUsed(ticketIndex, true);
	}

	return tickets;
}

int main()
{
	//n은 전체 티켓의 수, m은 요청 고객의 수
	int n, m;

	//n, m 입력
	scanf("%d%d", &n, &m);

	//벡터변수로 선언
	vector<int> ids(m);
	//고객의 수만큼 값 입력받는다.
	for (int i = 0; i < m; ++i)
	{
		scanf("%d", &ids[i]);
	}

	vector<int> tickets = getTicketNumbers(n, m, ids);
	//티켓사이즈만큼 반복문을 진행하여 실제로 어느 값에 저장되어있는지에 대해 출력
	for (int i = 0; i < tickets.size(); ++i)
	{
		printf("%d\n", tickets[i]);
	}
}