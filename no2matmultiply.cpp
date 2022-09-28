#include <bits/stdc++.h>
#include <mpi.h>
using namespace std;

int main(int argc, char **argv)
{
    MPI_Init(NULL, NULL);

    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int a[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    int b[4][4] = {{0, 1, 0, 1}, {0, 1, 0, 1}, {0, 1, 0, 1}, {0, 1, 0, 1}};

    int result[4][4] = {0};

    if (rank == 0)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                result[0][i] += a[0][j] * b[j][i];
            }
        }

        printf("[Rank %d] Result-> Row 1: ", rank);
        for (int i = 0; i < 4; i++)
        {
            printf("%d ", result[0][i]);
        }
        printf("\n");
    }

    if (rank == 1)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                result[1][i] += a[1][j] * b[j][i];
            }
        }

        printf("[Rank %d] Result-> Row 2: ", rank);
        for (int i = 0; i < 4; i++)
        {
            printf("%d ", result[1][i]);
        }
        printf("\n");
    }

    if (rank == 2)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                result[2][i] += a[2][j] * b[j][i];
            }
        }

        printf("[Rank %d] Result-> Row 3: ", rank);
        for (int i = 0; i < 4; i++)
        {
            printf("%d ", result[2][i]);
        }
        printf("\n");
    }

    if (rank == 3)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                result[3][i] += a[3][j] * b[j][i];
            }
        }

        printf("[Rank %d] Result-> Row 4: ", rank);
        for (int i = 0; i < 4; i++)
        {
            printf("%d ", result[3][i]);
        }
        printf("\n");
    }

    // for(int i=0; i<4; i++)
    // {
    //     for(int j=0; j<4; j++)
    //     {
    //         printf("%d ", result[i][j]);
    //     }
    //     printf("\n");

    // }

    MPI_Finalize();
}