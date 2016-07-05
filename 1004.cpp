#include <stdio.h>
#include <cmath>
using namespace std;
int callength(long int x){		//计算长度 
	int count=1;
    while( x=x/10 )
    	count++;
    return count; 
}
bool check(long int x){			//检查质数 
	for(long int i=2;i<=sqrt(x);i++)
		if(x%i==0 || x==0) 
			return false;
		return true;
}
int increase(int x[],int len){   //数组增加 
	int count = 1;
	for(int i=0;i<len+1;i++){
		x[i]++;
		if(x[i]<10)
			break;
		else{
			x[i] = 0;
			count++;
		}
	}
	if(count>len)
		return count;
	else return len;
}


int main(void)
{
	int a,num[5];
	int a_len,b_len;
	int i = 0;
	long int b,tsum;
    while (scanf("%d %d", &a, &b)==2){
    	a_len = callength(a);
    	b_len = callength(b);
    	int temp_len,new_len;
    	if(a_len%2==0){				//存储前半部分 
    		temp_len = a_len/2;
    		for(i=0;i<temp_len;i++){
    			a = a/10;
    		}
    		for(i=0;i<temp_len;i++){
    			num[i] = a%10;
				a = a/10; 
    		}
    	}else{
    		temp_len = (a_len+1)/2;
    		for(i=0;i<temp_len-1;i++){
    			a = a/10;
    		}
    		for(i=0;i<temp_len;i++){
    			num[i] = a%10;
				a = a/10; 
    		}
    	}
    	while(a_len<=b_len){			//奇偶切换 
    		tsum = 0;
    		if(a_len%2==0){
    			temp_len = a_len/2;
    			new_len = temp_len;
    			for(i=temp_len-1;i>=0;i--)
    				tsum = tsum*10+num[i];
    			for(i=0;i<temp_len;i++)
    				tsum = tsum*10+num[i];
    			if(tsum>b)
    				break;
    			if(check(tsum) && tsum!=0)
    				printf("%ld\n",tsum);
    			new_len = increase(num,temp_len);
    			if(new_len>temp_len){
    				a_len++;
    				num[new_len-1]=1;
    				for(i=0;i<new_len-1;i++)
    					num[i]=0;
    			}
    		}else{
    			temp_len = (a_len+1)/2;
    			new_len = temp_len;
    			for(i=temp_len-1;i>=0;i--)
    				tsum = tsum*10+num[i];
    			for(i=1;i<temp_len;i++)
    				tsum = tsum*10+num[i];
    			if(tsum>b)
    				break;
    			if(check(tsum) && tsum!=0)
    				printf("%ld\n",tsum);
    			new_len = increase(num,temp_len);
    			if(new_len>temp_len){
    				a_len++;
    				num[temp_len-1]=1;
    				for(i=0;i<temp_len-1;i++)
    					num[i]=0;
    			}
    		}
    		
    	}
    }
    return 0;
}
