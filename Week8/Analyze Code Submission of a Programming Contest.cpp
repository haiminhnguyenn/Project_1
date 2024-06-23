#include <bits/stdc++.h>
using namespace std;

int toInt(string str){
    int result = 0, digitMultiplier = 1;
    for(int index = str.size() - 1; index > 0; index--){
        result += (str[index] - 48) * digitMultiplier;
        digitMultiplier *= 10;
    }
    return result;
}

int main() {
    vector<vector<int>> matrix(20000, vector<int>(100, 0));
    vector<int> maxPoints(20000, 0);
    vector<int> errorCount(20000, 0);
    vector<int> beginTime(100000, 0);
    vector<int> endTime(100000, 0);

    int totalSubmissions = 0, numErrors = 0;
    string userID, problemID, timeStamp, status;
    int points;

    cin >> userID;

    while(userID != "#"){
        totalSubmissions += 1;
        cin >> problemID >> timeStamp >> status >> points;

        beginTime[(timeStamp[0] * 10 + timeStamp[1]) * 3600 +
                  (timeStamp[3] * 10 + timeStamp[4]) * 60 +
                  timeStamp[6] * 10 + timeStamp[7] - 1933008] += 1;

        int i = toInt(userID), j = toInt(problemID);

        if(matrix[i][j] < points){
            maxPoints[i] += points - matrix[i][j];
            matrix[i][j] = points;
        }

        if(status == "ERR"){
            errorCount[i] += 1;
            numErrors += 1;
        }

        cin >> userID;
    }

    for(int i = 1; i < 86401; i++){
        beginTime[i] += beginTime[i - 1];
        endTime[i] = totalSubmissions - beginTime[i];
    }

    cin >> userID;

    while(userID != "#"){
        if(userID == "?number_submission_period"){
            cin >> userID >> problemID;
            cout << totalSubmissions - beginTime[(userID[0] * 10 + userID[1]) * 3600 +
                                                  (userID[3] * 10 + userID[4]) * 60 +
                                                  userID[6] * 10 + userID[7] - 1933009] -
                    endTime[(problemID[0] * 10 + problemID[1]) * 3600 +
                            (problemID[3] * 10 + problemID[4]) * 60 +
                            problemID[6] * 10 + problemID[7] - 1933008] << "\n";
        }
        else if(userID == "?total_point_of_user"){
            cin >> userID;
            cout << maxPoints[toInt(userID)] << "\n";
        }
        else if(userID == "?number_error_submision_of_user"){
            cin >> userID;
            cout << errorCount[toInt(userID)] << "\n";
        }
        else if(userID == "?number_error_submision"){
            cout << numErrors << "\n";
        }
        else{
            cout << totalSubmissions << "\n";
        }

        cin >> userID;
    }
}
