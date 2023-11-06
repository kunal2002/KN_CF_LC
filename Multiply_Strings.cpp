class Solution {
public:
    string multiply(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int carry = 0; 
        if(num1.size() > num2.size())
            swap(num1, num2);
        string ans = "", res = "";
        int times = 0;
        for(int i = 0; i < num1.size(); i++)
        {
            for(int j = 0; j < num2.size(); j++)
            {
                int nm1 = num1[i] - '0', nm2 = num2[j] - '0';
                int prod = nm1 * nm2 + carry;
                if(j == num2.size() - 1)
                {
                    carry = 0;
                    string temp = to_string(prod);
                    reverse(temp.begin(), temp.end());
                    ans += temp;
                    break;
                }
                int dig = prod % 10;
                prod /= 10;
                carry = prod;
                ans += to_string(dig);
            }
            string what = ans;
            reverse(what.begin(), what.end());
            if(!times)
            {
                res = what;
                times++;
            }
            else
            {
                int tmp = times++;
                while(tmp--)
                    what += '0';
                // cout << res << " " << what << "\n";
                string final = "";
                if(res.size() < what.size())
                    swap(res, what);
                int one_i = res.size() - 1;
                int carry = 0;
                for(int i = what.size() - 1; ~i; i--)
                {
                    int dig1 = res[one_i--] - '0', dig2 = what[i] - '0';
                    int sum = dig1 + dig2 + carry;
                    final += to_string(sum % 10);
                    sum /= 10;
                    carry = sum;
                }
                int new_size = res.size() - what.size() - 1;
                for(int i = new_size; ~i; i--)
                {
                    int dig1 = res[i] - '0';
                    int sum = dig1 + carry;
                    final += to_string(sum % 10);
                    sum /= 10;
                    carry = sum;
                }
                if(carry)
                    final += to_string(carry);
                reverse(final.begin(), final.end());
                res = final;
                // cout << res << "\n";
            }
            ans.clear();
        }
        if(count(res.begin(), res.end(), '0') == res.size())
            return "0";
        return res;
    }
};
