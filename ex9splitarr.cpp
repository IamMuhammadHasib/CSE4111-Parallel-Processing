#include <bits/stdc++.h>
#include <mpi.h>
#define ll long long
#define ull unsigned long long
using namespace std;

int main()
{
    int s = 3;
    int suba[10];
    MPI_Status status;
    int rank;

    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    if (rank == 0)
    {
        int a[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        MPI_Send(a, s, MPI_INT, 1, 10, MPI_COMM_WORLD);
        MPI_Send(a + s, s, MPI_INT, 2, 10, MPI_COMM_WORLD);
        MPI_Send(a + s + s, s, MPI_INT, 3, 10, MPI_COMM_WORLD);

        int total = 0;
        for (int i = 0; i < 3; i++)
        {
            int res;
            MPI_Recv(&res, 1, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
            total += res;
        }

        cout << "Total sum: " << total << endl;
    }
    else
    {
        MPI_Recv(&suba, s, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
        int sum = 0;
        for (int i = 0; i < s; i++)
        {
            sum += suba[i];
        }
        cout << "Sum in rank " << rank << ": " << sum << endl;
        MPI_Send(&sum, 1, MPI_INT, 0, 10, MPI_COMM_WORLD);
    }
    MPI_Finalize();
}