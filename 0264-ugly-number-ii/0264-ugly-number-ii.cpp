class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long,vector<long long>,greater<long long>>pq;
        pq.push(1);
        long long node;
        unordered_map<long long,long long>m;
        m[1]=1;
        while(n--)
        {
            node=pq.top();
            pq.pop();
            if(!m.count(node*2))
            {pq.push(node*2);
            m[node*2]=1;}
            if(!m.count(node*3))
           { pq.push(node*3);
            m[node*3]=1;}
            if(!m.count(node*5))
            {pq.push(node*5);
            m[node*5]=1;}
            // n--;
        }
        return node;
    }
};