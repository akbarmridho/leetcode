interface Point {
    row: number;
    col: number;
}

interface Queue {
    prev: Point;
    current: Point;
    steps: number;
}

function nearestExit(maze: string[][], entrance: number[]): number {
    const rowLength = maze.length;
    const colLength = maze[0].length;

    const isExit = (point: Point): boolean => {
        return point.row === 0 || point.row === (rowLength - 1) || point.col === 0 || point.col === (colLength - 1);
    }

    let result: number | null = null;

    const queue: Queue[] = [{
        prev: {row: -1, col: -1},
        current: {row: entrance[0], col: entrance[1]},
        steps: 0
    }];

    while (queue.length !== 0) {
        const {current, prev, steps} = queue.shift();

        if (maze[current.row][current.col] === '+') {
            continue;
        }

        maze[current.row][current.col] = '+';

        console.log(`visiting ${current.row},${current.col} prev ${prev.row},${prev.col} steps ${steps}`)

        if (isExit(current) && (current.row !== entrance[0] || current.col !== entrance[1])) {
            if (result === null) {
                result = steps;
            } else if (steps < result) {
                result = steps;
            }
            continue;
        }

        if (current.col - 1 >= 0 && prev.col !== current.col - 1 && maze[current.row][current.col - 1] === ".") {
            queue.push({prev: current, current: {row: current.row, col: current.col - 1}, steps: steps + 1});
        }

        // move right
        if (current.col + 1 < colLength && prev.col !== current.col + 1 && maze[current.row][current.col + 1] === ".") {
            queue.push({prev: current, current: {row: current.row, col: current.col + 1}, steps: steps + 1});
        }

        // move up
        if (current.row - 1 >= 0 && prev.row !== current.row - 1  && maze[current.row - 1][current.col] === ".") {
            queue.push({prev: current, current: {row: current.row-1, col: current.col}, steps: steps + 1});
        }

        // move down
        if (current.row + 1 < rowLength && prev.col !== current.row + 1 && maze[current.row + 1][current.col] === ".") {
            queue.push({prev: current, current: {row: current.row+1, col: current.col}, steps: steps + 1});
        }
    }

    if (result === null) {
        return -1;
    }

    return result;
};