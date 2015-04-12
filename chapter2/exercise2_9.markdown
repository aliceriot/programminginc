#Exercise 2-9

This one asks us to explain why x &= (x-1) deletes the rightmost 1-bit in
x. Let's consider a little example:
    
    x = 11 = 1011
    x &= x-1 == 1011 &= 1010 = 1010

We can see that this follows from the way that we define &, where
0 & 0 = 0, 1 & 1 = 1, but a mismatch always gives zero.

So since decrementing x will always change some bits, we can follow what
will happen. In the case that the last bit of x is a 1, then that will
just become a zero in x-1 and 1 & 0 will give 0, deleting the last bit.

In the (slightly more complicated) case that the last digit is not 1,
consider the case where we have to go to the nth bit to find a 1. Then
bits 0 through n-1 will be zeros in x, otherwise they would have been bit
n (i.e. we would have found a 1 there). Then when we take x-1 bit n will
swap from a 1 to a zero, and bits 0 through n-1 will flip from 0 to 1.
Then for bit n we have 1(x) and 0(x-1) which gives 0, and for bits
0 through n-1 we have 0(x) and 1(x-1) which again gives 0, so our result
is that for all positions after n we have the same pattern as in our
original x, and the only change we've made is in the nth x.
