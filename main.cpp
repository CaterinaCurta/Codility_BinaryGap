#include <iostream>

using namespace std;

int solution(int N)
{
    int size = sizeof(N) * 8;
    int mask = 1;
    int foundOne = -1;
    int maxZeroes = 0;

    for(int i = 0; i < size; i++)
    {
        if(mask >= N)
        {
            // If N is 0 or 1, we don't do anything
            return maxZeroes;
        }

        if((mask & N) > 0)
        {
            if(foundOne == -1)
            {
                foundOne = i;
            }
            else
            {
                int zeroes = i - foundOne - 1;
                if(zeroes > maxZeroes)
                {
                    maxZeroes = zeroes;
                }
                foundOne = i;
            }
        }
        mask <<= 1;
    }

    return maxZeroes;
}
int main() {

    int N = 8;

    int zeroes = solution(8);

    cout <<" "<<zeroes;

    return 0;
}
