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


#include <algorithm>
#include <vector>
#include <functional>

template <typename T, typename Alloc, template <typename, typename> class TT>
int tournament(const int nbParents,
               const TT<T, Alloc>& fitnesses,
               const int pressure,
               std::function<bool (const T&, const T&)> comparator) {

    std::vector<int> selected;
    for (int i = 0; i < pressure; i++) {
        //selected.push_back(rand.random_int(0, nbParents - 1));
    }

    int bestIndex = selected[0];
    T bestFitness = fitnesses[selected[0]];
    for (int i = 0; i < selected.size(); i++) {
        if ( comparator(bestFitness, fitnesses[i]) ) {
            bestFitness = fitnesses[selected[i]];
            bestIndex = selected[i];
        }
    }

    return bestIndex;
}
