const int MAXN = 1e6;

long long fac[MAXN + 1];
long long inv[MAXN + 1];

/** Computes x^n modulo m in O(log p) time. */
long long exp(long long x, long long n, long long m) {
	x %= m;  // note: m * m must be less than 2^63 to avoid ll overflow
	long long res = 1;
	while (n > 0) {
		if (n % 2 == 1) { res = res * x % m; }
		x = x * x % m;
		n /= 2;
	}
	return res;
}

//length of number.
int numberLength(ll number) {
    return (number == 0) ? 1 : log10(llabs(number)) + 1;
}

/** Precomputes n! from 0 to MAXN. */
void factorial(long long p) {
	fac[0] = 1;
	for (int i = 1; i <= MAXN; i++) { fac[i] = fac[i - 1] * i % p; }
}

/**
 * Precomputes all modular inverse factorials
 * from 0 to MAXN in O(n + log p) time
 */
void inverses(long long p) {
	inv[MAXN] = exp(fac[MAXN], p - 2, p);
	for (int i = MAXN; i >= 1; i--) { inv[i - 1] = inv[i] * i % p; }
}

/** Computes nCr mod p */
long long choose(long long n, long long r, long long p) {
	return fac[n] * inv[r] % p * inv[n - r] % p;
}