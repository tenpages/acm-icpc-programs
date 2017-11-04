## [Word Ladder](https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=368&problem=2706)
### Description
You now work for a puzzle company. They have a puzzle they call a Word Ladder. A solver starts with a given starting word, and makes changes one letter at a time until s/he reaches a target word, with no word in the chain appearing more than once. There are three ways to take a single step from one word to another:

  *  Change one letter
  *  Add one letter
  *  Remove one letter

So, it's one step from COT to CAT, one step from CAT to SCAT, and one step from SCAT to SAT.


Here's a word ladder from COT to SCAT:


COT -> CAT -> SAT -> SCAT


Here's another word ladder from COT to SCAT:


COT -> CAT -> SCAT


The length of a word ladder is the number of words in it, so the examples above show a word ladder of length 4, and one of length 3. The second is the shortest possible between COT and SCAT. Shorter ladders are considered better than longer ladders.

The puzzle company knows that, given two words, a smart solver will always find the best ladder, which is the shortest ladder, between them. They want to give their solvers a challenge, so they are looking for long word ladders. Given a limited vocabulary, you need to tell them the length of the longest word ladder that a smart solver would find using only words in that vocabulary - that is, the longest of all best ladders. 

### Idea
Build a undirected graph of words, connected if they can be reached from each other in one step. Find the maximum of diameters of them amoung all connected components.

Notice that if there are duplicated words in the vocabulary, only keep one of them in the graph.