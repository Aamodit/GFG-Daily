class Solution {

public:

 

    int gcd(int a, int b) {

        if (b == 0) return a;

        return gcd(b, a % b);

    }

 

    int pour(int fromCap, int toCap, int d) {

        int from = fromCap; // fill from jug

        int to = 0; // to jug empty

        int step = 1;

 

        while (from != d && to != d) {

            int temp = min(from, toCap - to);

            

            to += temp;

            from -= temp;

            step++;

 

            if (from == d || to == d)

                break;

 

            if (from == 0) {

                from = fromCap;

                step++;

            }

 

            if (to == toCap) {

                to = 0;

                step++;

            }

        }

        return step;

    }

 

    int minSteps(int m, int n, int d) {

        // Not possible case

        if (d > max(m, n)) return -1;

 

        if (d % gcd(m, n) != 0) return -1;

 

        return min(pour(m, n, d), pour(n, m, d));

    }

};