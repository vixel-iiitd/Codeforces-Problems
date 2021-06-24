#include <bits/stdc++.h> 
using namespace std;
#define ll long long int
#define pii pair<ll,ll>
#define rep(i,st,en) for(ll i=st;i<en;i++)
#define vi vector<ll>
#define vii vector<pii>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define eb emplace_back
#define yes cout<<"YES"<<endl; return;
#define no cout<<"NO"<<endl; return;
#define flus fflush(stdout);
#define gin(x) cerr<<#x<<" : "<<x<<" ";
#define fin cerr<<endl;
#define F first
#define S second
#define np next_permutation
#define inf 1e18
#define mod 1000000007
#define N 200009
#define PI 3.14159265358979323846
#define minpq priority_queue <ll, vector<ll>, greater<ll>>
#define maxpq priority_queue<ll> 
#define notFind string::npos



void solve(){
  int n,l,r;
  cin>>n>>l>>r;

  int a[n];

  int left[n+1]{0};
  int right[n+1]{0};


  rep(i,0,n)
  {
    cin>>a[i];
  }


  rep(i,0,l)
  {
    left[a[i]]++;
  }

  rep(i,l,n){
    right[a[i]]++;
  }


  int count=abs(n/2-l);
  

  rep(i,0,n){

    int x = a[i];

    if(l!=r){


      if(l<r && right[x]-left[x]>=2){

        int z = n/2-l;

        int y =  min(z,(right[x]-left[x])/2);

        l+=y;
        r-=y;

        right[x]-=y;

        left[x]+=y;

      }

      else if(l>r && left[x]-right[x]>=2)
      {

        int z = n/2-r;

        int y = min(z,(left[x]-right[x])/2);
        r+=y;
        l-=y;
        left[x]-=y;

        right[x]+=y;
      }
    }

    else{
      break;
    }

  }


  if(l!=r)
  {

    if(l>r)
    { 

      for(int i =1 ;i<=n;i++)
      {

        if(left[i]-right[i]>=1)
        {


          left[i]--;
          right[i]++;

          l--;
          r++;
          if(r==l) break;

        }

      }

    }

    else{

      rep(i,1,n)
      {

        if(right[i]-left[i]>=1)
        {

          right[i]--;
          left[i]++;

          l++;
          r--;

          if(r==l) break;
        }


      }

    }



  }


  int ans[n];


  int t1 = 0;

  int p1 = 1;

  while(p1!=n+1 && t1!=n/2)
  {

    if(left[p1]!=0)
    {

      ans[t1] = p1;

      left[p1]--;


      if(left[p1]==0){
        p1++;
      }
      t1++;
    }
    else
    {

      p1++;
    }
  }

  int t2 = n/2;
  int p2 = 1;


  while(p2!=n+1 &&  t2!=n)
  { 

    if(right[p2]!=0)
    {
      ans[t2] = p2;


      right[p2]--;
      if(right[p2]==0)
      {
        p2++;

      }
      t2++;


    }
    else{
      p2++;
    }
  }


  bool r1[n]{false};
  bool r2[n]{false};

  int f1= 0;
  int f2= n/2;


  while(f2!=n && f1!=n/2)
  {

    if(ans[f1]==ans[f2])
    {

      r1[f1]=true;
      r2[f2] = true;
      f1++;
      f2++;
    }

    else if(ans[f1]>ans[f2])
    {

      r2[f2]=false;
      f2++;
    }

    else{
      r1[f1]=false;
      f1++;
    }

  }

  int c11 = 0;

  for(int i =0 ;i<n/2;i++)
  {

    if(!r1[i])
    { 

      c11++;
    }

  }

  for(int i =n/2;i<n;i++)
  {
    if(!r2[i])
    {
      c11++;
    }
  }

  c11/=2;

  
  cout<<count+c11<<endl;

}



int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t t1=clock();
  int t;
  cin>>t;
  // t=1;
  while(t--){
    solve();
  }
  cerr<<"Time elapsed: "<<(double)(clock()-t1)/1000<<" s"<<endl;
}


