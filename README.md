Pattern searching is a classic problem in competitive programming where you need to find if a particular string is actually a substring of another string. Given that S="abdsddddool", S1="ddo", S2="dol". S1 is a substring of S, but S2 isn't.

In order to maintain time and memory, especially if you have *t* testcases and you need to find if each of *q* strings is a substring of *s* or not. You can't run through *s* in each query *q*.

The solution breaks into two main ideas:
1) Hashing the lower english characters with proper hash funciton to avoid collisions. It acts like giving each character a primary key to uniquely define it with.
2) Avoid running through *s* in each query where we save the index (appearance) of each character of *s*
3) Direct comparison of the substring *q* that has a unique sum according to hash, with an already prepared prefix sum of *s* (cummulative sum).

The total time complexity is *O(t * (len1 + q * len2))*. Where len1 is the length of string *s*, len2 is the length of string *q*, *t* is the number of test cases and *q* is the number of queries (substrings).
