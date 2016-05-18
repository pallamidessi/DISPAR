#ifndef DISPAR_H
#define DISPAR_H

#include <bitset>
#include <vector>
#include <functional>

using matrix = std::vector<std::vector<int>>;

template<typename T>
matrix createRandomTournamentPool(T container,
                                  const size_t nbGroup,
                                  const size_t poolSize);


template<typename T, typename Alloc, template <typename, typename> class TT>
std::vector<int> selection(const size_t targetSize,
                           TT<T, Alloc> container,
                           std::function<void (const T&, const T&)> comparator);

#endif /* end of include guard: DISPAR_H */
