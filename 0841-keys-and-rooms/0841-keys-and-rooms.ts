function canVisitAllRooms(rooms: number[][]): boolean {
    const unusedKeys: number[] = [];
    const obtainedKeys = new Set<number>();
    let visitedCount = 0;
    
    unusedKeys.push(0);
    obtainedKeys.add(0);

    while (unusedKeys.length !== 0) {
        const idx = unusedKeys.pop();
        const keys = rooms[idx];
        visitedCount++;

        keys.forEach(e => {
            if (!obtainedKeys.has(e)) {
                obtainedKeys.add(e);
                unusedKeys.push(e);
            }
        })
    }

    return visitedCount === rooms.length;
};