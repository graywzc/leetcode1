class Solution {
public:
    void buildLadders(vector<vector<string>>& res, vector<string>& temp, const string& s, map<string, vector<string>>& parents)
    {
        if(parents[s].empty())     
        {
            if(temp.size() == 1)
                return;
            vector<string> lad = temp; 
            reverse(lad.begin(),lad.end());
            res.push_back(lad);
        }
        else
        {
            for(const string& par: parents[s])     
            {
                temp.push_back(par); 
                buildLadders(res, temp, par, parents);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        vector<vector<string>> res;
        if(start == end || start.size() == 0)
            return res;

        int size = start.size();
        map<string, vector<string> > parents;
        map<string, int > level;
        parents.insert(pair<string, vector<string> >(start, vector<string>()));
        level.insert(pair<string, int >(start, 0));

        queue<string> q; 
        q.push(start);
        int end_lvl = INT_MAX;

        while(!q.empty() && level[q.front()] < end_lvl)
        {
            string cur = q.front();     
            q.pop();
            for(int i = 0; i < size; i++) 
            {
                string temp = cur; 
                for(char j = 'a'; j <= 'z'; j++)
                {
                    if(j == cur[i]) 
                        continue;
                    temp[i] = j;

                    if(temp == end)
                    {
                        auto it = parents.find(end);    
                        if(it != parents.end())
                            it->second.push_back(cur);
                        else
                        {
                            parents[end] = vector<string>(1,cur);
                            end_lvl = level[cur]+1;
                            level[end] = end_lvl;
                        }
                    }
                    else if(dict.find(temp)!=dict.end())
                    {
                        auto it = parents.find(temp); 
                        if(it == parents.end())
                        {
                            level[temp] = level[cur] + 1;    
                            parents[temp] = vector<string>(1,cur); 
                            q.push(temp);
                        }
                        else
                        {
                            if(level[cur]<level[temp]) 
                                parents[temp].push_back(cur); 
                        }
                    }
                }
            }
        }
        
        vector<string> temp;
        temp.push_back(end);
        buildLadders(res,temp,end,parents);

        return res;
    }
};
