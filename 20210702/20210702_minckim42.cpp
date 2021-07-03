#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a, vector<int> b)
{
	int		idx = a.size();
	int		result = 0;
	while (idx--)
	{
		result += a[idx] * b[idx];
	}
	return result;
}