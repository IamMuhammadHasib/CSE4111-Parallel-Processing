#include <bits/stdc++.h>
#include <mpi.h>
using namespace std;

int a, b;

int main(int argc, char **argv)
{
    MPI_Init(NULL, NULL);
    // int aa, bb;
    // scanf("%d %d", &aa, &bb);

    a = 5;
    b = 8;

    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0)
    {
        printf("[Rank %d] Addition: %d\n", rank, a + b);
    }
    else if (rank == 1)
        printf("[Rank %d] Substraction: %d\n", rank, a - b);
    else if (rank == 2)
        printf("[Rank %d] Multiplication: %d\n", rank, a * b);
    else if (rank == 3)
        printf("[Rank %d] Division: %d\n", rank, a / b);

    MPI_Finalize();
}