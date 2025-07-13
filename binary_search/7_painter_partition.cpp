https://www.naukri.com/code360/problems/painter-s-partition-problem_1089557?leftPanelTabValue=PROBLEM

int count(vector<int>a, int time){
    int painter =1 ;
    long long boardsPainter=0;

    for(int i=0; i<a.size(); i++){
        if(boardsPainter+a[i]<=time){
            boardsPainter+=a[i];
        }
        else{
            painter++;
            boardsPainter=a[i];
        }
    }
    return painter;

}
int findLargestMinDistance(vector<int> &boards, int k)
{
    int l = *max_element(boards.begin(), boards.end());
    int h = accumulate(boards.begin(), boards.end(), 0);

    while(l<=h){
        int mid = (l+h)/2;
        int painters = count(boards, mid);
        if(painters>k){
            l=mid+1;
        }
        else{
            h=mid-1;
        }
    }
    return l;
}