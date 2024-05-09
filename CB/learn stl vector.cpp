#include<bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;
int main()
{
    vector<int>v;
    for(int i=0;i<5;i++)
    {
        int n;
        cin>>n;
        v.pb(n);
    }
  //assignin all element by a different number
//  v.assign(v.size(),12);
//   for(auto i=v.begin();i!=v.end();i++)
//      cout<<*i<<endl;


   //assgnig number by a different range from array
//      int a[]={3,4,5,6};
//      v.assign(a,a+3);//assgining first 3 element of a array  to the verctor
//      for(auto i=v.begin();i!=v.end();i++)
//        cout<<*i<<endl;//print vector between assign limit


  // insert element in a vector



    // inserts 3 at front
//    auto it = v.insert(v.begin(), 3);
//    // inserts 2 at front
//    v.insert(it, 2);
//
//    int i = 2;
//    // inserts 7 at i-th index
//    it = v.insert(v.begin() + i, 7);
//
//    cout << "The vector elements are: ";
//    for (auto it = v.begin(); it != v.end(); ++it)
//        cout << *it << " ";
//
//

// binary search in STL
//  if(binary_search(v.begin(),v.end(),2))
//    cout<<"YES"<<endl;//if 2  is in that vector
//  else
//    cout<<"NO"<<endl;


    //print max and min element from a vector
    cout<<*max_element(v.begin(),v.end())<<" "<<*min_element(v.begin(),v.end()<<endl;


 return 0;
}

