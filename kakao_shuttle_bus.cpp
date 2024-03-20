#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

bool compare(string a, string b) {
    return a < b;
}

bool compare2(pair<int, int> a, pair<int, int> b) {
    if (a.first < b.first) {
        return true;
    }
    else if (a.first > b.first) {
        return false;
    }
    else {
        return a.second < b.second;
    }
    return a < b;
}

pair<int, int> time_plus(pair<int, int> base, int val) {
    pair<int, int> tmp;
    if (base.second + val >= 60) {
        tmp.second = base.second + val - 60;
        tmp.first = base.first + 1;
    }
    else if (base.second + val < 0) {
        tmp.second = base.second + val + 60;
        tmp.first = base.first - 1;
    }
    else {
        tmp.first = base.first;
        tmp.second = base.second + val;
    }

    return tmp;

}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";

    // for(int i=0;i<timetable.size();i++){
    //     cout << timetable[i];
    // }

    vector<pair<int, int>> new_timetable;
    for (int i = 0; i < timetable.size(); i++) {
        int hour = stoi(timetable[i].substr(0, 2));
        int minute = stoi(timetable[i].substr(3, 2));
        new_timetable.push_back({ hour, minute });
    }



    vector<string> mp;
    copy(mp.begin(), mp.end(), timetable.begin());
    //tinetable 정렬
    sort(timetable.begin(), timetable.end(), compare);

    //셔틀 운영 큐
    vector<pair<int, int>> q;
    q.push_back({ 9,0 });
    pair<int, int> tmp = { 9,0 };
    for (int i = 1; i < n; i++) {
        tmp = time_plus(tmp, t);
        q.push_back(tmp);

        //cout << tmp.first << " " << tmp.second << endl;
    }


    //이분 탐색을 해보자
    pair<int, int> min = { 0,0 };
    pair<int, int> max = { 23,59 };
    pair<int, int> answer2;

    while (true) {
        if (min.first > max.first) {
            break;
        }
        else if (min.first == max.first && min.second > max.second) {
            break;
        }
        int tmp = ((min.first + max.first) * 60 + min.second + max.second) / 2;
        pair<int, int> mid = { tmp/60 , tmp%60 };


        //큐에 실어서 보내보자
        //timetable.push_back(mid);
        vector<pair<int, int>> table{ new_timetable.begin(), new_timetable.end() };
        bool search = false;
        table.push_back(mid);
        sort(table.begin(), table.end(), compare2);
        auto iter = find(table.begin(), table.end(), mid);
        for (int i = 0; i < q.size(); i++) {
            pair<int, int> bus_time = q[i];
            for (int j = 0; j < m; j++) {
                if (table[0].first < bus_time.first || (table[0].first == bus_time.first && table[0].second <= bus_time.second)) {
                    if (table[0] == mid ) {
                        if (table.size() > 1) {
                            if (table[1] == mid) {
                                table.erase(table.begin());
                                continue;
                            }
                        }
                        answer2 = mid;
                        search = true;
                        //cout << "답찾음" << mid.first << " " << mid.second << " " << bus_time.first << " "
                        //    << bus_time.second << endl;

                        goto A;
                    }

                    table.erase(table.begin());
                }

            }
        }
        A:



        //도착 할 수 있으면 더 늦게
        if (search) {
            min = time_plus(mid, 1);
        }
        else {
            //도착 할 수 없으면 더 빨리
            max = time_plus(mid, -1);
        }

        //cout << search << " " << mid.first <<" " << mid.second<<" " << min.first << " " << min.second << max.first << " " << max.second << endl;
        //break;
        //아무튼 넣었던 mid는 없애야함
    }


    //탈 수 있는 큐 찾아서 max 값 초기화
    string _hour = "00" + to_string(answer2.first);
    string _min = "00" + to_string(answer2.second);

    //cout << _hour.substr(_hour.size()-2) << _min.substr(_min.size()-2)  << endl;

    return _hour.substr(_hour.size() - 2) + _min.substr(_min.size() - 2);
}

void main() {
    vector<string> red;
    red.push_back("09:00");
    red.push_back("09:00");
    red.push_back("09:00");
    red.push_back("09:00");
    string blue = solution(2, 1, 2, red);
    cout << "답은 : " << blue;
}