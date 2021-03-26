//
// Created by Genki Sasaki on 2021/02/18.
//

#include "MLS.h"
#include <time.h>


//! @brief Constructor of MLS
//! @param[in]	Number of shift register
MLS::MLS(const int ShiftRegister) :
        mt(rnd()),
        rand_tar(0, 1),
        F(ShiftRegister, 0),
        D((int)(std::pow(2, ShiftRegister) - 1), 0) {

    N = ShiftRegister;
    L = (int) std::pow(2, N) - 1;
    SignalGenerate();
}

//! @brief Destructor
MLS::~MLS() = default;


//! @brief MLS generate function
void MLS::SignalGenerate() {

    while (!done_flag) {
        std::vector<int> judge(N, 0);
        while (1) {
            srand((unsigned int) time(NULL));
            int x = 0, y = 0, z = 0;
            for (int i = 0; i < N; i++) {
                F[i] = rand_tar(mt);
                F[0] = 1;
                D[i] = rand_tar(mt);
                x += D[i];
                y += F[i];
                z += D[i] * F[i];
            }
            if (x > 0 && x < N && y > 0 && y < N && z > 0 && z < N) break;
        }

        for (int i = N; i < L; ++i) {
            int buf = 0;
            int buf2 = 0;
            buf = D[i - N] * F[0];
            for (int j = 1; j < N; j++) {
                buf = (buf + (D[i - N + j] * F[j])) % 2;
            }
            D[i] = buf;
        }

        auto v1 = std::next(D.begin(), 0);

        for (int i = 0; i < L - N; ++i) {
            if (std::accumulate(std::next(v1, i), std::next(v1, i + N), 0) == N){
                for (int i = 0; i < L - N + 1; ++i) {
                    if (std::accumulate(std::next(v1, i), std::next(v1, i + N - 1), 0) == 0){
                        if (std::accumulate(std::next(v1, 0), std::next(v1, L), 0) == (L + 1) / 2)done_flag = true;
                    }
                }
            }
        }
    }

}


//! @brief Constructor of MLS
//! @param[in]	Number of shift register
int MLS::SignalGet() {
    static int i = 0;
    int x = D[i];

    i++;
    if (i == L) i = 0;

    return x;
}