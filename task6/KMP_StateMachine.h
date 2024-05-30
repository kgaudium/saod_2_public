//
// Created by Gaudium on 29.05.2024.
//

#ifndef SAOD_2_KMP_STATEMACHINE_H
#define SAOD_2_KMP_STATEMACHINE_H

#include "PF.h"

class KMP_StateMachine {
public:
    KMP_StateMachine(const char* s, int sz){
        state = 0;
        pf.Init(s, sz);
    }

    ~KMP_StateMachine(){
//        pf.~PF();
    }

    PF pf;
    int state;

};


#endif //SAOD_2_KMP_STATEMACHINE_H
