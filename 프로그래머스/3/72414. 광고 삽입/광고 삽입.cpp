#include <bits/stdc++.h>

using namespace std;

string time_to_string(long time) {
    string hh = to_string(time / 3600);
    time %= 3600;
    
    string mm = to_string(time / 60);
    time %= 60;
    
    string ss = to_string(time);
    
    if(hh.size() == 1) hh = '0' + hh;
    if(mm.size() == 1) mm = '0' + mm;
    if(ss.size() == 1) ss = '0' + ss;
    
    return hh + ':' + mm + ':' + ss;
}

long time_converter(string time) {
    long hh = stoi(time.substr(0, 2));
    long mm = stoi(time.substr(3, 2));
    long ss = stoi(time.substr(6, 2));
    
    return hh * 3600 + mm * 60 + ss;
}

pair<long, long> log_to_time(string time) {
    long h1 = stoi(time.substr(0, 2));
    long m1 = stoi(time.substr(3, 2));
    long s1 = stoi(time.substr(6, 2));
    
    long h2 = stoi(time.substr(9, 2));
    long m2 = stoi(time.substr(12, 2));
    long s2 = stoi(time.substr(15, 2));
    
    long start = h1 * 3600 + m1 * 60 + s1;
    long end = h2 * 3600 + m2 * 60 + s2;
    
    return {start, end};
}

string solution(string play_time, string adv_time, vector<string> logs) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    long endTime = time_converter(play_time);
    long adTime = time_converter(adv_time);
    
    vector<long> views(endTime+1, 0);

    for(const auto &log : logs) {
        auto watchData = log_to_time(log);
        views[watchData.first]++;
        views[watchData.second]--;
    }

    for(long i = 0; i <= endTime; i++) {
        views[i] += views[i - 1];
    }

    long adStart = 0;
    long maxSum = 0;
    long sum = 0;
    for(long i = 0; i < adTime; i++) {
        sum += views[i];
    }

    for(long i = adTime-1; i <= endTime; i++) {
        sum += views[i] - views[i - adTime];
        if(sum > maxSum) {
            maxSum = sum;
            adStart = i - adTime + 1;
        }
    }

    return time_to_string(adStart);
}