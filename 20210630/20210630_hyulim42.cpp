#include <string>
#include <vector>

using namespace std;

int get_ans_1(int i)
{
    return i % 5 + 1;
}

int get_ans_2(int i)
{
    if (i % 2 == 0)
        return 2;
    i = i % 8;
    if (i == 1)
        return 1;
    else if (i == 3)
        return 3;
    else if (i == 5)
        return 4;
    else
        return 5;
}

int get_ans_3(int i)
{
    i = i % 10;
    if (i <= 1)
        return 3;
    else if (i <= 3)
        return 1;
    else if (i <= 5)
        return 2;
    else if (i <= 7)
        return 4;
    else
        return 5;
}

vector<int> solution(vector<int> answers) {
    int correct[4] = {0,0,0,0};
    for (int i = 0; i < answers.size(); ++i)
    {
        if (get_ans_1(i) == answers[i])
            ++correct[1];
        if (get_ans_2(i) == answers[i])
            ++correct[2];
        if (get_ans_3(i) == answers[i])
            ++correct[3];
    }
    int _max = -1;
    for (int i = 1; i <= 3; ++i)
        _max = max(_max, correct[i]);
    vector<int> answer;
    for (int i = 1; i <= 3; ++i)
        if (_max == correct[i])
            answer.push_back(i);    
    return answer;
}
