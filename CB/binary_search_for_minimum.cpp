while(low<=high)
      {
          ll mid=(low+high)/2;
         
          if(check(mid))
            high=mid-1;
          else
            low=mid+1;
      }