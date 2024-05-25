---
title: Segment tree
documentation_of: //DS/Segment_tree.hpp
---

## Description:
Segment tree with fast optimization and based on
Atcoder segment tree

## Usage:

* define op() for operation and e() for identity element
* SegTree<>st(size,op,e)

## Time:
* $O(n)$ for build()
* $O(log(n))$ for add(),modify(),query()
