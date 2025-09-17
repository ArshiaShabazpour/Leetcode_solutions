
class Food {
  public:
    string name;
    string cuisine;
    int    rating;
    int    idx;   // index inside its cuisine heap
};

class Heap {
  public:
    vector<Food*> a; // binary max-heap of Food* (by rating desc, name asc)

    static bool better(const Food* x, const Food* y) {
        if (x->rating != y->rating) return x->rating > y->rating;
        return x->name < y->name;
    }

    static void swapAt(vector<Food*>& v, int i, int j) {
        if (i == j) return;
        swap(v[i], v[j]);
        v[i]->idx = i;
        v[j]->idx = j;
    }

    void siftUp(int i) {
        while (i > 0) {
            int p = (i - 1) / 2;
            if (better(a[i], a[p])) {
                swapAt(a, i, p);
                i = p;
            } else break;
        }
    }

    void siftDown(int i) {
        int n = (int)a.size();
        while (true) {
            int l = 2*i + 1, r = 2*i + 2, best = i;
            if (l < n && better(a[l], a[best])) best = l;
            if (r < n && better(a[r], a[best])) best = r;
            if (best == i) break;
            swapAt(a, i, best);
            i = best;
        }
    }

    // For constructor phase: push without heapifying (we'll build later)
    void addRaw(Food* f) {
        f->idx = (int)a.size();
        a.push_back(f);
    }

    // Bottom-up heapify once after all addRaw calls (O(m) per heap)
    void build() {
        for (int i = (int)a.size()/2 - 1; i >= 0; --i) siftDown(i);
        // ensure indices are consistent (siftDown already fixes via swapAt)
        for (int i = 0; i < (int)a.size(); ++i) a[i]->idx = i;
    }

    const string& topName() const { return a[0]->name; }
};

class FoodRatings {
    // Map #1: food name -> Food (owner; stable addresses after construction)
    unordered_map<string, Food> foods;
    // Map #2: cuisine -> Heap (vector<Food*>)
    unordered_map<string, Heap> heaps;

public:
    FoodRatings(vector<string>& foodsV, vector<string>& cuisinesV, vector<int>& ratingsV) {
        int n = (int)foodsV.size();

        // 1) Own all Food objects first so their addresses won't change.
        foods.reserve(n);
        for (int i = 0; i < n; ++i) {
            foods.emplace(foodsV[i], Food{foodsV[i], cuisinesV[i], ratingsV[i], 0});
        }

        // 2) Fill raw heaps with pointers, then build each once.
        heaps.reserve(n); // upper bound on number of cuisines
        for (int i = 0; i < n; ++i) {
            Food* f = &foods.at(foodsV[i]);
            heaps[f->cuisine].addRaw(f);
        }
        for (auto& kv : heaps) kv.second.build();
    }

    void changeRating(string foodName, int newRating) {
        Food& f = foods.at(foodName);
        Heap& h = heaps[f.cuisine];

        int old = f.rating;
        f.rating = newRating;

        if (newRating > old)       h.siftUp(f.idx);
        else if (newRating < old)  h.siftDown(f.idx);
        // equal -> no change (tie-breaker is only by name, which is constant)
    }

    string highestRated(string cuisine) {
        Heap& h = heaps[cuisine];
        return h.a.empty() ? string() : h.topName();
    }
};

