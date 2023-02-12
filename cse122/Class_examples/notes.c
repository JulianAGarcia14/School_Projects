Binary Search:
T(0) = 1
T(1) = 2 (for worst case with array of 2)
T(n) = T(n/2) + c

(unroll)
T(n/2) = T(n/4) + c
T(n) = T(n/4) + 2c
do more...

T(n) = T(n/2^k) + kc

n = 2^k, k = logn

T(n) = 1 + logn(c)

O(logn)

Extra:
T(n) = T(n/2) + d = logn + 2

T(n) = T(n/2) + 1
     =[log(n/2) + 2] + 1
     =[logn -log2 + 2] 1
     =[logn - 1 + 2] + 1
     =logn + 2
     O(logn)


Power function:

long power(long x, long n)
	if(n ==0) return 1;
	if(n==1) return x;
	if((n%2) == 0 )
		return power(power(x,n/2), x)
	else
		return power(power(x,n/2), x) * x
