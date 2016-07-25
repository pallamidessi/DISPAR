#ifndef DISPAR_H
#define DISPAR_H

#include <omp.h>
#include <vector>
#include <functional>

#include "tournament.h"
#include "rand.h"

using matrix = std::vector<std::vector<int>>;

template<typename T>
matrix createRandomTournamentPool(T container,
                                  const size_t nbGroup,
                                  const size_t poolSize,
                                  Rand& rand) {

    std::vector<bool> bs(container.size());
    matrix pools(nbGroup);

    size_t cardinality = 0;

    for (auto&& pool: pools) {
        pool.reserve(poolSize);
    }

    while(cardinality < nbGroup * poolSize) {
        int v = rand.random_int(0, container.size() - 1);
        if(!bs[v]) {
            bs[v] = true;
            size_t poolNumber = cardinality / poolSize;
            size_t poolPosition = cardinality % poolSize;
            pools[poolNumber].push_back(v);
            cardinality++;
        }
    }

    return pools;
}

template<typename T, typename Alloc, template <typename, typename> class TT>
std::vector<int> selection(const size_t targetSize,
                           TT<T, Alloc> container,
                           std::function<bool (const T&, const T&)> comparator) {

    const size_t nbGroup = 4;
    const size_t poolSize = 5;

    std::vector<int> selected_keys(nbGroup);
    Rand rand;

    matrix pools = createRandomTournamentPool(container, nbGroup, poolSize, rand);
    for(auto&& pool: pools) {
        std::cout << "[" << std::endl;
        for (auto&& item : pool) {
            std::cout << item << ", ";
        }
        std::cout << "]\n" << std::endl;
    }
    #pragma omp parallel for
    for (size_t i = 0; i < pools.size(); i++) {
        selected_keys[i] = tournamentByKey<T, Alloc, TT>(container, pools[i],
                           comparator);
    }

    return selected_keys;
}

#endif /* end of include guard: DISPAR_H */
