


#include <iostream>

using namespace std;

int K,N;//동전의 합이 K, 동전의 종류가 N
int W[11];
int countCoin=0;
int result=0;
void cal(int k,int t){
    countCoin = 0;
    if(k%W[t]==0){
        result = result + k/W[t];
        cout << result << endl;
        return;
    }
    else{
        countCoin = k / W[t];
        int f = W[t];
        result= result+countCoin;
        while(k-countCoin*f<W[t]){t--;}
        cal(k-countCoin*f,t);
    }
}


int main()
{
    cin>>N>>K;
    for(int i=1;i<=N;i++)
    {cin>>W[i];}
    for(int i=N;i>1;i--){
        if(K>=W[i]){cal(K,i);
        break; }

    }
//    cal(4200,7);
//    cout<<result;
    return 0;
}