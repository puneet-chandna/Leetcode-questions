struct PairHash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};

class MovieRentingSystem {
private:
    unordered_map<int, set<pair<int, int>>> availableMovies;
    unordered_map<pair<int, int>, int, PairHash> shopMoviePrice;
    set<tuple<int, int, int>> rentedMovies;
    
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto& entry : entries) {
            int shop = entry[0], movie = entry[1], price = entry[2];
            availableMovies[movie].insert({price, shop});
            shopMoviePrice[{shop, movie}] = price;
        }
    }
    
    vector<int> search(int movie) {
        vector<int> result;
        if (availableMovies.find(movie) == availableMovies.end()) {
            return result;
        }
        
        int count = 0;
        for (auto& entry : availableMovies[movie]) {
            if (count >= 5) break;
            result.push_back(entry.second);
            count++;
        }
        return result;
    }
    
    void rent(int shop, int movie) {
        int price = shopMoviePrice[{shop, movie}];
        availableMovies[movie].erase({price, shop});
        rentedMovies.insert({price, shop, movie});
    }
    
    void drop(int shop, int movie) {
        int price = shopMoviePrice[{shop, movie}];
        rentedMovies.erase({price, shop, movie});
        availableMovies[movie].insert({price, shop});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> result;
        int count = 0;
        for (auto& entry : rentedMovies) {
            if (count >= 5) break;
            result.push_back({get<1>(entry), get<2>(entry)});
            count++;
        }
        return result;
    }
};