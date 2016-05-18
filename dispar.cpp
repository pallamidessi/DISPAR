#include <bitset>
#include <vector>

using matrix = std::vector<std::vector<int>>;

template<typename T>
matrix createRandomTournamentPool(T container,
                                  const size_t nbGroup,
                                  const size_t poolSize) {

    std::bitset<1> bs(container.size());
    matrix pools(nbGroup);

    size_t cardinality = 0;

    for (auto&& pool: pools) {
        pool.reserve(poolSize);
    }

    while(cardinality < nbGroup * poolSize) {
        //int v = rand.nextInt(container.size());
        int v = 0;
        if(!bs[v]) {
            bs[v];
            cardinality++;
            pools[cardinality / poolSize][cardinality % poolSize] = v;
        }
    }

    return pools;
}



