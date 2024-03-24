#include <math.h>
#include <stdio.h>

typedef long long ll;

int main(void) {
    int q;
    scanf("%d", &q);

    for (int i = 0; i < q; i++) {
        ll k;
        scanf("%lld", &k); // Input

        ll cum = 0; // Cumulative bruh I ain't like that
        int dig; // Number of digits in the number the query is pointing at

        for (int j = 1; ; j++) {
            ll check = 9 * pow(10, (j - 1)) * j; // 9 x 1, 90 x 2, 900 x 3, etc
            cum += check;

            if (cum >= k) {
                dig = j;
                cum -= check; // To use in newk later on
                break;
            }
                
        } // This loop calculates dig

        /* For example, if k = 12
         * cum -= check in Line 23 makes cum = 9
         * newk = 12 - 9 = 3, which is the third query for 2 digit numbers */
        
        ll newk = k - cum;

        ll quo = (newk - 1) / dig; // Gives the quo'th 'dig' digit number

        ll start = pow(10, dig - 1);
        start += quo; // start has the exact number, query is pointing at one of its digits

        // newk is currently 1 indexed, to get the rem now we 0 index it
        newk -= 1;

        ll rem = newk % dig; // Position of the query in the exact number
        rem = (dig - 1) - rem; // Get rems in order of units, tens, etc

        ll penultimate = start / (ll)pow(10, rem);
        
        int final = penultimate % 10;

        printf("%lld\n", final);
    }
}