class Solution {
public:
    double findMedianSortedArrays(vector<int>& ar, vector<int>& br) {
        int n = ar.size(), m = br.size();

    if (n > m)
        return findMedianSortedArrays(br, ar);

    int i = 0, j = n;

    while (i <= j)

    {

        int mda = (i + j) / 2;

        int mdb = (n + m + 1) / 2 - mda;

        int mina = (mda > 0) ? ar[mda - 1] : INT_MIN;

        int minb = (mdb > 0) ? br[mdb - 1] : INT_MIN;

        int maxa = (mda < n) ? ar[mda] : INT_MAX;

        int maxb = (mdb < m) ? br[mdb] : INT_MAX;

        if (mina <= maxb && minb <= maxa)

        {

            if ((m + n) % 2 == 0)

            {

                return (float(max(mina, minb) + min(maxa, maxb))) / 2;
            }

            else

            {

                return max(mina, minb);
            }
        }

        else if (mina > maxb)

            j = mda - 1;

        else

            i = mda + 1;
    }
    return 0;
    }
};