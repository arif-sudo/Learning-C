#include <stdio.h>
#include <string.h>

#define NELEMS(x) (sizeof(x) / sizeof(x[0]))

int main(int argc, char *argv[])
{
    int games = 4;
    int players = 5;

    int arr[games][players];
    int sum[players];
    memset(sum, 0, sizeof(sum));


    for (int i = 0; i < games; i++)
    {
        printf("Game #%d\n", i + 1);
        for (int j = 0; j < players; j++)
        {
            printf("Enter scoring total for Player #%d: ", j + 1);
            scanf("%d", &arr[i][j]);
            sum[j] += arr[i][j];
        }
    }
    int M;
    int Mi = 0;
    for (int i = 1; i < players; i++)
    {
        M = sum[0];
        if (sum[i] > M) {
            M = sum[i];
            Mi = i;
        }
    }
    float ppg = (float)(M / 4);
    printf("Player #%d had the highest scoring average at %.2f points per game.", Mi, ppg);

    return 0;
}