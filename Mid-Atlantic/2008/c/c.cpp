#include<iostream>
#include<cstdio>
#include<string>
#include<stack>
using namespace std;

typedef pair<char,bool> stkNode;

string str, sub;
int n;
stack<stkNode> stk;
int b[201];

void clearStk(){
  while (!stk.empty())
    stk.pop();
}

bool checkTree(string sub){
  int pt;
  stkNode top;
  
  clearStk();
  //cout<<sub<<endl;
  /*
  stk.push(stkNode(sub[0],false));
  for (i=1;i<sub.length();i++){
    if (stk.empty())
      return false;
    cout<<stk.top().first<<' '<<stk.top().second<<endl;
    if (sub[i]=='#'){
      top=stk.top();
      stk.pop();
      if (top.second==false){
        top.second=true;
        stk.push(top);
      }
      else {
        while (!stk.empty())
          if (stk.top().second)
            stk.pop();
          else break;
      }
    }
    else {
      top=stk.top();
      stk.pop();
      stk.push(stkNode(top.first,!top.second));
      stk.push(stkNode(sub[i],false));
    }
  }
  cout<<"a\n";
  if (!stk.empty())
    return false;
  return true;
  */
  stk.push(stkNode(sub[0],false)); pt=1;
  while (!stk.empty()){
    if (pt>=sub.length())
      return false;
    //cout<<stk.top().first<<' '<<stk.top().second<<endl;
    if (sub[pt]=='#')
      if (stk.top().second==false){
        top=stk.top(); top.second=true;
        stk.pop();
        stk.push(top);
      }
      else {
          while (!stk.empty())
            if (stk.top().second)
              stk.pop();
            else break;
          if (!stk.empty()){
            top=stk.top(); top.second=true;
            stk.pop();
            stk.push(top);
          }
        }
    else
      stk.push(stkNode(sub[pt],false));
    pt++;
  }
  //cout<<"done"<<endl;
  if (pt==sub.length())
    return true;
  else return false;
}

int KMP(string sub){
  int i,j,counter=0;
  int m=sub.length();

  i=0; j=-1; b[0]=-1;
  while (i<m){
    while (j>=0 && sub[i]!=sub[j]) j=b[j];
    i++; j++;
    b[i]=j;
  }
  
  i=0; j=0;
  while (i<n){
    while (j>=0 && str[i]!=sub[j]) j=b[j];
    i++; j++;
    //cout<<i<<' '<<j<<endl;
    if (j==m){
      //cout<<"\""<<sub<<"\"is found at index"<<(i-j)<<"in T\n";
      j=b[j];
      counter++;
    }
  }
  return counter;
}

int main(){
  int i,j,k;
  int len,counter,cnt,hash;
  int ans=0;
  string ansstr;

  getline(cin,str);
  while (!(str=="END")){
    ans=-1; ansstr="";
    counter=0; n=str.length();
    //cout<<str<<'\t'<<n<<endl;
    for (i=0;i<n;i++)
      if (str[i]!='#')
        counter++;
    //cout<<counter<<endl;
    for (i=1;i<=counter;i++){
      len=i+i+1; //cout<<"i, len="<<i<<","<<len<<endl;
      for (j=0;j<=n-len;j++){
        if (str[j]!='#')
          sub=str.substr(j,len);
        else continue;
        hash=0;
        for (k=0;k<sub.length();k++)
          if (sub[k]=='#')
            hash++;
        if (hash!=i+1)
          continue;
        //cout<<sub<<'\t'<<j<<endl;
        if (!checkTree(sub))
          continue;
        //cout<<sub<<'\t'<<j<<endl;
        cnt=KMP(sub);
        //cout<<cnt<<endl;
        if (ans<(cnt-1)*i){
          ans=(cnt-1)*i;
          ansstr=sub;
        }
      }
      //cout<<"i="<<i<<endl;
    }
    cout<<ansstr<<" "<<ans<<"\n";
    getline(cin,str);
  }
  return 0;
}

