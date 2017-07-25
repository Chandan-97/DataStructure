// CHNGSUM
/*
The Result would be 
sum_of_all(max_effect[i] * min_sum[i+1]);
refer editorial, Gennady and Rajat code
*/

#include <bits/stdc++.h>
#define ll long long
#define sz 1000005
#define mod 1000000007

using namespace std;

int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
  #endif
  ll n;
  cin>>n;
  ll a[n];
  for(int i=0; i<n; i++)
    cin>>a[i];

  ll left[n];   // left[i] stores index upto which a[i] is maximum towards left
  ll right[n];  // right[i] stores index upto which a[i] is minimum towards right
  ll max_effect[n]; // max_effect[i] stores sum of all subarrays maximum, ending at i (from left)
  ll min_effect[n]; // min_effect[i] stores sum of all subarrays minimum starting from i (from right)
  ll min_sum[n];  // simply suffix sum of min_effect

  // Create left[]
  {
    stack <ll> st;
    for(int i=0; i<n; i++){
      ll value = a[i];
      while(!st.empty() and value > a[st.top()])
        st.pop();
      if(st.empty())
        left[i] = 0;
      else
        left[i] = st.top() + 1;
      st.push(i);
    }
  }

  // Create right[]
  {
    stack <ll> st;
    for(int i=n-1; i>=0; i--){
      ll value = a[i];
      while(!st.empty() and value < a[st.top()])
        st.pop();
      if(st.empty())
        right[i] = n - 1;
      else
        right[i] = st.top() - 1;
      st.push(i);
    }
  }

  // Create max_effect[]
  {
    for(int i=0; i<n; i++){
      
      ll effect_region = (i - left[i] + 1);
      ll effect_region_sum = (a[i] * effect_region) % mod;

      ll remain = i - effect_region;
      
      ll total_ai = 0;
      
      if(remain >= 0)
        total_ai = max_effect[remain];
      
      total_ai = (total_ai + effect_region_sum) % mod;

      max_effect[i] = total_ai % mod;
    }

    // for(int i=0; i<n; i++)
    //   cout<<max_effect[i]<<" ";
    // cout<<endl;
  }

  // Create min_effect[]
  {
    for(int i=n-1; i>=0; i--){

      ll effect_region = (right[i] - i + 1);
      ll effect_region_sum = (a[i] * effect_region) % mod;

      ll remain = i + effect_region;

      ll total_ai = 0;

      if(remain <= n-1)
        total_ai = min_effect[remain];

      total_ai = (total_ai + effect_region_sum) % mod;

      min_effect[i] = total_ai % mod;
    }

    // for(int i=0; i<n; i++)
    //   cout<<min_effect[i]<<" ";
    // cout<<endl;
  }

  // Create min_sum
  {
    for(int i=0; i<n; i++)
      min_sum[i] = min_effect[i];

    for(int i=n-2; i>=0; i--){
      min_sum[i] = (min_sum[i] + min_sum[i+1]) % mod;
    }

    // for(int i=0; i<n; i++)
    //   cout<<min_sum[i]<<" ";
    // cout<<endl;
  }

  // Calculate result
  ll ans = 0;
  for(int i=0; i<n-1; i++){
    ans = (ans + (max_effect[i] * min_sum[i+1]) % mod) % mod;
  }

  cout<<ans<<endl;

  return 0;

}
