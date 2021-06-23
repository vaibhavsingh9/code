// ***********Leet Code************
// q1. 14. Longest Common Prefix
// #include<iostream>
// #include<bits/stdc++>
// class Solution{
//     string longestCommonPrefix(vector<string>& strs){
//         int n = strs.size();
//         if(n==0) return "";
//         if(n==1) return a[0];

//         sort(strs.begin(),strs.end());
//         int en = min(strs[0].size(), strs[n-1].size());
//         int i = 0;
//         string first = strs[0], last = strs[n-1];
//         while(i<en && first[i]==last[i])
//             i++;
//         string pre = first.substr(0,i);
//         return pre;
//     }
// }

// q2. Defang the IP Address in leetcode, 1108
// class Solution {
// public:
//     string defangIPaddr(string address) {
//         string str = "";
//         // string defangIP = "";
     
//     // Loop to iterate over the
//     // characters of the string
//     for (char c : address)
//         {(c == '.') ? str += "[.]" :str += c;}
//     return str;
//     }
// };
// q3. Maximum number of Ballon leetcode 1189
// Using Unordered_map
// // class Solution {
// public:
//     int maxNumberOfBalloons(string text) {
//         unordered_map<char,int> record;
//         for(auto &c: text) 
//             record[c]++;
        
//         int count = 0, i = 0;
//         string target = "balloon";
       
//         while(true){
//             int idx = i%target.size();
           
//             if(record[target[idx]]==0)
//                 break;
            
//             if(idx == target.size()-1)
//                 count++;
//             record[target[idx]]--;
//             ++i;
//         }
//         return count;
//     }
// };
// class Solution {
// public:
//     int maxNumberOfBalloons(string text) {
//         int b, a, l, o, n;
//         b= a= l= o= n= 0;
//         for(auto ch: text)
//         {
//             if(ch== 'b') b++;
//             else if(ch== 'a') a++;
//             else if(ch== 'l') l++;
//             else if(ch== 'o') o++;
//             else if(ch== 'n') n++;
//         }
//         return min({b, a, l/2, o/2, n});
//     }
// };
