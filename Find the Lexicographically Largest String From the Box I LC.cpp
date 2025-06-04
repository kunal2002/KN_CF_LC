class Solution {
public:
    int rec(string& word, int numFr)
    {
        int n = word.size();
        int i = 0, j = 1;
        while(j < n)
        {
            int k = 0;
            while(j + k < n && word[i + k] == word[j + k])
                k++;
            if(j + k < n && word[i + k] < word[j + k])
            {
                i = j;
                j = j + 1;
            }
            else
                j = j + k + 1;
        }
        return i;
    }
    string answerString(string word, int numFriends) {
        int n = word.size();
        if(numFriends == 1)
            return word;
        int len = n - (numFriends - 1);
        int bestStart = rec(word, numFriends);
        int canTake = min(len, n - bestStart);
        return word.substr(bestStart, canTake);
    }
};
