/*1번 수포자가 찍는 방식: 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, ...
2번 수포자가 찍는 방식: 2, 1, 2, 3, 2, 4, 2, 5, 2, 1, 2, 3, 2, 4, 2, 5, ...
3번 수포자가 찍는 방식: 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, ...
*/
#include <string>
#include <vector>
#include <map>

using namespace std;

int			get_score(const vector<int>& answers, const vector<int>& pattern)
{
	int		p = 0;
	int		score = 0;
	for (int i : answers)
	{
		if (pattern[p++] == i)
			score++;
		if (p == pattern.size())
			p = 0;
	}
	return score;
}

vector<int> solution(vector<int> answers)
{
    vector<int> answer;
	vector<int>	pattern[3];
	multimap<int, int, greater<int>>	score;
	
	pattern[0].push_back(1);
	pattern[0].push_back(2);
	pattern[0].push_back(3);
	pattern[0].push_back(4);
	pattern[0].push_back(5);

	pattern[1].push_back(2);
	pattern[1].push_back(1);
	pattern[1].push_back(2);
	pattern[1].push_back(3);
	pattern[1].push_back(2);
	pattern[1].push_back(4);
	pattern[1].push_back(2);
	pattern[1].push_back(5);
	
	pattern[2].push_back(3);
	pattern[2].push_back(3);
	pattern[2].push_back(1);
	pattern[2].push_back(1);
	pattern[2].push_back(2);
	pattern[2].push_back(2);
	pattern[2].push_back(4);
	pattern[2].push_back(4);
	pattern[2].push_back(5);
	pattern[2].push_back(5);

	score.insert(pair(get_score(answers, pattern[0]), 1));
	score.insert(pair(get_score(answers, pattern[1]), 2));
	score.insert(pair(get_score(answers, pattern[2]), 3));
	
	int		prev_score = 0;
	auto it = score.upper_bound(score.begin()->first);
	for (auto i = score.begin() ; i != it ; ++i)
	{
		answer.push_back(i->second);
	}
    return answer;
}