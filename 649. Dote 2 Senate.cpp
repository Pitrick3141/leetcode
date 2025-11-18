class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<char> votes;
        int direVotes = 0;
        int direCount = 0;
        int radiantVotes = 0;
        int radiantCount = 0;
        for(int i = 0; i < senate.length(); i ++) {
            if(senate[i] == 'D') direCount ++;
            else radiantCount ++;
            votes.push(senate[i]);
        }
        while(votes.size() > 1) {
            if(!direCount) return "Radiant";
            if(!radiantCount) return "Dire";
            if(votes.front() == 'D') {
                if(radiantVotes) {
                    radiantVotes --;
                    direCount --;
                }
                else {
                    direVotes ++;
                    votes.push('D');
                }
            }
            else {
                if(direVotes) {
                    direVotes --;
                    radiantCount --;
                }
                else {
                    radiantVotes ++;
                    votes.push('R');
                }
            }
            votes.pop();
        }
        return direCount ? "Dire" : "Radiant";
    }
};