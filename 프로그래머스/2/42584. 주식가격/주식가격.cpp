#include <string>
#include <vector>
// #include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    vector<int> stack;
    
    for(int i = 0; i < prices.size(); i++)
    {
        
        // answer에 새 가격의 가격이 떨어지지 않은 기간 넣고
        answer.push_back(0);
        
        // stack에 남아있는 인덱스값의 answer에 기간 갱신 해주고
        for(int i = 0; i < stack.size(); i++)
        {
            answer[stack[i]]++;
        }

        
        while(!stack.empty() && prices[i] < prices[stack.back()])
        {
            // cout<<"end stack : "<<stack.back()<<"\n";
            stack.pop_back();
        }
        // stack에는 가격이 떨어지지 않은 값들의 인덱스가 담김
        stack.push_back(i);
        
    }
    
    return answer;
}