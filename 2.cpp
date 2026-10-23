#include <iostream>
using namespace std;

int U[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int not_set(int x[], int n, int res[]) {
    int k = 0;
    for (int i = 0; i < 10; i++) {
        bool found = 0;
        for (int j = 0; j < n; j++)
            if (U[i] == x[j])
                found = 1;
        if (!found)
            res[k++] = U[i];
    }
    return k;
}

int main() {
    int A[10] = {1, 2, 3, 4, 5, 6, 7};
    int B[10] = {4, 5, 6, 7, 8, 9, 10};
    int C[10] = {1, 3, 5, 7, 9};
    int nA = 7, nB = 7, nC = 5;

    int notA[10], notB[10], notC[10];
    int nNotA, nNotB, nNotC;

    nNotA = not_set(A, nA, notA);
    nNotB = not_set(B, nB, notB);
    nNotC = not_set(C, nC, notC);
// !(A обєднанняч !B)
    int t1[10], n1 = 0;
    for (int i = 0; i < nA; i++)
        t1[n1++] = A[i];
    for (int i = 0; i < nNotB; i++) {
        bool found = 0;
        for (int j = 0; j < n1; j++)
            if (notB[i] == t1[j])
                found = 1;
        if (!found)
            t1[n1++] = notB[i];
    }
    int t2[10];
    int n2 = not_set(t1, n1, t2);

    //F1 / !A
    int t3[10], n3 = 0;
    for (int i = 0; i < n2; i++) {
        bool found = 0;
        for (int j = 0; j < nNotA; j++)
            if (t2[i] == notA[j])
                found = 1;
        if (!found)
            t3[n3++] = t2[i];
    }

    //!c оюєднання A
    int t4[10], n4 = 0;
    for (int i = 0; i < nNotC; i++) {
        bool found = 0;
        for (int j = 0; j < nA; j++)
            if (notC[i] == A[j])
                found = 1;
        if (found)
            t4[n4++] = notC[i];
    }

    // F1 викмнож F2
    int res[10], nres = 0;
    for (int i = 0; i < n3; i++) {
        bool found = 0;
        for (int j = 0; j < n4; j++)
            if (t3[i] == t4[j])
                found = 1;
        if (!found)
            res[nres++] = t3[i];
    }
    for (int i = 0; i < n4; i++) {
        bool found = 0;
        for (int j = 0; j < n3; j++)
            if (t4[i] == t3[j])
                found = 1;
        if (!found)
            res[nres++] = t4[i];
    }
    cout<< "{ ";
    for (int i = 0; i < nres; i++)
        cout << res[i] << " ";

   cout << "}"<< endl;

    return 0;
}
