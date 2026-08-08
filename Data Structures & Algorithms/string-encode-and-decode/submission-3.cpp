class Solution {
public:

    // --------------------------------------------------
    // ENCODE
    // --------------------------------------------------
    // Convert:
    //
    // ["Hello", "World"]
    //
    // into:
    //
    // "5,5#HelloWorld"
    //
    // Format:
    //
    // [length1,length2,...,#][all strings]
    // --------------------------------------------------

    string encode(vector<string>& strs) {

        // If there are no strings, return empty string
        if (strs.empty())
            return "";

        vector<int> sizes;
        string res;

        // Step 1:
        // Store the length of every string
        //
        // ["Hello", "World"]
        //       ↓
        //     [5, 5]
        for (string& s : strs) {
            sizes.push_back(s.size());
        }

        // Step 2:
        // Store all lengths in the encoded string
        //
        // [5, 5]
        //  ↓
        // "5,5,"
        for (int sz : sizes) {
            res.append(to_string(sz));
            res.push_back(',');
        }

        // Step 3:
        // '#' marks the end of the length information
        //
        // "5,5,"
        //    ↓
        // "5,5,#"
        res.push_back('#');

        // Step 4:
        // Append all original strings
        //
        // "5,5,#"
        //    +
        // "HelloWorld"
        //
        // Result:
        // "5,5,#HelloWorld"
        for (string& s : strs) {
            res.append(s);
        }

        return res;
    }


    // --------------------------------------------------
    // DECODE
    // --------------------------------------------------
    // Convert:
    //
    // "5,5#HelloWorld"
    //
    // back into:
    //
    // ["Hello", "World"]
    // --------------------------------------------------

    vector<string> decode(string s) {

        // Empty encoded string means no strings
        if (s.empty())
            return {};

        vector<int> sizes;
        vector<string> res;

        int i = 0;

        // ----------------------------------------------
        // Step 1:
        // Read all string lengths until '#'
        //
        // "5,5,0,#HelloWorld"
        //  ^ 
        // ----------------------------------------------

        while (s[i] != '#') {

            // j searches for the next comma
            int j = i;

            while (s[j] != ',') {
                j++;
            }

            // Extract the number between i and j
            //
            // Example:
            // "5,5,0,#..."
            //  ^
            //  i=0, j=1
            //
            // s.substr(0,1) = "5"
            //
            // stoi("5") = 5
            sizes.push_back(
                stoi(s.substr(i, j - i))
            );

            // Move i after the comma
            i = j + 1;
        }

        // ----------------------------------------------
        // Step 2:
        // Skip '#'
        //
        // Now i points to the first character
        // of the actual string data.
        // ----------------------------------------------

        i++;


        // ----------------------------------------------
        // Step 3:
        // Use the stored lengths to extract strings
        // ----------------------------------------------

        for (int sz : sizes) {

            // Take exactly 'sz' characters
            //
            // Example:
            // sz = 5
            //
            // "HelloWorld"
            //  -----
            //  Hello
            res.push_back(
                s.substr(i, sz)
            );

            // Move to the beginning of the next string
            i += sz;
        }

        return res;
    }
};