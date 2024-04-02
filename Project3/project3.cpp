#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <sstream>

using namespace std;

class Train {
private:
    queue<stack<int>> trainStack;

    int trainNumber;
    int loadingTime;

public:
    Train(int number) : trainNumber(number), loadingTime(0) {}

    void addItem(int item) {
        if (trainStack.empty() || trainStack.back().size() >= 5) {
            stack<int> newStack;
            trainStack.push(newStack);
        }
        trainStack.back().push(item);
    }

    void calculateLoadingTime() {
        loadingTime = trainStack.size() * 2 * trainNumber;
    }

    int getLoadingTime() const {
        return loadingTime;
    }
};

class Plane {
private:
    queue<int> planeQueue;

    int planeNumber;
    int loadingTime;

public:
    Plane(int number) : planeNumber(number), loadingTime(0) {}

    void addItem(int item) {
        planeQueue.push(item);
    }

    void calculateLoadingTime() {
        loadingTime = planeQueue.size() * 10 * planeNumber;
    }

    int getLoadingTime() const {
        return loadingTime;
    }
};

class UMD {
private:
    vector<Train> trains;
    vector<Plane> planes;
    int nt, np;

public:
    UMD(int t, int p, int nt_items, int np_items) : nt(nt_items), np(np_items) {
        for (int i = 1; i <= t; i++) {
            trains.push_back(Train(i));
        }
        for (int i = 1; i <= p; i++) {
            planes.push_back(Plane(i));
        }
    }

    void itemsToTrains(const vector<int>& trainItems, const vector<int>& trainDestinations) {
        for (size_t i = 0; i < trainItems.size(); i++) {
            trains[trainDestinations[i] - 1].addItem(trainItems[i]);
        }
    }

    void itemsToPlanes(const vector<int>& planeItems, const vector<int>& planeDestinations) {
        for (size_t i = 0; i < planeItems.size(); i++) {
            planes[planeDestinations[i] - 1].addItem(planeItems[i]);
        }
    }

    void calculateLoadingTimes() {
        for (auto& train : trains) {
            train.calculateLoadingTime();
        }
        for (auto& plane : planes) {
            plane.calculateLoadingTime();
        }
    }

    void printLoadingTimes() {
        for (const auto& train : trains) {
            cout << train.getLoadingTime() << " ";
        }
        cout << endl;
        for (const auto& plane : planes) {
            cout << plane.getLoadingTime() << " ";
        }
        cout << endl;
    }
};

int main() {
    int t, p, nt, np;
    cin >> t >> p >> nt >> np;

    vector<int> trainItems(t);
    for (int i = 0; i < t; i++) {
        cin >> trainItems[i];
    }

    vector<int> planeItems(p);
    for (int i = 0; i < p; i++) {
        cin >> planeItems[i];
    }

    vector<int> trainDestinations(nt);
    for (int i = 0; i < nt; i++) {
        cin >> trainDestinations[i];
    }

    vector<int> planeDestinations(np);
    for (int i = 0; i < np; i++) {
        cin >> planeDestinations[i];
    }

    UMD umd(t, p, nt, np);
    umd.itemsToTrains(trainItems, trainDestinations);
    umd.itemsToPlanes(planeItems, planeDestinations);
    umd.calculateLoadingTimes();
    umd.printLoadingTimes();

    return 0;
}