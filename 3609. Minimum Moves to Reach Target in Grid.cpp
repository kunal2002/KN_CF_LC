class Solution {
public:
    int minMoves(int sx, int sy, int tx, int ty) {
        int ans = 0;
        if(sx == tx && sy == ty)
            return 0;
        if(tx < sx || ty < sy)
            return -1;
        if(sx == 0 && sy == 0)
        {
            if(tx == 0 && ty == 0)
                return 0;
            return -1;
        }
        if(tx == ty && sx != 0 && sy != 0)
            return -1;
        while(tx > sx || ty > sy)
        {
            if(tx > ty)
            {
                ans++;
                if(tx > ty * 2)
                {
                    if(!(tx&1))
                        tx >>= 1;
                    else
                        return -1;
                }
                else
                    tx -= ty;
            }
            else if(ty > tx)
            {
                ans++;
                if(ty > tx * 2)
                {
                    if(!(ty&1))
                        ty >>= 1;
                    else
                        return -1;
                }
                else
                    ty -= tx;
            }
            else
            {
                ans++;
                if(sx > sy)
                    ty -= tx;
                else
                    tx -= ty;
            }
        }
        return (tx == sx && ty == sy) ? ans : -1;
    }
};
