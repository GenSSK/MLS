//
// Created by Genki Sasaki on 2021/02/18.
//

#ifndef PCT_ARCS6_MSEQUENCE_H
#define PCT_ARCS6_MSEQUENCE_H

#include <iostream>
#include <cmath>
#include <cstdint>
#include <vector>
#include <numeric>
#include <iterator>
#include <random>

class MLS {
public:
    //! @brief Constructor
    explicit MLS(int ShiftRegister);
    //! @brief Destructor
    ~MLS();
    void SignalGenerate();
    int SignalGet();

private:
    int N;  // Shift Register
    int L;  // Long

    std::vector<int> F;
    std::vector<int> D;

    bool done_flag = false;

    std::random_device rnd;
    std::mt19937 mt;
    std::uniform_int_distribution<int> rand_tar;
    
};


#endif //PCT_ARCS6_MSEQUENCE_H
