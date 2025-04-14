from typing import Dict


class Trie:
    children: Dict[str, "Trie"]
    is_word: bool

    def __init__(self):

        self.children = {}
        self.is_word = False

    def insert(self, word: str) -> None:
        if len(word) == 0:
            self.is_word = True
            return

        ch = word[0]

        if ch not in self.children:
            self.children[ch] = Trie()

        self.children[ch].insert(word[1:])

    def search(self, word: str) -> bool:
        if len(word) == 0:
            return self.is_word

        ch = word[0]

        if ch in self.children:
            return self.children[ch].search(word[1:])

        return False

    def startsWith(self, prefix: str) -> bool:
        if len(prefix) == 0:
            return True

        ch = prefix[0]

        if ch in self.children:
            return self.children[ch].startsWith(prefix[1:])

        return False
