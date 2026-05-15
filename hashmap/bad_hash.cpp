#include<iostream>
using namespace std;


int bad_hash(int key) {
    return key % 10;  // All even numbers → even buckets
}

// GOOD: Multiplies by prime, spreads distribution
int good_hash(int key) {
    return (key * 2654435761UL) >> 32;  // Fibonacci hashing
}
int  main()
{

for (int i =0; i< 10;i++)
cout<< "i=" << i << "==" << bad_hash(i)<<"  Good=" << good_hash(i)<< endl;

return 0;
}
