/* 
 * File:   Negotiation.c
 * Author: varamadem
 *
 * Created on December 4, 2022, 2:32 PM
 */

#include <stdlib.h>
#include <stdio.h>
#include "Negotiation.h"

NegotiationData NegotiationHash(NegotiationData secret){
    return ((secret * secret) % PUBLIC_KEY);
}

int NegotiationVerify(NegotiationData secret, NegotiationData commitment){
    NegotiationData Temp = secret*secret % PUBLIC_KEY;
    return (Temp == commitment);
}

NegotiationOutcome NegotiateCoinFlip(NegotiationData A, NegotiationData B){
    NegotiationData result = A ^ B;
    int counter = 0;
    while(result != 0){
        if (result%2 == 1)
            counter++;
        result/= 2;
    }
    if (counter % 2)
        return HEADS;
    else 
        return TAILS;
}
