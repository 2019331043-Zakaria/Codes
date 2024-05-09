#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template<class T> using ordered_set = 
tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

//1 2 2 3 3 7
//greater->>descending order => 7 3 2 1
//less ->>ascending order => 1 2 3 7
//less_equal -> ascending but in duplicate value => 1 2 2 3 3 7 so this will work as multiset
// multi order set erase = --s.lower_bound(value)

int main() {

    ordered_set<int> A; // declaration

    // Inserting elements - 1st query
    A.insert(1);
    A.insert(10);
    A.insert(2);
    A.insert(7);
    A.insert(7);
    A.insert(7);
    A.insert(2);  // ordered set only contains unique values
    // A contains
    cout << "A = ";
    for (auto i : A)
        cout << i << " ";
    cout << endl;
    cout << endl;
    // finding kth element - 4th query
    cout << "0th element: " << *A.find_by_order(0) << endl;
    cout << "1st element: " << *A.find_by_order(1) << endl;
    cout << "2nd element: " << *A.find_by_order(2) << endl;
    cout << "3rd element: " << *A.find_by_order(3) << endl;
    cout << endl;

    // finding number of elements smaller than X - 3rd query
    cout << "No. of elems smaller than 6: " << A.order_of_key(6) << endl; // 2
    cout << "No. of elems smaller than 11: " << A.order_of_key(11) << endl; // 4
    cout << "No. of elems smaller than 7: " << A.order_of_key(7) << endl; // 0
    cout << endl;

    // lower bound -> Lower Bound of X = first element >= X in the set
    cout << "Lower Bound of 6: " << *A.lower_bound(6) << endl;
    cout << "Lower Bound of 2: " << *A.lower_bound(2) << endl;
    cout << endl;

    // Upper bound -> Upper Bound of X = first element > X in the set
    cout << "Upper Bound of 6: " << *A.upper_bound(6) << endl;
    cout << "Upper Bound of 1: " << *A.upper_bound(1) << endl;
    cout << endl;

    // // Remove elements - 2nd query
    A.erase(1);
    A.erase(11); // element that is not present is not affected

    // A contains
    cout << "A = ";
    for (auto i : A)
        cout << i << " ";
    cout << endl;

}