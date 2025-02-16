interface Pair {
    v1: number;
    v2: number;
}

function maxScore(nums1: number[], nums2: number[], k: number): number {
    const values: Pair[] = nums1.map((num1, i) => {
        return {
            v1: num1,
            v2: nums2[i]
        }
    });

    values.sort((a, b) => {
        return b.v2 - a.v2;
    });

    // initial value
    let result: number = 0;

    for (let i = 0; i < k; i++) {
        result += values[i].v1;
    }

    result = result * values[k-1].v2;

    // priority queue values of v1 just before index k
    const prioQueue: number[] = [];

    for (let i = 0; i < k; i++) {
        prioQueue.push(values[i].v1);
    }

    prioQueue.sort((a,b) => b-a); // sort desc

    const insertPrioQueue = (val: number) => {
        for (let i = 0; i < prioQueue.length; i++) {
            if (val > prioQueue[i]) {
                prioQueue.splice(i, 0, val);
                return;
            }
        }
    }

    for (let i = k; i < values.length; i++) {
        let currentResult = values[i].v1;

        for (let j = 0; j < k -1; j++) {
            currentResult += prioQueue[j]
        }

        currentResult *= values[i].v2;

        if (currentResult > result) {
            result = currentResult;
        }

        insertPrioQueue(values[i].v1);
    }

    return result;
};