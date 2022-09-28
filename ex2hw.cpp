#include <bits/stdc++.h>
#include <mpi.h>
#define ll long long
#define ull unsigned long long
using namespace std;

int main()
{
    MPI_Init(NULL, NULL);
    int p, r;
    MPI_Comm_size(MPI_COMM_WORLD, &p);
    MPI_Comm_rank(MPI_COMM_WORLD, &r);
    if (r % 2)
        cout << r << " of " << p << ": "
             << "Hello" << endl;
    else
        cout << r << " of " << p << ": "
             << "World" << endl;

    MPI_Finalize();
}