## [Trie, Trie Again](https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=333&page=show_problem&problem=2195)
### Description
Spark Plug Searching, Ltd., is looking to enter the market of web-based applications with a new word processor. The team implementing the spell checker have proposed storing the dictionary in a binary-encoded trie, a binary tree structure in which words are located by moving down the tree, one letter at a time, but discarding any letter from which one takes a right branch. 

The end of a word is indicated whenever a letter has no left child or by an @ character. This trie (in the diagram) contains the words a, abbot, abbey, abed, and bed.

Some team members have objected that the resulting data structure will be too large for practical use. Others have argued that the size can be dramatically reduced by taking advantage of the fact that many words end in common suffixes. The trie can be scanned for common subtrees and the parents of identical subtrees could be altered so that they all point to a single instance of that subtree. Your job is to demonstrate this process. Write a program to find the shared subtree that would produce the maximum reduction in the number of nodes if all instances of that subtree were replaced by a single shared instance.



### Idea
Counting the most frequent subtree in a trie. Frequency is defined as *(total appearing time - 1)\*(# of nodes in the subtree)*.

The trie is represented in a certain type of preorder form, transforming the problem to find the most frequent substring of a string, which has to be in the form of a tree, and follow a similiar definition of frequency.

Use KMP for string matching.