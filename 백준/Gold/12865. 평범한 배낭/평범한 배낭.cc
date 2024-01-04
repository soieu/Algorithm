#include <iostream>
using namespace std;

int weight[101];
int value[101];
int dp[101][100001];
int main(){
    cin.tie(0); 
    cout.tie(0); 
    ios::sync_with_stdio(false);

    int n,k;
    cin >> n >> k;

    for(int i = 1; i<=n; i++){
        cin >> weight[i];
        cin >> value[i];
    }

    for(int i = 1; i <= n; i++){    // i : 가방 번호
        for(int j = 1; j<= k; j++){ // j : 최대 무게
            // i번째 물건을 가방에 넣을 수 있는 경우 - 최대 무게보다 물건의 무게가 작은 경우
            if(j >= weight[i]) 
            {
                // 물건을 넣지 않거나, 바로 이전 물건까지 판단했을 때 그 당시 최대 무게가 현재 최대 무게 - 물건의 무게일 때의 가치와 현재 물건의 가치를 합한 값을 비교 후 큰 값을 저장
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-weight[i]]+value[i]);
            }
            else dp[i][j] = dp[i-1][j];
        }
    }

    cout << dp[n][k];

}