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
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include "dispar.h"

bool intComparator (const int& a, const int& b) {
    return a > b;
}

int main(int argc, const char *argv[]) {
    std::vector<int> test_data(20);
    std::iota(test_data.begin(), test_data.end(), 0);

    std::function<bool (const int& a, const int& b)> comp = intComparator;
    size_t toto = 5;
    auto res = selection(toto, test_data, comp);

    for (auto&& key: res) {
        std::cout << key << std::endl;
    }
    return 0;
}

