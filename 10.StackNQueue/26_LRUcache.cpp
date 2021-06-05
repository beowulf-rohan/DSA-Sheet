#include<bits/stdc++.h>
using namespace std;

class LRUCache
{
    private:list<int> dq;
            unordered_map<int,int> mp;
            int size;
    
    public: LRUCache(int cap)
            {
                this->size = cap;
            }
        
            int get(int key)
            {
                if(mp.find(key) == mp.end())
                    return -1;
                dq.remove(key);
                dq.push_back(key);
                return mp[key];
            }
            void set(int key, int value)
            {
                 if(mp.find(key) != mp.end())
                 {
                     dq.remove(key);
                     dq.push_back(key);
                 }
                 else
                 {
                     if(dq.size() == size)
                     {
                         mp.erase(dq.front());
                         dq.pop_front();
                     }
                     dq.push_back(key);
                 }
                 mp[key] = value;
            }
};