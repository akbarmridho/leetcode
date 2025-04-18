from collections import deque

class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        stack = deque()
        stack.append(0)

        results = [0] * len(temperatures)

        for i in range(1, len(temperatures)):
            while stack and temperatures[stack[-1]] < temperatures[i]:
                # pop and set result
                pop_i = stack.pop()
                results[pop_i] = i - pop_i

            stack.append(i)

        return results

            