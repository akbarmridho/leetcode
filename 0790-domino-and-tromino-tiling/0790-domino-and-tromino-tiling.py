class Solution:
    def numTilings(self, n: int) -> int:
        g, u = [0]*(1001), [0]*(1001)
        g[0], g[1], g[2] = 0, 1, 2
        u[0], u[1], u[2] = 0, 1, 2
        mod = 1000000007

        for i in range(3, n+1):
            u[i] = (g[i-1] + u[i-1]) % mod
            g[i] = (g[i-1] + g[i-2] + 2*u[i-2]) % mod
    
        return g[n] % mod

