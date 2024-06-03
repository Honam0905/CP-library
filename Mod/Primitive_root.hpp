#pragma once
#include "NT/prime/factorize.hpp"
u64 PrimitiveRoot(u64 p){
   u64 x=0;
   auto mi=factor(p-1);
   sort(all(mi));
   Barrett_u64 br;
   br.set(p);
   mi.resize(unique(all(mi))-mi.begin());
   for(int i=0;!i;){
      i=1; ++x;
      for(u64 f:mi){
         if(pow_b64(&br,x,(p-1)/f)==1){
            i=0; 
            break;
         }
      }
   }
   return x;
}
