// https://www.interviewbit.com/problems/hotel-bookings-possible/

bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int c)
{
 if(c == 0)
 return false;
 int size = arrive.size(); 
 vector<pair<int, int>> vec;
 for(int i = 0; i < size; ++i)
 {
 vec.push_back(make_pair(arrive[i], 1));
 vec.push_back(make_pair(depart[i], 0));
 }
 
 sort(vec.begin(), vec.end());
 
 int rooms_occ = 0;
 int rooms_need = 0;
 for (int i = 0; i < vec.size(); i++)
 if (vec[i].second == 1)
 {
 rooms_occ++;
 rooms_need = max(rooms_need, rooms_occ);
 }
 else
 rooms_occ--;
 if (c >= rooms_need)
 return true;
 return false;
}
