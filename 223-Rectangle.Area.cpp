class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        long long a1 = ((long long)C - (long long)A) * ((long long)D - (long long)B);
        long long a2 = ((long long)G - (long long)E) * ((long long)H - (long long)F);

        if (C <= E || G <= A || D <= F || H <= B)
            return (int)(a1 + a2);
        long long a3 = ((long long)min(C, G) - (long long)max(A, E)) * ((long long)min(D, H) - (long long)max(B, F));
        return (int)(a1+a2-a3);

    }
};