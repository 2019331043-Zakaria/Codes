/*
* @Author: Zakaria 
* @Date:   2022-04-25 22:47:02
* @Last Modified time: 2022-04-25 22:47:09
*/
int lowerIndex(vector<int>& arr, int n, int x)
{
   int l = 0, h = n - 1;
   while (l <= h) {
      int mid = (l + h) / 2;
      if (arr[mid] >= x)
         h = mid - 1;
      else
         l = mid + 1;
   }
   return l;
}
 
int upperIndex(vector<int>& arr, int n, int y)
{
   int l = 0, h = n - 1;
   while (l <= h) {
      int mid = (l + h) / 2;
      if (arr[mid] <= y)
         l = mid + 1;
      else
         h = mid - 1;
   }
   return h;
}
 
int countInRange(vector<int>& arr, int n, int x, int y)
{
   
   int count = 0;
   count = upperIndex(arr, n, y) - lowerIndex(arr, n, x) + 1;
   return count;
}