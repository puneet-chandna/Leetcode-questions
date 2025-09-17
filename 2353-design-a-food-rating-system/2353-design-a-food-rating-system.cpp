class FoodRatings {
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; ++i) {
            string food = foods[i];
            string cuisine = cuisines[i];
            int rating = ratings[i];
            foodToCuisine[food] = cuisine;
            foodToRating[food] = rating;
            
            cuisineSet[cuisine].insert({-rating, food});
        }
    }

    void changeRating(string food, int newRating) {
        string cuisine = foodToCuisine[food];
        int oldRating = foodToRating[food];
        auto &s = cuisineSet[cuisine];
        s.erase({-oldRating, food});
        s.insert({-newRating, food});
        foodToRating[food] = newRating;
    }

    string highestRated(string cuisine) {
       
        auto &s = cuisineSet[cuisine];
        auto it = s.begin();
        return it->second;
    }

private:
    unordered_map<string, string> foodToCuisine;
    unordered_map<string, int> foodToRating;
    unordered_map<string, set<pair<int, string>>> cuisineSet;
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */