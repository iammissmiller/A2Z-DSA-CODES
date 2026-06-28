class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int lastfruit = -1;
        int secondlastfruit = -1;

        int lastfruitcount = 0;
        int currentmax = 0;
        int maxfruits = 0;

        for(int fruit : fruits)
        {
            if(fruit == lastfruit || fruit == secondlastfruit)
            {
                currentmax++;
            }
            else
            {
                currentmax = lastfruitcount + 1;
            }

            if(fruit == lastfruit)
            lastfruitcount++;
            else
            {
                lastfruitcount = 1;
                secondlastfruit = lastfruit;
                lastfruit = fruit;
            }

            maxfruits = max(maxfruits,currentmax);
        }

        return maxfruits;

    }
};
