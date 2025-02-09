/**
 * @param {number} n
 * @param {number[][]} connections
 * @return {number}
 */
var minReorder = function(n, connections) {
    const adjList = [];

    for (let i = 0; i < n; i++) {
        adjList.push([])
    }

    let counter = 0;
    const visited = Array(n).fill(false);

    for (let [a, b] of connections) {
        adjList[a].push([b, 1]);
        adjList[b].push([a, 0]);
    }

    const traverse = (node) => {
        visited[node] = true;

        for (let [next, reversed] of adjList[node]) {
            if (!visited[next]) {
                counter += reversed;
                traverse(next);
            }
        }
    }

    traverse(0);

    return counter;
};