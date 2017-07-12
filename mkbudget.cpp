#include <iostream>
#include <vector>
#include <climits>
using namespace std;

long long minimumCost(vector<int> workers,int index,int hiringPay,int salary,int sevPay,int vecSize){
	long long dpArr[24][300];
	for(int i=0;i<24;i++) {
        for(int j=0;j<300;j++)
            dpArr[i][j]=LLONG_MAX;
	}
	for(int i=workers[0];i<300;i++) {
        dpArr[0][i]=i*(hiringPay+salary);

	}

	for(int i=1;i<vecSize;i++) {
        for(int j=workers[i];j<300;j++) {
            for(int k=0;k<300;k++) {
                if(dpArr[i-1][k]!=LLONG_MAX) {
                    if(j>k) {
                        dpArr[i][j]=min(dpArr[i][j],dpArr[i-1][k]+(j-k)*hiringPay+j*salary);
                    }
                    else {
                        dpArr[i][j]=min(dpArr[i][j],dpArr[i-1][k]+(k-j)*sevPay+j*salary);

                    }
                }

            }


        }

	}
	long long ans=LLONG_MAX;
	for(int i=workers[vecSize-1];i<300;i++) {
        ans=min(ans,dpArr[vecSize-1][i]);

	}
	return ans;

}
	/*if(index>size)
		return 0;

	if(index==0) {
		return workers[index]*(hiringPay+salary)+
		minimumCost(workers,index+1,hiringPay,salary,sevPay,size);
	}
	if(workers[index]>=workers[index-1]){
		return (workers[index]-workers[index-1])*hiringPay+workers[index]*salary +
		minimumCost(workers,index+1,hiringPay,salary,sevPay,size);
	}

	else {
		long long a;
		long long minVal=LLONG_MAX;

		for(int i=0;i<=workers[index-1]-workers[index];i++) {
			a=(workers[index]+i)*salary + (workers[index-1]-workers[index]-i)*sevPay;
			workers[index]=workers[index]+i;
			a+=minimumCost(workers,index+1,hiringPay,salary,sevPay,size);
			minVal=min(a,minVal);
		}

		return minVal;

	}

}*/

int main() {
	int n,hiringPay,salary,sevPay,tempWorker,t;
	vector<int> workers;
	cin>>n;
	t=1;
	while(n!=0) {
		workers.clear();
		cin>>hiringPay>>salary>>sevPay;
		for(int i=0;i<n;i++){
			cin>>tempWorker;
			workers.push_back(tempWorker);
		}
		cout<<"Case "<<t<<", cost = $" <<minimumCost(workers,0,hiringPay,salary,sevPay,n)<<endl;
		cin>>n;
		t++;
	}

	return 0;
}
