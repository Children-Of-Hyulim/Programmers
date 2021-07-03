#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.

bool	check_data(const string& condition, const string& friends)
{
	int		distance = friends.find(condition[0]) - friends.find(condition[2]);
	distance = distance > 0 ? distance : -distance;
	--distance;
	int		o_distance = condition[4] - '0';

	if ((condition[3] == '=' && distance == o_distance)
		|| (condition[3] == '<' && distance < o_distance)
		|| (condition[3] == '>' && distance > o_distance)
	)
	{
		return true;
	}
	return false;
}

bool	check_datas(const vector<string>& data, const string& friends)
{
	for (const string& condition : data)
	{
		if (check_data(condition, friends) == false)
			return false;
	}
	return true;
}


int solution(int n, vector<string> data) {
	string		friends = "ACFJMNRT";
    int answer = 0;
	
	do
	{
		if (check_datas(data, friends) == true)
		{
			++answer;
		}
		else
			continue;
	}
	while (next_permutation(friends.begin(), friends.end()));


    return answer;
}