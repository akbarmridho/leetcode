function findCircleNum(isConnected: number[][]): number {
    const queue: number[] = [];
    const visited = new Set<number>();

    for (let i = 0; i < isConnected.length; i++) {
        queue.push(i);
    }

    let provinceCount = 0;

    while (queue.length !== 0) {
        const val = queue.shift();

        const toVisitNodes: number[] = [];

        toVisitNodes.push(val);

        while (toVisitNodes.length !== 0) {
            const idx = toVisitNodes.shift();
            visited.add(idx);

            for (let i = 0; i < isConnected.length; i++) {
                if (isConnected[idx][i] === 0) {
                    continue;
                }

                if (visited.has(i)) {
                    continue;
                }

                toVisitNodes.push(i);
                const toDeleteIdx = queue.findIndex(e => e === i);

                if (toDeleteIdx !== -1) {
                    queue.splice(toDeleteIdx, 1);
                }
            }
        }

        provinceCount++;
    }

    return provinceCount;
};