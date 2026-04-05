class Solution {
public:
    bool judgeCircle(string moves) {
        // for the robot to reach again at its origin, all the operations performed should be equal no.of times
        // means the no.of times it goes up, should be equal to no.of times it goes down if he has to  
        // end up at same,  spot same applies for the left & right
        // so (up == down && left == right) is final equation!

        // if operations are not even then it's not going to came at origin, as explained above operations should be equal no.of times (odd+odd = even && evn+evn = evn)
        if(moves.size() % 2 != 0)
            return false;

        int U = 0, D = 0, L = 0, R = 0;
        for(char c: moves) {
            if(c == 'U')
                U++;
            else if(c == 'D')
                D++;
            else if(c == 'L')
                L++;
            else
                R++;
        }

        return (U == D && L == R);
    }
};