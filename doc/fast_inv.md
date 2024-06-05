---
title: fast mod_inv 
documentation_of: //NT/Fast_NT/fast_modinv.hpp
---

## Description:
-Optimized version of normal modulo inverse, notice the modulus is odd and less than 2^30<br>
-AC in problem normal modulo inverse: a⋅x≡1(mod m)<br>
-Not all cases faster than normal mod_inv but still good for big number than normal mod_inv
## Usage:

* fast_modinv inve(mod);
* inve.inv(a)

