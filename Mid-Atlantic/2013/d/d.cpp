#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
string str;

int main(){
	int n,k;
	int i;
	int flagG, flagWF, flagWG, countF, countG, countWF, ptF, ptG;
	int tree[1001];
	
	scanf("%d%d",&n,&k); flagWG=false;
	while (!(n==0&&k==0)){
		flagG=false; flagWF=false;
		countF=0; countG=0;
		ptF=0; ptG=0;
		//scanf("%d",&tree[i]);
		for (i=1;i<=n;i++){
			scanf("%d",&tree[i]);
			if (i>1 && tree[i]-tree[i-1]>1){
				countG+=countF;
				if (flagWF){
					countWF=countF;
					//cout<<tree[i]<<endl;
					flagWF=false;
				}
				ptF+=1; countF=0;
				if (ptF==2)
					flagG=true;
				if (flagG && tree[ptF]-tree[ptF-1]>1){
					if (flagWG){
						printf("%d\n",countG-countWF);
						flagWG=false;
						getline(cin,str);
						break;
					}
					ptG+=1; countG=0;
				}
			}
			if (tree[i]==k){
				if (!flagG){
					printf("0\n");
					getline(cin,str);
					break;
				}
				flagWG=true;
				flagWF=true;
			}
			countF+=1;
			//cout<<tree[ptF]<<' '<<tree[ptG]<<' '<<countF<<' '<<countG<<endl;
		}
		if (flagWG){
			if (flagWF){
				countWF=countF;
				flagWF=false;
			}
			printf("%d\n",countG+countF-countWF);
			flagWG=false;
		}
		scanf("%d%d",&n,&k);
	}
}

