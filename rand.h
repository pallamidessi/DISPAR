#pragma once
#include <algorithm>
#include <functional>
#include <random>
#include <ctime>

class Rand {
    std::mt19937 m_gen;

  public:

    Rand(): m_gen() {

        std::array<int, std::mt19937::state_size> seed_data;
        std::random_device r;

        std::srand(std::time(0));
        std::generate_n(seed_data.begin(), seed_data.size(), std::rand);

        std::seed_seq seq(std::begin(seed_data), std::end(seed_data));
        m_gen = std::mt19937(seq);
    }

    template <typename T>
    inline int random_int(T min, T max) {
        std::uniform_int_distribution<T> dist(min, max);
        return dist(m_gen);
    }

    inline float random_float(float min, float max) {
        std::uniform_real_distribution<float> dist(min, max);
        return dist(m_gen);
    }

    inline int random_int(int min, int max) {
        return random_int<int>(min, max);
    }

    inline bool toss_coin(float bias = 0.5f) {
        return random_float(0.0f, 1.0f) < bias;
    }

    inline int random_normal_int(int min, int max) {
        std::normal_distribution<> dist(min, max);
        return dist(m_gen);
    }

    template <typename IterT>
    void shuffle(IterT begin, IterT end) {
        std::random_shuffle(begin, end);
    }
};

