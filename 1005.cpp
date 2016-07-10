#include <cmath>  
#include <iostream>  
using namespace std;  
const int INF = 32767;  
/****************************************/  
const int N = 222;  
int n, m, dp[33][N], loc[N], pre[N], cost[N][N];  

//cost[i][j]为从第i个餐馆到第j个餐馆的花费
//dp[i][j]表示前i个仓库供应前j个餐馆的费用
//dp[i][j] = dp[i-1][k] + cost[i][j]
  
int main()
{  
	int i,j,k;
    int count = 1;  
    while(scanf("%d%d", &n, &m), n||m) {  
        for(i=0;i<n;i++){  
            scanf("%d",&loc[i]);  
        }
        for(i=0;i<n;i++){  
            for(j=0;j<n;j++){  
                cost[i][j] = 0;  
                int mid = (i+j)>>1;  
                for(k=i;k<j+1;k++){  
                    cost[i][j] += abs(loc[mid] - loc[k]);  
                }  
            }  
        }  
        for(j=0;j<n;j++){  
            dp[0][j] = cost[0][j];  
        }    
        for(i=1;i<m;i++){  
            for(j=0;j<n;j++){  
                int ret = INF;  
                for(k=0;k<j;k++){  
                    ret = min(ret, dp[i-1][k] + cost[k+1][j]);  
                }  
                dp[i][j] = ret;  
            }  
        }  
        printf("Chain %d\n", count++);  
        printf("Total distance sum = %d\n\n", dp[m-1][n-1]);  
    }  
    return 0;  
}   
