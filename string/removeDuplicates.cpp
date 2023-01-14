string removeDuplicates(string str) {
	   string ans;
	   // for storing freq using asc value
	   vector<int> hash(256,0);
       // iterating over string
	   for(char ch: str){
        // checking if char is already not visited
	       if(hash[ch] == 0)
	        ans.push_back(ch);
        // mark as visited current char
	       hash[ch]++;
	   }
	   return ans;
	}