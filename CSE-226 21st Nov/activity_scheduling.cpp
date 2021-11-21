#include <bits/stdc++.h>
using namespace std;

struct activity {
    int start, finish;
    activity(int start, int finish) {
        this->start = start;
        this->finish = finish;
    }
    void print_activity() {
        printf("(s: %d f: %d)\n", start, finish);
    }
};

vector<activity> schedule_activities(activity *activities, int n) {
    vector<activity> scheduled;
    int k = 0;
    scheduled.push_back(activities[k]);
    for(int i = 1; i < n; ++i)
        if(activities[i].start >= activities[k].finish) {
            scheduled.push_back(activities[i]);
            k = i;
        }

    return scheduled;
}

int main() {
    activity activities[] = {activity(1, 4), activity(3, 5),
                             activity(0, 6), activity(5, 7),
                             activity(3, 9), activity(5, 9),
                             activity(6, 10), activity(8, 11),
                             activity(8, 12), activity(2, 14),
                             activity(12, 16)};

    int n = sizeof(activities) / sizeof(activities[0]);
    vector<activity> scheduled = schedule_activities(activities, n);

    cout << scheduled.size() << endl;
    for(int i = 0; i < scheduled.size(); ++i)
        scheduled[i].print_activity();

    return 0;
}
