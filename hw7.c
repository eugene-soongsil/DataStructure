#define MAX_DEGREE 100
#include <stdio.h>
#include <stdlib.h>

struct term{
    double coefficent;
    int exponent;
};

typedef struct Poly_type2{
    int numberofterms;
    struct term T[MAX_DEGREE];
} Poly2;

void print_Poly(Poly2* p){
    for(int i = 0; i < p->numberofterms; i++){
        printf("%.2fx^%d ", p->T[i].coefficent, p->T[i].exponent);
    }
    printf("\n\n");
}

void add_poly(Poly2* c, Poly2* a, Poly2* b){
    int indexa = 0, indexb = 0, indexc = 0;

    while(indexa < a->numberofterms && indexb < b->numberofterms){
        if(a -> T[indexa].exponent > b -> T[indexb].exponent){
            c ->T[indexc].coefficent = a->T[indexa].coefficent;
            c ->T[indexc].exponent = a -> T[indexa].exponent;
            indexa++;
            indexc++;
        }

        if (a->T[indexa].exponent < b->T[indexb].exponent) {
            c->T[indexc].coefficent = b->T[indexb].coefficent;
            c->T[indexc].exponent = b->T[indexb].exponent;
            indexb++;
            indexc++;
        }

        if(a->T[indexa].exponent == b->T[indexb].exponent){
            c->T[indexc].coefficent = a->T[indexa].coefficent + b->T[indexb].coefficent;
            c->T[indexc].exponent = a->T[indexa].exponent;
            indexa++;
            indexb++;
            indexc++;
        }
    }

    if(indexa == a->numberofterms && indexb < b->numberofterms){
        while(indexb < b->numberofterms){
            c->T[indexc].coefficent = b->T[indexb].coefficent;
            c->T[indexc].exponent = b->T[indexb].exponent;
            indexb++;
            indexc++;
        }
    }

    if(indexa < a->numberofterms && indexb == b->numberofterms){
        while(indexa < a->numberofterms){
            c->T[indexc].coefficent = a->T[indexa].coefficent;
            c->T[indexc].exponent = a->T[indexa].exponent;
            indexa++;
            indexc++;
        }
    }
    
    c->numberofterms = indexc;
}

int main(){
    Poly2 A, B, C;
    A.numberofterms = 3;
    A.T[0] = {8, 3};
    A.T[1] = {7, 1};
    A.T[2] = {1, 0};

    B.numberofterms = 4;
    B.T[0] = {10, 40};
    B.T[1] = {3, 4};
    B.T[2] = {2, 1};
    B.T[3] = {1, 0};

    print_Poly(&A);
    print_Poly(&B);
    
    add_poly(&C, &A, &B);
    print_Poly(&C);
}