/*!
 * @file    MLS.h
 * @brief   M系列信号を生成するクラス（mbed版）
 * @author  G.Sasaki
 * @date    2021/2/18
 * */

#ifndef MSEQUENCE_H
#define MSEQUENCE_H

#include <iostream>
#include <cmath>
#include <cstdint>
#include <vector>
#include <numeric>
#include <iterator>

/*!
 * @brief M系列信号を生成するクラス
 * */
class MLS {
public:
    explicit MLS(int ShiftRegister);
    ~MLS() = default;
    int SignalGet();

private:
	void SignalGenerate();

    int N;  //!<シフトレジスタの数
    int L;  //!<MLSの長さ

    std::vector<int> F; //!<係数
    std::vector<int> D; //!<MLSを格納するベクタ

    bool done_flag = false; //!<MLS生成終了フラグ

};


#endif //MSEQUENCE_H
