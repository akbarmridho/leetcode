from typing import List, DefaultDict, Dict, Set
from sortedcontainers import SortedList
from collections import defaultdict


class MovieRentingSystem:
    # key movie # value List of (price, shop)
    unrented_by_movies: DefaultDict[int, SortedList]
    # list of value (price, shop, movie)
    rented: SortedList
    # movie => [shop => price]
    movie_shop_price: DefaultDict[int, Dict[int, int]]

    def __init__(self, n: int, entries: List[List[int]]):
        self.unrented_by_movies = defaultdict(SortedList)
        self.rented = SortedList()
        self.movie_shop_price = defaultdict(dict)

        for shop, movie, price in entries:
            self.unrented_by_movies[movie].add((price, shop))
            self.movie_shop_price[movie][shop] = price

    def search(self, movie: int) -> List[int]:
        unrented = self.unrented_by_movies[movie]
        return [e[1] for e in unrented[: min(5, len(unrented))]]

    def rent(self, shop: int, movie: int) -> None:
        entries = self.unrented_by_movies[movie]
        price = self.movie_shop_price[movie][shop]

        entries.remove((price, shop))
        self.rented.add((price, shop, movie))

    def drop(self, shop: int, movie: int) -> None:
        price = self.movie_shop_price[movie][shop]
        self.rented.remove((price, shop, movie))
        self.unrented_by_movies[movie].add((price, shop))

    def report(self) -> List[List[int]]:
        rented = self.rented[: min(5, len(self.rented))]
        return [[e[1], e[2]] for e in rented]
