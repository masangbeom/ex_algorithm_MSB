//
// Created by sangbeom ma on 2017. 11. 23..
//

#include <iostream>
using namespace std;
int K;
int N;
int countCoin = 0;
int use = 1;
int coinArr[11];
int calc(int moneyNow , int coinMoney){
    if(moneyNow % coinMoney == 0){
        countCoin += (moneyNow / coinMoney);
        return 0;
    }else {
        int tempMoneyNow = moneyNow % coinMoney;
        countCoin += (moneyNow / coinMoney);
        calc(tempMoneyNow, coinArr[--use]);
    }
}
int main(){
    cin >> N >> K;
    for(int i=1; i<=N; i++){
        int temp = 0;
        cin >> temp;
        if(temp < K)
            coinArr[use++] = temp;
    }
    calc(K, coinArr[--use]);
    cout << countCoin;
}