function orangesRotting(grid: number[][]): number {
    let loop = 0;
    let remainingFresh = 0;

    const rowLength = grid.length;
    const colLength = grid[0].length;

    const queue: number[][][] = [];

    const currentBatch: number[][] = []

    for (let i = 0; i < grid.length; i++) {
        for (let j = 0; j < grid[0].length; j++) {
            const value = grid[i][j];

            if (value === 1) {
                remainingFresh++;
            } else if (value === 2) {
                currentBatch.push([i, j]);
            }
        }
    }

    queue.push(currentBatch)

    const offsetList = [[1,0], [0,1], [-1,0], [0,-1]];

    while (remainingFresh !== 0 && queue.length !== 0) {
        loop++;
        // console.log(`Loop ${loop}`)
        // console.log(JSON.stringify(grid));
        // console.log(JSON.stringify(queue));

        const batch = queue.shift();
        const nextBatch: number[][] = [];

        while (batch.length !== 0) {
            const value = batch.shift();

            // check for surrounding
            for (const offset of offsetList) {
                const row = value[0] + offset[0];
                const col = value[1] + offset[1];

                if (row < 0 || row >= rowLength || col < 0 || col >= colLength) {
                    continue;
                }

                if (grid[row][col] === 1) {
                    nextBatch.push([row, col]);
                    grid[row][col] = 2;
                    remainingFresh--;
                }
            }
        }

        if (remainingFresh === 0) {
            break;
        }

        if (nextBatch.length > 0) {
            queue.push(nextBatch);
        }
    }

    return remainingFresh > 0 ? -1 : loop;
};