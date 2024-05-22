---
documentation_of: //DS/Sparse_table.hpp
---

## Description:
Range Minimum Queries on an array. Returns min(V[a], V[a + 1], ... V[b - 1]) in constant time.
Also work for max queries
## Usage:

*  RMQ rmq(values);
*  rmq.query(inclusive, exclusive);

## Time:
* $O(V\log(V)+Q)$
