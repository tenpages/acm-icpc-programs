#include<iostream>
#include<string>
#include<algorithm>
#define inf (1<<20)
using namespace std;
string str[501];
int d[501][501];

int dis1(int i, int j){
  int pt, counter=0;
  for (pt=0;pt<str[i].length();pt++){
    if (str[i][pt]!=str[j][pt]){
      counter++;
      if (counter>=2)
        return inf;
    }
  }
  return 1;
}

int dis2(int i, int j){
  int pt1=0, pt2=0;
  //cout<<str[i]<<' '<<str[j]<<endl;
  while (pt2<str[j].length()){  
    if (str[i][pt1]==str[j][pt2])
      pt1++;
    pt2++;
    if (pt2-pt1>=2)
      return inf;
  }
  return 1;
}

bool cmp(string a, string b){
  return a.length()<b.length();
}

int main(){
  int n,i,j,k,dis,ans;
  int tot;
  bool flag;
  string tempstr;
  
  cin>>n;
  while (n!=0){
    //cout<<inf<<endl;
    tot=-1;
    for (i=0;i<n;i++){
      cin>>tempstr; flag=false;
      //cout<<tempstr<<endl;
      for (j=0;j<=tot;j++)
        if (str[j]==tempstr){
          flag=true;
          break;
        }
      //cout<<tempstr<<endl;
      if (!flag){
        tot+=1;
        str[tot]=tempstr;
        //cout<<str[tot]<<endl;
      }
    }
    n=tot+1;
    //cout<<n<<endl;
    sort(str,str+n,cmp);
    /*
    for (i=0;i<n;i++)
      cout<<str[i]<<endl;
    */
    for (i=0;i<n;i++)
      for (j=i+1;j<n;j++){
        d[i][j]=inf; d[j][i]=inf;
        if (str[i].length()==str[j].length()){
          dis=dis1(i,j);
          d[i][j]=dis; d[j][i]=dis;
        }
        if (str[i].length()+1==str[j].length()){
          //cout<<str[i]<<' '<<str[j];
          dis=dis2(i,j);
          //cout<<dis<<endl;
          d[i][j]=dis; d[j][i]=dis;
        }
      }
    /*
    for (i=0;i<n;i++){
      for (j=0;j<n;j++)
        cout<<d[i][j]<<'\t';
      cout<<endl;
    }
    cout<<endl;
    */
    ans=0;
    for (k=0;k<n;k++)
      for (i=0;i<n;i++)
        for (j=0;j<n;j++)
          d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    for (i=0;i<n;i++){
      for (j=i+1;j<n;j++){
        if (d[i][j]<inf)
          ans=max(ans,d[i][j]);
        //cout<<d[i][j]<<'\t';
      }
      //cout<<endl;
    }
    cout<<(ans+1)<<endl;
    cin>>n;
  }
  return 0;
}

