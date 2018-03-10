#include <iostream>
#include <random>
#include "AliasSamplingGenerator.h"

using std::vector;
using std::string;
using std::cout;
using std::cerr;
using std::endl;

int main() {

    int n = 5;
    double weight[n]{0.1, 0.2, 0.3, 0.4, 0.5};

    vector<int> count(n, 0);

    AliasSamplingGenerator generator(n, weight);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0, 1.0);

    for (int i = 0; i < 100000; i++) {
        int index = generator.sample(dis(gen), dis(gen));
        if (index > n || index < 0) {
            std::cout << index << std::endl;
        }
        count[generator.sample(dis(gen), dis(gen))]++;
    }

    for (int i = 0; i < n; i++) {
        std::cout << i << ": " << count[i] << std::endl;
    }

    return 0;
}