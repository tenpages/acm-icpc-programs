#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int check1(long long int num){
  int count=0;
  while (num!=0){
    count+=num%2;
    num/=2;
  }
  return count;
}

int main(){
  char c;
  string str;
  int i,j,k,t;
  long long int son,num;
  vector<long long int> father,mother,child;
  vector<int> ans;
  
  cin>>c;
  while (!(c=='X')){
    father.clear(); mother.clear(); child.clear(); ans.clear();
    while (!(c=='X')){
      cin>>str;
      num=0;
      for (i=0;i<str.length();i++)
        num=(num<<1)+str[i]-'0';
      if (c=='F')
        father.push_back(num);
      else if (c=='M')
        mother.push_back(num);
      else if (c=='C'){
        child.push_back(num);
        ans.push_back(str.length());
      }
      cin>>c;
    }
    for (i=0;i<father.size();i++){
      for (j=0;j<mother.size();j++){
        son=father[i]|mother[j];
        //cout<<i<<' '<<j<<' '<<son<<endl;
        for (k=0;k<child.size();k++){
          t=check1(son^child[k]);
          //cout<<(son^child[k])<<' '<<k<<" "<<t<<endl;
          ans[k]=min(ans[k],t);
        }
      }
    }
    for (i=0;i<child.size();i++)
      printf("Child %d has a minimum of %d mutations.\n",i+1,ans[i]);
    cin>>c;
  }
  return 0;
  //cout<<check1(2)<<endl;
}

