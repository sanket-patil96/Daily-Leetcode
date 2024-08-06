class Solution {
public:
    // Initialize a frequency vector frequency of size 26 to store the count of each letter in the word.
    // Iterate through each character c in word and increment the count in frequency at the index corresponding to c - 'a'.
    // Sort the frequency vector in descending order to prioritize letters with higher counts.
    // Initialize a variable totalPushes to store the total number of key presses required.
    // Iterate through the sorted frequency vector:
    // If the frequency of a letter is zero, break the loop as there are no more letters to process.
    // Calculate the number of pushes for each letter based on its position in the sorted list: (i / 8 + 1) * frequency[i].
    // Accumulate this value in totalPushes.
    // Return totalPushes as the minimum number of key presses required to type the word.
    // T/C: O(n)  S/C: O(1)
    int minimumPushes(string word) {
        vector<int> freq(26, 0);
        for(auto ch: word)
            freq[ch-'a']++;

        
        // reverse sort by frequency
        sort(freq.rbegin(), freq.rend());

        int totalPushes = 0;
        for(int i = 0; i < 26; i++) {
            if(freq[i] == 0)        // from here no any word has typed
                break;

            // get the occurance of letter on button
            totalPushes += (i / 8 + 1) * freq[i];
        }
        
        return totalPushes;
    }
};