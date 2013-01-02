class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int head, tail, len , n , margin , slot_num , tmp , i, j;
        string s;
        vector<string> result;
        n = words.size();
        vector<int> margin_size(n,0);
        head = 0;
        while(1){
            tail = head;
            len = 0;
            while( len + tail - head + words[tail].length() <= L ){//find all words to be shown in this line
                len = len + words[tail].length();               
                tail ++;
                if (tail >= n) break;
            }
            margin = L - len;
            slot_num = tail - head - 1;
            for ( i = head ; i < tail - 1; i ++){
                margin_size[i] = margin / slot_num;
                if ( i- head <  ( margin % slot_num ) )//to distribute space evenly
                    margin_size[i] ++;
                    
                if (tail>= n ) // the last line
                  margin_size[i] = 1;
                  
            }
            
            if (tail - head == 1)// only one word per line
                margin_size[head] = margin; 
            
            s = "";
            for ( i = head; i < tail ; i ++){
                s = s + words[i];
                for (j = 0; j < margin_size[i]; j ++)
                    s = s + " ";
            }
            while(s.length() < L) s = s + " ";
            result.push_back(s);
            head = tail;
            if (head >= n ) break;
        }
        
        return result;
    }
};