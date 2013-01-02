class Solution {
public:
    string simplifyPath(string path) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
	vector<string> pathes;
	string tmp,result;
	int i ; 
	i = 0;
	if ( path.length() == 0 ) return "/";

	while ( i < path.length()){
		while(path[i] == '/' ){
			i ++;
			if ( i == path.length()) break;
		}
		if ( i == path.length()) break;
		tmp = "";
		while ( path[i] != '/' && i < path.length() ){
			tmp = tmp + path[i];
			i ++;
		}
		
		if ( tmp[0] != '.' ){
			pathes.push_back(tmp);
		}

		else {

			if (tmp.length()== 2) {
				if ( pathes.size() > 0 )
						pathes.pop_back();
				//	else
				//		pathes.push_back(tmp);

							
				}


		}
		result = tmp;
	}

	if (  pathes.size() == 0) return "/";

	 result = "";
	
	for ( i = 0 ; i < pathes.size(); i ++ )
		result = result + "/" + pathes[i];

        if ( result.length() == 0 ) result = "/";
	return result;

        
    }
};

