	
	string deal(string s){
		string res = "$#";
		for (int i = 0; i < s.length(); ++i){
			res += s[i];
			res += '#';
		}
		return res;

	}

	int manacher(string s){
		s = deal(s);
		int *p = new int[s.length() + 1];
		memset(p, 0, sizeof(p));
		int mx = 0, id = 0;
		int m = s.length();
		for (int i = 1; i < m; i++) {
			if (mx > i){
				p[i] = min(p[2 * id - i], mx - i);
			}
			else{
				p[i] = 1;
			}
			//p[i] = mx > i? min(mp[2*id-i], mx-i): 1;
			while (s[i + p[i]] == s[i - p[i]]){
				p[i]++;
			}
			//while(s[i+mp[i]] == s[i-mp[i]]) mp[i]++;
			if (i + p[i] > mx) {
				mx = i + p[i];
				id = i;
			}
		}
		int res = 0;
		for (int i = 1; i < m; ++i){
			if (p[i] == i){
				res = max(res, i);
			}
		}
		return res - 1;
	}