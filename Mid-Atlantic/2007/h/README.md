## [The Turn of the Shrew](https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=297&page=show_problem&problem=1927)
### Description
 Dr. Montgomery Moreau has been observing a population of Northern Madagascar Pie-bald Shrews in the wild for many years. He has made careful observations of all the shrews in the area, noting their distinctive physical characteristics and naming each one.

He has made a list of significant physical characteristics (e.g., brown fur, red eyes, white feet, prominent incisor teeth, etc.) and taken note of which if these appear to be dominant (if either parent has this characteristic, their children will have it.

In recent years he has begun to suspect that the shrew population has been undergoing a high rate of genetic mutation (possibly due to that strange glowing rock near their communal burrow). When the shrews emerged from their burrow at the end of the past winter, he noted quite a few new youngsters whose physical characteristics did not match up with any possible pair of prospective parents.

Write a program to determine the smallest number of mutations for each juvenile shrew that would account for its possible parentage. 



### Idea
Representing genetic code with 0/1 leads to bitmask compression. Then do bit operations:

   * Copulation <==> bitwise or, and
   * Checking different <==> bitwise xor.

Simply find all possible results of combinations of male and female identities. Check every possible result with every child identities to find the minimum possible mutations on each child.