leetcode 49 
group anagrams
tc-o(n3)
sc-o(n)
1️⃣ Brute Force Approach
💡 Idea

Compare every string with every other string.

Two strings are anagrams if after sorting they become equal.

Use a visited[] array so we don’t regroup the same string.

⚙️ Steps

For each string i, if not visited:

Create a new group.

Compare it with all j > i.

If i and j are anagrams → put in same group.

❌ Why is it brute?

Repeated comparisons

Sorting again and again

better 
tc- O(k . nlogn) //where k is the longest string length 
sc-o(n.k)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string , vector<string>>mpp;
        for(string s: strs){
            string key=s;
            sort(key.begin(),key.end());
            mpp[key].push_back(s);
        }

        vector<vector<string>> ans;
        for(auto &it : mpp){
         ans.push_back(it.second);
        }
        return ans;
    }
};


optimal ( count frequency)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (string s : strs) {
            vector<int> freq(26, 0);

            for (char c : s) {
                freq[c - 'a']++;
            }

            string key;
            for (int i = 0; i < 26; i++) {
                key += "#" + to_string(freq[i]);
            }

            mp[key].push_back(s);
        }

        vector<vector<string>> ans;
        for (auto &it : mp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};

🧪 Input
strs = ["eat", "tea", "tan", "ate", "nat", "bat"]

🔹 Initially
mp = {}

🔁 MAIN LOOP DRY RUN (VERY DETAILED)
🟢 1st string → "eat"
Step 1: Create frequency array
freq = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]

Step 2: Count characters

'e' → index 4

'a' → index 0

't' → index 19

freq[0]  = 1   // a
freq[4]  = 1   // e
freq[19] = 1   // t


All others remain 0.

Step 3: Build key

We convert entire freq into a string:

key = "#1#0#0#0#1#0#0#0#0#0#0#0#0#0#0#0#0#0#0#1#0#0#0#0#0#0"


👉 This key uniquely represents {a:1, e:1, t:1}

Step 4: Insert into map
mp[key].push_back("eat");


📦 mp now:

{
  key1 : ["eat"]
}

🟢 2nd string → "tea"
Frequency count

Characters: t, e, a

➡️ Same frequencies as "eat"

freq = [1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0]

Key generated
key = "#1#0#0#0#1#0#0#0#0#0#0#0#0#0#0#0#0#0#0#1#0#0#0#0#0#0"


(SAME KEY)

Insert
mp[key].push_back("tea");


📦 mp:

{
  key1 : ["eat", "tea"]
}

🟢 3rd string → "tan"
Frequency count

Characters: t, a, n

freq[0]  = 1   // a
freq[13] = 1   // n
freq[19] = 1   // t

Key
key = "#1#0#0#0#0#0#0#0#0#0#0#0#0#1#0#0#0#0#0#1#0#0#0#0#0#0"

Insert
mp[key].push_back("tan");


📦 mp:

{
  key1 : ["eat", "tea"],
  key2 : ["tan"]
}

🟢 4th string → "ate"

Same letters as "eat".

Key → SAME AS key1
mp[key1].push_back("ate");


📦 mp:

{
  key1 : ["eat", "tea", "ate"],
  key2 : ["tan"]
}

🟢 5th string → "nat"

Same letters as "tan".

Key → SAME AS key2
mp[key2].push_back("nat");


📦 mp:

{
  key1 : ["eat", "tea", "ate"],
  key2 : ["tan", "nat"]
}

🟢 6th string → "bat"
Frequency count

Characters: b, a, t

freq[0]  = 1   // a
freq[1]  = 1   // b
freq[19] = 1   // t

Key
key = "#1#1#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#1#0#0#0#0#0#0"

Insert
mp[key].push_back("bat");


📦 mp:

{
  key1 : ["eat", "tea", "ate"],
  key2 : ["tan", "nat"],
  key3 : ["bat"]
}

🔄 Final Step: Build Answer
ans = {
  ["eat", "tea", "ate"],
  ["tan", "nat"],
  ["bat"]
}


⚠️ Order may vary due to unordered_map.

note:
👉 Two strings are anagrams if and only if their frequency arrays are identical.

So instead of sorting:

We use character count as fingerprint

This fingerprint is the hashmap key


how it is tc and sc 
🔁 Recall the OPTIMAL approach (what operations are we doing?)

For each string:

Create a frequency array of size 26

Traverse the string and count characters

Convert frequency array into a key string

Insert the string into a hashmap

Let’s analyze each step properly.

🔢 Definitions (important)

n = number of strings

k = maximum length of a string

Characters are lowercase English letters → fixed 26

⏱️ TIME COMPLEXITY — Step by Step
🔹 Step 1: Loop over all strings
for (string s : strs)


➡️ Runs n times

🔹 Step 2: Count frequency of characters
for (char c : s)
    freq[c - 'a']++;


Each string has at most k characters

This loop takes O(k) time

✔️ So far:
👉 O(k) per string

🔹 Step 3: Build the key from frequency array
for (int i = 0; i < 26; i++)
    key += "#" + to_string(freq[i]);


Loop runs 26 times only

26 is a constant

Even though we are appending to a string, total size is bounded

➡️ O(26) = O(1)

✔️ Important interview point:

Fixed alphabet size ⇒ constant time

🔹 Step 4: Hashmap insertion
mp[key].push_back(s);


Hashmap insertion is O(1) average

push_back is O(1) amortized

✅ Time per string
O(k) + O(1) + O(1) = O(k)

✅ Total Time Complexity
n strings × O(k)
= O(n · k)

🎯 FINAL ANSWER (Time Complexity):

O(n · k)

❗ Why this is faster than sorting approach?
Approach	Time
Sorting-based	O(n · k log k)
Frequency-based	O(n · k)

💡 Because we removed sorting, which costs log k.

🧠 SPACE COMPLEXITY — Step by Step

Now let’s analyze extra memory used.

🔹 1. HashMap storage
unordered_map<string, vector<string>> mp;


We store:

All n strings

Each string length up to k

➡️ Total string storage = O(n · k)

🔹 2. Keys stored in HashMap

Each key:

Built from 26 frequencies

Length is bounded (constant-ish, but proportional to alphabet)

➡️ Across n keys → O(n · 1) ≈ O(n)

But since keys map to strings, total memory is still dominated by string storage.

🔹 3. Frequency array
vector<int> freq(26);


Size = 26

Created per iteration

Not stored permanently

➡️ O(1) auxiliary space

✅ Total Space Complexity

Dominant factor = storing all strings in hashmap:

O(n · k)

🎯 FINAL ANSWER (Space Complexity):

O(n · k)

🔍 Why we DON’T count freq[26] as extra space?

Interview rule:

If space does not grow with input size, it is considered O(1).

Alphabet size is fixed (26)

Does NOT depend on n or k

✔️ Hence ignored in SC

🧪 One-line Interview Explanation (VERY IMPORTANT)

“We iterate over all strings and count character frequencies
in O(k) time per string, leading to O(n·k) time. We store all strings in a hashmap, which takes O(n·k) space.”
