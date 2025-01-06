class Solution
{
public:
    string gcdOfStrings(string str1, string str2)
    {
        string prefix = "";

        int maxlen = 0;

        if (str1.length() < str2.length())
        {
            maxlen = str1.length();
        }
        else
        {
            maxlen = str2.length();
        }

        for (int i = 0; i < maxlen; i++)
        {
            if (str1[i] == str2[i])
            {
                prefix += str1[i];
            }
            else
            {
                break;
            }
        }

        int prefixlen = prefix.length();

        while (prefixlen > 0)
        {
            if ((str1.length() % prefixlen) != 0 || (str2.length() % prefixlen) != 0)
            {
                prefixlen--;
                continue;
            }

            bool validGcd = true;

            for (int i = 0; i < (str1.length() / prefixlen); i++)
            {
                if (!validGcd)
                {
                    break;
                }

                for (int j = 0; j < prefixlen; j++)
                {
                    if (str1[i * prefixlen + j] != prefix[j])
                    {
                        validGcd = false;
                        break;
                    }
                }
            }

            for (int i = 0; i < (str2.length() / prefixlen); i++)
            {
                if (!validGcd)
                {
                    break;
                }

                for (int j = 0; j < prefixlen; j++)
                {
                    if (str2[i * prefixlen + j] != prefix[j])
                    {
                        validGcd = false;
                        break;
                    }
                }
            }

            if (validGcd)
            {
                break;
            }
            else
            {
                prefixlen--;
            }
        }

        string result = "";

        for (int i = 0; i < prefixlen; i++) {
            result += prefix[i];
        }

        return result;
    }
};