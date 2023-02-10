#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

void showData(double *,int,int);

void randData(double *,int,int);

void findRowSum(const double *,double *,int,int);

void findColSum(const double *,double *,int,int);

int main(){
	srand(time(0));
	const int N = 6, M = 8;
	double data[N][M] = {};
	double sum1[N] = {};
	double sum2[M] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findRowSum(dPtr,sum1,N,M);
	showData(sum1,N,1);
	
	cout << "---------------------------------------------\n";
	
	findColSum(dPtr,sum2,N,M); 
	showData(sum2,1,M);
	
}

void showData(double *pointerD,int N,int M){
    cout << fixed << setprecision(2);
    for(int i = 0; i < N*M; i++){
        cout << *(pointerD+i);
        if(i%M == M-1) cout << endl;
        else cout << " ";
    }
}

void randData(double *pointerD,int N,int M){
    for(int i = 0; i < N*M; i++){
        *(pointerD+i) = (rand()%101) / 100.0;
    }
}

void findRowSum(const double *pointerD,double *sum,int N,int M){
	double sumRs = 0;
	int j = 0;
	for(int i = 0; i < M*N; i++){
		sumRs += *(pointerD+i);
		if(i%M == M-1){
			*(sum+j) = sumRs;
			sumRs = 0;
			j++;
		}	
    }
}

void findColSum(const double *pointerD,double *sum,int N,int M){
	double sumRs = 0;
	for(int j = 0; j < M; j++){
		for(int i = 0; i < N*M; i++){
			if(i%M == j){
				sumRs += pointerD[i];
			}	
   		}
		*(sum+j) = sumRs;
		sumRs = 0;
	}
}