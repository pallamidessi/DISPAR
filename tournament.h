/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 *
 * Copyright (C) Pallamidessi Joseph, 2016
 */


#ifndef TOURNAMENT_H
#define TOURNAMENT_H

#include <algorithm>
#include <vector>
#include <functional>

template <typename T, typename Alloc, template <typename, typename> class TT>
int tournamentByKey(const TT<T, Alloc>& fitnesses,
                    const std::vector<int>& keys,
                    std::function<bool (const T&, const T&)> comparator) {

    int bestIndex = keys[0];
    T bestFitness = fitnesses[keys[0]];
    for (size_t i = 0; i < keys.size(); i++) {
        if ( comparator(bestFitness, fitnesses[i]) ) {
            bestFitness = fitnesses[keys[i]];
            bestIndex = keys[i];
        }
    }

    return bestIndex;
}
#endif /* end of include guard: TOURNAMENT_H */
