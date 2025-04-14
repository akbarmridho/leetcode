class Solution:
    def minFlips(self, a: int, b: int, c: int) -> int:
        a_bit = f"{a:032b}"
        b_bit = f"{b:032b}"
        ab_bit = f"{a|b:032b}"
        c = f"{c:032b}"

        n = 0

        for i in range(32):
            if c[i] == "1":
                # need either to be one
                if ab_bit[i] == "0":
                    n += 1
            else:
                if a_bit[i] == "1":
                    n += 1
                
                if b_bit[i] == "1":
                    n += 1
        
        return n