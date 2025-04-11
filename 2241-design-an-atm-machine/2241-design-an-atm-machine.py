from typing import List


class ATM:
    notes: List[int]
    values: List[int]

    def __init__(self):
        self.notes = [0, 0, 0, 0, 0]
        self.values = [20, 50, 100, 200, 500]

    def deposit(self, banknotesCount: List[int]) -> None:
        for i in range(len(self.notes)):
            self.notes[i] += banknotesCount[i]

        print("notes")
        print(self.notes)

    def withdraw(self, amount: int) -> List[int]:
        remaining = amount
        used = [0, 0, 0, 0, 0]

        for i in range(4, -1, -1):
            if self.notes[i] == 0:
                continue

            count = remaining // self.values[i]

            if count != 0 and self.notes[i] >= count:
                used[i] = count
                remaining = remaining % self.values[i]

        print("notes")
        print(self.notes)

        if remaining != 0 or sum(used) == 0:
            return [-1]

        for i in range(len(self.notes)):
            self.notes[i] -= used[i]

        return used