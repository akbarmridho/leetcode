function calcEquation(equations: string[][], values: number[], queries: string[][]): number[] {
    const mapper: string[] = [... new Set(equations.reduce((prev, val) => {
        prev.push(...val);
        return prev;
    }, []))];

    const computed: number[][] = [];

    for (let i = 0; i < mapper.length; i++) {
        computed.push(new Array(mapper.length).fill(0));
        computed[i][i] = 1;
    }

    for (let i = 0; i < equations.length; i++) {
        const [a, b] = equations[i];
        const value = values[i];

        const aIdx = mapper.findIndex(e => e === a);
        const bIdx = mapper.findIndex(e => e === b);

        // fill initial values
        computed[aIdx][bIdx] = 1/value;
        computed[bIdx][aIdx] = value;
    }

    const visited = new Set<string>()

    // traverse each symbol
    /**
     *   a b c
     * a x x x
     * b 2 x x
     * c x 3 x
     * b/a[0,1] = 2, b/c[2,1] = 3
     * c/a[0,2] = [0,1]/[2,1] = 2/3
     * a/c[2,0] = [2,1]/[0,1] = 3/2
     */
    const traverse = (a: number, b: number) => {
        const key = `${Math.min(a,b)}-${Math.max(a,b)}`;
        
        if (visited.has(key)) {
            return;
        } else {
            visited.add(key);
        }

        // traverse horizontal
        for (let i = 0; i < mapper.length; i++) {
            if (i === b) {
                continue;
            }

            const firstVal = computed[a][b];
            const secondVal = computed[a][i];

            if (computed[b][i] === 0 && firstVal !== 0 && secondVal !== 0) {
                computed[b][i] = secondVal/firstVal;
                computed[i][b] = firstVal/secondVal;

                traverse(b, i);
            }
        }

        // traverse vertical
        for (let i = 0; i < mapper.length; i++) {
            if (i === a) {
                continue;
            }

            const firstVal = computed[a][b];
            const secondVal = computed[i][b];

            if (computed[a][i] === 0 && firstVal !== 0 && secondVal !== 0) {
                computed[a][i] = firstVal/secondVal;
                computed[i][a] = secondVal/firstVal;

                traverse(a, i);
            }
        }
    }

    // traverse
    for (let i = 0; i < equations.length; i++) {
        const [a, b] = equations[i];
        const value = values[i];

        const aIdx = mapper.findIndex(e => e === a);
        const bIdx = mapper.findIndex(e => e === b);

        traverse(aIdx, bIdx);
    }

    console.log(visited);
    console.log(mapper);

    for (const val of computed) {
        console.log(val);
    }

    return queries.map(([a, b]) => {
        const aIdx = mapper.findIndex(e => e === a);
        const bIdx = mapper.findIndex(e => e === b);

        if (aIdx === -1 || bIdx === -1) {
            return -1;
        }

        return computed[bIdx][aIdx];
    })
};