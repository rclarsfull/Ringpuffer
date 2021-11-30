#include <iostream>
using namespace std;
class Ringpuffer {


    
    int* puffer;
    bool* status;
    int leseKopfPos, schreibKopfPos;
    int size;

    Ringpuffer(int s) {
        size = s;
        puffer = new int[size];
        status = new bool[size];
        leseKopfPos = 0;
        schreibKopfPos = 0;
        for (int i = 0; i < size; i++) {
            status[i] = false;
            puffer[i] = 0;
        }
    }

    bool schreiben(int z) {
        if (schreibKopfPos >= size) schreibKopfPos = 0;
        if (!status[schreibKopfPos]) {
            puffer[schreibKopfPos] = z;
            status[schreibKopfPos] = true;
            schreibKopfPos++;
            return true;
        }
        return false;
    }

    int lesen() {
        if (leseKopfPos >= size) leseKopfPos = 0;
        if (status[leseKopfPos]) {
            int ausgabe = puffer[leseKopfPos];
            status[leseKopfPos] = false;
            leseKopfPos++;
            return ausgabe;
        }
        return -1;
    }


};

