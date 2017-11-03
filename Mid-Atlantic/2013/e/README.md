## [Ping!](https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=618&page=show_problem&problem=4495)
### Description
Suppose you are tracking some satellites. Each satellite broadcasts a `Ping' at a regular interval, and
the intervals are unique (that is, no two satellites ping at the same interval). You need to know which
satellites you can hear from your current position. The problem is that the pings cancel each other out.
If an even number of satellites ping at a given time, you won't hear anything, and if an odd number
ping at a given time, it sounds like a single ping. All of the satellites ping at time 0, and then each
pings regularly at its unique interval.
Given a sequence of pings and non-pings, starting at time 0, which satellites can you determine
that you can hear from where you are? The sequence you're given may, or may not, be long enough to
include all of the satellites' ping intervals. There may be satellites that ping at time 0, but the sequence
isn't long enough for you to hear their next ping. You don't have enough information to report about
these satellites. Just report about the ones with an interval short enough to be in the sequence of pings.

### Idea
Interesting small tricks.
Scan through time frame 1 to maximum. For time frame *k*, if it's 0, do nothing; if it is 1, meaning there is one satellite whose interval length is *k*, we can now delete this satellite from the set by reverse status of all time frame *t* that is divisible by *k* (1 to 0 and 0 to 1).