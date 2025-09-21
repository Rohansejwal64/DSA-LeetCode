class Solution {
public:
class node{
    public:
    int value;
    int row;
    int col;
    node(int val , int r, int c){
        value=val;
        row=r;
        col=c;
    }
};
class compare{
    public:
    bool operator()(node* a, node* b){
        return a->value > b->value;

    }
};


    vector<int> smallestRange(vector<vector<int>>& nums) {


        priority_queue< node*, vector< node*> , compare > pq;
        int r=nums.size();
        
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int i=0;i<r;i++){
            mini=min(mini,nums[i][0]);
            maxi=max(maxi,nums[i][0]);

            node* temp= new node(nums[i][0],i,0);
            pq.push(temp);
        }
        int st=mini;
        int end=maxi;

        while(!pq.empty()){

            node *temp=pq.top();
            pq.pop();
            int i=temp->row;
            int j=temp->col;
            if(j+1<nums[i].size()){
                node *newnode=new node(nums[i][j+1],i,j+1);
                pq.push(newnode);
                mini=pq.top()->value;
                maxi=max(maxi,newnode->value);
                if(maxi-mini < end-st){
                    end=maxi;
                    st=mini;
                }

            }
            else{
                break;

            }
        }


        return { st,end};

       


        
    }
};