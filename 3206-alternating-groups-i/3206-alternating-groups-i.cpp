class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) 
    {
         int count = 0;
        int n = colors.size();
        if(colors.size()<3) return 0;

        
        for(int i =0; i<n-2; i++)
        {
        
            if(colors[i] == colors[i+2] && colors[i] != colors[i+1])
            count++;
        
        }

        if(colors[n-1] == colors[1] && colors[n-1] != colors[0]) 
            count++;
        
        if(colors[n-2] == colors[0] && colors[n-2] != colors[n-1])
            count++;

         return count;
        
    }
};