#define MAX 100
#include <iostream>
using namespace std;

class term{
    int exponent;
    double coefficient;

    public:
    term(double coeff, int exp){
        coefficient = coeff;
        exponent = exp;
    }
    int getExponent(){
        return exponent;
    }
    double getCoefficient(){
        return coefficient;
    }

    void setExponent(int exp){
        exponent = exp;
    }
    void setCoefficient(int coeff){
        coefficient = coeff;
    }
};

class Poly{
    int numberofterms;
    term* pTerm[MAX];

    public:
    poly(){
        numberofterms = 0;
    }

    void setNumberofTerms(int n){
        numberofterms = n;
    }
    int getNumberofTerms(){
        return numberofterms;
    }
    //새로운 term 객체를 만들고 pTerm에 대입(numberofterms가 가리키는 곳은 최상단 빈곳)
    void addTerm(double coeff, int exp){
        pTerm[numberofterms] = new term(coeff, exp);
        numberofterms++;
    }
    //why this??
    void printPoly(){
        for(int i = 0; i < this->numberofterms; i++){
            cout << pTerm[i]->getCoefficient() << "x^" << pTerm[i]->getExponent() << "+";
        }
        cout << endl;
    }
    

    void addPoly(Poly *a, Poly* b){
        int indexa = 0, indexb = 0;

         while (indexa < a->getNumberofTerms() && indexb < b->getNumberofTerms() ) {


            if (a->pTerm[indexa]->getExponent() > b->pTerm[indexb]->getExponent()) {
                this->addTerm ( a->pTerm[indexa]->getCoefficient(), a->pTerm[indexa]->getExponent() );
                indexa++;
            }

            if (a->pTerm[indexa]->getExponent() < b->pTerm[indexb]->getExponent()) {
                this->addTerm(b->pTerm[indexb]->getCoefficient(), b->pTerm[indexb]->getExponent());
                indexb++;
            }

            if (a->pTerm[indexa]->getExponent() == b->pTerm[indexb]->getExponent()) {
                this->addTerm( a->pTerm[indexa]->getCoefficient()+ b->pTerm[indexb]->getCoefficient(), a->pTerm[indexa]->getExponent());
                indexa++;
                indexb++;
            }

        }
                 
        if (indexa == a->getNumberofTerms() && indexb < b->getNumberofTerms() ) {
            while (indexb < b->getNumberofTerms() ) {
                this->addTerm (b->pTerm[indexb]->getCoefficient(), b->pTerm[indexb]->getExponent() );
                indexb++;
            }
        }

        if (indexa < a->getNumberofTerms() && indexb == b->getNumberofTerms()) {
            while (indexb < a->getNumberofTerms()) {
                this->addTerm(a->pTerm[indexb]->getCoefficient(), a->pTerm[indexb]->getExponent());
                indexa++;
            }
        }     
    
    }

};

int main(){
    Poly A, B;

    A.addTerm(8, 3);
    A.addTerm(7, 1);
    A.addTerm(1, 0);

    B.addTerm(10, 40);
    B.addTerm(3, 4);
    B.addTerm(2, 1);
    B.addTerm(1, 0);

    A.printPoly();
    B.printPoly();

    Poly C;
    C.addPoly(&A, &B);

    C.printPoly();
}
