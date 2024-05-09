while(low<=high)
      {
          ll mid=(low+high)/2;
         
          if(check(mid))
            low=mid+1;
          else
            high=mid-1;
      }