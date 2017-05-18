/**
355. Design Twitter
Design a simplified version of Twitter where users can post tweets, follow/unfollow another user and is able to see the 10 most recent tweets in the user's news feed. Your design should support the following methods:
  1. postTweet(userId, tweetId): Compose a new tweet.
  2. getNewsFeed(userId): Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
  3. follow(followerId, followeeId): Follower follows a followee.
  4. unfollow(followerId, followeeId): Follower unfollows a followee.
Example:
Twitter twitter = new Twitter();

// User 1 posts a new tweet (id = 5).
twitter.postTweet(1, 5);

// User 1's news feed should return a list with 1 tweet id -> [5].
twitter.getNewsFeed(1);

// User 1 follows user 2.
twitter.follow(1, 2);

// User 2 posts a new tweet (id = 6).
twitter.postTweet(2, 6);

// User 1's news feed should return a list with 2 tweet ids -> [6, 5].
// Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
twitter.getNewsFeed(1);

// User 1 unfollows user 2.
twitter.unfollow(1, 2);

// User 1's news feed should return a list with 1 tweet id -> [5],
// since user 1 is no longer following user 2.
twitter.getNewsFeed(1);
思路1：getNewsFeed遍历存储所有tweet的vector,遇到是某人自己或者他关注的人发出的，就写出到结果vector。
但是这种方式的时间复杂度是O(N).N是所有tweet的数量，时间复杂度太高。
**/
class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
        
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        //someone_tweet[userId].push_back(tweetId);
        all_tweet.push_back(make_pair(tweetId,userId));
        follower_relat[userId].insert(userId);
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        int count=0;
        int size=all_tweet.size();
        int index=size-1;
        vector<int> res;
        while(count<10 && index!=-1){
            if(follower_relat[userId].find(all_tweet[index].second)!=follower_relat[userId].end()){
                res.push_back(all_tweet[index].first);
                count++;
            }
            index--;    
        }
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        follower_relat[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(followerId==followeeId)   //一个人不能取消关注他自己
            return;
        follower_relat[followerId].erase(followeeId);
    }
private:
    unordered_map<int,unordered_set<int>> follower_relat;
    //unordered_map<int,vector<int>> someone_tweet;
    vector<pair<int,int>> all_tweet;  //存储所有的tweet
};


/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
/**
思路2：
需要实现发tweet、获取新tweet推送、关注和取消关注四个功能，数据存储方式比较多，这里采用Hash Table来存储所有用户的tweet列表和关注列表，
单个用户的tweet列表用vector存储，因为关注列表涉及到插入和删除，所以选择了unordered_set来存储单个用户的关注列表，
不用list是因为list在删除时需要查找，时间复杂度理论上比unordered_set高。由于tweetId不能表示该tweet的发布时间，所以在tweet存储时加了时间戳来表示tweet的发布顺序。
还可以采用其他数据存储方式，感兴趣的同学可以比较一下不同数据结构的优劣。

​数据结构选定之后实现就比较简单了，获取最新10条tweet推送时，遍历用户的关注列表，将他关注的用户tweet列表中的前10条tweet存入堆中，
并将自身tweet列表的前10条tweet存入堆中，由于堆中数据依据时间戳排序，所以从堆中取出前10条tweet即获得了最新10条tweet推送。具体代码
**/
struct TNode{
    int tweetId;
    int time_stamp;
    TNode(int a,int b): tweetId(a),time_stamp(b){}
    bool operator <(const TNode& rhs) const{
        return this->time_stamp > rhs.time_stamp;
    }
};
class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter(): time_stamp(0) {
        
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        map[userId].push_back(TNode(tweetId,time_stamp));
        time_stamp++;
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        int count=0;
        set<TNode> max_heap;
        int index=map[userId].size()-1;
        while(count<10 && index>=0){
            max_heap.insert(map[userId][index]);
            index--;
            count++;
        }
        for(auto ite=relation_map[userId].begin();ite!=relation_map[userId].end();ite++){
            count=0;
            int index=map[*ite].size()-1;
            while(count<10 && index>=0){
            max_heap.insert(map[*ite][index]);
            index--;
            count++;
            }
        }
        auto ite=max_heap.begin();
        count=0;
        while(count<10 && ite!=max_heap.end()){
            res.push_back(ite->tweetId);
            count++;
            ite++;
        }
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        relation_map[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        relation_map[followerId].erase(followeeId);
    }
private:
    int time_stamp;
    unordered_map<int,vector<TNode>> map;
    unordered_map<int,unordered_set<int>> relation_map;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
