#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int partition(int a[], int low, int high)
{
	int pivot = a[high];

	int j, i = low;

	for (int j = low; j < high; j++)
	{
		if (a[j] <= pivot)
		{
			swap(a[i], a[j]);
			i++;
		}
	}
	swap(a[i], a[high]);

	return i;

}

void quick_sort(int a[], int low, int high)
{
	if (low < high)
	{
		int p = partition(a, low, high); // here p is index of pivot

		quick_sort(a, low, p - 1);
		quick_sort(a, p + 1, high);
	}
}

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(0);

	int a[10] = {5, 8, 9, 1, -2, 5, 10, 2, 4, 7};

	quick_sort(a, 0, 9);

	for (auto i : a)
		cout << i << " ";


	return 0;


}

