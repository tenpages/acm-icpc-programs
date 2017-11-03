#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;

int main(){
	string str;
	int i,j;
	vector<int> ans;
	
	getline(cin,str);
	while (!(str.length()==1 && str[0]=='0')){
		ans.clear();
		for (i=1;i<str.length();i++)
			if (str[i]=='1'){
				ans.push_back(i);
				for (j=0;j<str.length();j+=i)
					if (str[j]=='1')
						str[j]='0';
					else
						str[j]='1';
			}
		for (i=0;i<ans.size()-1;i++)
			cout<<ans[i]<<' ';
		cout<<ans[ans.size()-1]<<endl;
		getline(cin,str);
	}
	
	return 0;
}

