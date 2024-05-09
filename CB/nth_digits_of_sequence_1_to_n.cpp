int getSpecialNumber(int n)
{
   
      ll len = 1;
      ll cnt = 9;
      ll start = 1;
      while(n > len * cnt){
         n -= len * cnt;
         cnt *= 10;
         start *= 10;
         len++;
      }
      start += (n - 1) / len;
      string s = to_string(start);
      return s[(n - 1) % len] - '0';
   
}

1234567891011121314....