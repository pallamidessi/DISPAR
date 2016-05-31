#include <omp.h>
#include "dispar.h"
#include "tournament.h"

template<typename T>
matrix createRandomTournamentPool(T container,
                                  const size_t nbGroup,
                                  const size_t poolSize) {

    std::vector<bool> bs(size);
    matrix pools(nbGroup);

    size_t cardinality = 0;

    for (auto&& pool: pools) {
        pool.reserve(poolSize);
    }

    while(cardinality < nbGroup * poolSize) {
        //int v = rand.random_int(offset, size - 1);
        int v = 0;
        if(!bs[v]) {
            bs[v];
            bs[v] = true;
            pools[cardinality / poolSize][cardinality % poolSize] = v;
            cardinality++;
        }
    }

    return pools;
}

template<typename T, typename Alloc, template <typename, typename> class TT>
std::vector<int> selection(const size_t targetSize,
                           TT<T, Alloc> container,
                           std::function<void (const T&, const T&)> comparator) {

    const size_t nbGroup = 1;
    const size_t poolSize = 5;

    std::vector<int> selected_keys;
    selected_keys.reserve(targetSize);

    matrix pools = createRandomTournamentPool(container, nbGroup, poolSize);

    #pragma omp parallel for
    for (int i = 0; i < pools.size(); i++) {
        selected_keys.push_back(tournament<TT, T>(container, pools[i], comparator));
    }

    return selected_keys;
}

