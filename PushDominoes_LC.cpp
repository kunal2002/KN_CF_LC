class Solution {
public:
    string pushDominoes(string dominoes) {
        dominoes = "L" + dominoes + "R";
        int n = dominoes.size();
        int i = 0;
        for (int j = 1; j < n; j++) 
        {
            if (dominoes[j] == '.') continue;
            int middle = j - i - 1;
            if (dominoes[i] == dominoes[j]) 
            {
                for (int k = i + 1; k < j; ++k)
                    dominoes[k] = dominoes[i];
            } 
            else if (dominoes[i] == 'R' && dominoes[j] == 'L') 
            {
                for (int k = 1; k <= middle / 2; k++) 
                {
                    dominoes[i + k] = 'R';
                    dominoes[j - k] = 'L';
                }
            }
            i = j;
        }
        dominoes.erase(dominoes.begin());
        dominoes.pop_back();
        return dominoes;
    }
};
