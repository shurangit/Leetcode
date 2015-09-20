class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area1=abs((C-A)*(D-B));
        int area2=abs((G-E)*(H-F));
        if(A>=G||C<=E||D<=F||H<=B) return area1+area2;
        int area3=abs(min(D,H)-max(B,F))*abs(min(C,G)-max(A,E));
        return area1+area2-area3;
    }
};