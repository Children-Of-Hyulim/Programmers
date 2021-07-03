// https://programmers.co.kr/learn/courses/30/lessons/42576
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
	sort(participant.begin(), participant.end());
	sort(completion.begin(), completion.end());

	int		idx = -1;
	while (++idx < completion.size())
	{
		if (participant[idx] != completion[idx])
			return participant[idx];
	}
	return participant.back();
}