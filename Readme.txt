I'll be honest. I completely botched this project. 
I thought multithreaded parallel programming would be much easier than it was. I have a lot to learn.
The code I am submitting does not even work. 
I got a single-threaded version to work but could not get a multithreaded version to work.
I will explain my idea in the hopes of a tiny bit of partial credit.

I wanted to have a sieve that could go over a range instead of starting from zero. Then split up ranges throughout the cores
and run the prime checker on each of the ranges. 

However, the prime checker I originally coded did not work for ranges. So I searched for one online that could work with ranges. 
I found some but they were very inefficient. Even my current implementation is very inefficient. 

In terms of correctness, I feel I may have gotten 20% of the way there but it may as well have been 0 since the code does not work.

I debated sending in my single-threaded version but I feel that would be even dumber than this botched multithreaded one.

In terms of efficiency, there is nothing to say.

Experimental Evaluation: I did learn about the sieves for finding prime numbers but I do not understand why you would want to have a multithreaded
solution to finding primes. Maybe that is just because I could not make one though.
