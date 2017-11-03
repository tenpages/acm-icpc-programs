#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main(){
	string str;
	int n,pos,i;
	
	cin>>n; getchar();
	while (n!=0){
		pos=0;
		for (i=0;i<n;i++){
			getline(cin,str);
			//cout<<str<<endl;
			for (;pos<str.length();pos++)
				if (str[pos]==' ')
					break;
			//cout<<pos<<endl;
		}
		cout<<pos+1<<endl;
		cin>>n; getchar();
	}
}

