#include <stdio.h>

struct Stats
{
    int points;
    int games;
};
struct Stats player[5];

int main(int argc, char const *argv[])
{
    int count = 5;
    for (int i = 0; i < count; i++)
    {
        printf("Enter Player %d's point total: ", i + 1);
        scanf("%d", &player[i].points);

        printf("Enter Player %d's games total: ", i + 1);
        scanf("%d", &player[i].games);
    }
    puts("");
    for (int i = 0; i < count; i++)
    {
        float ppg = (float)player[i].points / player[i].games;
        printf("Player %d's scoring average was %.2f ppg\n", i + 1, ppg);
    }

    return 0;
}
