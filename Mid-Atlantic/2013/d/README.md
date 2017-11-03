## [Count Your Cousins](https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=618&page=show_problem&problem=4559)
### Description
"*Cousins*" of a node on a tree are nodes with same grandparent but different parents. Given a tree and a node, give the number of cousins of the node.

### Idea
Use pointers pointing at grandparent and parent and set up counters. Solve it in $O(n)$ time by scanning through the given sequence representation of the tree.