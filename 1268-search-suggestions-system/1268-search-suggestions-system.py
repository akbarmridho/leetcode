from typing import List, Dict


class TrieNode:
    isWord: bool
    nodes: Dict[str, "TrieNode"]
    top_search: List[str]

    def __init__(self, parent=None):
        self.isWord = False
        self.nodes = {}
        self.parent = parent
        self.top_search = []

    def propagate(self, word: str):
        self.top_search.append(word)
        self.top_search.sort()
        self.top_search = self.top_search[: min(len(self.top_search), 3)]

        if self.parent is not None:
            self.parent.propagate(word)


class Trie:
    def __init__(self):
        self.root = TrieNode()

    # Inserts a word into the trie.
    def insert(self, word: str) -> None:
        cur = self.root

        for c in word:
            if c not in cur.nodes:
                cur.nodes[c] = TrieNode(cur)
            cur = cur.nodes[c]

        cur.isWord = True
        cur.propagate(word)

    def suggest(self, prefix: str) -> List[str]:
        cur = self.root

        for c in prefix:
            if c not in cur.nodes:
                return []
            cur = cur.nodes[c]

        return cur.top_search


class Solution:
    def suggestedProducts(
        self, products: List[str], searchWord: str
    ) -> List[List[str]]:
        t = Trie()

        for product in products:
            t.insert(product)

        result = []

        for i in range(len(searchWord)):
            prefix = searchWord[: i + 1]
            result.append(t.suggest(prefix))

        return result
