#include <iostream>
#include "MLS.h"

int main() {
    MLS mls{15}; //MLS信号のコンストラクタを呼ぶ（引数はシフトレジスタの次数）

    for (int i = 0; i < 100; ++i) {
        int x = mls.SignalGet();    //MLS信号は関数を呼ぶたびに次の値を返す
        std::cout << x << std::endl;
    }

    return 0;
}
