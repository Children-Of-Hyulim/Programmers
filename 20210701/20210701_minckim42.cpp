#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int		i = 0;
	int		answer = 0;
	while (i < absolutes.size())
	{
		answer += signs[i] ? absolutes[i] : -absolutes[i];
		i++;
	}
    return answer;
}